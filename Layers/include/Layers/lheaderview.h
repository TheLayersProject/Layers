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

#ifndef LHEADERVIEW_H
#define LHEADERVIEW_H

#include <QHeaderView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LHeaderView : public QHeaderView, public LThemeable
{
	Q_OBJECT

public:
	LHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

	virtual void update() override;

private:
	LAttribute* m_border_fill{
		new LAttribute("Border.Fill", "#a0a0a4", this) };

	LAttribute* m_border_thickness{
		new LAttribute("Border.Thickness", 0.0, this) };

	LAttribute* m_corner_radii_bottom_left{
		new LAttribute("Corner Radii.Bottom Left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right{
		new LAttribute("Corner Radii.Bottom Right", 0.0, this) };

	LAttribute* m_corner_radii_top_left{
		new LAttribute("Corner Radii.Top Left", 2.0, this) };

	LAttribute* m_corner_radii_top_right{
		new LAttribute("Corner Radii.Top Right", 2.0, this) };

	LAttribute* m_fill{
		new LAttribute("Fill", "#808080", this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", "#000000", this) };
};
LAYERS_NAMESPACE_END

#endif // LHEADERVIEW_H  
