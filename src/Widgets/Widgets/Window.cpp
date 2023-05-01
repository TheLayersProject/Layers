#include "Window.h"

#include "calculate.h"
#include "Menu.h"
#include "Titlebar.h"

#include "Menus/SettingsMenu/SettingsMenu.h"
#include "Menus/SettingsMenu/ThemesWidget.h"
#include "Menus/ThemeEditor/ThemeEditor.h"
#include "Menus/ThemeEditor/WidgetEditor.h"
#include "Widgets/Dialogs/CreateNewThemeDialog.h"

#include <Windows.h>
#include <windowsx.h>

#include <QIcon>
#include <QPainterPath>

using Layers::ColorDialog;
using Layers::ThemeEditor;
using Layers::GradientDialog;
using Layers::Menu;
using Layers::SettingsMenu;
using Layers::Theme;
using Layers::Themeable;
using Layers::Titlebar;
using Layers::Window;

Window::Window(bool preview, QWidget* parent) :
	m_settings_menu{ new SettingsMenu },
	m_theme_editor{ new ThemeEditor },
	m_titlebar{ new Titlebar },
	Widget(parent)
{
	init_attributes();
	init_layout();
	init_themes_widget_connections();
	init_titlebar_connections();
	resize(1200, 800);
	set_name("window");
	set_proper_name("Window");
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	if (!preview)
		layersApp->add_child_themeable_pointer(*this);
	
	m_settings_menu->hide();
	m_theme_editor->hide();

	m_separator->set_icon(new Graphic(":/svgs/separator_h_icon.svg"));
	m_separator->set_name("separator");
	m_separator->set_proper_name("Separator");
	m_separator->setFixedHeight(3);

	assign_tag_prefixes();
	apply_theme(*layersApp->current_theme());
}

void Window::edit_themeable(Themeable* themeable)
{
	m_theme_editor->edit_themeable(themeable);
}

void Window::set_main_menu(Menu* main_menu)
{
	m_app_menu = main_menu;

	set_icon(new Graphic(*m_app_menu->icon()));

	m_titlebar->menu_tab_bar()->add_tab(m_app_menu);
	m_titlebar->menu_tab_bar()->tabs().last()->exit_button()->hide();
	m_titlebar->menu_tab_bar()->tabs().last()->text_label()->set_font_size(12);
	m_titlebar->menu_tab_bar()->tabs().last()->text_label()->set_padding(0, 8, 8, 0);
	m_titlebar->menu_tab_bar()->tabs().last()->fill()->set_state("Active");

	m_app_menu->set_is_app_themeable(true);
	m_app_menu->apply_theme(*layersApp->current_theme());

	m_main_layout->addWidget(m_app_menu);
}

void Window::center_dialog(QDialog* dialog)
{
	dialog->move(x() + (width() / 2) - (dialog->width() / 2), y() + (height() / 2) - (dialog->height() / 2));
}

Themeable* Window::clone()
{
	Window* w = new Window(true);

	w->setMinimumSize(500, 400);
	w->setMaximumSize(800, 600);

	return w;
}

void Window::update_theme_dependencies()
{
	if (isMaximized())
		m_main_layout->setContentsMargins(0, 0, 0, 0);
	else
	{
		int border_thickness = border()->thickness()->as<double>();

		int left_c_margin = border_thickness + m_margins->left()->as<double>();
		int top_c_margin = border_thickness + m_margins->top()->as<double>();
		int right_c_margin = border_thickness + m_margins->right()->as<double>();
		int bottom_c_margin = border_thickness + m_margins->bottom()->as<double>();

		m_main_layout->setContentsMargins(
			left_c_margin, top_c_margin, right_c_margin, bottom_c_margin);
	}
}

