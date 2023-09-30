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

#ifndef LTHEMECOMBOBOXITEMDELEGATE_H
#define LTHEMECOMBOBOXITEMDELEGATE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcomboboxitemdelegate.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeComboBoxItemDelegate : public LComboBoxItemDelegate
{
	Q_OBJECT

signals:
	void mouse_moved(QPoint cursor_pos);

public:
	virtual bool editorEvent(QEvent* event,
		QAbstractItemModel* model,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) override;

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

private:
	QImage m_caution_image{ QImage(":/images/caution.png") };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMDELEGATE_H
