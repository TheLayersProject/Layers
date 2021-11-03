#include "../../../include/AttributeWidgets.h"

#include <QIntValidator>

using Layers::Attribute;
using Layers::NumberAttributeWidget;
using Layers::Theme;

NumberAttributeWidget::NumberAttributeWidget(const QString& attribute_label_text, Attribute* attribute, QIntValidator* int_validator, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, m_int_validator{ int_validator }, AttributeWidget(parent)
{
	init_child_themeable_reference_list();

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_attribute_value("background_disabled", true);

	// Setup Line Editor
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_name("line_editor");
	m_line_editor->set_text(QString::number(attribute->value().value<int>()));
	m_line_editor->set_validator(m_int_validator);

	m_line_editor->replace_attribute_with_proxy("text", attribute);

	//m_line_editor->set_target_attribute(attribute);

	// Setup Unit Label
	m_unit_label->set_name("label");
	m_unit_label->set_font_size(14);
	m_unit_label->set_padding(0, 7, 0, 0);

	setFixedHeight(55);

	setup_layout();
}

void NumberAttributeWidget::enable_silder()
{
	QHBoxLayout* hbox2 = new QHBoxLayout;

	m_slider = new Slider(m_int_validator->top());

	m_slider->set_name("slider");

	add_child_themeable_reference(m_slider);

	hbox2->setContentsMargins(0, 0, 0, 0);
	hbox2->setSpacing(0);
	hbox2->addWidget(m_slider);

	m_slider->replace_attribute_with_proxy("value", m_line_editor->attribute("text"));

	setFixedHeight(105);

	m_main_layout->addLayout(hbox2);
}

void NumberAttributeWidget::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}

void NumberAttributeWidget::set_unit_label_text(const QString& unit_string)
{
	m_unit_label->setText(unit_string);
}

void NumberAttributeWidget::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_label);
	add_child_themeable_reference(m_line_editor);
	add_child_themeable_reference(m_unit_label);
}

void NumberAttributeWidget::setup_layout()
{
	QHBoxLayout* hbox1 = new QHBoxLayout;

	hbox1->setContentsMargins(0, 0, 0, 0);
	hbox1->setSpacing(0);
	hbox1->addWidget(m_left_stretch);
	hbox1->addWidget(m_attribute_label);
	hbox1->addSpacing(8);
	hbox1->addWidget(m_line_editor);
	hbox1->addSpacing(1);
	hbox1->addWidget(m_unit_label);
	hbox1->addWidget(m_right_stretch);

	m_main_layout->setContentsMargins(8, 5, 8, 5);
	m_main_layout->setSpacing(5);
	m_main_layout->addLayout(hbox1);

	setLayout(m_main_layout);
}
