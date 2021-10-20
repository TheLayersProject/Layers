#include "../../../include/AttributeSharingCombo.h"
#include "../../../include/AttributeWidgets.h"

#include <QIntValidator>

using Layers::CornerRadiiAttributeWidget;
using Layers::Theme;

CornerRadiiAttributeWidget::CornerRadiiAttributeWidget(Themeable* themeable, bool is_primary, QWidget* parent) :
	m_attribute_widget{ new AttributeWidget(is_primary) }, AttributeWidgetContainer("Corner Radii", is_primary, parent)
{
	init_child_themeable_reference_list();

	store_attribute_pointer(themeable->attribute_set().attribute("corner_radius_tl"));

	if (m_stateful_attribute) set_customize_states(themeable->states());
	add_attribute_widget(m_attribute_widget);
	//set_name("corner_radii_attribute_widget");

	m_attribute_widget->setFixedSize(260, 177);
	m_attribute_widget->set_stateless_attribute_value("background_disabled", true);
	//m_attribute_widget->set_name("main_widget");

	m_tl_line_editor->set_default_value("0");
	m_tl_line_editor->set_font_size(13);
	m_tl_line_editor->set_name("line_editor");
	m_tl_line_editor->set_text("0");
	m_tl_line_editor->set_validator(new QIntValidator(0, 30));

	m_tr_line_editor->set_default_value("0");
	m_tr_line_editor->set_font_size(13);
	m_tr_line_editor->set_name("line_editor");
	m_tr_line_editor->set_text("0");
	m_tr_line_editor->set_validator(new QIntValidator(0, 30));

	m_bl_line_editor->set_default_value("0");
	m_bl_line_editor->set_font_size(13);
	m_bl_line_editor->set_name("line_editor");
	m_bl_line_editor->set_text("0");
	m_bl_line_editor->set_validator(new QIntValidator(0, 30));

	m_br_line_editor->set_default_value("0");
	m_br_line_editor->set_font_size(13);
	m_br_line_editor->set_name("line_editor");
	m_br_line_editor->set_text("0");
	m_br_line_editor->set_validator(new QIntValidator(0, 30));

	m_tl_slider->set_name("mini_slider");
	
	m_tr_slider->set_name("mini_slider");
	
	m_bl_slider->set_name("mini_slider");
	
	m_br_slider->set_name("mini_slider");

	m_example_widget->setFixedSize(50, 50);
	m_example_widget->set_name("example_widget");

	// Share with themeable

	if (m_stateful_attribute)
	{
		StatefulAttribute* corner_radius_tl_atribute = themeable->attribute_set().stateful_attribute("corner_radius_tl");
		StatefulAttribute* corner_radius_tr_atribute = themeable->attribute_set().stateful_attribute("corner_radius_tr");
		StatefulAttribute* corner_radius_bl_atribute = themeable->attribute_set().stateful_attribute("corner_radius_bl");
		StatefulAttribute* corner_radius_br_atribute = themeable->attribute_set().stateful_attribute("corner_radius_br");

		m_tl_line_editor_asc = m_tl_line_editor->share_attribute_with_themeable(
			m_tl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tl_atribute, corner_radius_tl_atribute->state(),
			true);

		m_tr_line_editor_asc = m_tr_line_editor->share_attribute_with_themeable(
			m_tr_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tr_atribute, corner_radius_tr_atribute->state(),
			true);

		m_bl_line_editor_asc = m_bl_line_editor->share_attribute_with_themeable(
			m_bl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_bl_atribute, corner_radius_bl_atribute->state(),
			true);

		m_br_line_editor_asc = m_br_line_editor->share_attribute_with_themeable(
			m_br_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_br_atribute, corner_radius_br_atribute->state(),
			true);
	}
	else
	{
		m_tl_line_editor_asc = m_tl_line_editor->share_attribute_with_themeable(
			m_tl_line_editor->attribute_set().stateless_attribute("text"),
			themeable->attribute_set().stateless_attribute("corner_radius_tl"),
			true);

		m_tr_line_editor_asc = m_tr_line_editor->share_attribute_with_themeable(
			m_tr_line_editor->attribute_set().stateless_attribute("text"),
			themeable->attribute_set().stateless_attribute("corner_radius_tr"),
			true);

		m_bl_line_editor_asc = m_bl_line_editor->share_attribute_with_themeable(
			m_bl_line_editor->attribute_set().stateless_attribute("text"),
			themeable->attribute_set().stateless_attribute("corner_radius_bl"),
			true);

		m_br_line_editor_asc = m_br_line_editor->share_attribute_with_themeable(
			m_br_line_editor->attribute_set().stateless_attribute("text"),
			themeable->attribute_set().stateless_attribute("corner_radius_br"),
			true);
	}

	// Setup sharing relations between line editors and sliders

	m_tl_line_editor->share_attribute_with_themeable(
		m_tl_line_editor->attribute_set().stateless_attribute("text"),
		m_tl_slider->attribute_set().stateless_attribute("value"));

	m_tl_slider->share_attribute_with_themeable(
		m_tl_slider->attribute_set().stateless_attribute("value"),
		m_tl_line_editor->attribute_set().stateless_attribute("text"));

	m_tr_line_editor->share_attribute_with_themeable(
		m_tr_line_editor->attribute_set().stateless_attribute("text"),
		m_tr_slider->attribute_set().stateless_attribute("value"));

	m_tr_slider->share_attribute_with_themeable(
		m_tr_slider->attribute_set().stateless_attribute("value"),
		m_tr_line_editor->attribute_set().stateless_attribute("text"));

	m_bl_line_editor->share_attribute_with_themeable(
		m_bl_line_editor->attribute_set().stateless_attribute("text"),
		m_bl_slider->attribute_set().stateless_attribute("value"));

	m_bl_slider->share_attribute_with_themeable(
		m_bl_slider->attribute_set().stateless_attribute("value"),
		m_bl_line_editor->attribute_set().stateless_attribute("text"));

	m_br_line_editor->share_attribute_with_themeable(
		m_br_line_editor->attribute_set().stateless_attribute("text"),
		m_br_slider->attribute_set().stateless_attribute("value"));

	m_br_slider->share_attribute_with_themeable(
		m_br_slider->attribute_set().stateless_attribute("value"),
		m_br_line_editor->attribute_set().stateless_attribute("text"));

	// Share with example widget

	m_tl_line_editor->share_attribute_with_themeable(
		m_tl_line_editor->attribute_set().stateless_attribute("text"),
		m_example_widget->attribute_set().stateless_attribute("corner_radius_tl"));

	m_tr_line_editor->share_attribute_with_themeable(
		m_tr_line_editor->attribute_set().stateless_attribute("text"),
		m_example_widget->attribute_set().stateless_attribute("corner_radius_tr"));

	m_bl_line_editor->share_attribute_with_themeable(
		m_bl_line_editor->attribute_set().stateless_attribute("text"),
		m_example_widget->attribute_set().stateless_attribute("corner_radius_bl"));

	m_br_line_editor->share_attribute_with_themeable(
		m_br_line_editor->attribute_set().stateless_attribute("text"),
		m_example_widget->attribute_set().stateless_attribute("corner_radius_br"));
	

	setup_layout();
}

