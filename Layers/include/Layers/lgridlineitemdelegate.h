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

#ifndef LGRIDLINEITEMDELEGATE_H
#define LGRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGridlineItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

signals:
	void changed();

public:
	LGridlineItemDelegate(QObject* parent = nullptr);

	LAttribute* grid_fill() const;

	LAttribute* grid_thickness() const;

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	using QStyledItemDelegate::sizeHint;
	using QStyledItemDelegate::createEditor;
	using QStyledItemDelegate::setEditorData;
	using QStyledItemDelegate::setModelData;
	using QStyledItemDelegate::updateEditorGeometry;

private:
	LAttribute* m_grid_fill{
		new LAttribute("Grid.Fill", "#808080", this) };

	LAttribute* m_grid_thickness{
		new LAttribute("Grid.Thickness", 3.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LGRIDLINEITEMDELEGATE_H  
