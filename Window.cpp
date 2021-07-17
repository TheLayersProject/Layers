#include "Layers.h"

using Layers::Customize_Menu;
using Layers::Menu;
using Layers::Settings_Menu;
using Layers::Theme;
using Layers::Titlebar;
using Layers::Window;

Window::Window(const QString& app_name, bool is_preview_window, QWidget* parent) :
	m_app_dir{ QDir(app_path(app_name)) }, m_app_themes_dir{ QDir(app_themes_path(app_name)) }, Widget(parent)
{
    Q_INIT_RESOURCE(Layers);

	qRegisterMetaTypeStreamOperators<QGradientStops>("QGradientStops");

	if (!m_app_dir.exists())
	{
		m_app_dir.mkdir(m_app_dir.absolutePath());
		m_app_themes_dir.mkdir(m_app_themes_dir.absolutePath());

		QDir deprecated_layers_dir(deprecated_layers_path());

		// If the deprecated Layers path exists, move the theme files into the new themes directory and delete the deprecated directory
		if (deprecated_layers_dir.exists())
		{
			QDir deprecated_themes_dir(deprecated_layers_themes_path());

			for (const QString& file_name : deprecated_themes_dir.entryList(QDir::Files))
				QDir().rename(deprecated_themes_dir.absoluteFilePath(file_name), m_app_themes_dir.absoluteFilePath(file_name));

			deprecated_layers_dir.removeRecursively();
		}
	}

    connect(m_titlebar->window_icon(), &Button::clicked, [this] { open_menu(m_app_menu); });
    connect(m_titlebar->settings_button(), &Button::clicked, this, &Window::settings_clicked);
    connect(m_titlebar->minimize_button(), &Button::clicked, this, &Window::minimize_clicked);
    connect(m_titlebar->maximize_button(), &Button::clicked, this, &Window::maximize_clicked);
    connect(m_titlebar->exit_button(), &Button::clicked, this, &Window::exit_clicked);
    connect(m_settings_menu->themes_settings_panel()->theme_combobox(), &Combobox::current_item_changed, [this] { apply_theme(m_themes[m_settings_menu->themes_settings_panel()->theme_combobox()->current_item()]); });
    connect(m_settings_menu->themes_settings_panel()->theme_combobox(), SIGNAL(item_replaced(const QString&, const QString&)), this, SLOT(change_current_theme_name(const QString&, const QString&)));
    connect(m_settings_menu->themes_settings_panel()->customize_theme_button(), &Button::clicked, this, &Window::customize_clicked);
	connect(m_settings_menu->themes_settings_panel()->new_theme_button(), &Button::clicked, this, &Window::new_theme_clicked);

	init_child_themeable_reference_list();

    set_name("window");
    set_proper_name("Window");
    set_attribute_value("border_thickness", 15);
    set_attribute_value("border_gradient_disabled", false);
    set_attribute_value("corner_radius_tl", 10);
    set_attribute_value("corner_radius_tr", 10);
    set_attribute_value("corner_radius_bl", 10);
    set_attribute_value("corner_radius_br", 10);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
    setMinimumSize(200, m_titlebar->height() + attributes()["border_thickness"].value().value<int>() * 2);
	resize(1000, 700);

    m_app_menu->set_attribute_value("background_disabled", true);

    m_settings_menu->set_attribute_value("background_color", QColor("#ff5555"));
    m_settings_menu->set_attribute_value("background_disabled", true);
    m_settings_menu->hide();

    m_customize_menu->set_attribute_value("background_disabled", true);
    m_customize_menu->hide();

	connect(m_customize_menu->apply_button(), &Button::clicked, this, &Window::apply_theme_changes);

    add_menu(m_app_menu);
    add_menu(m_settings_menu);
    add_menu(m_customize_menu);

    m_menu_stack.append(m_app_menu);

    setup_layout();

	if (!is_preview_window)
	{
		for (const QString& file_path : m_app_themes_dir.entryList(QDir::Files))
		{
			Theme loaded_theme = load_theme(file_path);

			add_theme(loaded_theme.name, loaded_theme);
		}

		if (m_themes.isEmpty())
		{
			add_theme("Blue", build_blue_theme());
			add_theme("Dark", build_dark_theme());
			add_theme("Light", build_light_theme());

			save_theme(m_themes["Blue"]);
			save_theme(m_themes["Dark"]);
			save_theme(m_themes["Light"]);
		}
	}

	// Do this last:
	assign_tag_prefixes();
}

void Window::add_menu(Menu* menu)
{
    m_menus.append(menu);
}

void Window::add_theme(const QString& name, const Theme& theme)
{
    m_themes.insert(name, theme);

    m_settings_menu->themes_settings_panel()->theme_combobox()->add_item(name);

	m_create_new_theme_dialog->add_theme_name_to_combobox(name);
}

