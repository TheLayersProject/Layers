#include <Layers/lfilleditor.h>

using Layers::LAttribute;
using Layers::LFillEditor;
using Layers::LFillControl;
using Layers::LTheme;

LFillEditor::LFillEditor(LAttribute* attribute, QWidget* parent) :
	LAttributeEditor(attribute, parent)
{
	set_name("Fill Editor");

	// Setup Attribute Label
	m_attribute_label->set_name("Label");
	m_attribute_label->set_font_size(14);

	if (attribute)
	{
		m_attribute_label->setText(attribute->name());
		m_fill_control->set_attribute(attribute);
	}

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_attribute_label);
	hbox->addWidget(m_fill_control);
	hbox->addStretch();
	setLayout(hbox);
}

LFillControl* LFillEditor::fill_control() const
{
	return m_fill_control;
}
