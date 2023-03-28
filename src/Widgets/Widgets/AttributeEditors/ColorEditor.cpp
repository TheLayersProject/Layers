#include "ColorEditor.h"

using Layers::Attribute;
using Layers::ColorEditor;
using Layers::ColorControl;
using Layers::Theme;

ColorEditor::ColorEditor(Attribute* attribute, QWidget* parent) :
	AttributeEditor(attribute, parent)
{
	exclude_tag_prefixes({ "aw_group", "state_aw" });

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_proper_name("Label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);
	if (attribute)
		m_attribute_label->setText(attribute->capitalized_name());

	connect(m_disabled_toggle, &ToggleSwitch::toggled_event, [this, attribute] {
		if (m_disabled_toggle->toggled())
		{
			m_color_control->show();

			attribute->set_disabled(false);
		}
		else
		{
			m_color_control->hide();

			attribute->set_disabled();
		}
	});

	if (attribute)
	{
		if (!attribute->disabled()) m_disabled_toggle->toggle();
		else m_color_control->hide();

		// Setup Color Control
		m_color_control->fill()->entangle_with(*attribute);
	}

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(14);
	hbox->addWidget(m_disabled_toggle);
	hbox->addSpacing(6);
	hbox->addWidget(m_color_control);
	hbox->addStretch();
	setLayout(hbox);
}

ColorControl* ColorEditor::color_control() const
{
	return m_color_control;
}

void ColorEditor::set_current_editting_state(const QString& state)
{
	m_color_control->set_current_editting_state(state);
}
