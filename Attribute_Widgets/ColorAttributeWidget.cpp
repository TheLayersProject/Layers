#include "../Layers.h"

using Layers::Attribute;
using Layers::ColorAttributeWidget;
using Layers::Theme;

ColorAttributeWidget::ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, AttributeWidget(is_primary, parent)
{
	init_child_themeable_reference_list();

	store_attribute_pointer(attribute);

	if (m_stateful_attribute)
		set_customize_states(m_stateful_attribute->states());

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_stateless_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_stateless_attribute_value("background_disabled", true);

	// Setup Color Control
	if (m_stateful_attribute) // This shares to the attribute's current state; Not sure yet how this should behave with stateful attributes
		m_color_control_asc = m_color_control->share_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"),
			m_stateful_attribute, m_stateful_attribute->state(),
			true);
	else
		m_color_control_asc = m_color_control->share_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"),
			m_stateless_attribute,
			true);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(6);
	hbox->addWidget(m_color_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

ColorAttributeWidget::ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, Attribute* disabling_attribute, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, m_disabling_attribute{ disabling_attribute },
	m_disabled_attribute_toggle{ new ToggleSwitch }, AttributeWidget(is_primary, parent)
{
	init_child_themeable_reference_list();

	store_attribute_pointer(attribute);

	if (m_stateful_attribute)
		set_customize_states(m_stateful_attribute->states());

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_stateless_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_stateless_attribute_value("background_disabled", true);

	// Setup Disabling Attribute Toggle
	m_disabled_attribute_toggle->set_name("toggle");

	StatefulAttribute* stateful_disabling_attribute = dynamic_cast<StatefulAttribute*>(disabling_attribute);
	StatelessAttribute* stateless_disabling_attribute = dynamic_cast<StatelessAttribute*>(disabling_attribute);

	connect(m_disabled_attribute_toggle, &ToggleSwitch::toggled_event, [this, stateful_disabling_attribute, stateless_disabling_attribute] {
		if (m_disabled_attribute_toggle->toggled())
		{
			m_color_control->show();

			if (stateful_disabling_attribute)
				stateful_disabling_attribute->set_value(stateful_disabling_attribute->state(), false);
			else
				stateless_disabling_attribute->set_value(false);

			m_disabling_attribute->parent_themeable()->share_attributes();
			m_disabling_attribute->parent_themeable()->issue_update();
		}
		else
		{
			m_color_control->hide();

			if (stateful_disabling_attribute)
				stateful_disabling_attribute->set_value(stateful_disabling_attribute->state(), true);
			else
				stateless_disabling_attribute->set_value(true);

			m_disabling_attribute->parent_themeable()->share_attributes();
			m_disabling_attribute->parent_themeable()->issue_update();
		}
	});

	if (!m_disabling_attribute->value().value<bool>())
	{
		m_disabled_attribute_toggle->toggle();
	}
	else m_color_control->hide();

	// Setup Color Control
	if (m_stateful_attribute) // This shares to the attribute's current state; Not sure yet how this should behave with stateful attributes
		m_color_control_asc = m_color_control->share_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"), 
			m_stateful_attribute, m_stateful_attribute->state(),
			true);
	else
		m_color_control_asc = m_color_control->share_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"), 
			m_stateless_attribute,
			true);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(14);
	hbox->addWidget(m_disabled_attribute_toggle);
	hbox->addSpacing(6);
	hbox->addWidget(m_color_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

void ColorAttributeWidget::apply_theme(Theme& theme)
{
	if (m_color_control_asc) m_color_control_asc->obtain_attribute();

	if (m_disabling_attribute)
	{
		if (m_disabling_attribute->value().value<bool>() && m_disabled_attribute_toggle->toggled())
			m_disabled_attribute_toggle->toggle();
		else if (!m_disabling_attribute->value().value<bool>() && !m_disabled_attribute_toggle->toggled())
			m_disabled_attribute_toggle->toggle();
	}

	Themeable::apply_theme(theme);
}

void ColorAttributeWidget::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}

void ColorAttributeWidget::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_label);
	if (m_disabled_attribute_toggle) add_child_themeable_reference(m_disabled_attribute_toggle);
}

void ColorAttributeWidget::update_customizing_state(const QString& customizing_state)
{
	if (m_customize_states.contains(customizing_state))
	{
		m_color_control->unshare_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"),
			m_stateful_attribute, m_color_control_asc->to_state());
		
		m_color_control_asc = m_color_control->share_attribute_with_themeable(
			m_color_control->attribute_set().stateless_attribute("background_color"),
			m_stateful_attribute, customizing_state,
			true);
	}
}
