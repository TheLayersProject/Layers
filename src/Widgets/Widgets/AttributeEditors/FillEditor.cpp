#include "FillEditor.h"

using Layers::Attribute;
using Layers::FillEditor;
using Layers::FillControl;
using Layers::Theme;

FillEditor::FillEditor(Attribute* attribute, QWidget* parent) :
	AttributeEditor(attribute, parent)
{
	set_name("Fill Editor");

	// Setup Attribute Label
	m_attribute_label->set_name("Label");
	m_attribute_label->set_font_size(14);
	if (attribute)
		m_attribute_label->setText(attribute->capitalized_name());

	connect(m_disabled_toggle, &ToggleSwitch::toggled_event, [this] {
		 if (m_disabled_toggle->toggled())
		 {
		 	m_fill_control->show();

		 	m_entity->set_disabled(false);
		 }
		 else
		 {
		 	m_fill_control->hide();

		 	m_entity->set_disabled();

			emit widget_disabled();
		 }
	});

	if (attribute)
	{
		if (!attribute->disabled())
			m_disabled_toggle->toggle(false);
		else
			/* TODO: Emit a signal when an attribute widget is disabled so that children,
			   like this, can handle hiding their controls */
			m_fill_control->hide();

		// Setup Control
		m_fill_control->set_attribute(attribute);
	}

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	//hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_disabled_toggle);
	hbox->addWidget(m_toggle_label_separator);
	//hbox->addSpacing(16);
	hbox->addWidget(m_attribute_label);
	//hbox->addSpacing(6);
	hbox->addWidget(m_fill_control);
	hbox->addStretch();
	setLayout(hbox);
}

FillControl* FillEditor::fill_control() const
{
	return m_fill_control;
}

//void FillEditor::set_centered(bool centered)
//{
//	if (m_centered != centered)
//	{
//		m_centered = centered;
//
//		if (m_centered) m_left_stretch->show();
//		else m_left_stretch->hide();
//	}
//}

void FillEditor::set_current_editing_state(const QString& state)
{
	m_fill_control->set_current_editing_state(state);
}
