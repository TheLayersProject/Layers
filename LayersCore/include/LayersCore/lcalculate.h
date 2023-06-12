#ifndef LCALCULATE_H
#define LCALCULATE_H

#include <cmath>

#include "layers_global.h"
#include "layerscore_exports.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_CORE_EXPORT inline double round(double d)
{
	return floor(d + 0.5);
}

LAYERS_CORE_EXPORT inline bool is_even(int i)
{
	if (i % 2) return false;

	return true;
}

LAYERS_CORE_EXPORT inline double inner_radius(int outer_radius, int thickness)
{
	double value = outer_radius - thickness;

	if (value < 0.0)
		return 0.0;

	return value;
}

LAYERS_NAMESPACE_END

#endif // LCALCULATE_H
