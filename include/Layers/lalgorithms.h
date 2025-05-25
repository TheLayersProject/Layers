/*
 * Copyright (C) 2024 The Layers Project
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
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

template<typename T>
inline LAYERS_EXPORT T split(const LString& s, char delimiter)
{
	T tokens;
	std::string token;
	std::istringstream tokenStream(s.c_str());
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(LString(token.c_str()));
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

inline LAYERS_EXPORT
std::string load_json_file(const std::filesystem::path& path)
{
	std::ifstream file(path.c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cerr << __FUNCTION__ << ": Could not read file: "
			<< path << std::endl;
		return "";
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string data = buffer.str();
	file.close();

	data = remove_whitespace(data);

	return data;
}

LAYERS_NAMESPACE_END

#endif // LALGORITHMS_H
