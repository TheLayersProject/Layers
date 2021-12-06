#include "../../include/CustomizePanel.h"
#include "../../include/calculate.h"
#include "../../include/Window.h"

#include <QApplication>
#include <QIntValidator>

using Layers::AttributeWidget;
using Layers::Button;
using Layers::CustomizePanel;
using Layers::Label;

CustomizePanel::CustomizePanel(Themeable* themeable, QWidget* parent) :
	m_themeable{ themeable }, Widget(parent)
{
	init_attributes();
	init_child_themeable_reference_list();
	set_name("customize_panel");
	set_proper_name(*themeable->proper_name());
	setFixedWidth(300);
	hide();

	m_attributes_label->set_name("attributes_label");
	m_attributes_label->set_proper_name("Attributes Label");
	m_attributes_label->set_font_size(17);
	m_attributes_label->set_padding(0, 8, 0, 0);

	m_widgets_label->set_name("widgets_label");
	m_widgets_label->set_proper_name("Widgets Label");
	m_widgets_label->set_font_size(17);
	m_widgets_label->set_padding(0, 8, 0, 0);

	m_stateful_attributes_label->set_name("stateful_attributes_label");
	m_stateful_attributes_label->set_font_size(15);
	m_stateful_attributes_label->set_padding(0, 7, 0, 0);

	m_stateless_attributes_label->set_name("stateless_attributes_label");
	m_stateless_attributes_label->set_font_size(15);
	m_stateless_attributes_label->set_padding(0, 7, 0, 0);

	m_state_label->set_name("states_label");
	m_state_label->set_font_size(15);
	m_state_label->set_padding(0, 8, 0, 0);

	m_state_combobox->setFixedSize(190, 45);
	m_state_combobox->set_name("state_combobox");

	m_show_all_button->set_name("show_all_button");
	m_show_all_button->set_proper_name("'Show All' Button");
	m_show_all_button->disable_text_hover_color();
	m_show_all_button->set_margin(0, 7, 0, 7);
	m_show_all_button->set_text_padding(3, 5, 0, 0);

	m_show_primary_button->set_name("show_primary_button");
	m_show_primary_button->set_proper_name("'Show Primary' Button");
	m_show_primary_button->disable_text_hover_color();
	m_show_primary_button->set_margin(0, 7, 0, 7);
	m_show_primary_button->set_text_padding(3, 5, 0, 0);
	m_show_primary_button->hide();

	//for (const QString& state : m_themeable->states())
	//{
	//	m_state_combobox->add_item(state);
	//}

	connect(m_show_all_button, &Button::clicked, [this] {
		m_showing_primary = false;

		//for (AttributeWidget* attribute_widget : m_stateful_attribute_widgets)
		//{
		//	if (attribute_widget->customize_states().contains(m_state_combobox->current_item()))
		//		attribute_widget->show();
		//}

		for (AttributeWidget* attribute_widget : m_stateless_attribute_widgets)
			attribute_widget->show();

		//update_attribute_widget_background_colors();

		m_show_all_button->hide();
		m_show_primary_button->show();
	});

	connect(m_show_primary_button, &Button::clicked, [this] {
		m_showing_primary = true;

		//for (AttributeWidget* attribute_widget : m_stateful_attribute_widgets)
		//{
		//	if (attribute_widget->customize_states().contains(m_state_combobox->current_item()) && !attribute_widget->is_primary())
		//		attribute_widget->hide();
		//}

		//for (AttributeWidget* attribute_widget : m_stateless_attribute_widgets)
		//	if (!attribute_widget->is_primary()) attribute_widget->hide();

		//update_attribute_widget_background_colors();

		m_show_all_button->show();
		m_show_primary_button->hide();
	});

	if (m_themeable->child_themeable_references().isEmpty()) m_widgets_label->hide();
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

				add_widget_button(element_button);
			}
		}
	}

	init_attribute_widgets();
}

