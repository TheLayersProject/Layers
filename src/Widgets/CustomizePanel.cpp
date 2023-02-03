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
	set_name("customize_panel");
	if (themeable->proper_name())
		set_proper_name(*themeable->proper_name());
	else
		set_proper_name("Customize Panel");
	setFixedWidth(300);
	//hide();

	m_attributes_label->set_name("attributes_label");
	m_attributes_label->set_proper_name("Attributes Label");
	m_attributes_label->set_font_size(17);
	m_attributes_label->set_padding(0, 8, 0, 0);

	m_widgets_label->set_name("widgets_label");
	m_widgets_label->set_proper_name("Widgets Label");
	m_widgets_label->set_font_size(17);
	m_widgets_label->set_padding(0, 8, 0, 0);

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

	connect(m_show_all_button, &Button::clicked, [this] {
		//m_showing_primary = false;

		for (AttributeWidget* attribute_widget : m_attribute_widgets)
			attribute_widget->show();

		m_show_all_button->hide();
		m_show_primary_button->show();
	});

	connect(m_show_primary_button, &Button::clicked, [this] {
		//m_showing_primary = true;

		//for (AttributeWidget* attribute_widget : m_stateful_attribute_widgets)
		//{
		//	if (attribute_widget->customize_states().contains(m_state_combobox->current_item()) && !attribute_widget->is_primary())
		//		attribute_widget->hide();
		//}

		//for (AttributeWidget* attribute_widget : m_stateless_attribute_widgets)
		//	if (!attribute_widget->is_primary()) attribute_widget->hide();

		for (AttributeWidget* aw : m_attribute_widgets)
			if (aw->disabled())
				aw->hide();

		m_show_all_button->show();
		m_show_primary_button->hide();
	});

	if (m_themeable->child_themeables().isEmpty()) m_widgets_label->hide();
	else
	{
		for (Themeable* child_themeable : m_themeable->child_themeables())
		{
			// Check if themeable has a proper name to determine that it is customizable
			if (child_themeable->proper_name()) // TODO: Consider a Themeable::is_customizable() function so this is clearer
			{
				Button* element_button;

				if (child_themeable->icon())
					element_button = new Button(new Graphic(*child_themeable->icon()), *child_themeable->proper_name());
				else
					element_button = new Button(*child_themeable->proper_name());

				QObject::connect(element_button, &Button::clicked, [child_themeable] {
					static_cast<Window*>(QApplication::activeWindow()
						)->customize_menu()->open_customize_panel(
							new CustomizePanel(child_themeable));
				});

				add_widget_button(element_button);
			}
		}
	}

	setup_layout();

	init_attribute_widgets();
}

CustomizePanel::~CustomizePanel()
{
	for (Button* widget_button : m_widget_buttons)
		widget_button->deleteLater();
}

void CustomizePanel::add_attribute_widget(AttributeWidget* attribute_widget)
{
	//add_child_themeable_pointer(attribute_widget);
	m_attribute_widgets.append(attribute_widget);

	// TEMP
	m_attributes_layout->addWidget(attribute_widget);
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

	if (index == -1) m_widget_buttons_layout->addWidget(button);
	else m_widget_buttons_layout->insertWidget(index, button);
}

