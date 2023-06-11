#include <LayersWidgets/lattributeeditor.h>

using Layers::LAttributeEditor;
using Layers::LToggleSwitch;
using Layers::LWidget;

LAttributeEditor::LAttributeEditor(LAbstractAttribute* entity, QWidget* parent) :
	m_entity{ entity }, LWidget(parent)
{
	init_attributes();

	// Setup Disabling Attribute Toggle
	m_disabled_toggle->set_name("Disable Toggle");

	m_toggle_label_separator->fill()->set_disabled();
	m_toggle_label_separator->setFixedSize(16, 1);
}

LAttributeEditor::~LAttributeEditor()
{
	/*
		TODO: Should probably just not initialize the disable toggle if it is
		not used.
	*/
	if (!m_disabled_toggle->parentWidget())
		delete m_disabled_toggle;

	if (!m_toggle_label_separator->parentWidget())
		delete m_toggle_label_separator;
}

LToggleSwitch* LAttributeEditor::disable_toggle() const
{
	return m_disabled_toggle;
}

bool LAttributeEditor::disabled() const
{
	if (m_entity)
		return m_entity->disabled();

	return false;
}

LWidget* LAttributeEditor::toggle_label_separator() const
{
	return m_toggle_label_separator;
}

void LAttributeEditor::set_current_editing_state(const QString& state)
{
}

void LAttributeEditor::init_attributes()
{
	m_fill->set_value(QColor("#1A000000")); // Black with 10% opacity
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);
}