void CustomizePanel::add_attribute_widget(AttributeWidget* attribute_widget)
{
	add_child_themeable_reference(attribute_widget);
	m_attribute_widgets.append(attribute_widget);

	// TEMP
	m_stateless_attribute_widgets.append(attribute_widget);
	m_stateless_attributes_layout->addWidget(attribute_widget);
	//
	
	//if (attribute_widget->attribute())
	//{
	//	m_stateful_attribute_widgets.append(attribute_widget);
	//	m_stateful_attributes_layout->addWidget(attribute_widget);

	//	if (ColorAW* caw = dynamic_cast<ColorAW*>(attribute_widget))
	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			caw->color_control(), SLOT(set_current_editting_state(const QString&)));

	//	else if (CornerRadiiAW* craw = dynamic_cast<CornerRadiiAW*>(attribute_widget))
	//	{
	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			craw->tl_slider(), SLOT(set_current_editting_state(const QString&)));

	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			craw->tr_slider(), SLOT(set_current_editting_state(const QString&)));

	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			craw->bl_slider(), SLOT(set_current_editting_state(const QString&)));

	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			craw->br_slider(), SLOT(set_current_editting_state(const QString&)));
	//	}
	//}
	//else
	//{
	//	m_stateless_attribute_widgets.append(attribute_widget);
	//	m_stateless_attributes_layout->addWidget(attribute_widget);
	//}
}

void CustomizePanel::add_widget_button(Button* button, int index)
{
	m_widget_buttons.append(button);

	button->set_available_width(252);
	button->a_fill.set_disabled();
	button->set_font_size(16);
	//button->set_name("widget_button");
	button->set_text_padding(0, 5, 0, 0);

	//add_child_themeable_reference(button);

	if (m_current_theme)
		button->apply_theme(*m_current_theme);

	if (index == -1) m_element_buttons_layout->addWidget(button);
	else m_element_buttons_layout->insertWidget(index, button);
}

void CustomizePanel::init_attribute_widgets()
{
	for (AttributeLayoutItem* attr_layout_item : m_themeable->attribute_layout())
	{
		if (Attribute* attribute = dynamic_cast<Attribute*>(attr_layout_item))
		{
			if (attribute->name().contains("Fill"))
			{
				FillAW* fill_aw = new FillAW(attribute);

				m_fill_awidgets.append(fill_aw);

				//fill_aw->replace_all_attributes_with(m_control_fill_aw);

				add_attribute_widget(fill_aw);
			}
			else if (attribute->name().contains("Color"))
			{
				ColorAW* color_aw = new ColorAW(attribute);

				m_color_awidgets.append(color_aw);

				add_attribute_widget(color_aw);
			}
			else if (
				attribute->name().contains("Thickness") ||
				attribute->name().contains("Margin"))
			{
				NumberAW* number_aw = new NumberAW(attribute, new QIntValidator(0, 30));

				m_number_awidgets.append(number_aw);

				//number_aw->replace_all_attributes_with(m_control_number_aw);

				add_attribute_widget(number_aw);
			}
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(attr_layout_item))
		{
			if (attr_group->name() == "Corner Radii")
			{
				m_corner_radii_aw = new CornerRadiiAW(attr_group);

				//corner_radii_aw->replace_all_attributes_with(m_control_corner_radii_aw);

				add_attribute_widget(m_corner_radii_aw);
			}
			else
			{
				AWGroup* aw_group = new AWGroup(attr_group->name());

				m_aw_groups.append(aw_group);

				//aw_group->replace_all_attributes_with(m_control_aw_group);

				for (Attribute* attribute : attr_group->attributes())
				{
					if (attribute->name().contains("Fill"))
					{
						FillAW* fill_aw = new FillAW(attribute);

						m_fill_awidgets.append(fill_aw);

						//fill_aw->replace_all_attributes_with(m_control_fill_aw);

						aw_group->add_attribute_widget(fill_aw);
					}
					else if (attribute->name().contains("Color"))
					{
						ColorAW* color_aw = new ColorAW(attribute);

						m_color_awidgets.append(color_aw);

						aw_group->add_attribute_widget(color_aw);
					}
					else if (
						attribute->name().contains("Thickness") ||
						attribute->name().contains("Margin"))
					{
						NumberAW* number_aw = new NumberAW(attribute, new QIntValidator(0, 30));

						m_number_awidgets.append(number_aw);

						//number_aw->replace_all_attributes_with(m_control_number_aw);

						aw_group->add_attribute_widget(number_aw);
					}
				}

				add_attribute_widget(aw_group);
			}
		}
	}
}

