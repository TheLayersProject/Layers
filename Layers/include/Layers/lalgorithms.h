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

#ifndef LALGORITHMS_H
#define LALGORITHMS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "layers_global.h"
#include "layers_exports.h"

#include <QGradientStops>

LAYERS_NAMESPACE_BEGIN

template<typename T>
inline LAYERS_EXPORT T split(const std::string& s, char delimiter)
{
	T tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

inline LAYERS_EXPORT
std::string remove_whitespace(const std::string& str)
{
	std::string result;

	bool insideQuotes = false;

	for (char c : str)
	{
		if (c == '\"')
			insideQuotes = !insideQuotes;

		if (insideQuotes || (c != ' ' && c != '\n' && c != '\r'))
			result.push_back(c);
	}

	return result;
}

/* Qt Conversion Functions */

inline LAYERS_EXPORT
QGradientStops to_QGradientStops(const std::vector<std::string>& stops)
{
	QGradientStops q_gradient_stops;

	for (const auto& stop : stops)
	{
		auto stop_parts =
			split<std::vector<std::string>>(stop, ':');

		q_gradient_stops.append(QGradientStop(
			std::stod(stop_parts[0]),
			QString::fromStdString(stop_parts[1])));
	}

	return q_gradient_stops;
}

LAYERS_NAMESPACE_END

#endif // LALGORITHMS_H
