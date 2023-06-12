#include <LayersWidgets/lnumbereditor.h>

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
		m_attribute_label->setText(attribute->capitalized_name());

	// Setup Line Editor
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_name("Line Editor");
	if (int_validator)
		m_line_editor->set_validator(int_validator);
	if (attribute)
	{
		m_line_editor->set_text(QString::number(attribute->as<double>()));
		m_line_editor->text()->entangle_with(*attribute);
	}

	// Setup LSlider
	m_slider->set_name("Slider");
	m_slider->value().entangle_with(*m_line_editor->text());
	if (int_validator)
		m_slider->set_limit(int_validator->top());

	// Setup Unit Label
	//m_unit_label->set_name("label");
	//m_unit_label->set_font_size(14);
	//m_unit_label->set_padding(0, 7, 0, 0);

	//setFixedHeight(55);

	init_layout();
}

void LNumberEditor::set_unit_label_text(const QString& unit_string)
{
	//m_unit_label->setText(unit_string);
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