void CustomizePanel::replace_all_attributes_with(CustomizePanel* cpanel)
{
	Widget::replace_all_attributes_with(cpanel);

	if (m_attributes_label) m_attributes_label->replace_all_attributes_with(cpanel->m_attributes_label);
	if (m_widgets_label) m_widgets_label->replace_all_attributes_with(cpanel->m_widgets_label);
	if (m_show_all_button) m_show_all_button->replace_all_attributes_with(cpanel->m_show_all_button);
	if (m_show_primary_button) m_show_primary_button->replace_all_attributes_with(cpanel->m_show_primary_button);
}

void CustomizePanel::replace_all_aw_group_attrs_with(AWGroup* control_aw_group)
{
	for (AWGroup* aw_group : m_aw_groups)
		aw_group->replace_all_attributes_with(control_aw_group);
}

void Layers::CustomizePanel::replace_all_color_awidgets_attrs_with(ColorAW* control_color_aw)
{
	for (ColorAW* color_aw : m_color_awidgets)
		color_aw->replace_all_attributes_with(control_color_aw);
}

void CustomizePanel::init_attributes()
{
	// TODO: re-enable
	a_fill.set_disabled();

	m_show_all_button->a_fill.set_value(QColor("#61ad50"));
	m_show_all_button->a_hover_fill.set_value(QColor("#6fc65b"));
	//m_show_all_button->a_text_color->set_value(QColor("#f8f8f8"));
	m_show_all_button->a_corner_radius_tl.set_value(5);
	m_show_all_button->a_corner_radius_tr.set_value(5);
	m_show_all_button->a_corner_radius_bl.set_value(5);
	m_show_all_button->a_corner_radius_br.set_value(5);

	m_show_primary_button->a_fill.set_value(QColor("#61ad50"));
	m_show_primary_button->a_hover_fill.set_value(QColor("#6fc65b"));
	//m_show_primary_button->set_attribute_value("text_color", QColor("#f8f8f8"));
	m_show_primary_button->a_corner_radius_tl.set_value(5);
	m_show_primary_button->a_corner_radius_tr.set_value(5);
	m_show_primary_button->a_corner_radius_bl.set_value(5);
	m_show_primary_button->a_corner_radius_br.set_value(5);
}

void CustomizePanel::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_state_label);
	add_child_themeable_reference(m_state_combobox);
	add_child_themeable_reference(m_stateful_attributes_label);
	add_child_themeable_reference(m_stateless_attributes_label);
	add_child_themeable_reference(m_attributes_label);
	add_child_themeable_reference(m_widgets_label);
	add_child_themeable_reference(m_show_all_button);
	add_child_themeable_reference(m_show_primary_button);
}

void CustomizePanel::replace_all_fill_awidgets_attrs_with(FillAW* control_fill_aw)
{
	for (FillAW* fill_aw : m_fill_awidgets)
		fill_aw->replace_all_attributes_with(control_fill_aw);
}

void CustomizePanel::replace_all_number_awidgets_attrs_with(NumberAW* control_number_aw)
{
	for (NumberAW* number_aw : m_number_awidgets)
		number_aw->replace_all_attributes_with(control_number_aw);
}

