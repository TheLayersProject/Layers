#include "AttributeEditorGroup.h"

#include "calculate.h"

using Layers::AttributeEditorGroup;

AttributeEditorGroup::AttributeEditorGroup(AttributeGroup* attr_group, QWidget* parent) :
	AttributeEditor(attr_group, parent)
{
	init_attributes();

	set_name("aw_group");

	if (attr_group)
		m_label->setText(attr_group->capitalized_name());
	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_font_size(14);
	m_label->set_padding(0, 7, 0, 0);

	m_collapse_button->set_name("collapse_button");
	m_collapse_button->set_proper_name("Collapse Button");

	connect(m_collapse_button, &Button::clicked, [this] {
		if (m_collapsed)
			set_collapsed(false);
		else
			set_collapsed();
	});

	connect(m_disabled_toggle, &ToggleSwitch::toggled_event, [this] {
		if (m_disabled_toggle->toggled())
		{
			m_collapse_button->show();

			if (m_collapsed)
			{
				set_collapsed(false);
				m_collapse_button->toggle_graphics();
			}

			m_entity->set_disabled(false);
		}
		else
		{
			m_collapse_button->hide();

			if (!m_collapsed)
			{
				set_collapsed();
				m_collapse_button->toggle_graphics();
			}

			m_entity->set_disabled();

			emit widget_disabled();
		}
		});

	if (attr_group)
	{
		if (!attr_group->disabled())
			m_disabled_toggle->toggle(false);
		else
			m_collapse_button->hide();
	}

	setup_layout();
}

void AttributeEditorGroup::add_modifier_widget(AttributeEditor* attribute_widget)
{
	attribute_widget->disable_toggle()->hide();
	attribute_widget->toggle_label_separator()->hide();

	m_widgets_vbox->addWidget(attribute_widget);

	m_child_attribute_widgets.append(attribute_widget);

	if (m_collapsed) attribute_widget->hide();
}

void AttributeEditorGroup::set_collapsed(bool collapsed)
{
	if (collapsed)
	{
		m_widgets_vbox->setContentsMargins(0, 0, 0, 0);

		for (AttributeEditor* attribute_widget : m_child_attribute_widgets)
			attribute_widget->hide();

		m_collapsed = true;
	}
	else
	{
		m_widgets_vbox->setContentsMargins(10, 0, 10, 10);

		for (AttributeEditor* attribute_widget : m_child_attribute_widgets)
			attribute_widget->show();

		m_collapsed = false;
	}
}

//bool AttributeEditorGroup::disabled() const
//{
//	for (Attribute* attribute : m_attr_group->attributes())
//		if (attribute->disabled())
//			return true;
//
//	return false;
//}

void AttributeEditorGroup::set_current_editting_state(const QString& state)
{
	for (AttributeEditor* attribute_widget : m_child_attribute_widgets)
		attribute_widget->set_current_editting_state(state);
}

void AttributeEditorGroup::setup_layout()
{
	QHBoxLayout* top_hbox = new QHBoxLayout;

	top_hbox->setContentsMargins(8, 0, 8, 0);
	top_hbox->setSpacing(0);
	//top_hbox->addStretch();
	top_hbox->addWidget(m_disabled_toggle);
	top_hbox->addSpacing(16);
	top_hbox->addWidget(m_label);
	top_hbox->addWidget(m_collapse_button);
	top_hbox->addStretch();

	m_widgets_vbox->setContentsMargins(0, 0, 0, 0);
	m_widgets_vbox->setSpacing(3);

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addLayout(top_hbox);
	main_layout->addLayout(m_widgets_vbox);

	setLayout(main_layout);
}
