/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

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
	m_label->setObjectName("Label");
	m_label->set_font_size(12);

	m_collapse_button->setObjectName("Collapse Button");

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
