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

#include <Layers/ltab.h>

#include <QEvent>
#include <QMouseEvent>

using Layers::LButton;
using Layers::LLabel;
using Layers::LStatePool;
using Layers::LTab;

LTab::LTab(const LGraphic& icon, const QString& text, QWidget* parent) :
	m_icon_label{ new LLabel(icon) },
	m_text_label{ new LLabel(text) },
	LWidget(parent)
{
	init();
}

LTab::LTab(const QString& text, QWidget* parent) :
	m_text_label{ new LLabel(text) },
	LWidget(parent)
{
	init();
}

LButton* LTab::close_button() const
{
	return m_close_button;
}

LLabel* LTab::icon_label() const
{
	return m_icon_label;
}

LStatePool* LTab::status_states() const
{
	return m_status_states;
}

LLabel* LTab::text_label() const
{
	return m_text_label;
}

bool LTab::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress &&
		!m_close_button->underMouse())
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			emit clicked();
		}
	}

	LWidget::eventFilter(object, event);

	return false;
}

void LTab::init()
{
	add_state_pool(m_status_states);
	init_attributes();
	init_layout();
	installEventFilter(this);

	m_status_states->set_state("Inactive");

	if (m_icon_label)
	{
		m_icon_label->setAlignment(Qt::AlignCenter);
		m_icon_label->setMinimumWidth(42);
		m_icon_label->setObjectName("Icon");
	}

	m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_text_label->setObjectName("Text Label");
	m_text_label->set_font_size(12);

	m_close_button->setObjectName("Close Button");

	connect(m_close_button, &LButton::clicked,
		[this] { emit closed(); });
}

void LTab::init_attributes()
{
	m_fill->set_value(QColor("#36393f"));
	m_fill->create_override("Active", QColor("#25272b"));

	corner_radii_top_left()->set_value(5.0);
	corner_radii_top_right()->set_value(5.0);

	m_text_label->text_color()->set_value(QColor("#e3e3e3"));

	if (m_icon_label)
		if (LSvgRenderer* renderer = m_icon_label->graphic()->svg_renderer())
			renderer->color()->set_value(QColor("#e3e3e3"));

	m_close_button->
		graphic_label()->
			graphic()->svg_renderer()->color()->set_value(QColor("#5f5f5f"));
}

void LTab::init_layout()
{
	main_layout->setContentsMargins(2, 0, 4, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_icon_label);
	main_layout->addWidget(m_text_label);
	main_layout->addWidget(m_close_button);

	setLayout(main_layout);
}
