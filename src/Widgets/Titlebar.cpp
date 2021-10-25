#include "../../include/AttributeWidgets.h"
#include "../../include/Titlebar.h"

using Layers::Button;
using Layers::MenuLabelLayer;
using Layers::Titlebar;

Titlebar::Titlebar(QWidget* parent) : Widget(parent)
{
	init_child_themeable_reference_list();

	setFixedHeight(45);

    set_name("titlebar");
    set_proper_name("Titlebar");
    set_icon(new Graphic(":/svgs/titlebar_icon.svg", QSize(20, 20)));
	set_stateless_attribute_value("background_disabled", true);

    filter_attribute("background_color_hover");
    filter_attribute("border_color");
    filter_attribute("border_gradient_stops");
    filter_attribute("border_thickness");
    filter_attribute("border_gradient_disabled");

    m_window_icon->set_padding(6, 0, 6, 0);

    m_window_title_label->set_name("window_title_label");
    m_window_title_label->set_padding(0, 7, 0, 0);
    m_window_title_label->set_proper_name("Window Title Label");
    m_window_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_settings_button->set_name("settings_button");
	m_settings_button->set_proper_name("Settings Button");
    m_settings_button->add_stateless_attribute("#gear", QColor(Qt::lightGray));
    m_settings_button->add_stateless_attribute("#gear_hover", QColor(Qt::darkGray));

    m_minimize_button->set_name("minimize_button");
	m_minimize_button->set_proper_name("Minimize Button");
    m_minimize_button->add_stateless_attribute("#bar", QColor(Qt::lightGray));
    m_minimize_button->add_stateless_attribute("#bar_hover", QColor(Qt::darkGray));

    m_maximize_button->set_name("maximize_button");
	m_maximize_button->set_proper_name("Maximize Button");
    m_maximize_button->add_stateless_attribute("#square_frame", QColor(Qt::lightGray));
    m_maximize_button->add_stateless_attribute("#square_frame_hover", QColor(Qt::darkGray));

    m_exit_button->set_name("exit_button");
	m_exit_button->set_proper_name("Exit Button");
    m_exit_button->add_stateless_attribute("#x", QColor(Qt::lightGray));
    m_exit_button->add_stateless_attribute("#x_hover", QColor("#E33034"));

    m_buttons_container->setFixedHeight(height());
    m_buttons_container->setFixedWidth(m_settings_button->width() + m_minimize_button->width() + m_maximize_button->width() + m_exit_button->width());
    m_buttons_container->set_stateless_attribute_value("background_disabled", true);

    m_stretch_widget->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_stretch_widget->set_stateless_attribute_value("background_disabled", true);

    m_control_mll->set_proper_name("Menu Label Layers");

    setup_layout();

    m_buttons_container->raise();
}

void Titlebar::add_mll(MenuLabelLayer* mll)
{
    if (!mll_stack.count())
    {
        m_window_title_label->hide();
        m_stretch_widget->hide();
    }
    else mll_stack.last()->shrink();

    mll_stack.append(mll);

    main_layout->addWidget(mll);

    m_buttons_container->raise();

    mll->replace_all_attributes_with(m_control_mll);

    //m_control_mll->share_all_attributes_with(mll);
    //m_control_mll->replace_all_attributes_with(mll);
}

void Titlebar::remove_mlls_past(int index)
{
    while (index + 1 <= mll_stack.count() - 1)
    {
        remove_child_themeable_reference(mll_stack.last());

        //m_control_mll->unshare_all_attributes_with(mll_stack.last());

        mll_stack.takeLast()->deleteLater();
    }

    if (index < 0)
    {
        m_window_title_label->show();
        m_stretch_widget->show();
    }
    else
    {
        mll_stack.last()->expand();
    }
}

void Titlebar::init_child_themeable_reference_list()
{
    add_child_themeable_reference(m_window_title_label);
    add_child_themeable_reference(m_control_mll);
    add_child_themeable_reference(m_settings_button);
    add_child_themeable_reference(m_minimize_button);
    add_child_themeable_reference(m_maximize_button);
    add_child_themeable_reference(m_exit_button);
}

bool Titlebar::is(QWidget* widget)
{
    if (this == widget) return true;
    else if (mll_stack.count() && mll_stack.last() == widget) return true;

    return false;
}

void Titlebar::set_window_icon(const Graphic& icon_graphic)
{
    m_window_icon->deleteLater();

    m_window_icon = new Button(new Graphic(icon_graphic));

    //m_window_icon->set_stateless_attribute_value("background_disabled", false);

    //m_window_icon->graphic()->set_stateless_attribute_value("background_disabled", false);
    //m_window_icon->graphic()->set_stateless_attribute_value("background_color", QColor(Qt::blue));

    m_window_icon->set_padding(6, 0, 6, 0);

    main_layout->insertWidget(0, m_window_icon);

    emit window_icon_updated();
}

void Titlebar::set_window_title(const QString & title)
{
	m_window_title_label->setText(title);
}

Button* Titlebar::window_icon() const
{
    return m_window_icon;
}

Button* Titlebar::settings_button() const
{
    return m_settings_button;
}

Button* Titlebar::minimize_button() const
{
    return m_minimize_button;
}

Button* Titlebar::maximize_button() const
{
    return m_maximize_button;
}

Button* Titlebar::exit_button() const
{
    return m_exit_button;
}

void Titlebar::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
}

void Titlebar::resizeEvent(QResizeEvent* event)
{
    if (m_base_mll) m_base_mll->setFixedWidth(width() - (20 + m_window_icon->width()));

    m_buttons_container->move(width() - m_buttons_container->width(), 0);
}

void Titlebar::setup_layout()
{
    // Main Layout
    main_layout->setContentsMargins(10, 0, 0, 0);
    main_layout->setSpacing(5);
    main_layout->addWidget(m_window_icon);
    main_layout->addSpacing(5);
    main_layout->addWidget(m_window_title_label);
    main_layout->addWidget(m_stretch_widget);

    setLayout(main_layout);

    // Buttons Layout
    QHBoxLayout* buttons_layout = new QHBoxLayout;

    buttons_layout->setContentsMargins(0, 0, 0, 0);
    buttons_layout->setSpacing(0);
    buttons_layout->addWidget(m_settings_button);
    buttons_layout->addWidget(m_minimize_button);
    buttons_layout->addWidget(m_maximize_button);
    buttons_layout->addWidget(m_exit_button);

    m_buttons_container->setLayout(buttons_layout);
}
