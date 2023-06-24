#include <Layers/lnumbereditor.h>

using Layers::LAttribute;
using Layers::LNumberEditor;
using Layers::LTheme;

LNumberEditor::LNumberEditor(LAttribute* attribute, QIntValidator* int_validator, QWidget* parent) :
	LAttributeEditor(attribute, parent)
{
	set_name("Number Editor");

	// Setup Attribute Label
	m_attribute_label->set_name("Label");
	m_attribute_label->set_font_size(14);
	if (attribute)
		m_attribute_label->setText(attribute->name());

	// Setup Line Editor
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_name("Line Editor");
	if (int_validator)
		m_line_editor->set_validator(int_validator);
	if (attribute)
	{
		m_line_editor->set_text(QString::number(attribute->as<double>()));
		m_line_editor->text()->establish_link(*attribute);
	}

	// Setup LSlider
	m_slider->set_name("Slider");
	m_slider->value().establish_link(*m_line_editor->text());
	if (int_validator)
		m_slider->set_limit(int_validator->top());

	init_layout();
}

void LNumberEditor::init_layout()
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
