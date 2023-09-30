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

#ifndef LCALCULATE_H
#define LCALCULATE_H

#include <cmath>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_EXPORT inline double round(double d)
{
	return floor(d + 0.5);
}

LAYERS_EXPORT inline bool is_even(int i)
{
	if (i % 2) return false;

	return true;
}

LAYERS_EXPORT inline double inner_radius(int outer_radius, int thickness)
{
	double value = outer_radius - thickness;

	if (value < 0.0)
		return 0.0;

	return value;
}

LAYERS_NAMESPACE_END

#endif // LCALCULATE_H