void CornerRadiiAttributeWidget::apply_theme(Theme& theme)
{
	if (m_tl_line_editor_asc) m_tl_line_editor_asc->obtain_attribute();
	if (m_tr_line_editor_asc) m_tr_line_editor_asc->obtain_attribute();
	if (m_bl_line_editor_asc) m_bl_line_editor_asc->obtain_attribute();
	if (m_br_line_editor_asc) m_br_line_editor_asc->obtain_attribute();

	Themeable::apply_theme(theme);
}

void CornerRadiiAttributeWidget::update_customizing_state(const QString& customizing_state)
{
	if (m_customize_states.contains(customizing_state))
	{
		StatefulAttribute* corner_radius_tl_atribute = m_tl_line_editor_asc->to_stateful_attribute();
		StatefulAttribute* corner_radius_tr_atribute = m_tr_line_editor_asc->to_stateful_attribute();
		StatefulAttribute* corner_radius_bl_atribute = m_bl_line_editor_asc->to_stateful_attribute();
		StatefulAttribute* corner_radius_br_atribute = m_br_line_editor_asc->to_stateful_attribute();

		m_tl_line_editor->unshare_attribute_with_themeable(
			m_tl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tl_atribute, m_tl_line_editor_asc->to_state());

		m_tr_line_editor->unshare_attribute_with_themeable(
			m_tr_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tr_atribute, m_tr_line_editor_asc->to_state());

		m_bl_line_editor->unshare_attribute_with_themeable(
			m_bl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_bl_atribute, m_bl_line_editor_asc->to_state());

		m_br_line_editor->unshare_attribute_with_themeable(
			m_br_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_br_atribute, m_br_line_editor_asc->to_state());

		m_tl_line_editor_asc = m_tl_line_editor->share_attribute_with_themeable(
			m_tl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tl_atribute, customizing_state,
			true);

		m_tr_line_editor_asc = m_tr_line_editor->share_attribute_with_themeable(
			m_tr_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_tr_atribute, customizing_state,
			true);

		m_bl_line_editor_asc = m_bl_line_editor->share_attribute_with_themeable(
			m_bl_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_bl_atribute, customizing_state,
			true);

		m_br_line_editor_asc = m_br_line_editor->share_attribute_with_themeable(
			m_br_line_editor->attribute_set().stateless_attribute("text"),
			corner_radius_br_atribute, customizing_state,
			true);

		m_tl_line_editor->share_attributes();
		m_tr_line_editor->share_attributes();
		m_bl_line_editor->share_attributes();
		m_br_line_editor->share_attributes();
	}
}

