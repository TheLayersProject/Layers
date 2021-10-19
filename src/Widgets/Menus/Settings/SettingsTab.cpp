#include "../../../Layers.h"

using Layers::Graphic;
using Layers::SettingsTab;

SettingsTab::SettingsTab(Graphic* icon, const QString& label_text, QWidget* parent) :
	m_tab_icon{ icon }, m_text_label { new Label(label_text) }, Widget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	connect(this, &SettingsTab::clicked, [this] { if (state() != "Selected") set_state("Selected"); });

    installEventFilter(this);
    setMouseTracking(true);
	setFixedHeight(60);

    set_icon(new Graphic(":/svgs/settings_tab_icon.svg", QSize(20, 9)));
    set_name("settings_tab");
    set_proper_name(label_text + " Tab");

    m_tab_icon->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_tab_icon->set_icon(new Graphic(*m_tab_icon));
    m_tab_icon->set_name("icon");
	m_tab_icon->set_proper_name("Icon");

    m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_text_label->set_name("text_label");
    m_text_label->set_proper_name("Text Label");
    m_text_label->set_font_size(14);
    m_text_label->set_padding(0, 8, 0, 0);

    m_spacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_spacer->setFixedSize(12, 12);

    m_stretch_widget->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_stretch_widget->hide();

    m_stretch_widget2->setAttribute(Qt::WA_TransparentForMouseEvents);

    setup_layout();
}

void SettingsTab::expand()
{
    m_spacer->show();
    m_text_label->show();
    m_stretch_widget->hide();

    main_layout->setContentsMargins(18, 0, 0, 0);
}

void SettingsTab::shrink()
{
    m_spacer->hide();
    m_text_label->hide();
    m_stretch_widget->show();

    main_layout->setContentsMargins(0, 0, 0, 0);
}

void SettingsTab::init_attributes()
{
	set_stateless_attribute_value("corner_radius_tl", 5);
	set_stateless_attribute_value("corner_radius_bl", 5);

	m_spacer->set_stateless_attribute_value("background_disabled", true);

	m_stretch_widget->set_stateless_attribute_value("background_disabled", true);

	m_stretch_widget2->set_stateless_attribute_value("background_disabled", true);

	convert_attribute_to_stateful("background_color", {
		{ "Unselected", QColor(Qt::lightGray) },
		{ "Selected", QColor(Qt::white) }
		});

	m_tab_icon->svg()->set_stateless_attribute_value("use_common_hover_color", false);
	m_tab_icon->convert_attribute_to_stateful("common_color", {
		{ "Unselected", QColor(Qt::gray) },
		{ "Selected", QColor(Qt::black) }
		});

	m_text_label->convert_attribute_to_stateful("color", {
		{ "Unselected", QColor(Qt::gray) },
		{ "Selected", QColor(Qt::black) }
		});

	set_state("Unselected");
}

void SettingsTab::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		AttributeWidgetContainer* border_awc = new AttributeWidgetContainer("Border", false);
		ColorAttributeWidget* background_caw = new ColorAttributeWidget("Background", m_attribute_set.attribute("background_color"), m_attribute_set.attribute("background_disabled"), true);
		ColorAttributeWidget* hover_background_caw = new ColorAttributeWidget("Hover Background", m_attribute_set.attribute("background_color_hover"), m_attribute_set.attribute("background_color_hover_disabled"), false);
		ColorAttributeWidget* outline_caw = new ColorAttributeWidget("Outline", m_attribute_set.attribute("outline_color"), m_attribute_set.attribute("outline_color_disabled"), false);
		ColorAttributeWidget* corner_color_caw = new ColorAttributeWidget("Corner Color", m_attribute_set.attribute("corner_color"), m_attribute_set.attribute("corner_color_disabled"), false);
		ColorAttributeWidget* border_caw = new ColorAttributeWidget("Color", m_attribute_set.attribute("border_color"), true);
		CornerRadiiAttributeWidget* corner_radii_attribute_widget = new CornerRadiiAttributeWidget(this, true);
		GradientAttributeWidget* border_gaw = new GradientAttributeWidget("Gradient", m_attribute_set.attribute("border_gradient_stops"), true);
		NumberAttributeWidget* border_thickness_naw = new NumberAttributeWidget("Thickness", m_attribute_set.attribute("border_thickness"), new QIntValidator(0, 30), true);

		SwitchAttributeWidget* border_color_saw = new SwitchAttributeWidget(
			"Solid", border_caw,
			"Gradient", border_gaw,
			m_attribute_set.stateless_attribute("border_gradient_disabled"), true);

		border_caw->set_centered();
		border_gaw->set_centered();

		border_thickness_naw->set_centered();
		border_thickness_naw->set_unit_label_text("px");
		border_thickness_naw->enable_silder();

		border_awc->add_attribute_widget(border_color_saw);
		border_awc->add_attribute_widget(border_thickness_naw);

		m_customize_panel->add_attribute_widget(background_caw);
		m_customize_panel->add_attribute_widget(hover_background_caw);
		m_customize_panel->add_attribute_widget(outline_caw);
		m_customize_panel->add_attribute_widget(corner_color_caw);
		m_customize_panel->add_attribute_widget(border_awc);
		m_customize_panel->add_attribute_widget(corner_radii_attribute_widget);

		// Add attribute widget references

		m_attribute_widgets["border_awc"] = border_awc;
		m_attribute_widgets["background_caw"] = background_caw;
		m_attribute_widgets["hover_background_caw"] = hover_background_caw;
		m_attribute_widgets["outline_caw"] = outline_caw;
		m_attribute_widgets["corner_color_caw"] = corner_color_caw;
		m_attribute_widgets["border_caw"] = border_caw;
		m_attribute_widgets["border_gaw"] = border_gaw;
		m_attribute_widgets["border_thickness_naw"] = border_thickness_naw;
		m_attribute_widgets["corner_radii_attribute_widget"] = corner_radii_attribute_widget;
		m_attribute_widgets["border_color_saw"] = border_color_saw;

		// TODO: Consider an implicit way to get this done
		m_customize_panel->add_child_themeable_reference(border_color_saw);
		m_customize_panel->add_child_themeable_reference(border_caw);
		m_customize_panel->add_child_themeable_reference(border_gaw);
		m_customize_panel->add_child_themeable_reference(border_thickness_naw);
	}
}

void SettingsTab::init_child_themeable_reference_list()
{
    add_child_themeable_reference(m_tab_icon);
    add_child_themeable_reference(m_text_label);
}

int SettingsTab::recommended_minimum_width()
{
    return 18 + m_tab_icon->width() + 12 + m_text_label->width() + 18;
}

void SettingsTab::set_disabled(bool cond)
{
    m_disabled = cond;
}

bool SettingsTab::eventFilter(QObject* object, QEvent* event)
{
    if (!m_disabled)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

            if (mouse_event->button() & Qt::LeftButton)
            {
                emit clicked();
            }
        }
    }

    return false;
}

void SettingsTab::resizeEvent(QResizeEvent* event)
{
    int minimum_width = 18 + m_tab_icon->width() + 12 + m_text_label->width() + 18;

    if (width() < minimum_width) emit under_minimum_width();
    else emit over_minimum_width();
}

void SettingsTab::setup_layout()
{
    main_layout->setContentsMargins(18, 0, 0, 0);
    main_layout->setSpacing(0);
    main_layout->addWidget(m_stretch_widget);
    main_layout->addWidget(m_tab_icon);
    main_layout->addWidget(m_spacer);
    main_layout->addWidget(m_text_label);
    main_layout->addWidget(m_stretch_widget2);

    setLayout(main_layout);
}
