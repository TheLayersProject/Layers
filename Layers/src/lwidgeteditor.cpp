#include <Layers/lwidgeteditor.h>

#include <QApplication>
#include <QIntValidator>

#include <Layers/lcalculate.h>
#include <Layers/lmainwindow.h>
#include <Layers/ldialog.h>
#include <Layers/lradiobutton.h>

#include "lthemeeditor.h"

//using Layers::LAttributeEditor;
using Layers::LButton;
using Layers::LWidgetEditor;
using Layers::LLabel;
using Layers::LThemeable;

LWidgetEditor::LWidgetEditor(LThemeable* themeable, LThemeEditor* parent_theme_editor, QWidget* parent) :
	m_themeable{ themeable }, LWidget(parent)
{
	setFixedWidth(300);

	m_control_attr_editor->hide();
	m_control_attr_editor_group->hide();
	m_control_widget_button->hide();
	m_control_widget_button_group->hide();

	m_attributes_label->set_name("Attributes Label");
	m_attributes_label->set_font_size(17);

	m_widgets_label->set_name("Widgets Label");
	m_widgets_label->set_font_size(17);

	if (m_themeable->child_themeables().isEmpty())
		m_widgets_label->hide();
	else
	{
		QMap<QString, QWidget*> organized_widgets = QMap<QString, QWidget*>();

		QList<LWidgetButton*> button_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> dialog_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> label_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> line_editor_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> menu_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> radio_button_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> slider_widget_buttons = QList<LWidgetButton*>();
		QList<LWidgetButton*> window_widget_buttons = QList<LWidgetButton*>();

		for (LThemeable* child_themeable : m_themeable->child_themeables())
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

			if (child_themeable->name())
			{
				LWidgetButton* widget_button;

				if (child_themeable->icon())
					widget_button = new LWidgetButton(*child_themeable->icon(), *child_themeable->name());
				else
					widget_button = new LWidgetButton(*child_themeable->name());

				widget_button->entangle_with(m_control_widget_button);

				QObject::connect(widget_button, &LWidgetButton::clicked,
					[child_themeable, parent_theme_editor] {
						parent_theme_editor->edit_themeable(child_themeable);
					});

				if (dynamic_cast<LButton*>(child_themeable))
					button_widget_buttons.append(widget_button);

				else if (dynamic_cast<LDialog*>(child_themeable))
					dialog_widget_buttons.append(widget_button);

				else if (dynamic_cast<LLabel*>(child_themeable))
					label_widget_buttons.append(widget_button);

				else if (dynamic_cast<LLineEditor*>(child_themeable))
					line_editor_widget_buttons.append(widget_button);

				else if (dynamic_cast<LRadioButton*>(child_themeable))
					radio_button_widget_buttons.append(widget_button);

				else if (dynamic_cast<LMiniSlider*>(child_themeable))
					slider_widget_buttons.append(widget_button);

				else if (dynamic_cast<LMainWindow*>(child_themeable))
					window_widget_buttons.append(widget_button);

				else
					organized_widgets[widget_button->label_text()] = widget_button;
			}
		}

		if (button_widget_buttons.size() == 1)
			organized_widgets[button_widget_buttons.first()->label_text()] = button_widget_buttons.first();
		else if (!button_widget_buttons.isEmpty())
			organized_widgets["Buttons"] = new LWidgetButtonGroup("Buttons", button_widget_buttons);

		if (dialog_widget_buttons.size() == 1)
			organized_widgets[dialog_widget_buttons.first()->label_text()] = dialog_widget_buttons.first();
		else if (!dialog_widget_buttons.isEmpty())
			organized_widgets["Dialogs"] = new LWidgetButtonGroup("Dialogs", dialog_widget_buttons);

		if (label_widget_buttons.size() == 1)
			organized_widgets[label_widget_buttons.first()->label_text()] = label_widget_buttons.first();
		else if (!label_widget_buttons.isEmpty())
			organized_widgets["Labels"] = new LWidgetButtonGroup("Labels", label_widget_buttons);

		if (line_editor_widget_buttons.size() == 1)
			organized_widgets[line_editor_widget_buttons.first()->label_text()] = line_editor_widget_buttons.first();
		else if (!line_editor_widget_buttons.isEmpty())
			organized_widgets["Line Editors"] = new LWidgetButtonGroup("Line Editors", line_editor_widget_buttons);

		if (radio_button_widget_buttons.size() == 1)
			organized_widgets[radio_button_widget_buttons.first()->label_text()] = radio_button_widget_buttons.first();
		else if (!radio_button_widget_buttons.isEmpty())
			organized_widgets["Radio Buttons"] = new LWidgetButtonGroup("Radio Buttons", radio_button_widget_buttons);

		if (slider_widget_buttons.size() == 1)
			organized_widgets[slider_widget_buttons.first()->label_text()] = slider_widget_buttons.first();
		else if (!slider_widget_buttons.isEmpty())
			organized_widgets["Sliders"] = new LWidgetButtonGroup("Sliders", slider_widget_buttons);

		if (window_widget_buttons.size() == 1)
			organized_widgets[window_widget_buttons.first()->label_text()] = window_widget_buttons.first();
		else if (!window_widget_buttons.isEmpty())
			organized_widgets["Windows"] = new LWidgetButtonGroup("Windows", window_widget_buttons);

		for (QWidget* widget : organized_widgets)
		{
			if (LWidgetButton* widget_button = dynamic_cast<LWidgetButton*>(widget))
				add_widget_button(widget_button);
			else if (LWidgetButtonGroup* widget_button_group = dynamic_cast<LWidgetButtonGroup*>(widget))
				add_widget_button_group(widget_button_group);
		}
	}

	init_layout();

	if (!m_themeable->child_attributes().isEmpty())
		init_attribute_editors();
	else
	{
		m_attributes_label->hide();

		m_attributes_label_layout->setContentsMargins(0, 0, 0, 0);
		m_widgets_layout->setContentsMargins(0, 5, 0, 0);
	}
}