void Window::apply_theme(Theme& theme)
{
    Themeable::apply_theme(theme);

	if (theme.built_in)
		m_settings_menu->themes_settings_panel()->show_custom_theme_buttons(false);
	else
		m_settings_menu->themes_settings_panel()->show_custom_theme_buttons();

    if (m_customize_menu->preview_window())
    {
        m_customize_menu->preview_window()->apply_theme(theme);
        m_customize_menu->preview_window()->settings_menu()->themes_settings_panel()->theme_combobox()->set_current_item(theme.name);
    }

	issue_update();
}

void Window::assign_tag_prefixes()
{
    for (Themeable* themeable_child_element : m_child_themeable_references)
    {
        themeable_child_element->assign_tag_prefixes(m_tag_prefixes, "");
    }

    m_tag_prefixes_assigned = true;
}

void Window::center_dialog(QDialog* dialog)
{
    dialog->move(x() + (width() / 2) - (dialog->width() / 2), y() + (height() / 2) - (dialog->height() / 2));
}

Customize_Menu* Window::customize_menu() const
{
    return m_customize_menu;
}

void Window::finalize()
{
    m_customize_menu->init_preview_window();

	m_customize_menu->preview_window()->customize_menu()->apply_button()->set_disabled();

	for (Theme& theme : m_themes)
		m_customize_menu->preview_window()->add_theme(theme.name, theme);

	//apply_theme(m_themes["Dark"]); // Sets initial theme
    m_settings_menu->themes_settings_panel()->theme_combobox()->set_current_item("Light"); // Also sets initial theme
}

void Window::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_titlebar);
	add_child_themeable_reference(m_settings_menu);
	add_child_themeable_reference(m_customize_menu);
    add_child_themeable_reference(m_create_new_theme_dialog);
}

void Window::update_theme_dependencies()
{
    if (m_maximized)
		m_main_layout->setMargin(0);
    else
		m_main_layout->setMargin(attributes()["border_thickness"].value().value<int>());
}

void Window::set_window_title(const QString& title)
{
	m_titlebar->set_window_title(title);

	if (m_customize_menu->preview_window())
		m_customize_menu->preview_window()->set_window_title(title);
}

Settings_Menu* Window::settings_menu() const
{
    return m_settings_menu;
}

Titlebar* Window::titlebar() const
{
    return m_titlebar;
}

void Window::apply_theme_changes()
{
	m_customize_menu->preview_window()->replace_all_attributes_in_theme(m_current_theme);

	apply_theme(*m_current_theme);

	save_theme(*m_current_theme);

	update();
}

void Window::change_current_theme_name(const QString& old_name, const QString& new_name)
{
    m_themes.insert(new_name, m_themes.take(old_name));

	m_themes[new_name].name = new_name;

    apply_theme(m_themes[new_name]);

	QFile old_theme_file(m_app_themes_dir.absoluteFilePath(old_name.toLower()));

	old_theme_file.remove();

	save_theme(m_themes[new_name]);
}

void Window::create_theme(const QString& new_theme_name, const QString& copy_theme_name)
{
	add_theme(new_theme_name, Theme(m_themes[copy_theme_name]));

	m_themes[new_theme_name].name = new_theme_name;
	m_themes[new_theme_name].built_in = false;

	m_settings_menu->themes_settings_panel()->theme_combobox()->set_current_item(new_theme_name);

	save_theme(m_themes[new_theme_name]);
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
        Menu_Label_Layer* mll = new Menu_Label_Layer(menu);

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
	m_create_new_theme_dialog->set_current_start_theme_name(m_current_theme->name);

	static_cast<Window*>(QApplication::activeWindow())->center_dialog(m_create_new_theme_dialog);

	m_create_new_theme_dialog->show();

	if (m_create_new_theme_dialog->exec())
	{
		create_theme(m_create_new_theme_dialog->new_theme_name(), m_create_new_theme_dialog->copy_theme_name());

		m_create_new_theme_dialog->clear();
	}
}

void Window::settings_clicked()
{
    open_menu(m_settings_menu);
}

void Window::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
}

Theme Window::load_theme(const QString& file_path)
{
	QFile theme_file(m_app_themes_dir.absoluteFilePath(file_path));

	qDebug() << "Loading" << theme_file.fileName();

	Theme loaded_theme = load_theme_2_1_0_a(theme_file);

	if (loaded_theme.m_data.count() == 0)
	{
		qDebug() << "Theme load failed. Trying 2.0.0a load..";

		Theme_2_0_0_a loaded_theme_2_0_0_a = load_theme_2_0_0_a(theme_file);

		if (loaded_theme_2_0_0_a.m_data.count() == 0)
		{
			qDebug() << "Theme load failed. The data must be corrupt.";
		}
		else
		{
			qDebug() << "Successfully loaded theme with 2.0.0a compatibility.";
			
			loaded_theme = update_theme_2_0_0_a_to_2_1_0_a(loaded_theme_2_0_0_a);

			qDebug() << "Updated theme from 2.0.0a to 2.1.0a.";

			save_theme(loaded_theme);
		}
	}

	return loaded_theme;
}

