#include <Layers/lstateeditor.h>

using Layers::LComboBox;
using Layers::LStateEditor;

LStateEditor::LStateEditor(QWidget* parent) : LAttributeEditor(nullptr, parent)
{
	set_name("State Editor");

	m_label->set_name("Label");
	m_label->set_font_size(16);

	m_state_combobox->set_name("State Combobox");
	m_state_combobox->setFixedSize(190, 35);

	//connect(m_state_combobox, &LComboBox::currentTextChanged, [this] {
	//	for (LAttributeEditor* aw : m_child_attribute_widgets)
	//		aw->set_current_editing_state(m_state_combobox->currentText());
	//	});

	init_layout();
}

void LStateEditor::add_attribute_editor(LAttributeEditor* attribute_editor)
{
	m_widgets_vbox->addWidget(attribute_editor);

	m_attribute_editors.append(attribute_editor);
}

LComboBox* LStateEditor::state_combobox() const
{
	return m_state_combobox;
}

void LStateEditor::populate_state_combobox(const QList<QString>& states)
{
	for (const QString& state : states)
		m_state_combobox->addItem(state);
}

void LStateEditor::init_layout()
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
