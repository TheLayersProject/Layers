#include "../../../include/AttributeWidgets.h"

#include <QIntValidator>

using Layers::Attribute;
using Layers::NumberAW;
using Layers::Theme;

NumberAW::NumberAW(Attribute* attribute, QIntValidator* int_validator, QWidget* parent) :
	AttributeWidget(attribute, parent)
{
	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_proper_name("Label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);
	if (attribute)
		m_attribute_label->setText(attribute->capitalized_name());

	// Setup Line Editor
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_name("line_editor");
	m_line_editor->set_proper_name("Line Editor");
	if (int_validator)
		m_line_editor->set_validator(int_validator);
	if (attribute)
	{
		m_line_editor->set_text(QString::number(attribute->as<double>()));
		m_line_editor->text()->entangle_with(*attribute);
	}

	// Setup Slider
	m_slider->set_name("mini_slider");
	m_slider->set_proper_name("Slider");
	m_slider->a_value.entangle_with(*m_line_editor->text());
	if (int_validator)
		m_slider->set_limit(int_validator->top());

	// Setup Unit Label
	//m_unit_label->set_name("label");
	//m_unit_label->set_font_size(14);
	//m_unit_label->set_padding(0, 7, 0, 0);

	//setFixedHeight(55);

	setup_layout();
}

void NumberAW::set_unit_label_text(const QString& unit_string)
{
	//m_unit_label->setText(unit_string);
}

void NumberAW::setup_layout()
{
	QHBoxLayout* hbox1 = new QHBoxLayout;

	hbox1->setContentsMargins(0, 0, 0, 0);
	hbox1->setSpacing(0);
	hbox1->addWidget(m_attribute_label);
	hbox1->addSpacing(8);
	hbox1->addWidget(m_line_editor);
	hbox1->addWidget(m_slider);
	//hbox1->addSpacing(1);
	//hbox1->addWidget(m_unit_label);
	hbox1->addStretch();

	m_main_layout->setContentsMargins(8, 0, 8, 0);
	m_main_layout->setSpacing(5);
	m_main_layout->addLayout(hbox1);

	setLayout(m_main_layout);
}
