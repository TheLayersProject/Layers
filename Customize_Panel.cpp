#include "Layers.h"

using Layers::Attribute_Widget;
using Layers::Button;
using Layers::Customize_Panel;
using Layers::Label;

Customize_Panel::Customize_Panel(Themeable* themeable, QWidget* parent) :
	m_themeable{ themeable }, Widget(parent)
{
	init_attributes();
	init_child_themeable_reference_list();
	set_name("customize_panel");
	set_proper_name(*themeable->proper_name());
	setFixedWidth(300);
	hide();

	m_attributes_label->set_name("attributes_label");
	m_attributes_label->set_font_size(17);
	m_attributes_label->set_padding(0, 8, 0, 0);

	m_elements_label->set_name("elements_label");
	m_elements_label->set_font_size(17);
	m_elements_label->set_padding(0, 8, 0, 0);

	m_states_label->set_name("states_label");
	m_states_label->set_font_size(17);
	m_states_label->set_padding(0, 8, 0, 0);

	m_state_combobox->setFixedSize(190, 45);
	m_state_combobox->set_name("state_combobox");

	for (const QString& state : m_themeable->states())
	{
		m_state_combobox->add_item(state);
	}

	connect(m_state_combobox, &Combobox::current_item_changed, [this] {
		for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
		{
			attribute_widget->update_customizing_state(m_state_combobox->current_item());

			if (attribute_widget->customize_states().contains(m_state_combobox->current_item()))
			{
				if (!attribute_widget->isVisible())
				{
					if (!attribute_widget->is_primary() && m_show_all_button->isVisible());
					else attribute_widget->show();
				}
			}
			else
			{
				if (attribute_widget->isVisible()) attribute_widget->hide();
			}
		}
	});

	m_show_all_button->set_name("show_all_button");
	m_show_all_button->disable_text_hover_color();
	m_show_all_button->set_margin(0, 7, 0, 7);
	m_show_all_button->set_text_padding(3, 5, 0, 0);

	connect(m_show_all_button, &Button::clicked, [this] {
		m_showing_primary = false;

		for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
		{
			if (!m_state_combobox->items().isEmpty())
			{
				if (attribute_widget->customize_states().contains(m_state_combobox->current_item()))
					attribute_widget->show();
			}
			else attribute_widget->show();
		}

		update_attribute_widget_background_colors();

		m_show_all_button->hide();
		m_show_primary_button->show();
	});

	m_show_primary_button->set_name("show_primary_button");
	m_show_primary_button->disable_text_hover_color();
	m_show_primary_button->set_margin(0, 7, 0, 7);
	m_show_primary_button->set_text_padding(3, 5, 0, 0);
	m_show_primary_button->hide();

	connect(m_show_primary_button, &Button::clicked, [this] {
		m_showing_primary = true;

		for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
		{
			if (!m_state_combobox->items().isEmpty())
			{
				if (attribute_widget->customize_states().contains(m_state_combobox->current_item()) && !attribute_widget->is_primary())
					attribute_widget->hide();
			}
			else if (!attribute_widget->is_primary()) attribute_widget->hide();
		}

		update_attribute_widget_background_colors();

		m_show_all_button->show();
		m_show_primary_button->hide();
	});

	setup_layout();

	if (m_themeable->child_themeable_references().isEmpty()) m_elements_label->hide();
	else
	{
		for (Themeable* child_themeable : m_themeable->child_themeable_references())
		{
			// Check is themeable has a proper name to determine that is it customizable
			if (child_themeable->proper_name()) // TODO: Consider a Themeable::is_customizable() function so this is clearer
			{
				Button* element_button = new Button(child_themeable->icon(), *child_themeable->proper_name());

				QObject::connect(element_button, &Button::clicked, [child_themeable] {
					static_cast<Window*>(QApplication::activeWindow())->customize_menu()->open_customize_panel(child_themeable->customize_panel());
				});

				add_element_button(element_button);
			}
		}
	}
}

void Customize_Panel::add_attribute_widget(Attribute_Widget* attribute_widget)
{
	m_child_attribute_widgets.append(attribute_widget);
	add_child_themeable_reference(attribute_widget);
	m_attributes_layout->addWidget(attribute_widget);

	if (!m_state_combobox->items().isEmpty())
	{
		attribute_widget->update_customizing_state(m_state_combobox->current_item());

		if (!attribute_widget->customize_states().contains(m_state_combobox->current_item()))
			attribute_widget->hide();
	}
}