void CornerRadiiAttributeWidget::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_widget);
	add_child_themeable_reference(m_tl_line_editor);
	add_child_themeable_reference(m_tr_line_editor);
	add_child_themeable_reference(m_bl_line_editor);
	add_child_themeable_reference(m_br_line_editor);
	add_child_themeable_reference(m_tl_slider);
	add_child_themeable_reference(m_tr_slider);
	add_child_themeable_reference(m_bl_slider);
	add_child_themeable_reference(m_br_slider);
	add_child_themeable_reference(m_example_widget);
}

void CornerRadiiAttributeWidget::setup_layout()
{
	QHBoxLayout* top_controls_hbox = new QHBoxLayout;
	QHBoxLayout* bottom_controls_hbox = new QHBoxLayout;

	top_controls_hbox->setContentsMargins(0, 0, 0, 0);
	top_controls_hbox->addWidget(m_tl_line_editor);
	top_controls_hbox->addWidget(m_tl_slider);
	top_controls_hbox->addStretch();
	top_controls_hbox->addWidget(m_tr_slider);
	top_controls_hbox->addWidget(m_tr_line_editor);

	bottom_controls_hbox->setContentsMargins(0, 0, 0, 0);
	bottom_controls_hbox->addWidget(m_bl_line_editor);
	bottom_controls_hbox->addWidget(m_bl_slider);
	bottom_controls_hbox->addStretch();
	bottom_controls_hbox->addWidget(m_br_slider);
	bottom_controls_hbox->addWidget(m_br_line_editor);

	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->addLayout(top_controls_hbox);
	m_main_layout->addWidget(m_example_widget);
	m_main_layout->addLayout(bottom_controls_hbox);
	m_main_layout->setAlignment(m_example_widget, Qt::AlignHCenter);

	m_attribute_widget->setLayout(m_main_layout);
}
