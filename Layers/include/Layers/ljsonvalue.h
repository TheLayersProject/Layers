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

#ifndef LJSONVALUE_H
#define LJSONVALUE_H

#include <map>
#include <variant>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

class LJsonValue;

using LJsonArray = std::vector<LJsonValue>;
using LJsonObject = std::map<LString, LJsonValue>;
using LJsonVariant =
std::variant<bool, double, LString, LJsonArray, LJsonObject>;

class LAYERS_EXPORT LJsonValue
{
public:
	LJsonValue();
	LJsonValue(bool v);
	LJsonValue(double v);
	LJsonValue(const char* v);
	LJsonValue(const LString& v);
	LJsonValue(const LJsonObject& v);
	LJsonValue(const LJsonArray& v);
	LJsonValue(const LJsonValue& other);
	LJsonValue(LJsonValue&& other) noexcept;
	~LJsonValue();

	bool is_array() const;

	bool is_bool() const;

	bool is_double() const;

	bool is_object() const;

	bool is_string() const;

	LJsonArray to_array() const;

	bool to_bool() const;

	double to_double() const;

	LJsonObject to_object() const;

	LString to_string() const;

	LString to_output(
		int indent_space_count = 2, int indent_level = 0) const;

	LJsonValue& operator=(const LJsonValue& other);

	LJsonValue& operator=(LJsonValue&& other) noexcept;

private:
	class Impl;
	Impl* pimpl;
};

LAYERS_NAMESPACE_END

#endif // LJSONVALUE_H
