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

#ifndef LMENUBAR_H
#define LMENUBAR_H

#include <QMenuBar>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LMenuBar : public QMenuBar, public LThemeable
{
	Q_OBJECT

public:
	LMenuBar(QWidget* parent = nullptr);

	LAttribute* selected_text_color() const;

	LAttribute* text_color() const;

	virtual void update() override;

private:
	QString build_stylesheet();

	LAttribute* m_selected_text_color
		{ new LAttribute("selected_text_color", QColor(Qt::lightGray), this) };

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor(Qt::gray), this) };
};
LAYERS_NAMESPACE_END

#endif // LMENUBAR_H
