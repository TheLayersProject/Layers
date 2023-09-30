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

#ifndef LTHEMEABLEBOX_H
#define LTHEMEABLEBOX_H

#include <QPainter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lpaint.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeableBox : public LThemeable
{
public:
	LAttribute* border_fill() const;

	LAttribute* border_thickness() const;

	static QPainterPath box_path(
		const QRect& box_rect, const LCornerRadii& corner_radii);

	LAttribute* corner_radii_bottom_left() const;

	LAttribute* corner_radii_bottom_right() const;

	LAttribute* corner_radii_top_left() const;

	LAttribute* corner_radii_top_right() const;

	LAttribute* fill() const;

	LAttribute* margins_bottom() const;

	LAttribute* margins_left() const;

	LAttribute* margins_right() const;

	LAttribute* margins_top() const;

	void set_margin(double margin);

	void set_margin(double left, double top, double right, double bottom);

protected:
	void init_attributes();

	void paint(QWidget* widget);

	LAttribute* m_border_fill
		{ new LAttribute("Border.Fill", QColor(Qt::gray)) };

	LAttribute* m_border_thickness
		{ new LAttribute("Border.Thickness", 0.0) };

	LAttribute* m_corner_radii_bottom_left
		{ new LAttribute("Corner Radii.Bottom Left", 0.0) };

	LAttribute* m_corner_radii_bottom_right
		{ new LAttribute("Corner Radii.Bottom Right", 0.0) };

	LAttribute* m_corner_radii_top_left
		{ new LAttribute("Corner Radii.Top Left", 0.0) };

	LAttribute* m_corner_radii_top_right
		{ new LAttribute("Corner Radii.Top Right", 0.0) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor(Qt::white)) };

	LAttribute* m_margins_bottom
		{ new LAttribute("Margins.Bottom", 0.0) };

	LAttribute* m_margins_left
		{ new LAttribute("Margins.Left", 0.0) };

	LAttribute* m_margins_right
		{ new LAttribute("Margins.Right", 0.0) };

	LAttribute* m_margins_top
		{ new LAttribute("Margins.Top", 0.0) };
};

LAYERS_NAMESPACE_END

#endif // LTHEMEABLEBOX_H
