#include <LayersWidgets/lgradienteditor.h>

using Layers::LAttribute;
using Layers::LGradientEditor;
using Layers::LTheme;

LGradientEditor::LGradientEditor(const QString& attribute_label_text, LAttribute* attribute, QWidget* parent) :
	m_attribute_label{ new LLabel(attribute_label_text) }, LAttributeEditor(attribute, parent)
{
	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);

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
