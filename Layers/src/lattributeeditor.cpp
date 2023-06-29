#include <Layers/lattributeeditor.h>

using Layers::LAttributeEditor;
using Layers::LToggleSwitch;
using Layers::LWidget;

LAttributeEditor::LAttributeEditor(LAttribute* attr, QWidget* parent) :
	m_attr{ attr }, LWidget(parent)
{
	init_attributes();
}

//LAttributeEditor::~LAttributeEditor()
//{
//}

void LAttributeEditor::init_attributes()
{
	m_fill->set_value(QColor("#1A000000")); // Black with 10% opacity
	m_corner_radii_top_left->set_value(10.0);
	m_corner_radii_top_right->set_value(10.0);
	m_corner_radii_bottom_left->set_value(10.0);
	m_corner_radii_bottom_right->set_value(10.0);
}
