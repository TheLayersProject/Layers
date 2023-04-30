#ifndef CALCULATE_H
#define CALCULATE_H

#include <cmath>

namespace Layers
{
	inline double round(double d)
	{
		return floor(d + 0.5);
	}

	inline bool is_even(int i)
	{
		if (i % 2) return false;

		return true;
	}

	inline double inner_radius(int outer_radius, int thickness)
	{
		double border_lower_bound = 3;
		double border_range = 27;
		double border_percent = (thickness - border_lower_bound) / border_range;

		double y_int_lower_bound = -2.2164;
		double y_int_range = 2.5446;

		double slope_lower_bound = 0.3435;
		double slope_range = 0.6205;

		double y_int = (border_percent * y_int_range) + y_int_lower_bound;

		double slope = ((1 - border_percent) * slope_range) + slope_lower_bound;

		double value = round(slope * double(outer_radius) + y_int);

		if (value < 0) value = 0;

		return value;
	}
}

#endif // CALCULATE_H
