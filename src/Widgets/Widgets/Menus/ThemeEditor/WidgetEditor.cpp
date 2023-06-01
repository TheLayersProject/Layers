#include "WidgetEditor.h"

#include "calculate.h"
#include "Dialog.h"
#include "MainWindow.h"

#include "ThemeEditor.h"

#include <QApplication>
#include <QIntValidator>

using Layers::AttributeEditor;
using Layers::Button;
using Layers::WidgetEditor;
using Layers::Label;
using Layers::Themeable;

WidgetEditor::WidgetEditor(Themeable* themeable, ThemeEditor* parent_theme_editor, QWidget* parent) :
	m_themeable{ themeable }, Widget(parent)
{
	init_attributes();
	set_name("widget_editor");
	//set_proper_name("Widget Editor");
	setFixedWidth(300);

	m_control_attribute_editor_group->hide();
	m_control_corner_radii_editor->hide();
	m_control_fill_editor->hide();
	m_control_number_editor->hide();
	m_control_state_editor->hide();
	m_control_widget_button->hide();
	m_control_widget_button_group->hide();

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

	m_show_enabled_button->set_name("show_enabled_button");
	m_show_enabled_button->set_proper_name("'Show Enabled' Button");
	m_show_enabled_button->disable_text_hover_color();
	m_show_enabled_button->set_margin(0, 7, 0, 7);
	m_show_enabled_button->set_text_padding(3, 5, 0, 0);
	m_show_enabled_button->hide();

	connect(m_show_all_button, &Button::clicked, [this] {
		for (AttributeEditor* aw : m_modifier_widgets)
			aw->show();

		m_show_all_button->hide();
		m_show_enabled_button->show();
	});

	connect(m_show_enabled_button, &Button::clicked, [this] {
		for (AttributeEditor* aw : m_modifier_widgets)
			if (aw->disabled())
				aw->hide();

		m_show_all_button->show();
		m_show_enabled_button->hide();
	});

	if (m_themeable->child_themeables().isEmpty())
		m_widgets_label->hide();
	else
	{
		QMap<QString, QWidget*> organized_widgets = QMap<QString, QWidget*>();

		QList<WidgetButton*> button_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> dialog_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> editor_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> label_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> line_editor_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> menu_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> slider_widget_buttons = QList<WidgetButton*>();
		QList<WidgetButton*> window_widget_buttons = QList<WidgetButton*>();

		for (Themeable* child_themeable : m_themeable->child_themeables())
		{
			/*qDebug() << child_themeable->tag();

			if (QObject* child_object = dynamic_cast<QObject*>(child_themeable))
			{
				QStringList child_hierarchy;

				const QMetaObject* meta_object = child_object->metaObject();

				while (meta_object)
				{
					QString class_name = QString(meta_object->className());

					if (class_name != "QObject" && class_name != "QWidget")
						child_hierarchy.append(class_name);

					meta_object = meta_object->superClass();
				}

				qDebug() << child_hierarchy;
				qDebug() << "";
			}*/

			// Check if themeable has a proper name to determine that it is customizable
			if (child_themeable->proper_name()) // TODO: Consider a Themeable::is_customizable() function so this is clearer
			{
				WidgetButton* widget_button;

				if (child_themeable->icon())
					widget_button = new WidgetButton(new Graphic(*child_themeable->icon()), *child_themeable->proper_name());
				else
					widget_button = new WidgetButton(*child_themeable->proper_name());

				widget_button->entangle_with(m_control_widget_button);

				QObject::connect(widget_button, &WidgetButton::clicked,
					[child_themeable, parent_theme_editor] {
						parent_theme_editor->edit_themeable(child_themeable);
					});

				if (dynamic_cast<Button*>(child_themeable))
					button_widget_buttons.append(widget_button);

				else if (dynamic_cast<Dialog*>(child_themeable))
					dialog_widget_buttons.append(widget_button);

				else if (dynamic_cast<AttributeEditor*>(child_themeable))
					editor_widget_buttons.append(widget_button);

				else if (dynamic_cast<Label*>(child_themeable))
					label_widget_buttons.append(widget_button);

				else if (dynamic_cast<LineEditor*>(child_themeable))
					line_editor_widget_buttons.append(widget_button);

				//else if (dynamic_cast<Menu*>(child_themeable))
				//	menu_widget_buttons.append(widget_button);

				else if (dynamic_cast<MiniSlider*>(child_themeable))
					slider_widget_buttons.append(widget_button);

				else if (dynamic_cast<MainWindow*>(child_themeable))
					window_widget_buttons.append(widget_button);

				else
					organized_widgets[widget_button->label_text()] = widget_button;
			}
		}

		if (button_widget_buttons.size() == 1)
			organized_widgets[button_widget_buttons.first()->label_text()] = button_widget_buttons.first();
		else if (!button_widget_buttons.isEmpty())
			organized_widgets["Buttons"] = new WidgetButtonGroup("Buttons", button_widget_buttons);

		if (dialog_widget_buttons.size() == 1)
			organized_widgets[dialog_widget_buttons.first()->label_text()] = dialog_widget_buttons.first();
		else if (!dialog_widget_buttons.isEmpty())
			organized_widgets["Dialogs"] = new WidgetButtonGroup("Dialogs", dialog_widget_buttons);

		if (editor_widget_buttons.size() == 1)
			organized_widgets[editor_widget_buttons.first()->label_text()] = editor_widget_buttons.first();
		else if (!editor_widget_buttons.isEmpty())
			organized_widgets["Editors"] = new WidgetButtonGroup("Editors", editor_widget_buttons);

		if (label_widget_buttons.size() == 1)
			organized_widgets[label_widget_buttons.first()->label_text()] = label_widget_buttons.first();
		else if (!label_widget_buttons.isEmpty())
			organized_widgets["Labels"] = new WidgetButtonGroup("Labels", label_widget_buttons);

		if (line_editor_widget_buttons.size() == 1)
			organized_widgets[line_editor_widget_buttons.first()->label_text()] = line_editor_widget_buttons.first();
		else if (!line_editor_widget_buttons.isEmpty())
			organized_widgets["Line Editors"] = new WidgetButtonGroup("Line Editors", line_editor_widget_buttons);

		if (menu_widget_buttons.size() == 1)
			organized_widgets[menu_widget_buttons.first()->label_text()] = menu_widget_buttons.first();
		else if (!menu_widget_buttons.isEmpty())
			organized_widgets["Menus"] = new WidgetButtonGroup("Menus", menu_widget_buttons);

		if (slider_widget_buttons.size() == 1)
			organized_widgets[slider_widget_buttons.first()->label_text()] = slider_widget_buttons.first();
		else if (!slider_widget_buttons.isEmpty())
			organized_widgets["Sliders"] = new WidgetButtonGroup("Sliders", slider_widget_buttons);

		if (window_widget_buttons.size() == 1)
			organized_widgets[window_widget_buttons.first()->label_text()] = window_widget_buttons.first();
		else if (!window_widget_buttons.isEmpty())
			organized_widgets["Windows"] = new WidgetButtonGroup("Windows", window_widget_buttons);

		for (QWidget* widget : organized_widgets)
		{
			if (WidgetButton* widget_button = dynamic_cast<WidgetButton*>(widget))
				add_widget_button(widget_button);
			else if (WidgetButtonGroup* widget_button_group = dynamic_cast<WidgetButtonGroup*>(widget))
				add_widget_button_group(widget_button_group);
		}
	}

	setup_layout();

	if (!m_themeable->attributes().isEmpty())
		init_attribute_editors();
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
	//for (WidgetButton* widget_button : m_widget_buttons)
	//	widget_button->deleteLater();
}