void Window::open_menu(Menu* menu)
{
	if (!menu->isVisible())
	{
		bool contains_tab_for_menu = false;
		Tab* pre_existing_tab = nullptr;

		for (Tab* tab : m_titlebar->menu_tab_bar()->tabs())
			if (tab->menu() == menu)
			{
				contains_tab_for_menu = true;
				pre_existing_tab = tab;
				break;
			}

		if (!contains_tab_for_menu)
		{
			m_titlebar->menu_tab_bar()->add_tab(menu);

			m_titlebar->menu_tab_bar()->select_tab(
				m_titlebar->menu_tab_bar()->tabs().last());
		}
		else
			m_titlebar->menu_tab_bar()->select_tab(pre_existing_tab);
	}
}

void Window::new_theme_clicked()
{
	CreateNewThemeDialog* dialog = layersApp->create_new_theme_dialog();

	dialog->clear_theme_combobox();

	for (Theme* theme : layersApp->themes())
		if (theme->has_app_implementation())
			dialog->add_theme_to_combobox(theme);

	dialog->set_current_start_theme_name(
		layersApp->current_theme()->name());

	static_cast<Window*>(QApplication::activeWindow())->center_dialog(dialog);

	dialog->show();

	if (dialog->exec() && !m_functionality_disabled)
	{
		Theme* copy_theme = layersApp->theme(dialog->copy_theme_id());
		Theme* new_theme = new Theme(dialog->new_theme_name());

		layersApp->themes()[new_theme->id()] = new_theme;

		QDir new_theme_dir = latest_T_version_path() + new_theme->id() + "\\";
		QDir copy_theme_dir = copy_theme->dir();

		new_theme->set_dir(new_theme_dir);

		if (!new_theme_dir.exists())
			new_theme_dir.mkdir(".");

		for (const QString& file_name : copy_theme_dir.entryList(QDir::Files))
			if (file_name != "meta.json")
				QFile::copy(
					copy_theme_dir.filePath(file_name),
					new_theme_dir.filePath(file_name));

		for (const QString& theme_id : copy_theme->lineage())
			new_theme->append_to_lineage(theme_id);

		new_theme->append_to_lineage(copy_theme->id());

		new_theme->save_meta_file();
		new_theme->load();

		ThemeComboBox* theme_combobox =
			m_settings_menu->themes_widget()->theme_combobox();

		theme_combobox->addItem(new_theme);

		layersApp->apply_theme(*new_theme);

		for (int i = 0; i < theme_combobox->count(); i++)
			if (theme_combobox->itemData(i) == new_theme->id())
			{
				theme_combobox->setCurrentIndex(i);
				break;
			}

		dialog->clear();
	}
}

bool Window::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
		{
			return false;
		}

		*result = 0;
		const LONG borderWidth = border()->thickness()->as<double>() * devicePixelRatio();;
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		// must be short to correctly work with multiple monitors (negative coordinates)
		short x = msg->lParam & 0x0000FFFF;
		short y = (msg->lParam & 0xFFFF0000) >> 16;

		bool resizeWidth = minimumWidth() != maximumWidth();
		bool resizeHeight = minimumHeight() != maximumHeight();

		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + borderWidth)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - borderWidth)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPRIGHT;
			}
		}

		if (m_titlebar->is(QApplication::widgetAt(QCursor::pos()))) {
			*result = HTCAPTION;
			return true;
		}

		if (*result != 0) return true;
	}

	return false;
}

