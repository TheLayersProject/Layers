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

#include <Layers/lresizer.h>

#include <QMouseEvent>
#include <QPainter>

using Layers::LResizer;

LResizer::LResizer(LSizeDimension resize_dimension, QWidget* parent) :
	m_resize_dimension{ resize_dimension },
	m_icon_svg{ (resize_dimension == LSizeDimension::Height) ?
		new LSvgRenderer(":/images/resizer_icon_height.svg", this) :
		new LSvgRenderer(":/images/resizer_icon_width.svg", this) },
	QWidget(parent)
{
	add_state_pool(m_select_states);
	installEventFilter(this);
	setObjectName("Resizer");

	m_select_states->set_state("Unselected");

	if (resize_dimension == LSizeDimension::Height)
	{
		setFixedHeight(20);
		m_icon_size = QSize(26, 10);
	}
	else
	{
		setFixedWidth(20);
		m_icon_size = QSize(10, 26);
	}

	m_icon_svg->setObjectName("Icon Svg");
}

void LResizer::set_widget(QWidget* widget, int lower_limit, int upper_limit)
{
	m_widget = widget;
	m_lower_limit = lower_limit;
	m_upper_limit = upper_limit;
}

bool LResizer::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Enter)
	{
		m_select_states->set_state("Selected");
	}
	else if (event->type() == QEvent::Leave)
	{
		m_select_states->set_state("Unselected");
	}
	else if (event->type() == QMouseEvent::MouseButtonPress)
	{
		m_click_pos = QCursor::pos();

		if (m_widget)
			m_click_size = m_widget->size();
	}
	else if (event->type() == QMouseEvent::MouseMove)
	{
		if (m_widget)
		{
			QPoint cursor_delta = QCursor::pos() - m_click_pos;

			if (m_resize_dimension == LSizeDimension::Height)
			{
				int new_height = m_click_size.height() + cursor_delta.y();

				if (new_height < m_lower_limit)
					new_height = m_lower_limit;
				else if (new_height > m_upper_limit)
					new_height = m_upper_limit;

				m_widget->setFixedHeight(new_height);
			}
			else if (m_resize_dimension == LSizeDimension::Width)
			{
				int new_width = m_click_size.width() + cursor_delta.x();

				if (new_width < m_lower_limit)
					new_width = m_lower_limit;
				else if (new_width > m_upper_limit)
					new_width = m_upper_limit;

				m_widget->setFixedWidth(new_width);
			}
		}
	}
	else if (event->type() == QMouseEvent::MouseButtonRelease)
	{
		m_click_pos = QPoint();
		m_click_size = QSize();
	}

	return false;
}

void LResizer::paintEvent(QPaintEvent* event)
{
	QPainter painter = QPainter(this);

	QPoint icon_pos = QPoint(
		(width() / 2) - (m_icon_size.width() / 2),
		(height() / 2) - (m_icon_size.height() / 2));

	m_icon_svg->render(&painter, QRectF(icon_pos, m_icon_size));
}
