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

#include <Layers/lthemecompatibilityitemdelegate.h>

#include <QPainter>

using Layers::LSvgRenderer;
using Layers::LThemeCompatibilityItemDelegate;

LThemeCompatibilityItemDelegate::LThemeCompatibilityItemDelegate(QObject* parent) :
	LGridlineItemDelegate(parent)
{
	m_check_svg->setObjectName("Checkmark Svg");
}

void LThemeCompatibilityItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	LGridlineItemDelegate::paint(painter, option, index);

	if (index.column() == index.model()->columnCount() - 1)
	{
		if (index.data(Qt::DecorationRole).toBool())
		{
			int centered_x = option.rect.x() + (option.rect.width() / 2) - 10;
			int centered_y = option.rect.y() + (option.rect.height() / 2) - 10;

			m_check_svg->render(painter,
				QRectF(centered_x, centered_y, 20, 15));
		}
	}
}
