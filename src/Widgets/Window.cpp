#include "../../include/AttributeWidgets.h"
#include "../../include/calculate.h"
#include "../../include/CustomizePanel.h"
#include "../../include/Window.h"

#include <Windows.h>
#include <windowsx.h>

#include <QIcon>
#include <QPainterPath>

using Layers::ColorDialog;
using Layers::CustomizeMenu;
using Layers::GradientDialog;
using Layers::Menu;
using Layers::SettingsMenu;
using Layers::Theme;
using Layers::Titlebar;
using Layers::Window;

Window::Window(bool preview, QWidget* parent) :
	m_preview{ preview }, Widget(parent)
{
	layersApp->add_child_themeable_pointer(*this);

	set_window_title(layersApp->name());
	
	if (layersApp->icon_file())
	{
		set_window_icon(Graphic(layersApp->icon_file()->fileName()));

		setWindowIcon(QIcon(layersApp->icon_file()->fileName()));
	}

	connect(m_titlebar->window_icon(), &Button::clicked, [this] { open_menu(m_app_menu); });
	connect(m_titlebar, &Titlebar::window_icon_updated, [=]
		{
			connect(m_titlebar->window_icon(), &Button::clicked, [this] { open_menu(m_app_menu); });
		});
	connect(m_titlebar->settings_button(), &Button::clicked, this, &Window::settings_clicked);
	connect(m_titlebar->minimize_button(), &Button::clicked, this, &Window::minimize_clicked);
	connect(m_titlebar->maximize_button(), &Button::clicked, this, &Window::maximize_clicked);
	connect(m_titlebar->exit_button(), &Button::clicked, this, &Window::exit_clicked);
	connect(m_settings_menu->themes_settings_panel()->customize_theme_button(), &Button::clicked, this, &Window::customize_clicked);
	connect(m_settings_menu->themes_settings_panel()->new_theme_button(), &Button::clicked, this, &Window::new_theme_clicked);

	set_name("window");
	set_proper_name("Window");
	border.thickness.set_value(15.0);
	border.fill.set_value(
		QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } })));
	corner_radii.top_left.set_value(10.0);
	corner_radii.top_right.set_value(10.0);
	corner_radii.bottom_left.set_value(10.0);
	corner_radii.bottom_right.set_value(10.0);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setMinimumSize(200, m_titlebar->height() + border.thickness.as<double>() * 2);
	resize(1200, 800);

	m_create_new_theme_dialog->set_proper_name("Create New Theme Dialog");

	m_control_color_dialog->hide();
	m_control_color_dialog->set_proper_name("Color Dialog");

	m_control_gradient_selection_dialog->hide();
	m_control_gradient_selection_dialog->set_proper_name("Gradient Dialog");

	m_control_update_dialog->hide();
	m_control_update_dialog->set_proper_name("Update Dialog");

	m_app_menu->a_fill.set_disabled();

	m_settings_menu->a_fill.set_value(QColor("#ff5555"));
	m_settings_menu->a_fill.set_disabled();
	m_settings_menu->hide();

	m_customize_menu->a_fill.set_disabled();
	m_customize_menu->hide();

	add_menu(m_app_menu);
	add_menu(m_settings_menu);
	add_menu(m_customize_menu);
	
	m_menu_stack.append(m_app_menu);

	setup_layout();

	for (const QString& theme_name : layersApp->themes().keys())
		link_theme_name(theme_name);

	// Do this last:
	assign_tag_prefixes();

	if (!preview)
	{
		m_customize_menu->init_preview_window();

		apply_theme(*layersApp->current_theme()); // Sets initial theme
		m_settings_menu->themes_settings_panel()->theme_combobox()->set_current_item(m_current_theme->name());
	}
}

void Window::add_menu(Menu* menu)
{
	m_menus.append(menu);
}

Menu* Window::app_menu() const
{
	return m_app_menu;
}

void Window::link_theme_name(const QString& name)
{
	m_settings_menu->themes_settings_panel()->theme_combobox()->add_item(name);

	m_create_new_theme_dialog->add_theme_name_to_combobox(name);
}