void Layers::CustomizePanel::replace_all_widget_buttons_attrs_with(Button* control_widget_button)
{
	for (Button* widget_button : m_widget_buttons)
		widget_button->replace_all_attributes_with(control_widget_button);
}

void CustomizePanel::replace_corner_radii_aw_attrs_with(CornerRadiiAW* control_corner_radii_aw)
{
	if (m_corner_radii_aw)
		m_corner_radii_aw->replace_all_attributes_with(control_corner_radii_aw);
}

void CustomizePanel::setup_layout()
{
	if (!m_layout_setup)
	{
		// States Layout

		m_states_layout->setContentsMargins(6, 0, 0, 0);
		m_states_layout->setSpacing(13);
		m_states_layout->addWidget(m_state_label);
		m_states_layout->addWidget(m_state_combobox);
		m_states_layout->addStretch();

		// Stateful Attributes Layout

		m_stateful_attributes_layout->setContentsMargins(0, 0, 0, 0);
		m_stateful_attributes_layout->setSpacing(3);

		// Stateless Attributes Layout

		m_stateless_attributes_layout->setContentsMargins(0, 0, 0, 0);
		m_stateless_attributes_layout->setSpacing(3);

		// Attribute Layout HBox 1

		QHBoxLayout* attributes_label_layout = new QHBoxLayout;

		attributes_label_layout->setContentsMargins(6, 0, 0, 0);
		attributes_label_layout->setSpacing(0);
		attributes_label_layout->addWidget(m_attributes_label);
		attributes_label_layout->addStretch();
		attributes_label_layout->addWidget(m_show_all_button);
		attributes_label_layout->addWidget(m_show_primary_button);
		attributes_label_layout->addStretch();

		// Attributes Layout

		m_attributes_layout->setContentsMargins(0, 0, 0, 0);
		m_attributes_layout->setSpacing(3);
		m_attributes_layout->addLayout(attributes_label_layout);

		if (!m_stateful_attribute_widgets.isEmpty())
		{
			m_attributes_layout->addWidget(m_stateful_attributes_label);
			m_attributes_layout->addSpacing(8);
			m_attributes_layout->addLayout(m_states_layout);
			m_attributes_layout->addSpacing(15);
			m_attributes_layout->addLayout(m_stateful_attributes_layout);
			m_attributes_layout->setAlignment(m_stateful_attributes_label, Qt::AlignHCenter);

			if (!m_stateless_attribute_widgets.isEmpty())
			{
				m_attributes_layout->addSpacing(8);
				m_attributes_layout->addWidget(m_stateless_attributes_label);
				m_attributes_layout->addSpacing(8);
				m_attributes_layout->setAlignment(m_stateless_attributes_label, Qt::AlignHCenter);
			}
		}
		else m_attributes_layout->addSpacing(8);

		m_attributes_layout->addLayout(m_stateless_attributes_layout);

		// Elements Layout

		QHBoxLayout* hbox2 = new QHBoxLayout;

		hbox2->setContentsMargins(6, 0, 0, 0);
		hbox2->setSpacing(0);
		hbox2->addWidget(m_widgets_label);
		hbox2->addStretch();
		hbox2->activate();

		m_element_buttons_layout->setContentsMargins(27, 0, 0, 0);
		m_element_buttons_layout->setSpacing(10);

		m_elements_layout->setContentsMargins(0, 0, 0, 0);
		m_elements_layout->setSpacing(15);
		m_elements_layout->addLayout(hbox2);
		m_elements_layout->addLayout(m_element_buttons_layout);

		// Main Layout

		QVBoxLayout* main_layout = new QVBoxLayout;

		main_layout->setContentsMargins(10, 17, 10, 18);
		main_layout->setSpacing(0);
		main_layout->addLayout(m_attributes_layout);
		main_layout->addSpacing(24);
		main_layout->addLayout(m_elements_layout);
		main_layout->addStretch();
		main_layout->activate();

		setLayout(main_layout);

		m_layout_setup = true;
	}
}
