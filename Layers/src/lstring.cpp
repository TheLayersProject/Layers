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
using Layers::LStringImpl;

/* LStringImpl */

LStringImpl::LStringImpl() {}

LStringImpl::LStringImpl(const char* string) :
	m_string{ string } {}

/* LString */

LString::LString() :
	pimpl{ new LStringImpl() } {}

LString::LString(const char* string) :
	pimpl{ new LStringImpl(string) } {}

LString::LString(const LString& other) :
	pimpl{ new LStringImpl(*(other.pimpl)) } {}

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
	pimpl = new LStringImpl(*other.pimpl);
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

//bool Layers::operator==(const LString& lhs, const LString& rhs)
//{
//	return lhs.pimpl->m_string == rhs.pimpl->m_string;
//}

bool Layers::operator!=(const LString& lhs, const LString& rhs)
{
	return !(lhs == rhs);
}

LAYERS_EXPORT LString Layers::operator+(const char* lhs, const LString& rhs) {
	return LString((std::string(lhs) + rhs.c_str()).c_str());
}
