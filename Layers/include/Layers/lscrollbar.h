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

#ifndef LSCROLLBAR_H
#define LSCROLLBAR_H

#include <QScrollBar>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LScrollBar : public QScrollBar, public LThemeable
{
	Q_OBJECT

public:
	LScrollBar(QWidget* parent = nullptr);

	LAttribute* background_color() const;

	LAttribute* corner_radii_bottom_left() const;

	LAttribute* corner_radii_bottom_right() const;

	LAttribute* corner_radii_top_left() const;

	LAttribute* corner_radii_top_right() const;

	LAttribute* handle_color() const;

	LAttribute* handle_corner_radii_bottom_left() const;

	LAttribute* handle_corner_radii_bottom_right() const;

	LAttribute* handle_corner_radii_top_left() const;

	LAttribute* handle_corner_radii_top_right() const;

	virtual void update() override;

private:
	LAttribute* m_background_color
		{ new LAttribute("Background Color", QColor(Qt::gray), this) };

	LAttribute* m_corner_radii_bottom_left
		{ new LAttribute("Corner Radii.Bottom Left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right
		{ new LAttribute("Corner Radii.Bottom Right", 0.0, this) };

	LAttribute* m_corner_radii_top_left
		{ new LAttribute("Corner Radii.Top Left", 0.0, this) };

	LAttribute* m_corner_radii_top_right
		{ new LAttribute("Corner Radii.Top Right", 0.0, this) };

	LAttribute* m_handle_color
		{ new LAttribute("Handle Color", QColor(Qt::white), this) };

	LAttribute* m_handle_corner_radii_bottom_left
		{ new LAttribute("Handle Corner Radii.Bottom Left", 5.0, this) };

	LAttribute* m_handle_corner_radii_bottom_right
		{ new LAttribute("Handle Corner Radii.Bottom Right", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_left
		{ new LAttribute("Handle Corner Radii.Top Left", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_right
		{ new LAttribute("Handle Corner Radii.Top Right", 5.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LSCROLLBAR_H
