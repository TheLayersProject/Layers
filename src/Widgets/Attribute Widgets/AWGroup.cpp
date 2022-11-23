#include "../../../include/AttributeWidgets.h"
#include "../../../include/calculate.h"

using Layers::AWGroup;

AWGroup::AWGroup(const QString& label_text, QWidget* parent) :
	m_label{ new Label(label_text) }, AttributeWidget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_font_size(16);
	m_label->set_padding(17, 7, 0, 0);

	m_collapse_button->set_name("collapse_button");
	m_collapse_button->set_proper_name("Collapse Button");

	connect(m_collapse_button, &Button::clicked, [this] {
		if (m_collapsed)
		{
			m_widgets_vbox->setContentsMargins(10, 0, 10, 10);

			//int new_height = 45;

			for (AttributeWidget* attribute_widget : m_child_attribute_widgets)
			{
				//new_height += attribute_widget->height();

				attribute_widget->show();
			}

			//new_height += (m_child_attribute_widgets.count() - 1) * m_widgets_vbox->spacing();

			//new_height += m_widgets_vbox->contentsMargins().bottom();

			//setFixedHeight(new_height);

			m_collapsed = false;
		}
		else
		{
			m_widgets_vbox->setContentsMargins(0, 0, 0, 0);

			for (AttributeWidget* attribute_widget : m_child_attribute_widgets)
			{
				attribute_widget->hide();
			}

			//setFixedHeight(45);

			m_collapsed = true;
		}
	});

	setup_layout();
}

void AWGroup::add_attribute_widget(AttributeWidget* attribute_widget)
{
	m_widgets_vbox->addWidget(attribute_widget);

	m_child_attribute_widgets.append(attribute_widget);

	if (m_collapsed) attribute_widget->hide();
}

void AWGroup::replace_all_attributes_with(AWGroup* aw_group)
{
	Widget::replace_all_attributes_with(aw_group);

	if (m_collapse_button) m_collapse_button->replace_all_attributes_with(aw_group->m_collapse_button);
	if (m_label) m_label->replace_all_attributes_with(aw_group->m_label);
}

void AWGroup::set_current_editting_state(const QString& state)
{
	for (AttributeWidget* attribute_widget : m_child_attribute_widgets)
		attribute_widget->set_current_editting_state(state);
}

void AWGroup::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_label);
	store_child_themeable_pointer(m_collapse_button);
}

void AWGroup::setup_layout()
{
	QHBoxLayout* top_hbox = new QHBoxLayout;

	top_hbox->setContentsMargins(8, 0, 8, 0);
	top_hbox->setSpacing(0);
	top_hbox->addStretch();
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
