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

#ifndef LSCROLLAREA_H
#define LSCROLLAREA_H

#include <QScrollArea>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LScrollArea : public QScrollArea, public LThemeable
{
	Q_OBJECT

public:
	LScrollArea(QWidget* parent = nullptr);

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	void setWidget(QWidget* widget);

private:
	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };
};
LAYERS_NAMESPACE_END

#endif // LSCROLLAREA_H
