#include "MainWindow.h"

#include "calculate.h"
#include "MainWindowTitlebar.h"

#include "Menus/SettingsMenu/SettingsMenu.h"
#include "Menus/SettingsMenu/ThemesWidget.h"
#include "Menus/ThemeEditor/ThemeEditor.h"
#include "Menus/ThemeEditor/WidgetEditor.h"
#include "Widgets/Dialogs/CreateNewThemeDialog.h"

#include <Windows.h>
#include <windowsx.h>

#include <QIcon>
#include <QPainterPath>

using Layers::ThemeEditor;
using Layers::Menu;
using Layers::SettingsMenu;
using Layers::Themeable;
using Layers::MainWindowTitlebar;
using Layers::MainWindow;

MainWindow::MainWindow(bool preview, QWidget* parent) :
	m_settings_menu{ new SettingsMenu },
	m_theme_editor{ new ThemeEditor },
	m_titlebar{ new MainWindowTitlebar },
	Widget(parent)
{
	init_attributes();
	init_layout();
	init_themes_widget_connections();
	init_titlebar_connections();
	resize(1200, 800);
	set_name("main_window");
	set_proper_name("Main Window");
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	if (!preview)
		layersApp->add_child_themeable_pointer(*this);
	
	m_settings_menu->hide();
	m_theme_editor->hide();

	connect(m_titlebar->menu_tab_bar(), SIGNAL(index_changed(int, int)),
		this, SLOT(menu_changed(int, int)));

	connect(m_titlebar->menu_tab_bar(), SIGNAL(tab_closed(int)),
		this, SLOT(close_menu(int)));

	m_separator->set_icon(new Graphic(":/svgs/separator_h_icon.svg"));
	m_separator->set_name("separator");
	m_separator->set_proper_name("Separator");
	m_separator->setFixedHeight(3);

	assign_tag_prefixes();
	apply_theme(*layersApp->active_theme());
}

void MainWindow::edit_themeable(Themeable* themeable)
{
	m_theme_editor->edit_themeable(themeable);
}

void MainWindow::set_central_widget(Widget* central_widget)
{
	m_central_widget = central_widget;

	if (Themeable* central_themeable = dynamic_cast<Themeable*>(m_central_widget))
	{
		central_themeable->set_is_app_themeable(true);
		central_themeable->apply_theme(*layersApp->active_theme());

		if (central_themeable->icon())
			set_icon(new Graphic(*central_themeable->icon()));
	}

	m_main_layout->addWidget(m_central_widget);

	if (m_central_widget->icon())
		open_widget(m_central_widget, *m_central_widget->name(),
			m_central_widget->icon());
	else
		open_widget(m_central_widget, *m_central_widget->name());

	Tab* app_menu_tab = m_titlebar->menu_tab_bar()->tabs().last();
	app_menu_tab->close_button()->hide();
	//app_menu_tab->text_label()->set_font_size(12);
	app_menu_tab->text_label()->set_padding(0, 8, 8, 0);
}

void MainWindow::center_dialog(QDialog* dialog)
{
	dialog->move(
		x() + (width() - dialog->width()) / 2,
		y() + (height() - dialog->height()) / 2);
}

Themeable* MainWindow::clone()
{
	MainWindow* w = new MainWindow(true);

	w->setMinimumSize(500, 400);

	return w;
}

void MainWindow::update_theme_dependencies()
{
	if (isMaximized())
		m_main_layout->setContentsMargins(0, 0, 0, 0);
	else
	{
		int border_thickness = border()->thickness()->as<double>();

		m_main_layout->setContentsMargins(
			border_thickness + m_margins->left()->as<double>(),
			border_thickness + m_margins->top()->as<double>(),
			border_thickness + m_margins->right()->as<double>(),
			border_thickness + m_margins->bottom()->as<double>());
	}
}

void MainWindow::menu_changed(int old_index, int new_index)
{
	if (QWidget* old_widget = (old_index != -1) ?
		m_opened_widgets[old_index] : nullptr)
	{
		old_widget->hide();
	}

	m_opened_widgets[new_index]->show();
}

void MainWindow::open_widget(
	Widget* widget, const QString& name, Graphic* graphic)
{
	TabBar* tab_bar = m_titlebar->menu_tab_bar();

	if (!m_opened_widgets.contains(widget))
	{
		m_opened_widgets.append(widget);

		if (graphic)
			tab_bar->add_tab(new Graphic(*graphic), name);
		else
			tab_bar->add_tab(name);
	}

	tab_bar->set_current_index(m_opened_widgets.indexOf(widget));
}

void MainWindow::close_menu(int index)
{
	m_opened_widgets.removeAt(index);
}

void MainWindow::new_theme_clicked()
{
	CreateNewThemeDialog* dialog = layersApp->create_new_theme_dialog();

	dialog->clear_theme_combobox();

	for (Theme* theme : layersApp->themes())
		if (theme->has_app_implementation())
			dialog->add_theme_to_combobox(theme);

	dialog->set_current_start_theme_name(
		layersApp->active_theme()->name());

	center_dialog(dialog);

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

bool MainWindow::nativeEvent(
	const QByteArray& eventType, void* message, qintptr* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
			return false;

		*result = 0;
		const LONG borderWidth =
			border()->thickness()->as<qreal>() * devicePixelRatio();
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		// must be short to correctly work with multiple monitors
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

		if (m_titlebar == QApplication::widgetAt(QCursor::pos()))
		{
			*result = HTCAPTION;
			return true;
		}

		if (*result != 0)
			return true;
	}

	return false;
}

void MainWindow::init_attributes()
{
	m_border->thickness()->set_value(15.0);
	m_border->fill()->set_value(
		QVariant::fromValue(
			QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } })));
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	connect(m_border->thickness(), &Attribute::changed, [this]
		{ update_theme_dependencies(); });

	for (Attribute* margin : *m_margins)
		connect(margin, &Attribute::changed, [this]
			{ update_theme_dependencies(); });

	m_settings_menu->fill()->set_value(QColor("#ff5555"));
	m_settings_menu->fill()->set_disabled();

	m_theme_editor->fill()->set_disabled();

	m_separator->fill()->set_value(QColor("#25272b"));
}

void MainWindow::init_layout()
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

void MainWindow::init_themes_widget_connections()
{
	ThemesWidget* themes_widget = m_settings_menu->themes_widget();

	connect(themes_widget->customize_theme_button(), &Button::clicked, [this]
		{
			if (!m_theme_editor->preview_widget())
				m_theme_editor->edit_themeable(layersApp);

			open_widget(m_theme_editor, *m_theme_editor->name());
		});

	connect(themes_widget->new_theme_button(), &Button::clicked,
		this, &MainWindow::new_theme_clicked);
}

void MainWindow::init_titlebar_connections()
{
	connect(m_titlebar->settings_button(), &Button::clicked, [this]
		{
			open_widget(m_settings_menu, *m_settings_menu->name());
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
