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

#include <Layers/lheaderview.h>

#include <QPainter>

using Layers::LHeaderView;

LHeaderView::LHeaderView(Qt::Orientation orientation, QWidget* parent) :
	QHeaderView(orientation, parent)
{
	update();

	if (orientation == Qt::Horizontal)
		setObjectName("Horizontal Header");
	else
		setObjectName("Vertical Header");
}

void LHeaderView::update()
{
	setStyleSheet(
		"QHeaderView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"border-top-left-radius: "
			+ m_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: "
			+ m_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: "
			+ m_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: "
			+ m_corner_radii_bottom_right->as<QString>() + "px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QHeaderView::section {"
		"background: transparent;"
		"}"
	);

	QWidget::update();
}
