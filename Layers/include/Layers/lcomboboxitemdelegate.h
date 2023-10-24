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

#ifndef LCOMBOBOXITEMDELEGATE_H
#define LCOMBOBOXITEMDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"
#include "lstatepool.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LComboBoxItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

public:
	LComboBoxItemDelegate(QObject* parent = nullptr);

	QPainterPath background_path(
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

	LAttribute* corner_radius() const;

	LAttribute* fill() const;

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	void set_is_above_control(bool condition = true);

	LAttribute* text_color() const;

protected:
	LAttribute* m_corner_radius
		{ new LAttribute("Corner Radius", 4.0, this) };

	LAttribute* m_fill
		{ new LAttribute("Fill", "#27272e", this)};

	LAttribute* m_text_color
		{ new LAttribute("Text Color", "#e1e1e1", this) };

private:
	void init_attributes();

	bool m_is_above_control{ false };

	LStatePool* m_select_states{
		new LStatePool("Status", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOXITEMDELEGATE_H  