void WidgetEditor::add_attribute_editor(AttributeEditor* editor)
{
	//add_child_themeable_pointer(attribute_widget);
	m_modifier_widgets.append(editor);

	// TEMP
	m_attributes_layout->addWidget(editor);
}

AttributeEditor* WidgetEditor::create_edtior(Attribute* attribute)
{
	AttributeEditor* editor = nullptr;

	if (QString(attribute->typeName()) == "double")
	{
		editor = new NumberEditor(attribute, new QIntValidator(0, 30));
		editor->entangle_with(m_control_number_editor);
	}
	else if (
		// TODO: Decide how to differ between when to use a FillControl or a ColorControl
		// TEMP: For now, we will assume all use FillControl
		QString(attribute->typeName()) == "QColor" ||
		QString(attribute->typeName()) == "QList<std::pair<double,QColor>>"
		)
	{
		editor = new FillEditor(attribute);
		editor->entangle_with(m_control_fill_editor);
	}

	return editor;
}

void WidgetEditor::handle_editor(AbstractAttribute* abs_attr, AttributeEditor* editor)
{
	if (abs_attr->disabled())
		editor->hide();

	if (abs_attr->is_multi_valued())
		m_state_editor->add_modifier_widget(editor);
	else
		add_attribute_editor(editor);

	connect(editor, &AttributeEditor::widget_disabled, [this, editor] {
		if (m_show_all_button->isVisible())
			editor->hide();
		});
}