bool Window::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_NCHITTEST)
    {
        if (isMaximized())
        {
            return false;
        }

        *result = 0;
        const LONG borderWidth = attributes()["border_thickness"].value().value<int>() * devicePixelRatio();;
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

		bool background_disabled = m_attributes["background_disabled"].value().value<bool>();

		int border_thickness = m_attributes["border_thickness"].value().value<int>();

		int margin_left = m_attributes["margin_left"].value().value<int>();
		int margin_top = m_attributes["margin_top"].value().value<int>();
		int margin_right = m_attributes["margin_right"].value().value<int>();
		int margin_bottom = m_attributes["margin_bottom"].value().value<int>();

		int draw_width = width() - margin_left - margin_right;
		int draw_height = height() - margin_top - margin_bottom;

		int corner_radius_tl = m_attributes["corner_radius_tl"].value().value<int>();
		int corner_radius_tr = m_attributes["corner_radius_tr"].value().value<int>();
		int corner_radius_bl = m_attributes["corner_radius_bl"].value().value<int>();
		int corner_radius_br = m_attributes["corner_radius_br"].value().value<int>();

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

		painter.begin(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// - Draw Corner Color
		if (!m_attributes["corner_color_disabled"].value().value<bool>())
		{
			painter.fillPath(corner_color_path, m_attributes["corner_color"].value().value<QColor>());
		}

		// - Draw Border
		if (border_thickness)
		{
			if (!m_attributes["border_gradient_disabled"].value().value<bool>())
			{
				QLinearGradient gradient;

				gradient.setStart(0, 0);
				gradient.setFinalStop(width(), 0);
				gradient.setStops(m_attributes["border_gradient_stops"].value().value<QGradientStops>());

				painter.fillPath(border_path, gradient);
			}
			else painter.fillPath(border_path, m_attributes["border_color"].value().value<QColor>());
		}

		// - Draw Background
		if (!background_disabled)
		{
			if (m_attributes["background_gradient_disabled"].value().value<bool>())
			{
				if (!m_attributes["background_color_hover_disabled"].value().value<bool>() && m_attributes["using_background_color_hover"].value().value<bool>())
					painter.fillPath(background_path, m_attributes["background_color_hover"].value().value<QColor>());
				else
					painter.fillPath(background_path, m_attributes["background_color"].value().value<QColor>());
			}
			else
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(m_attributes["background_gradient_stops"].value().value<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
		}

		// - Draw Outline Color
		if (!m_attributes["outline_color_disabled"].value().value<bool>())
		{
			painter.strokePath(outline_color_path, QPen(m_attributes["outline_color"].value().value<QColor>()));
		}

		painter.end();
	}
	else
	{
		// CREATE VARIABLES:

		bool background_disabled = m_attributes["background_disabled"].value().value<bool>();

		int margin_left = m_attributes["margin_left"].value().value<int>();
		int margin_top = m_attributes["margin_top"].value().value<int>();
		int margin_right = m_attributes["margin_right"].value().value<int>();
		int margin_bottom = m_attributes["margin_bottom"].value().value<int>();

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

		painter.begin(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// - Draw Background
		if (!background_disabled)
		{
			if (m_attributes["background_gradient_disabled"].value().value<bool>())
			{
				if (!m_attributes["background_color_hover_disabled"].value().value<bool>() && m_attributes["using_background_color_hover"].value().value<bool>())
					painter.fillPath(background_path, m_attributes["background_color_hover"].value().value<QColor>());
				else
					painter.fillPath(background_path, m_attributes["background_color"].value().value<QColor>());
			}
			else
			{
				QLinearGradient bg_gradient;

				bg_gradient.setStart(0, 0);
				bg_gradient.setFinalStop(width(), 0);
				bg_gradient.setStops(m_attributes["background_gradient_stops"].value().value<QGradientStops>());

				painter.fillPath(background_path, bg_gradient);
			}
		}

		// - Draw Outline Color
		if (!m_attributes["outline_color_disabled"].value().value<bool>())
		{
			painter.strokePath(outline_color_path, QPen(m_attributes["outline_color"].value().value<QColor>()));
		}

		painter.end();
	}
}

void Window::save_theme(const Theme& theme)
{
	QFile theme_file(m_app_themes_dir.absoluteFilePath(theme.name.toLower()));

	if (!theme_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create theme file";
		return;
	}

	QDataStream out(&theme_file);
	out.setVersion(QDataStream::Qt_5_13);

	out << theme;

	theme_file.close();
}

void Window::setup_layout()
{
    m_main_layout->setMargin(attributes()["border_thickness"].value().value<int>());
    m_main_layout->setSpacing(0);
    m_main_layout->addWidget(m_titlebar);
    m_main_layout->addWidget(m_app_menu);
    m_main_layout->addWidget(m_settings_menu);
    m_main_layout->addWidget(m_customize_menu);

    setLayout(m_main_layout);
}
