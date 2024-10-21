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

#ifndef LSTRING_H
#define LSTRING_H

#include <filesystem>
#include <ostream>
#include <string>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

class LString;
using LStringList = std::vector<LString>;

class LAYERS_EXPORT LString
{
public:
	LString();
	LString(const char* string);
	LString(const LString& other);
	LString(LString&& other) noexcept;
	~LString();

	std::string::iterator begin();

	std::string::const_iterator begin() const;

	const char* c_str() const noexcept;

	bool empty() const;

	std::string::iterator end();

	std::string::const_iterator end() const;

	LString& remove(const LString& substring);

	bool starts_with(const LString& prefix) const;

	LString& operator=(const LString& other);

	LString& operator=(LString&& other) noexcept;

	bool operator<(const LString& other) const;

	LString operator+(const char* other) const;

	LString operator+(const LString& other) const;

	bool operator==(const LString& other) const;

	friend LAYERS_EXPORT std::ostream& operator<<(std::ostream& os, const LString& lstr);

	friend LAYERS_EXPORT bool operator!=(const LString& lhs, const LString& rhs);

private:
	class Impl;
	Impl* pimpl;
};

LAYERS_EXPORT LString operator+(const char* lhs, const LString& rhs);

LAYERS_NAMESPACE_END

#endif // LSTRING_H
