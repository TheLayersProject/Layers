#include "StateEditor.h"

#include "calculate.h"

using Layers::ComboBox;
using Layers::StateEditor;

StateEditor::StateEditor(QWidget* parent) : AttributeEditor(nullptr, parent)
{
	//init_attributes();

	set_name("state_editor");
	set_proper_name("State Editor");

	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_font_size(16);
	m_label->set_padding(0, 7, 0, 0);

	m_state_combobox->set_name("state_combobox");
	m_state_combobox->set_proper_name("State Combobox");
	m_state_combobox->setFixedSize(190, 35);

	connect(m_state_combobox, &ComboBox::currentTextChanged, [this] {
		for (AttributeEditor* aw : m_child_attribute_widgets)
			aw->set_current_editting_state(m_state_combobox->currentText());
		});

	setup_layout();
}

void StateEditor::add_modifier_widget(AttributeEditor* attribute_widget)
{
	m_widgets_vbox->addWidget(attribute_widget);

	m_child_attribute_widgets.append(attribute_widget);
}

ComboBox* StateEditor::state_combobox() const
{
	return m_state_combobox;
}

void StateEditor::populate_state_combobox(const QList<QString>& states)
{
	for (const QString& state : states)
		m_state_combobox->addItem(state);
}

void StateEditor::setup_layout()
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