void Window::set_main_widget(Widget* main_widget)
{
	m_main_widget = main_widget;

	main_widget->set_is_app_themeable(true);
	main_widget->apply_theme(*layersApp->current_theme());

	add_child_themeable_pointer(main_widget);

	m_app_menu_layout->addWidget(main_widget);

	//if (m_customize_menu->preview_window())
	//	m_customize_menu->preview_window()->build_main_widget<T>();
}

void Window::assign_tag_prefixes()
{
	for (Themeable* themeable_child_element : child_themeables())
	{
		themeable_child_element->assign_tag_prefixes(m_tag_prefixes, "");
	}

	m_tag_prefixes_assigned = true;
}

void Window::center_dialog(QDialog* dialog)
{
	dialog->move(x() + (width() / 2) - (dialog->width() / 2), y() + (height() / 2) - (dialog->height() / 2));
}

ColorDialog* Window::control_color_dialog() const
{
	return m_control_color_dialog;
}

GradientDialog* Window::control_gradient_selection_dialog() const
{
	return m_control_gradient_selection_dialog;
}

CustomizeMenu* Window::customize_menu() const
{
	return m_customize_menu;
}

void Window::finalize()
{
	m_customize_menu->init_preview_window();

	apply_theme(*layersApp->current_theme()); // Sets initial theme
	m_settings_menu->themes_settings_panel()->theme_combobox()->set_current_item(m_current_theme->name());
}

void Window::update_theme_dependencies()
{
	if (m_maximized)
		m_main_layout->setContentsMargins(0, 0, 0, 0);
	else
	{
		int margin = border.thickness.as<double>();

		m_main_layout->setContentsMargins(margin, margin, margin, margin);
	}
}

//void Window::set_application_widget(Widget* application_widget)
//{
//	m_app_menu_layout->addWidget(application_widget);
//	//m_app_menu_layout->setAlignment(application_widget, Qt::AlignCenter);
//}

void Window::set_window_icon(const Graphic& icon_graphic)
{
	m_titlebar->set_window_icon(icon_graphic);

	//if (m_customize_menu->preview_window())
	//	m_customize_menu->preview_window()->set_window_icon(icon_graphic);
}

void Window::set_window_title(const QString& title)
{
	m_titlebar->set_window_title(title);

	//if (m_customize_menu->preview_window())
	//	m_customize_menu->preview_window()->set_window_title(title);
}

SettingsMenu* Window::settings_menu() const
{
	return m_settings_menu;
}

Titlebar* Window::titlebar() const
{
	return m_titlebar;
}

void Window::open_menu(Menu* menu)
{
	if (m_menu_stack.contains(menu))
	{
		if (m_menu_stack.last() != menu)
		{
			int menu_index = m_menu_stack.indexOf(menu);

			m_menu_stack.last()->hide();

			menu->show();

			while (menu_index < m_menu_stack.count() - 1) m_menu_stack.removeLast();

			m_titlebar->remove_mlls_past(menu_index - 1);
		}
	}
	else
	{
		MenuLabelLayer* mll = new MenuLabelLayer(menu);

		Menu* previous_menu = m_menu_stack.last();

		connect(mll->back_button(), &Button::clicked, [this, previous_menu] { open_menu(previous_menu); });

		previous_menu->hide();

		m_menu_stack.append(menu);

		menu->show();

		connect(mll->icon_button(), &Button::clicked, [this, menu] { open_menu(menu); });

		m_titlebar->add_mll(mll);
	}
}

void Window::customize_clicked()
{
	if (m_customize_menu->panels().isEmpty())
		m_customize_menu->open_customize_panel(
			new CustomizePanel(m_customize_menu->preview_widget()));
	
	open_menu(m_customize_menu);
}

void Window::exit_clicked()
{
	qApp->quit();
}

void Window::maximize_clicked()
{
	if (m_maximized)
	{
		showNormal();
		m_maximized = false;
	}
	else
	{
		showMaximized();
		m_maximized = true;
	}

	update_theme_dependencies();
	update();
}

void Window::minimize_clicked()
{
	showMinimized();
}

