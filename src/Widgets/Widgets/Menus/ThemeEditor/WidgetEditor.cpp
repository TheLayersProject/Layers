#include "WidgetEditor.h"

#include "calculate.h"
#include "Menu.h"
#include "Window.h"

#include "Widgets/Widgets/AttributeEditors/AttributeEditor.h"
#include "Widgets/Widgets/AttributeEditors/ColorEditor.h"
#include "Widgets/Widgets/AttributeEditors/CornerRadiiEditor.h"
#include "Widgets/Widgets/AttributeEditors/FillEditor.h"
#include "Widgets/Widgets/AttributeEditors/NumberEditor.h"
#include "Widgets/Widgets/AttributeEditors/StateEditor.h"

#include <QApplication>
#include <QIntValidator>

using Layers::AttributeEditor;
using Layers::Button;
using Layers::WidgetEditor;
using Layers::Label;

WidgetEditor::WidgetEditor(Themeable* themeable, bool init_buttons, QWidget* parent) :
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
		for (AttributeEditor* aw : m_modifier_widgets)
			aw->show();

		m_show_all_button->hide();
		m_show_primary_button->show();
	});

	connect(m_show_primary_button, &Button::clicked, [this] {
		for (AttributeEditor* aw : m_modifier_widgets)
			if (aw->disabled())
				aw->hide();

		m_show_all_button->show();
		m_show_primary_button->hide();
	});

	if (m_themeable->child_themeables().isEmpty()) m_widgets_label->hide();
	else
	{
		if (init_buttons)
		{
			QMap<QString, QWidget*> organized_widgets = QMap<QString, QWidget*>();

			QList<WidgetButton*> button_widget_buttons = QList<WidgetButton*>();
			QList<WidgetButton*> label_widget_buttons = QList<WidgetButton*>();
			QList<WidgetButton*> menu_widget_buttons = QList<WidgetButton*>();
			//QList<WidgetButton*> ungrouped_widget_buttons = QList<WidgetButton*>();

			for (Themeable* child_themeable : m_themeable->child_themeables())
			{
				// Check if themeable has a proper name to determine that it is customizable
				if (child_themeable->proper_name()) // TODO: Consider a Themeable::is_customizable() function so this is clearer
				{
					WidgetButton* widget_button;

					if (child_themeable->icon())
						widget_button = new WidgetButton(new Graphic(*child_themeable->icon()), *child_themeable->proper_name());
					else
						widget_button = new WidgetButton(*child_themeable->proper_name());

					QObject::connect(widget_button, &WidgetButton::clicked, [child_themeable] {
						static_cast<Window*>(QApplication::activeWindow()
							)->open_themeable_customization_widget(
								new WidgetEditor(child_themeable));
						});

					if (dynamic_cast<Button*>(child_themeable))
						button_widget_buttons.append(widget_button);

					else if (dynamic_cast<Label*>(child_themeable))
						label_widget_buttons.append(widget_button);

					else if (dynamic_cast<Menu*>(child_themeable))
						menu_widget_buttons.append(widget_button);

					else
						organized_widgets[widget_button->label_text()] = widget_button;
				}
			}

			if (button_widget_buttons.size() == 1)
				organized_widgets[button_widget_buttons.first()->label_text()] = button_widget_buttons.first();
			else if (!button_widget_buttons.isEmpty())
				organized_widgets["Buttons"] = new WidgetButtonGroup("Buttons", button_widget_buttons);

			if (label_widget_buttons.size() == 1)
				organized_widgets[label_widget_buttons.first()->label_text()] = label_widget_buttons.first();
			else if (!label_widget_buttons.isEmpty())
				organized_widgets["Labels"] = new WidgetButtonGroup("Labels", label_widget_buttons);

			if (menu_widget_buttons.size() == 1)
				organized_widgets[menu_widget_buttons.first()->label_text()] = menu_widget_buttons.first();
			else if (!menu_widget_buttons.isEmpty())
				organized_widgets["Menus"] = new WidgetButtonGroup("Menus", menu_widget_buttons);

			//if (label_widget_buttons.size() == 1)
			//	ungrouped_widget_buttons.append(label_widget_buttons);
			//else if (!label_widget_buttons.isEmpty())
			//	add_widget_button_group(new WidgetButtonGroup("Labels", label_widget_buttons));

			//if (menu_widget_buttons.size() == 1)
			//	ungrouped_widget_buttons.append(menu_widget_buttons);
			//else if (!menu_widget_buttons.isEmpty())
			//	add_widget_button_group(new WidgetButtonGroup("Menus", menu_widget_buttons));

			//if (!ungrouped_widget_buttons.isEmpty())
			//	for (WidgetButton* widget_button : ungrouped_widget_buttons)
			//		add_widget_button(widget_button);

			for (QWidget* widget : organized_widgets)
			{
				if (WidgetButton* widget_button = dynamic_cast<WidgetButton*>(widget))
					add_widget_button(widget_button);
				else if (WidgetButtonGroup* widget_button_group = dynamic_cast<WidgetButtonGroup*>(widget))
					add_widget_button_group(widget_button_group);
			}
		}
	}

	setup_layout();

	if (!m_themeable->entities().isEmpty())
		init_attribute_widgets();
	else
	{
		m_attributes_label->hide();
		m_show_all_button->hide();

		m_attributes_label_layout->setContentsMargins(0, 0, 0, 0);
		m_widgets_layout->setContentsMargins(0, 5, 0, 0);
	}
}

