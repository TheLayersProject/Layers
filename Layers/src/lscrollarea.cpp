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

#include <Layers/lscrollarea.h>

#include <QEvent>

using Layers::LScrollArea;
using Layers::LScrollBar;
using Layers::LThemeable;

LScrollArea::LScrollArea(QWidget* parent) : QScrollArea(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	setWidgetResizable(true);
	setStyleSheet(
		"QScrollArea { background-color:transparent; border:none; }");
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->setObjectName("Horizontal ScrollBar");

	m_vertical_scrollbar->setObjectName("Vertical ScrollBar");
}

QList<LThemeable*> LScrollArea::child_themeables(
	Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables =
		LThemeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	if (LThemeable* themeable_widget = dynamic_cast<LThemeable*>(widget()))
	{
		child_themeables.append(themeable_widget);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> widget_child_objects =
				widget()->findChildren<QObject*>(options);

			for (QObject* widget_child_object : widget_child_objects)
				if (LThemeable* child_themeable =
					dynamic_cast<LThemeable*>(widget_child_object))
				{
					child_themeables.append(child_themeable);
				}
		}
	}

	return child_themeables;
}

void LScrollArea::setWidget(QWidget* widget)
{
	QScrollArea::setWidget(widget);

	widget->setStyleSheet("background-color:transparent;");
}
