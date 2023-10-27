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

#include <Layers/lobject.h>

using Layers::LConnectionID;
using Layers::LObject;

LObject::LObject(LObject* parent)
{
	set_parent(parent);
}

LObject::~LObject()
{
	for (auto& destroyed_connection : m_destroyed_connections)
	{
		destroyed_connection.second();
	}

	for (LObject* child : std::vector<LObject*>(m_children))
	{
		delete child;
	}

	if (m_parent)
	{
		m_parent->remove_child(this);
	}
}

void LObject::add_child(LObject* child)
{
	m_children.push_back(child);
}

std::vector<LObject*>& LObject::children()
{
	return m_children;
}

void LObject::disconnect_destroyed(LConnectionID connection)
{
	m_destroyed_connections.erase(connection);
}

std::string LObject::object_name() const
{
	return m_object_name;
}

LConnectionID LObject::on_destroyed(std::function<void()> callback)
{
	m_destroyed_connections[m_destroyed_connections_next_id++] = callback;
	return std::prev(m_destroyed_connections.end())->first;
}

LObject* LObject::parent() const
{
	return m_parent;
}

void LObject::remove_child(LObject* child)
{
	m_children.erase(
		std::remove(m_children.begin(), m_children.end(), child),
		m_children.end());
}

void LObject::set_object_name(const std::string& object_name)
{
	m_object_name = object_name;
}

void LObject::set_parent(LObject* parent)
{
	if (m_parent != nullptr)
	{
		m_parent->remove_child(this);
	}

	m_parent = parent;

	if (m_parent != nullptr)
	{
		m_parent->add_child(this);
	}
}