WidgetEditor::~WidgetEditor()
{
	for (WidgetButton* widget_button : m_widget_buttons)
		widget_button->deleteLater();
}

void WidgetEditor::add_modifier_widget(AttributeEditor* attribute_widget)
{
	//add_child_themeable_pointer(attribute_widget);
	m_modifier_widgets.append(attribute_widget);

	// TEMP
	m_attributes_layout->addWidget(attribute_widget);
	//
	
	//if (attribute_widget->attribute())
	//{
	//	m_stateful_attribute_widgets.append(attribute_widget);
	//	m_stateful_attributes_layout->addWidget(attribute_widget);

	//	if (ColorEditor* caw = dynamic_cast<ColorEditor*>(attribute_widget))
	//		connect(
	//			m_state_combobox, SIGNAL(current_item_changed(const QString&)),
	//			caw->color_control(), SLOT(set_current_editting_state(const QString&)));

	//	else if (CornerRadiiEditor* craw = dynamic_cast<CornerRadiiEditor*>(attribute_widget))
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

void WidgetEditor::add_widget_button(WidgetButton* button)
{
	m_widget_buttons.append(button);

	m_widget_buttons_layout->addWidget(button);
}

void WidgetEditor::add_widget_button_group(WidgetButtonGroup* button_group)
{
	m_widget_button_groups.append(button_group);

	for (WidgetButton* widget_button : button_group->widget_buttons())
		m_widget_buttons.append(widget_button);

	m_widget_buttons_layout->addWidget(button_group);
}

void WidgetEditor::init_attribute_widgets()
{
	if (m_themeable->is_multi_valued()) // TODO: IF THEMEABLE CONTAINS STATE
	{
		m_state_aw = new StateEditor;
		m_state_aw->populate_state_combobox(m_themeable->states());
		m_state_awidgets.append(m_state_aw);

		add_modifier_widget(m_state_aw);
	}

	for (Entity* entity : m_themeable->entities())
	{
		if (Attribute* attribute = dynamic_cast<Attribute*>(entity))
		{
			AttributeEditor* aw = nullptr;

			if (QString(attribute->typeName()) == "double")
			{
				aw = new NumberEditor(attribute, new QIntValidator(0, 30));
				m_number_awidgets.append(dynamic_cast<NumberEditor*>(aw));
			}
			else if ( // TODO: Decide how to differ between when to use a FillControl or a ColorControl
				// TEMP: For now, we will assume all use FillControl
				QString(attribute->typeName()) == "QColor" ||
				QString(attribute->typeName()) == "QList<std::pair<double,QColor>>"
				)
			{
				aw = new FillEditor(attribute);
				m_fill_awidgets.append(dynamic_cast<FillEditor*>(aw));
			}

			if (attribute->disabled())
				aw->hide();

			if (attribute->is_multi_valued())
			{
				m_state_aw->add_modifier_widget(aw);

				//connect(
				//	m_state_aw->state_combobox(), SIGNAL(current_item_changed(const QString&)),
				//	aw, SLOT(set_current_editting_state(const QString&)));
			}
			else add_modifier_widget(aw);

			connect(aw, &AttributeEditor::widget_disabled, [this, aw] {
				if (m_show_all_button->isVisible())
					aw->hide();
				});
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
		{
			if (attr_group->name().endsWith("corner_radii"))
			{
				CornerRadiiEditor* corner_radii_aw = new CornerRadiiEditor(dynamic_cast<CornerRadiiAttributes*>(attr_group));
				m_corner_radii_awidgets.append(corner_radii_aw);

				if (attr_group->disabled())
					corner_radii_aw->hide();

				if (attr_group->is_multi_valued()) m_state_aw->add_modifier_widget(corner_radii_aw);
				else add_modifier_widget(corner_radii_aw);

				connect(corner_radii_aw, &AttributeEditor::widget_disabled, [this, corner_radii_aw] {
					if (m_show_all_button->isVisible())
						corner_radii_aw->hide();
					});
			}
			else
			{
				/* TODO: Now that AttributeEditorGroup requires the attr_group data,
				   it could initialize its own AttributeWidgets */
				AttributeEditorGroup* aw_group = new AttributeEditorGroup(attr_group);
				m_aw_groups.append(aw_group);

				bool hide_aw_group = true;

				for (Attribute* attribute : attr_group->attributes())
				{
					AttributeEditor* aw = nullptr;

					if (QString(attribute->typeName()) == "double")
					{
						aw = new NumberEditor(attribute, new QIntValidator(0, 30));
						m_number_awidgets.append(dynamic_cast<NumberEditor*>(aw));
					}
					else if ( // TODO: Decide how to differ between when to use a FillControl or a ColorControl
						// TEMP: For now, we will assume all use FillControl
						QString(attribute->typeName()) == "QColor" ||
						QString(attribute->typeName()) == "QList<std::pair<double,QColor>>"
						)
					{
						aw = new FillEditor(attribute);
						m_fill_awidgets.append(dynamic_cast<FillEditor*>(aw));
					}

					aw_group->add_modifier_widget(aw);
				}

				if (attr_group->disabled())
					aw_group->hide();

				if (attr_group->is_multi_valued()) m_state_aw->add_modifier_widget(aw_group);
				else add_modifier_widget(aw_group);

				connect(aw_group, &AttributeEditor::widget_disabled, [this, aw_group] {
					if (m_show_all_button->isVisible())
						aw_group->hide();
					});
			}
		}
	}
}

void WidgetEditor::replace_all_aw_group_attrs_with(AttributeEditorGroup* control_aw_group)
{
	for (AttributeEditorGroup* aw_group : m_aw_groups)
		aw_group->entangle_with(control_aw_group);
}

void WidgetEditor::replace_all_color_awidgets_attrs_with(ColorEditor* control_color_aw)
{
	for (ColorEditor* color_aw : m_color_awidgets)
		color_aw->entangle_with(control_color_aw);
}

void WidgetEditor::init_attributes()
{
	// TODO: re-enable
	m_fill->set_disabled();

	m_show_all_button->fill()->set_value(QColor("#61ad50"));
	m_show_all_button->hover_fill()->set_value(QColor("#6fc65b"));
	//m_show_all_button->text_color()->set_value(QColor("#f8f8f8"));
	m_show_all_button->corner_radii()->top_left()->set_value(5.0);
	m_show_all_button->corner_radii()->top_right()->set_value(5.0);
	m_show_all_button->corner_radii()->bottom_left()->set_value(5.0);
	m_show_all_button->corner_radii()->bottom_right()->set_value(5.0);

	m_show_primary_button->fill()->set_value(QColor("#61ad50"));
	m_show_primary_button->hover_fill()->set_value(QColor("#6fc65b"));
	//m_show_primary_button->set_attribute_value("text_color", QColor("#f8f8f8"));
	m_show_primary_button->corner_radii()->top_left()->set_value(5.0);
	m_show_primary_button->corner_radii()->top_right()->set_value(5.0);
	m_show_primary_button->corner_radii()->bottom_left()->set_value(5.0);
	m_show_primary_button->corner_radii()->bottom_right()->set_value(5.0);
}

void WidgetEditor::replace_all_fill_awidgets_attrs_with(FillEditor* control_fill_aw)
{
	for (FillEditor* fill_aw : m_fill_awidgets)
		fill_aw->entangle_with(control_fill_aw);
}

void WidgetEditor::replace_all_number_awidgets_attrs_with(NumberEditor* control_number_aw)
{
	for (NumberEditor* number_aw : m_number_awidgets)
		number_aw->entangle_with(control_number_aw);
}

void WidgetEditor::replace_all_state_awidgets_attrs_with(StateEditor* control_state_aw)
{
	for (StateEditor* state_aw : m_state_awidgets)
		state_aw->entangle_with(control_state_aw);
}

void WidgetEditor::replace_all_widget_buttons_attrs_with(WidgetButton* control_widget_button)
{
	for (WidgetButton* widget_button : m_widget_buttons)
		widget_button->entangle_with(control_widget_button);
}

void WidgetEditor::replace_all_widget_button_groups_attrs_with(WidgetButtonGroup* control_widget_button_group)
{
	for (WidgetButtonGroup* widget_button_group : m_widget_button_groups)
		widget_button_group->entangle_with(control_widget_button_group);
}

void WidgetEditor::replace_all_corner_radii_aw_attrs_with(CornerRadiiEditor* control_corner_radii_aw)
{
	for (CornerRadiiEditor* corner_radii_aw : m_corner_radii_awidgets)
		corner_radii_aw->entangle_with(control_corner_radii_aw);
}

void WidgetEditor::setup_layout()
{
	if (!m_layout_setup)
	{
		// Attribute Layout HBox 1

		m_attributes_label_layout->setContentsMargins(6, 0, 0, 8);
		m_attributes_label_layout->setSpacing(0);
		m_attributes_label_layout->addWidget(m_attributes_label);
		m_attributes_label_layout->addStretch();
		m_attributes_label_layout->addWidget(m_show_all_button);
		m_attributes_label_layout->addWidget(m_show_primary_button);
		m_attributes_label_layout->addStretch();

		// Attributes Layout

		m_attributes_layout->setContentsMargins(0, 0, 0, 0);
		m_attributes_layout->setSpacing(3);
		m_attributes_layout->addLayout(m_attributes_label_layout);

		// Widgets Layout

		QHBoxLayout* hbox2 = new QHBoxLayout;

		hbox2->setContentsMargins(6, 0, 0, 0);
		hbox2->setSpacing(0);
		hbox2->addWidget(m_widgets_label);
		hbox2->addStretch();
		hbox2->activate();

		m_widget_buttons_layout->setContentsMargins(0, 0, 0, 0);
		m_widget_buttons_layout->setSpacing(3);

		m_widgets_layout->setContentsMargins(0, 24, 0, 0);
		m_widgets_layout->setSpacing(15);
		m_widgets_layout->addLayout(hbox2);
		m_widgets_layout->addLayout(m_widget_buttons_layout);

		// Main Layout

		QVBoxLayout* main_layout = new QVBoxLayout;

		main_layout->setContentsMargins(10, 17, 10, 18);
		main_layout->setSpacing(0);
		main_layout->addLayout(m_attributes_layout);
		main_layout->addLayout(m_widgets_layout);
		main_layout->addStretch();
		main_layout->activate();

		setLayout(main_layout);

		m_layout_setup = true;
	}
}
