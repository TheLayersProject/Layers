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

#include <Layers/lstring.h>

using Layers::LString;

class LString::Impl
{
public:
	Impl() {}

	Impl(const char* string) :
		m_string{ string } {}

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

LString::LString() :
	pimpl{ new Impl() } {}

LString::LString(const char* string) :
	pimpl{ new Impl(string) } {}

LString::LString(const LString& other) :
	pimpl{ new Impl(*(other.pimpl)) } {}

LString::LString(LString&& other) noexcept :
	pimpl{ std::exchange(other.pimpl, nullptr) } {}

LString::~LString()
{
	if (pimpl)
	{
		delete pimpl;
		pimpl = nullptr;
	}
}

std::string::iterator LString::begin()
{
	return pimpl->begin();
}

std::string::const_iterator LString::begin() const
{
	return pimpl->begin();
}

const char* LString::c_str() const noexcept
{
	return pimpl->c_str();
}

bool LString::empty() const
{
	return pimpl->empty();
}

std::string::iterator LString::end()
{
	return pimpl->end();
}

std::string::const_iterator LString::end() const
{
	return pimpl->end();
}

LString LString::operator+(const char* other) const
{
	return (pimpl->m_string + other).c_str();
}

bool LString::operator<(const LString& other) const
{
	return pimpl->m_string < other.pimpl->m_string;
}

LString LString::operator+(const LString& other) const
{
	return (pimpl->m_string + other.c_str()).c_str();
}

LString& LString::operator=(const LString& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete pimpl;
	pimpl = new Impl(*other.pimpl);
	return *this;
}

LString& LString::operator=(LString&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	delete pimpl;
	pimpl = std::exchange(other.pimpl, nullptr);
	return *this;
}

bool LString::operator==(const LString& other) const
{
	return pimpl->m_string == other.pimpl->m_string;
}

std::ostream& Layers::operator<<(std::ostream& os, const LString& str) {
	os << std::string(str.c_str());
	return os;
}

bool Layers::operator!=(const LString& lhs, const LString& rhs)
{
	return !(lhs == rhs);
}

LAYERS_EXPORT LString Layers::operator+(const char* lhs, const LString& rhs) {
	return LString((std::string(lhs) + rhs.c_str()).c_str());
}
