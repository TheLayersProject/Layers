#include <Layers/lattributeeditorgroup.h>

#include <Layers/lcalculate.h>

using Layers::LAttributeEditorGroup;

LAttributeEditorGroup::LAttributeEditorGroup(
	const QString& name, QWidget* parent
) :
	LWidget(parent)
{
	init_attributes();

	m_label->setText(name);
	m_label->set_name("Label");
	m_label->set_font_size(12);

	m_collapse_button->set_name("Collapse Button");

	connect(m_collapse_button, &LButton::clicked, [this] {
		if (m_collapsed)
			set_collapsed(false);
		else
			set_collapsed();
	});

	init_layout();
}

void LAttributeEditorGroup::add_attribute_editor(
	LAttributeEditor* attribute_editor)
{
	m_widgets_vbox->addWidget(attribute_editor);

	m_attribute_editors.append(attribute_editor);

	if (m_collapsed)
		attribute_editor->hide();
}

void LAttributeEditorGroup::init_layout()
{
	QHBoxLayout* top_hbox = new QHBoxLayout;

	top_hbox->setContentsMargins(0, 0, 0, 0);
	top_hbox->setSpacing(0);
	top_hbox->addWidget(m_collapse_button);
	top_hbox->addWidget(m_label);
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

void LAttributeEditorGroup::set_collapsed(bool collapsed)
{
	if (collapsed)
	{
		m_widgets_vbox->setContentsMargins(0, 0, 0, 0);

		for (LAttributeEditor* attribute_editor : m_attribute_editors)
			attribute_editor->hide();

		m_collapsed = true;
	}
	else
	{
		m_widgets_vbox->setContentsMargins(10, 0, 0, 10);

		for (LAttributeEditor* attribute_editor : m_attribute_editors)
			attribute_editor->show();

		m_collapsed = false;
	}
}
