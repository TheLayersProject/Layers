#include "../Layers.h"

using Layers::Attribute;
using Layers::Number_Attribute_Widget;
using Layers::Theme;

Number_Attribute_Widget::Number_Attribute_Widget(const QString& attribute_label_text, Attribute* attribute, QIntValidator* int_validator, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, m_int_validator{ int_validator }, Attribute_Widget(is_primary, parent)
{
	init_child_themeable_reference_list();

	store_attribute_pointer(attribute);

	if (m_stateful_attribute)
		set_customize_states(m_stateful_attribute->states());

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_stateless_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_stateless_attribute_value("background_disabled", true);

	// Setup Line Editor
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_name("line_editor");
	m_line_editor->set_text(QString::number(attribute->value().value<int>()));
	m_line_editor->set_validator(m_int_validator);

	if (m_stateful_attribute) // This shares to the attribute's current state; Not sure yet how this should behave with stateful attributes
		m_line_editor_asc = m_line_editor->share_attribute_with_themeable(
			m_line_editor->attribute_set().stateless_attribute("text"),
			m_stateful_attribute, m_stateful_attribute->state(),
			true);
	else
		m_line_editor_asc = m_line_editor->share_attribute_with_themeable(
			m_line_editor->attribute_set().stateless_attribute("text"),
			m_stateless_attribute,
			true);

	// Setup Unit Label
	m_unit_label->set_name("label");
	m_unit_label->set_font_size(14);
	m_unit_label->set_padding(0, 7, 0, 0);

	setFixedHeight(55);

	setup_layout();
}

void Number_Attribute_Widget::apply_theme(Theme& theme)
{
	if (m_line_editor_asc) m_line_editor_asc->obtain_attribute();

	Themeable::apply_theme(theme);
}

void Number_Attribute_Widget::enable_silder()
{
	QHBoxLayout* hbox2 = new QHBoxLayout;

	m_slider = new Slider(m_int_validator->bottom(), m_int_validator->top());

	m_slider->set_name("slider");

	add_child_themeable_reference(m_slider);

	hbox2->setMargin(0);
	hbox2->setSpacing(0);
	hbox2->addWidget(m_slider);

	m_line_editor_to_slider_asc = m_line_editor->share_attribute_with_themeable(
		m_line_editor->attribute_set().stateless_attribute("text"),
		m_slider->attribute_set().stateless_attribute("value"));

	m_slider_to_line_editor_asc = m_slider->share_attribute_with_themeable(
		m_slider->attribute_set().stateless_attribute("value"),
		m_line_editor->attribute_set().stateless_attribute("text"));

	setFixedHeight(105);

	m_main_layout->addLayout(hbox2);
}

void Number_Attribute_Widget::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}

void Number_Attribute_Widget::set_unit_label_text(const QString& unit_string)
{
	m_unit_label->setText(unit_string);
}

void Number_Attribute_Widget::update_customizing_state(const QString& customizing_state)
{
	if (m_customize_states.contains(customizing_state))
	{
		m_line_editor->unshare_attribute_with_themeable(
			m_line_editor->attribute_set().stateless_attribute("text"),
			m_stateful_attribute, m_line_editor_asc->to_state());

		if (m_slider)
		{
			m_line_editor->unshare_attribute_with_themeable(
				m_line_editor->attribute_set().stateless_attribute("text"),
				m_slider->attribute_set().stateless_attribute("value"));

			m_slider->unshare_attribute_with_themeable(
				m_slider->attribute_set().stateless_attribute("value"),
				m_line_editor->attribute_set().stateless_attribute("text"));
		}

		m_line_editor_asc = m_line_editor->share_attribute_with_themeable(
			m_line_editor->attribute_set().stateless_attribute("text"),
			m_stateful_attribute, customizing_state,
			true);

		if (m_slider)
		{
			m_line_editor_to_slider_asc = m_line_editor->share_attribute_with_themeable(
				m_line_editor->attribute_set().stateless_attribute("text"),
				m_slider->attribute_set().stateless_attribute("value"));

			m_slider_to_line_editor_asc = m_slider->share_attribute_with_themeable(
				m_slider->attribute_set().stateless_attribute("value"),
				m_line_editor->attribute_set().stateless_attribute("text"));
		}
	}
}

void Number_Attribute_Widget::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_label);
	add_child_themeable_reference(m_line_editor);
	add_child_themeable_reference(m_unit_label);
}

void Number_Attribute_Widget::setup_layout()
{
	QHBoxLayout* hbox1 = new QHBoxLayout;

	hbox1->setMargin(0);
	hbox1->setSpacing(0);
	hbox1->addWidget(m_left_stretch);
	hbox1->addWidget(m_attribute_label);
	hbox1->addSpacing(8);
	hbox1->addWidget(m_line_editor);
	hbox1->addSpacing(1);
	hbox1->addWidget(m_unit_label);
	hbox1->addWidget(m_right_stretch);

	// - 

	m_main_layout->setContentsMargins(8, 5, 8, 5);
	m_main_layout->setSpacing(5);
	m_main_layout->addLayout(hbox1);

	setLayout(m_main_layout);
}
