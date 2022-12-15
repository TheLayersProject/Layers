#include "../../../include/AttributeWidgets.h"

using Layers::AttributeWidget;
using Layers::ToggleSwitch;
using Layers::Widget;

AttributeWidget::AttributeWidget(AttributeType* attr_type, QWidget* parent) :
	m_attribute_type{ attr_type }, Widget(parent)
{
	init_attributes();

	set_name("attribute_widget");

	// Setup Disabling Attribute Toggle
	m_disabled_toggle->set_proper_name("Disable Toggle");

	m_toggle_label_separator->a_fill.set_disabled();
	m_toggle_label_separator->setFixedSize(16, 1);
}

ToggleSwitch* AttributeWidget::disable_toggle() const
{
	return m_disabled_toggle;
}

bool AttributeWidget::disabled() const
{
	if (m_attribute_type)
		return m_attribute_type->disabled();

	return false;
}

Widget* AttributeWidget::toggle_label_separator() const
{
	return m_toggle_label_separator;
}

void AttributeWidget::set_current_editting_state(const QString& state)
{
}

void AttributeWidget::init_attributes()
{
	a_fill.set_value(QColor("#1A000000")); // Black with 10% opacity
	corner_radii.top_left.set_value(10.0);
	corner_radii.top_right.set_value(10.0);
	corner_radii.bottom_left.set_value(10.0);
	corner_radii.bottom_right.set_value(10.0);
}