void Customize_Panel::add_element_button(Button* button)
{
	button->set_attribute_value("background_disabled", true);
	button->set_font_size(16);
	button->set_name("element_button");
	button->set_text_padding(0, 5, 0, 0);

	add_child_themeable_reference(button);

	m_element_buttons_layout->addWidget(button);
}

void Customize_Panel::init_attributes()
{
	set_attribute_value("background_disabled", true);

	m_show_all_button->set_attribute_value("background_color", QColor("#61ad50"));
	m_show_all_button->set_attribute_value("background_color_hover", QColor("#6fc65b"));
	m_show_all_button->set_attribute_value("text_color", QColor("#f8f8f8"));
	m_show_all_button->set_attribute_value("corner_radius_tl", 5);
	m_show_all_button->set_attribute_value("corner_radius_tr", 5);
	m_show_all_button->set_attribute_value("corner_radius_bl", 5);
	m_show_all_button->set_attribute_value("corner_radius_br", 5);

	m_show_primary_button->set_attribute_value("background_color", QColor("#61ad50"));
	m_show_primary_button->set_attribute_value("background_color_hover", QColor("#6fc65b"));
	m_show_primary_button->set_attribute_value("text_color", QColor("#f8f8f8"));
	m_show_primary_button->set_attribute_value("corner_radius_tl", 5);
	m_show_primary_button->set_attribute_value("corner_radius_tr", 5);
	m_show_primary_button->set_attribute_value("corner_radius_bl", 5);
	m_show_primary_button->set_attribute_value("corner_radius_br", 5);
}

void Customize_Panel::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_states_label);
	add_child_themeable_reference(m_state_combobox);
	add_child_themeable_reference(m_attributes_label);
	add_child_themeable_reference(m_elements_label);
	add_child_themeable_reference(m_show_all_button);
	add_child_themeable_reference(m_show_primary_button);
}

void Customize_Panel::update_attribute_widget_background_colors()
{
	int counter = 0;

	if (m_showing_primary)
	{
		for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
		{
			if (attribute_widget->is_primary())
			{
				if (is_even(counter))
					attribute_widget->enable_secondary_background_color(false);
				else
					attribute_widget->enable_secondary_background_color();

				counter++;
			}
		}
	}
	else
	{
		for (Attribute_Widget* attribute_widget : m_child_attribute_widgets)
		{
			if (is_even(counter))
				attribute_widget->enable_secondary_background_color(false);
			else
				attribute_widget->enable_secondary_background_color();

			counter++;
		}
	}
}

void Customize_Panel::setup_layout()
{
	// States Layout

	m_states_layout->setContentsMargins(6, 0, 0, 12);
	m_states_layout->setSpacing(13);
	m_states_layout->addWidget(m_states_label);
	m_states_layout->addWidget(m_state_combobox);
	m_states_layout->addStretch();

	// Attributes Layout

	QHBoxLayout* hbox1 = new QHBoxLayout;

	hbox1->setContentsMargins(6, 0, 0, 8);
	hbox1->setSpacing(0);
	hbox1->addWidget(m_attributes_label);
	hbox1->addStretch();
	hbox1->addWidget(m_show_all_button);
	hbox1->addWidget(m_show_primary_button);
	hbox1->addStretch();

	m_attributes_layout->setMargin(0);
	m_attributes_layout->setSpacing(3);
	m_attributes_layout->addLayout(hbox1);

	// Elements Layout

	QHBoxLayout* hbox2 = new QHBoxLayout;

	hbox2->setContentsMargins(6, 0, 0, 0);
	hbox2->setSpacing(0);
	hbox2->addWidget(m_elements_label);
	hbox2->addStretch();
	hbox2->activate();

	m_element_buttons_layout->setContentsMargins(27, 0, 0, 0);
	m_element_buttons_layout->setSpacing(10);

	m_elements_layout->setMargin(0);
	m_elements_layout->setSpacing(15);
	m_elements_layout->addLayout(hbox2);
	m_elements_layout->addLayout(m_element_buttons_layout);

	// Main Layout

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(10, 17, 10, 18);
	main_layout->setSpacing(0);
	if (!m_state_combobox->items().isEmpty()) main_layout->addLayout(m_states_layout);
	main_layout->addLayout(m_attributes_layout);
	main_layout->addSpacing(24);
	main_layout->addLayout(m_elements_layout);
	main_layout->addStretch();
	main_layout->activate();

	setLayout(main_layout);
}