void Window::new_theme_clicked()
{
	m_create_new_theme_dialog->set_current_start_theme_name(m_current_theme->name());

	static_cast<Window*>(QApplication::activeWindow())->center_dialog(m_create_new_theme_dialog);

	m_create_new_theme_dialog->show();

	if (m_create_new_theme_dialog->exec() && !m_functionality_disabled)
	{
		layersApp->create_theme(m_create_new_theme_dialog->new_theme_name(), m_create_new_theme_dialog->copy_theme_name());

		link_theme_name(m_create_new_theme_dialog->new_theme_name());

		m_settings_menu->themes_settings_panel()->theme_combobox()->set_current_item(m_create_new_theme_dialog->new_theme_name());

		m_create_new_theme_dialog->clear();
	}
}

void Window::settings_clicked()
{
	open_menu(m_settings_menu);
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
		const LONG borderWidth = border.thickness.as<double>() * devicePixelRatio();;
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
	if (!m_maximized)
	{
		// CREATE VARIABLES:

		bool fill_disabled = a_fill.disabled();

		int border_thickness = (!border.disabled()) ?
			border.thickness.as<double>() : 0;

		int margin_left = margins.left.as<double>();
		int margin_top = margins.top.as<double>();
		int margin_right = margins.right.as<double>();
		int margin_bottom = margins.bottom.as<double>();

		int draw_width = width() - margin_left - margin_right;
		int draw_height = height() - margin_top - margin_bottom;

		int corner_radius_tl = (!corner_radii.disabled()) ?
			corner_radii.top_left.as<double>() : 0;
		int corner_radius_tr = (!corner_radii.disabled()) ?
			corner_radii.top_right.as<double>() : 0;
		int corner_radius_bl = (!corner_radii.disabled()) ?
			corner_radii.bottom_left.as<double>() : 0;
		int corner_radius_br = (!corner_radii.disabled()) ?
			corner_radii.bottom_right.as<double>() : 0;

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

		// - Draw Corner Color
		if (!a_corner_color.disabled())
		{
			painter.fillPath(corner_color_path, a_corner_color.as<QColor>());
		}

		// - Draw Border
		if (border_thickness)
		{
			if (QString(border.fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient gradient;

				gradient.setStart(0, 0);
				gradient.setFinalStop(width(), 0);
				gradient.setStops(border.fill.as<QGradientStops>());

				painter.fillPath(border_path, gradient);
			}
			else painter.fillPath(border_path, border.fill.as<QColor>());
		}

		// - Draw Background
		if (!fill_disabled)
		{
			if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(a_fill.as<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
			else
			{
				if (m_hovering && !a_hover_fill.disabled())
					painter.fillPath(background_path, a_hover_fill.as<QColor>());
				else
					painter.fillPath(background_path, a_fill.as<QColor>());
			}
		}

		// - Draw Outline Color
		if (!a_outline_color.disabled())
		{
			painter.strokePath(outline_color_path, QPen(a_outline_color.as<QColor>()));
		}
	}
	else
	{
		// CREATE VARIABLES:

		bool fill_disabled = a_fill.disabled();

		int margin_left = margins.left.as<double>();
		int margin_top = margins.top.as<double>();
		int margin_right = margins.right.as<double>();
		int margin_bottom = margins.bottom.as<double>();

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
			if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(a_fill.as<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
			else
			{
				if (m_hovering && !a_hover_fill.disabled())
					painter.fillPath(background_path, a_hover_fill.as<QColor>());
				else
					painter.fillPath(background_path, a_fill.as<QColor>());
			}
		}

		// - Draw Outline Color
		if (!a_outline_color.disabled())
		{
			painter.strokePath(outline_color_path, QPen(a_outline_color.as<QColor>()));
		}
	}
}

void Window::setup_layout()
{
	m_app_menu_layout->setContentsMargins(0, 0, 0, 0);
	m_app_menu_layout->setSpacing(0);

	m_app_menu->setLayout(m_app_menu_layout);

	int margin = border.thickness.as<double>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addWidget(m_app_menu);
	m_main_layout->addWidget(m_settings_menu);
	m_main_layout->addWidget(m_customize_menu);

	setLayout(m_main_layout);
}
