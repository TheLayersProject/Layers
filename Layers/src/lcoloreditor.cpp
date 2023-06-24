#include <Layers/lcoloreditor.h>

using Layers::LAttribute;
using Layers::LColorEditor;
using Layers::LColorControl;
using Layers::LTheme;

LColorEditor::LColorEditor(LAttribute* attribute, QWidget* parent) :
	LAttributeEditor(attribute, parent)
{
	// Setup Attribute Label
	m_attribute_label->set_name("Label");
	m_attribute_label->set_font_size(14);
	if (attribute)
		m_attribute_label->setText(attribute->name());

	if (attribute)
		m_color_control->fill()->establish_link(*attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_attribute_label);
	hbox->addWidget(m_color_control);
	hbox->addStretch();
	setLayout(hbox);
}

LColorControl* LColorEditor::color_control() const
{
	return m_color_control;
}
