#include "../../../include/AttributeWidgets.h"
#include "../../../include/calculate.h"

using Layers::Combobox;
using Layers::StateAW;

StateAW::StateAW(QWidget* parent) : AttributeWidget(nullptr, parent)
{
	init_child_themeable_list();
	init_attributes();

	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_font_size(16);
	m_label->set_padding(0, 7, 0, 0);

	m_state_combobox->set_name("state_combobox");
	m_state_combobox->set_proper_name("State Combobox");
	m_state_combobox->setFixedSize(190, 35);

	connect(m_state_combobox, &Combobox::current_item_changed, [this] {
		for (AttributeWidget* aw : m_child_attribute_widgets)
			aw->set_current_editting_state(m_state_combobox->current_item());
		});

	setup_layout();
}

void StateAW::add_attribute_widget(AttributeWidget* attribute_widget)
{
	m_widgets_vbox->addWidget(attribute_widget);

	m_child_attribute_widgets.append(attribute_widget);
}

Combobox* StateAW::state_combobox() const
{
	return m_state_combobox;
}

void StateAW::populate_state_combobox(const QList<QString>& states)
{
	for (const QString& state : states)
		m_state_combobox->add_item(state);
}

void StateAW::init_child_themeable_list()
{
	add_child_themeable_pointer(m_label);
	add_child_themeable_pointer(m_state_combobox);
}

void StateAW::setup_layout()
{
	QHBoxLayout* top_hbox = new QHBoxLayout;

	top_hbox->setContentsMargins(0, 0, 0, 0);
	top_hbox->setSpacing(0);
	top_hbox->addStretch();
	top_hbox->addWidget(m_label);
	top_hbox->addStretch();
	top_hbox->addWidget(m_state_combobox);

	m_widgets_vbox->setContentsMargins(0, 0, 0, 0);
	m_widgets_vbox->setSpacing(3);

	m_main_layout->setContentsMargins(10, 10, 10, 10);
	m_main_layout->setSpacing(7);
	m_main_layout->addLayout(top_hbox);
	m_main_layout->addLayout(m_widgets_vbox);

	setLayout(m_main_layout);
}
