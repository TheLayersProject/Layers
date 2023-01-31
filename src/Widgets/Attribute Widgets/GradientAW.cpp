#include "../../../include/AttributeWidgets.h"

using Layers::Attribute;
using Layers::GradientAW;
using Layers::Theme;

GradientAW::GradientAW(const QString& attribute_label_text, Attribute* attribute, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, AttributeWidget(attribute, parent)
{
	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->a_fill.set_disabled();
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->a_fill.set_disabled();

	// Setup Color Control
	m_gradient_control->a_fill.entangle_with(*attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(6);
	hbox->addWidget(m_gradient_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

void GradientAW::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}
