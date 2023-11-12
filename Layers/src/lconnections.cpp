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

#include <Layers/lconnections.h>

using Layers::LConnectionID;

LConnectionID::LConnectionID() :
	m_value{ 0 } {}

LConnectionID::LConnectionID(int value) :
	m_value{ value } {}

LConnectionID::LConnectionID(const LConnectionID& other) :
	m_value(other.m_value) {}

LConnectionID& LConnectionID::operator=(const LConnectionID& other)
{
	m_value = other.m_value;
	return *this;
}

bool LConnectionID::operator<(const LConnectionID& other) const
{
	return m_value < other.m_value;
}

LConnectionID LConnectionID::operator++(int)
{
	LConnectionID temp(*this);
	m_value++;
	return temp;
}
