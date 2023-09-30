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

#include <Layers/lgridlineitemdelegate.h>

#include <QPainter>

using Layers::LAttribute;
using Layers::LGridlineItemDelegate;

LGridlineItemDelegate::LGridlineItemDelegate(QObject* parent) :
	QStyledItemDelegate(parent)
{
	setObjectName("Cells");
}

LAttribute* LGridlineItemDelegate::grid_fill() const
{
	return m_grid_fill;
}

LAttribute* LGridlineItemDelegate::grid_thickness() const
{
	return m_grid_thickness;
}

void LGridlineItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QStyledItemDelegate::paint(painter, option, index);

	QColor grid_fill = m_grid_fill->as<QColor>();

	int grid_thickness = m_grid_thickness->as<int>();

	if (index.row() < index.model()->rowCount() - 1)
	{
		QRect border_rect_bottom = QRect(
			option.rect.x(),
			option.rect.y() + option.rect.height() - grid_thickness,
			option.rect.width(),
			grid_thickness
		);
		painter->fillRect(border_rect_bottom, grid_fill);
	}

	if (index.column() < index.model()->columnCount() - 1)
	{
		QRect border_rect_right = QRect(
			option.rect.x() + option.rect.width() - grid_thickness,
			option.rect.y(),
			grid_thickness,
			option.rect.height()
		);
		painter->fillRect(border_rect_right, grid_fill);
	}
}