void WidgetEditor::add_widget_button(WidgetButton* button)
{
	//m_widget_buttons.append(button);

	m_widget_buttons_layout->addWidget(button);
}

void WidgetEditor::add_widget_button_group(WidgetButtonGroup* button_group)
{
	button_group->entangle_with(m_control_widget_button_group);

	m_widget_buttons_layout->addWidget(button_group);
}

Themeable* WidgetEditor::themeable() const
{
	return m_themeable;
}

void WidgetEditor::init_attribute_editors()
{
	if (m_themeable->is_multi_valued())
	{
		m_state_editor = new StateEditor;
		m_state_editor->entangle_with(m_control_state_editor);
		m_state_editor->populate_state_combobox(m_themeable->states());

		add_attribute_editor(m_state_editor);
	}

	for (AbstractAttribute* abs_attribute : m_themeable->attributes())
	{
		if (Attribute* attribute = dynamic_cast<Attribute*>(abs_attribute))
		{
			handle_editor(attribute, create_edtior(attribute));
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(abs_attribute))
		{
			if (CornerRadiiAttributes* corner_radii = dynamic_cast<CornerRadiiAttributes*>(attr_group))
			{
				CornerRadiiEditor* corner_radii_editor = new CornerRadiiEditor(corner_radii);
				corner_radii_editor->entangle_with(m_control_corner_radii_editor);

				handle_editor(corner_radii, corner_radii_editor);
			}
			else
			{
				AttributeEditorGroup* aw_group = new AttributeEditorGroup(attr_group);
				aw_group->entangle_with(m_control_attribute_editor_group);

				for (Attribute* attribute : attr_group->attributes())
					aw_group->add_modifier_widget(create_edtior(attribute));

				handle_editor(attr_group, aw_group);
			}
		}
	}
}

void WidgetEditor::init_attributes()
{
	m_fill->set_disabled();

	m_show_all_button->fill()->set_value(QColor("#61ad50"));
	// TODO:
	//m_show_all_button->hover_fill()->set_value(QColor("#6fc65b"));
	m_show_all_button->corner_radii()->top_left()->set_value(5.0);
	m_show_all_button->corner_radii()->top_right()->set_value(5.0);
	m_show_all_button->corner_radii()->bottom_left()->set_value(5.0);
	m_show_all_button->corner_radii()->bottom_right()->set_value(5.0);

	m_show_enabled_button->fill()->set_value(QColor("#61ad50"));
	// TODO:
	//m_show_primary_button->hover_fill()->set_value(QColor("#6fc65b"));
	m_show_enabled_button->corner_radii()->top_left()->set_value(5.0);
	m_show_enabled_button->corner_radii()->top_right()->set_value(5.0);
	m_show_enabled_button->corner_radii()->bottom_left()->set_value(5.0);
	m_show_enabled_button->corner_radii()->bottom_right()->set_value(5.0);
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
		m_attributes_label_layout->addWidget(m_show_enabled_button);
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
