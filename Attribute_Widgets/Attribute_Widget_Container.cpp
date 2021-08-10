#include "../Layers.h"

using Layers::Attribute_Widget_Container;

Attribute_Widget_Container::Attribute_Widget_Container(const QString& label_text, bool is_primary, QWidget* parent) :
	m_label{ new Label(label_text) }, Attribute_Widget(is_primary, parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	m_label->set_name("label");
	m_label->set_font_size(16);
	m_label->set_padding(17, 7, 0, 0);

	m_collapse_button->set_name("collapse_button");

	connect(m_collapse_button, &Button::clicked, [this] {
		if (m_collapsed)
		{
			int new_height = 55;

			for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
			{
				new_height += attribute_widget->height();

				attribute_widget->show();
			}

			setFixedHeight(new_height);

			m_widgets_vbox->setContentsMargins(10, 0, 10, 10);

			m_collapsed = false;
		}
		else
		{
			for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
			{
				attribute_widget->hide();
			}

			setFixedHeight(45);

			m_widgets_vbox->setMargin(0);

			m_collapsed = true;
		}
	});

	setup_layout();
}

void Attribute_Widget_Container::add_attribute_widget(Attribute_Widget* attribute_widget)
{
	m_widgets_vbox->addWidget(attribute_widget);

	m_child_attribute_widgets.append(attribute_widget);

	if (m_collapsed) attribute_widget->hide();

	if (m_customize_states.isEmpty())
	{
		if (attribute_widget->stateful_attribute())
			set_customize_states(attribute_widget->stateful_attribute()->states());
	}
}

void Attribute_Widget_Container::enable_secondary_background_color(bool cond)
{
	Attribute_Widget::enable_secondary_background_color(cond);

	int counter = 0;

	for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
	{
		if (is_even(counter))
			attribute_widget->enable_secondary_background_color(!cond);
		else
			attribute_widget->enable_secondary_background_color(cond);

		counter++;
	}
}

void Attribute_Widget_Container::init_attributes()
{
	set_stateless_attribute_value("border_thickness", 2);
}

void Attribute_Widget_Container::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_label);
	add_child_themeable_reference(m_collapse_button);
}

void Attribute_Widget_Container::set_customize_states(const QList<QString>& customize_states)
{
	m_customize_states = customize_states;

	for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
	{
		attribute_widget->set_customize_states(customize_states);
	}
}

void Attribute_Widget_Container::update_customizing_state(const QString& customizing_state)
{
	for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
	{
		attribute_widget->update_customizing_state(customizing_state);
	}
}

void Attribute_Widget_Container::setup_layout()
{
	QHBoxLayout* top_hbox = new QHBoxLayout;

	top_hbox->setContentsMargins(8, 0, 8, 0);
	top_hbox->setSpacing(0);
	top_hbox->addStretch();
	top_hbox->addWidget(m_label);
	top_hbox->addWidget(m_collapse_button);
	top_hbox->addStretch();

	m_widgets_vbox->setMargin(0);
	m_widgets_vbox->setSpacing(0);

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setMargin(0);
	main_layout->setSpacing(0);
	main_layout->addLayout(top_hbox);
	main_layout->addLayout(m_widgets_vbox);

	setLayout(main_layout);
}
