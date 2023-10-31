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

#ifndef LSTRING_H
#define LSTRING_H

#include <ostream>
#include <string>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LStringImpl
{
public:
	LStringImpl();

	LStringImpl(const char* string);

	inline const char* c_str() const noexcept
	{
		return m_string.c_str();
	}

	inline bool empty() const
	{
		return m_string.empty();
	}

	inline std::string::iterator begin()
	{
		return m_string.begin();
	}

	inline std::string::const_iterator begin() const
	{
		return m_string.begin();
	}

	inline std::string::iterator end()
	{
		return m_string.end();
	}

	inline std::string::const_iterator end() const
	{
		return m_string.end();
	}

	std::string m_string;
};

class LAYERS_EXPORT LString
{
public:
	LString();
	LString(const char* string);
	LString(const LString& other);
	LString(LString&& other) noexcept;
	~LString();

	inline const char* c_str() const noexcept
	{
		return pimpl->c_str();
	}

	inline bool empty() const
	{
		return pimpl->empty();
	}

	inline std::string::iterator begin()
	{
		return pimpl->begin();
	}

	inline std::string::const_iterator begin() const
	{
		return pimpl->begin();
	}

	inline std::string::iterator end()
	{
		return pimpl->end();
	}

	inline std::string::const_iterator end() const
	{
		return pimpl->end();
	}

	LString& operator=(const LString& other);

	LString& operator=(LString&& other) noexcept;

	bool operator<(const LString& other) const;

	LString operator+(const char* other) const;

	LString operator+(const LString& other) const;

	bool operator==(const LString& other) const;

	friend std::ostream& operator<<(std::ostream& os, const LString& lstr);

	//friend bool operator==(const Layers::LString& lhs, const Layers::LString& rhs);

	friend bool operator!=(const LString& lhs, const LString& rhs);

private:
	LStringImpl* pimpl;
};

LAYERS_EXPORT LString operator+(const char* lhs, const LString& rhs);

LAYERS_NAMESPACE_END

#endif // LSTRING_H
