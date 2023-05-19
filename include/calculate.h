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
		double value = outer_radius - thickness;

		if (value < 0.0)
			return 0.0;

		return value;
	}
}

#endif // CALCULATE_H
