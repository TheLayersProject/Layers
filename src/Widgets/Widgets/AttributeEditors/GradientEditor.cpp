#include "GradientEditor.h"

using Layers::Attribute;
using Layers::GradientEditor;
using Layers::Theme;

GradientEditor::GradientEditor(const QString& attribute_label_text, Attribute* attribute, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, AttributeEditor(attribute, parent)
{
	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Color Control
	m_gradient_control->fill()->entangle_with(*attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(6);
	hbox->addWidget(m_gradient_control);
	hbox->addStretch();
	setLayout(hbox);
}