void Window::paintEvent(QPaintEvent* event)
{
	if (!isMaximized())
	{
		// CREATE VARIABLES:

		bool fill_disabled = m_fill->disabled();

		int border_thickness = (!border()->disabled()) ?
			border()->thickness()->as<double>() : 0;

		int margin_left = m_margins->left()->as<double>();
		int margin_top = m_margins->top()->as<double>();
		int margin_right = m_margins->right()->as<double>();
		int margin_bottom = m_margins->bottom()->as<double>();

		int draw_width = width() - margin_left - margin_right;
		int draw_height = height() - margin_top - margin_bottom;

		int corner_radius_tl = (!m_corner_radii->disabled()) ?
			m_corner_radii->top_left()->as<double>() : 0;
		int corner_radius_tr = (!m_corner_radii->disabled()) ?
			m_corner_radii->top_right()->as<double>() : 0;
		int corner_radius_bl = (!m_corner_radii->disabled()) ?
			m_corner_radii->bottom_left()->as<double>() : 0;
		int corner_radius_br = (!m_corner_radii->disabled()) ?
			m_corner_radii->bottom_right()->as<double>() : 0;

		int tl_background_radius = border_thickness ? inner_radius(corner_radius_tl, border_thickness) : corner_radius_tl;
		int tr_background_radius = border_thickness ? inner_radius(corner_radius_tr, border_thickness) : corner_radius_tr;
		int bl_background_radius = border_thickness ? inner_radius(corner_radius_bl, border_thickness) : corner_radius_bl;
		int br_background_radius = border_thickness ? inner_radius(corner_radius_br, border_thickness) : corner_radius_br;

		// CREATE PATHS:

		// - Create Border Path
		QPainterPath border_path;
		border_path.moveTo(margin_left, margin_top + corner_radius_tl);
		border_path.arcTo(QRect(margin_left, margin_top, corner_radius_tl * 2, corner_radius_tl * 2), 180, -90);
		border_path.lineTo(margin_left + draw_width - corner_radius_tr, margin_top);
		border_path.arcTo(QRect(margin_left + draw_width - corner_radius_tr * 2, margin_top, corner_radius_tr * 2, corner_radius_tr * 2), 90, -90);
		border_path.lineTo(margin_left + draw_width, margin_top + draw_height - corner_radius_br);
		border_path.arcTo(QRect(margin_left + draw_width - corner_radius_br * 2, margin_top + draw_height - corner_radius_br * 2, corner_radius_br * 2, corner_radius_br * 2), 0, -90);
		border_path.lineTo(margin_left + corner_radius_bl, margin_top + draw_height);
		border_path.arcTo(QRect(margin_left, margin_top + draw_height - corner_radius_bl * 2, corner_radius_bl * 2, corner_radius_bl * 2), -90, -90);
		border_path.lineTo(margin_left, margin_top + corner_radius_tl);

		// - Create Background Path
		QPainterPath background_path;
		background_path.moveTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);
		background_path.arcTo(QRect(margin_left + border_thickness, margin_top + border_thickness, tl_background_radius * 2, tl_background_radius * 2), 180, -90);
		background_path.lineTo(margin_left + draw_width - tr_background_radius - border_thickness, margin_top + border_thickness);
		background_path.arcTo(QRect(margin_left + draw_width - tr_background_radius * 2 - border_thickness, margin_top + border_thickness, tr_background_radius * 2, tr_background_radius * 2), 90, -90);
		background_path.lineTo(margin_left + draw_width - border_thickness, margin_top + draw_height - br_background_radius - border_thickness);
		background_path.arcTo(QRect(margin_left + draw_width - br_background_radius * 2 - border_thickness, margin_top + draw_height - br_background_radius * 2 - border_thickness, br_background_radius * 2, br_background_radius * 2), 0, -90);
		background_path.lineTo(margin_left + border_thickness + bl_background_radius, margin_top + draw_height - border_thickness);
		background_path.arcTo(QRect(margin_left + border_thickness, margin_top + draw_height - bl_background_radius * 2 - border_thickness, bl_background_radius * 2, bl_background_radius * 2), -90, -90);
		background_path.lineTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);

		border_path = border_path - background_path;

		// - Create Corner Path
		QPainterPath corner_color_path;
		corner_color_path.addRect(0, 0, width(), height());
		corner_color_path = corner_color_path - background_path;
		corner_color_path = corner_color_path - border_path;

		// - Create Outline Path
		QPainterPath outline_color_path;
		outline_color_path.addRect(0, 0, width(), height());
		outline_color_path = outline_color_path - corner_color_path;

		// DRAW:

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// - Draw Border
		if (border_thickness)
		{
			if (QString(m_border->fill()->typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient gradient;

				gradient.setStart(0, 0);
				gradient.setFinalStop(width(), 0);
				gradient.setStops(m_border->fill()->as<QGradientStops>());

				painter.fillPath(border_path, gradient);
			}
			else painter.fillPath(border_path, m_border->fill()->as<QColor>());
		}

		// - Draw Background
		if (!fill_disabled)
		{
			if (QString(m_fill->typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(m_fill->as<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
			else
			{
				painter.fillPath(background_path, m_fill->as<QColor>());
			}
		}
	}
	else
	{
		// CREATE VARIABLES:

		bool fill_disabled = m_fill->disabled();

		int margin_left = m_margins->left()->as<double>();
		int margin_top = m_margins->top()->as<double>();
		int margin_right = m_margins->right()->as<double>();
		int margin_bottom = m_margins->bottom()->as<double>();

		int draw_width = width() - margin_left - margin_right;
		int draw_height = height() - margin_top - margin_bottom;

		// CREATE PATHS:

		// - Create Background Path
		QPainterPath background_path;
		background_path.moveTo(margin_left, margin_top);
		background_path.lineTo(margin_left + draw_width, margin_top);
		background_path.lineTo(margin_left + draw_width, margin_top + draw_height);
		background_path.lineTo(margin_left, margin_top + draw_height);
		background_path.lineTo(margin_left, margin_top);

		// - Create Outline Path
		QPainterPath outline_color_path;
		outline_color_path.addRect(0, 0, width(), height());

		// DRAW:

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// - Draw Background
		if (!fill_disabled)
		{
			if (QString(m_fill->typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(m_fill->as<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
			else
			{
				painter.fillPath(background_path, m_fill->as<QColor>());
			}
		}
	}
}

void Window::init_attributes()
{
	m_border->thickness()->set_value(15.0);
	m_border->fill()->set_value(
		QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } })));
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	connect(m_border->thickness(), &Attribute::value_changed, [this] {
		update_theme_dependencies();
		});

	for (Attribute* margin : *m_margins)
		connect(margin, &Attribute::value_changed, [this] {
		update_theme_dependencies();
			});

	m_settings_menu->fill()->set_value(QColor("#ff5555"));
	m_settings_menu->fill()->set_disabled();

	m_theme_editor->fill()->set_disabled();

	m_separator->fill()->set_value(QColor("#25272b"));
}

void Window::init_layout()
{
	int margin = border()->thickness()->as<double>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addWidget(m_separator);
	m_main_layout->addWidget(m_settings_menu);
	m_main_layout->addWidget(m_theme_editor);

	setLayout(m_main_layout);
}

void Window::init_themes_widget_connections()
{
	ThemesWidget* themes_widget = m_settings_menu->themes_widget();

	connect(themes_widget->customize_theme_button(), &Button::clicked, [this]
		{
			if (!m_theme_editor->preview_widget())
				m_theme_editor->edit_themeable(layersApp);

			open_menu(m_theme_editor);
		});

	connect(themes_widget->new_theme_button(), &Button::clicked,
		this, &Window::new_theme_clicked);
}

void Window::init_titlebar_connections()
{
	connect(m_titlebar->settings_button(), &Button::clicked, [this]
		{
			open_menu(m_settings_menu);
		});

	connect(m_titlebar->minimize_button(), &Button::clicked, [this]
		{
			showMinimized();
		});

	connect(m_titlebar->maximize_button(), &Button::clicked, [this]
		{
			if (isMaximized())
				showNormal();
			else
				showMaximized();

			update_theme_dependencies();
			update();
		});

	connect(m_titlebar->exit_button(), &Button::clicked, [this]
		{
			if (!m_functionality_disabled)
				qApp->quit();
		});
}