LWidgetEditor::~LWidgetEditor()
{
	//for (LWidgetButton* widget_button : m_widget_buttons)
	//	widget_button->deleteLater();
}

void LWidgetEditor::add_widget_button(LWidgetButton* button)
{
	//m_widget_buttons.append(button);

	m_widget_buttons_layout->addWidget(button);
}

void LWidgetEditor::add_widget_button_group(LWidgetButtonGroup* button_group)
{
	button_group->entangle_with(m_control_widget_button_group);

	m_widget_buttons_layout->addWidget(button_group);
}

LThemeable* LWidgetEditor::themeable() const
{
	return m_themeable;
}

void LWidgetEditor::init_attribute_editors()
{
	QMap<QString, QWidget*> organized_widgets;
	QMap<QString, LAttributeEditorGroup*> attr_editor_groups;

	for (const QString& group_name : m_themeable->attribute_group_names())
	{
		LAttributeEditorGroup* attr_editor_group =
			new LAttributeEditorGroup(group_name);

		attr_editor_group->entangle_with(m_control_attr_editor);
		attr_editor_groups[group_name] = attr_editor_group;
		organized_widgets[group_name] = attr_editor_group;
	}

	for (LAttribute* attr : m_themeable->child_attributes())
	{
		LAttributeEditor* attr_editor = new LAttributeEditor(attr);
		attr_editor->entangle_with(m_control_attr_editor);

		if (attr->name().contains("."))
		{
			QString group_name = attr->name().split(".").first();

			attr_editor_groups[group_name]->add_attribute_editor(attr_editor);
		}
		else
			organized_widgets[attr->name()] = attr_editor;
	}

	for (QWidget* widget : organized_widgets)
		m_attributes_layout->addWidget(widget);
}

void LWidgetEditor::init_layout()
{
	if (!m_layout_setup)
	{
		// Attribute Layout HBox 1

		m_attributes_label_layout->setContentsMargins(6, 0, 0, 8);
		m_attributes_label_layout->setSpacing(0);
		m_attributes_label_layout->addWidget(m_attributes_label);
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
