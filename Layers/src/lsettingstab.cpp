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

#include "lsettingstab.h"

#include <QIntValidator>
#include <QMouseEvent>

#include <Layers/llabel.h>

using Layers::LGraphic;
using Layers::LSettingsTab;
using Layers::LStatePool;

LSettingsTab::LSettingsTab(const LGraphic& icon, const QString& label_text, QWidget* parent) :
	m_icon_label{ new LLabel(icon) }, m_text_label { new LLabel(label_text) }, LWidget(parent)
{
	init_attributes();
	init_layout();
	add_state_pool(m_select_states);

	m_select_states->set_state("Unselected");

	connect(this, &LSettingsTab::clicked, [this]
		{
			m_select_states->set_state("Selected");
		});

	installEventFilter(this);
	setMouseTracking(true);
	setFixedHeight(60);

	setObjectName("Setting Tab");

	m_icon_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_icon_label->setObjectName("Icon Label");

	m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_text_label->setObjectName("Text Label");
	m_text_label->set_font_size(14);
}

void LSettingsTab::init_attributes()
{
	m_corner_radii_top_left->set_value(5.0);
	m_corner_radii_bottom_left->set_value(5.0);
	m_fill->set_value("#c0c0c0");
	m_fill->create_override("Selected", "#ffffff");

	m_icon_label->graphic()->svg_renderer()->color()->set_value(
		"#a0a0a4");
	m_icon_label->graphic()->svg_renderer()->color()->create_override(
		"Selected", "#000000");

	m_text_label->text_color()->set_value("#a0a0a4");
	m_text_label->text_color()->create_override("Selected", "#000000");
}

int LSettingsTab::recommended_minimum_width()
{
	return 18 + m_icon_label->sizeHint().width() + 12 + m_text_label->sizeHint().width() + 18;
}

LStatePool* LSettingsTab::select_states() const
{
	return m_select_states;
}

void LSettingsTab::set_disabled(bool cond)
{
	m_disabled = cond;
}

bool LSettingsTab::eventFilter(QObject* object, QEvent* event)
{
	if (!m_disabled)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

			if (mouse_event->button() & Qt::LeftButton)
			{
				emit clicked();
			}
		}
	}

	return false;
}

//void LSettingsTab::resizeEvent(QResizeEvent* event)
//{
//    int minimum_width = 18 + m_icon_label->width() + 12 + m_text_label->width() + 18;
//
//    if (width() < minimum_width)
//        emit under_minimum_width();
//    else
//        emit over_minimum_width();
//}

void LSettingsTab::init_layout()
{
	main_layout->setContentsMargins(18, 0, 18, 0);
	main_layout->setSpacing(12);
	main_layout->addWidget(m_icon_label);
	main_layout->addWidget(m_text_label);

	setLayout(main_layout);
}