void CustomizePanel::init_attribute_widgets()
{
	if (m_themeable->is_stateful()) // TODO: IF THEMEABLE CONTAINS STATE
	{
		m_state_aw = new StateAW;
		m_state_aw->populate_state_combobox(m_themeable->states());
		m_state_awidgets.append(m_state_aw);

		add_attribute_widget(m_state_aw);
	}

	for (Entity* entity : m_themeable->entities())
	{
		if (Attribute* attribute = dynamic_cast<Attribute*>(entity))
		{
			AttributeWidget* aw = nullptr;

			if (QString(attribute->typeName()) == "double")
			{
				aw = new NumberAW(attribute, new QIntValidator(0, 30));
				m_number_awidgets.append(dynamic_cast<NumberAW*>(aw));
			}
			else if ( // TODO: Decide how to differ between when to use a FillControl or a ColorControl
				// TEMP: For now, we will assume all use FillControl
				QString(attribute->typeName()) == "QColor" ||
				QString(attribute->typeName()) == "QList<std::pair<double,QColor>>"
				)
			{
				aw = new FillAW(attribute);
				m_fill_awidgets.append(dynamic_cast<FillAW*>(aw));
			}

			if (attribute->disabled())
				aw->hide();

			if (attribute->is_stateful())
			{
				m_state_aw->add_attribute_widget(aw);

				//connect(
				//	m_state_aw->state_combobox(), SIGNAL(current_item_changed(const QString&)),
				//	aw, SLOT(set_current_editting_state(const QString&)));
			}
			else add_attribute_widget(aw);

			connect(aw, &AttributeWidget::widget_disabled, [this, aw] {
				if (m_show_all_button->isVisible())
					aw->hide();
				});
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
		{
			if (attr_group->name().endsWith("corner_radii"))
			{
				CornerRadiiAW* corner_radii_aw = new CornerRadiiAW(dynamic_cast<CornerRadiiAttributes*>(attr_group));
				m_corner_radii_awidgets.append(corner_radii_aw);

				if (attr_group->disabled())
					corner_radii_aw->hide();

				if (attr_group->is_stateful()) m_state_aw->add_attribute_widget(corner_radii_aw);
				else add_attribute_widget(corner_radii_aw);

				connect(corner_radii_aw, &AttributeWidget::widget_disabled, [this, corner_radii_aw] {
					if (m_show_all_button->isVisible())
						corner_radii_aw->hide();
					});
			}
			else
			{
				/* TODO: Now that AWGroup requires the attr_group data,
				   it could initialize its own AttributeWidgets */
				AWGroup* aw_group = new AWGroup(attr_group);
				m_aw_groups.append(aw_group);

				bool hide_aw_group = true;

				for (Attribute* attribute : attr_group->attributes())
				{
					AttributeWidget* aw = nullptr;

					if (QString(attribute->typeName()) == "double")
					{
						aw = new NumberAW(attribute, new QIntValidator(0, 30));
						m_number_awidgets.append(dynamic_cast<NumberAW*>(aw));
					}
					else if ( // TODO: Decide how to differ between when to use a FillControl or a ColorControl
						// TEMP: For now, we will assume all use FillControl
						QString(attribute->typeName()) == "QColor" ||
						QString(attribute->typeName()) == "QList<std::pair<double,QColor>>"
						)
					{
						aw = new FillAW(attribute);
						m_fill_awidgets.append(dynamic_cast<FillAW*>(aw));
					}

					aw_group->add_attribute_widget(aw);
				}

				if (attr_group->disabled())
					aw_group->hide();

				if (attr_group->is_stateful()) m_state_aw->add_attribute_widget(aw_group);
				else add_attribute_widget(aw_group);

				connect(aw_group, &AttributeWidget::widget_disabled, [this, aw_group] {
					if (m_show_all_button->isVisible())
						aw_group->hide();
					});
			}
		}
	}
}

void CustomizePanel::replace_all_aw_group_attrs_with(AWGroup* control_aw_group)
{
	for (AWGroup* aw_group : m_aw_groups)
		aw_group->entangle_with(control_aw_group);
}

void CustomizePanel::replace_all_color_awidgets_attrs_with(ColorAW* control_color_aw)
{
	for (ColorAW* color_aw : m_color_awidgets)
		color_aw->entangle_with(control_color_aw);
}

void CustomizePanel::init_attributes()
{
	// TODO: re-enable
	a_fill.set_disabled();

	m_show_all_button->a_fill.set_value(QColor("#61ad50"));
	m_show_all_button->a_hover_fill.set_value(QColor("#6fc65b"));
	//m_show_all_button->a_text_color->set_value(QColor("#f8f8f8"));
	m_show_all_button->corner_radii.top_left.set_value(5.0);
	m_show_all_button->corner_radii.top_right.set_value(5.0);
	m_show_all_button->corner_radii.bottom_left.set_value(5.0);
	m_show_all_button->corner_radii.bottom_right.set_value(5.0);

	m_show_primary_button->a_fill.set_value(QColor("#61ad50"));
	m_show_primary_button->a_hover_fill.set_value(QColor("#6fc65b"));
	//m_show_primary_button->set_attribute_value("text_color", QColor("#f8f8f8"));
	m_show_primary_button->corner_radii.top_left.set_value(5.0);
	m_show_primary_button->corner_radii.top_right.set_value(5.0);
	m_show_primary_button->corner_radii.bottom_left.set_value(5.0);
	m_show_primary_button->corner_radii.bottom_right.set_value(5.0);
}

void CustomizePanel::replace_all_fill_awidgets_attrs_with(FillAW* control_fill_aw)
{
	for (FillAW* fill_aw : m_fill_awidgets)
		fill_aw->entangle_with(control_fill_aw);
}

void CustomizePanel::replace_all_number_awidgets_attrs_with(NumberAW* control_number_aw)
{
	for (NumberAW* number_aw : m_number_awidgets)
		number_aw->entangle_with(control_number_aw);
}

void CustomizePanel::replace_all_state_awidgets_attrs_with(StateAW* control_state_aw)
{
	for (StateAW* state_aw : m_state_awidgets)
		state_aw->entangle_with(control_state_aw);
}

void CustomizePanel::replace_all_widget_buttons_attrs_with(Button* control_widget_button)
{
	for (Button* widget_button : m_widget_buttons)
		widget_button->entangle_with(control_widget_button);
}

void CustomizePanel::replace_all_corner_radii_aw_attrs_with(CornerRadiiAW* control_corner_radii_aw)
{
	for (CornerRadiiAW* corner_radii_aw : m_corner_radii_awidgets)
		corner_radii_aw->entangle_with(control_corner_radii_aw);
}

void CustomizePanel::setup_layout()
{
	if (!m_layout_setup)
	{
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
		m_attributes_layout->addSpacing(8);

		// Widgets Layout

		QHBoxLayout* hbox2 = new QHBoxLayout;

		hbox2->setContentsMargins(6, 0, 0, 0);
		hbox2->setSpacing(0);
		hbox2->addWidget(m_widgets_label);
		hbox2->addStretch();
		hbox2->activate();

		m_widget_buttons_layout->setContentsMargins(27, 0, 0, 0);
		m_widget_buttons_layout->setSpacing(10);

		m_widgets_layout->setContentsMargins(0, 0, 0, 0);
		m_widgets_layout->setSpacing(15);
		m_widgets_layout->addLayout(hbox2);
		m_widgets_layout->addLayout(m_widget_buttons_layout);

		// Main Layout

		QVBoxLayout* main_layout = new QVBoxLayout;

		main_layout->setContentsMargins(10, 17, 10, 18);
		main_layout->setSpacing(0);
		main_layout->addLayout(m_attributes_layout);
		main_layout->addSpacing(24);
		main_layout->addLayout(m_widgets_layout);
		main_layout->addStretch();
		main_layout->activate();

		setLayout(main_layout);

		m_layout_setup = true;
	}
}
