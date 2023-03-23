#include "AttributeEditor.h"

using Layers::AttributeEditor;
using Layers::ToggleSwitch;
using Layers::Widget;

AttributeEditor::AttributeEditor(Entity* entity, QWidget* parent) :
	m_entity{ entity }, Widget(parent)
{
	init_attributes();

	set_name("attribute_widget");

	// Setup Disabling Attribute Toggle
	m_disabled_toggle->set_proper_name("Disable Toggle");

	m_toggle_label_separator->fill()->set_disabled();
	m_toggle_label_separator->setFixedSize(16, 1);
}

AttributeEditor::~AttributeEditor()
{
	if (!m_disabled_toggle->parentWidget())
	{
		delete m_disabled_toggle;
		m_disabled_toggle = nullptr;
	}

	if (!m_toggle_label_separator->parentWidget())
	{
		delete m_toggle_label_separator;
		m_toggle_label_separator = nullptr;
	}
}

ToggleSwitch* AttributeEditor::disable_toggle() const
{
	return m_disabled_toggle;
}

bool AttributeEditor::disabled() const
{
	if (m_entity)
		return m_entity->disabled();

	return false;
}

Widget* AttributeEditor::toggle_label_separator() const
{
	return m_toggle_label_separator;
}

void AttributeEditor::set_current_editting_state(const QString& state)
{
}

void AttributeEditor::init_attributes()
{
	m_fill->set_value(QColor("#1A000000")); // Black with 10% opacity
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);
}
