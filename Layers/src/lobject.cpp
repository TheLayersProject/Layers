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
using Layers::LObjectImpl;
using Layers::LString;

//LObjectImpl::LObjectImpl(LObject* parent)
//{
//	set_parent(parent);
//}

LObjectImpl::~LObjectImpl()
{
	for (auto& destroyed_connection : m_destroyed_connections)
	{
		destroyed_connection.second();
	}

	for (LObject* child : std::vector<LObject*>(m_children))
	{
		delete child;
	}
}

void LObjectImpl::add_child(LObject* child)
{
	m_children.push_back(child);
}

std::vector<LObject*>& LObjectImpl::children()
{
	return m_children;
}

void LObjectImpl::disconnect_destroyed(LConnectionID connection)
{
	m_destroyed_connections.erase(connection);
}

LString LObjectImpl::object_name() const
{
	return m_object_name;
}

LConnectionID LObjectImpl::on_destroyed(std::function<void()> callback)
{
	m_destroyed_connections[m_destroyed_connections_next_id++] = callback;
	return std::prev(m_destroyed_connections.end())->first;
}

LObject* LObjectImpl::parent() const
{
	return m_parent;
}

void LObjectImpl::remove_child(LObject* child)
{
	m_children.erase(
		std::remove(m_children.begin(), m_children.end(), child),
		m_children.end());
}

void LObjectImpl::set_object_name(const LString& object_name)
{
	m_object_name = object_name;
}

//void LObjectImpl::set_parent(LObject* parent)
//{
//	m_parent = parent;
//}

LObject::LObject(LObject* parent) :
	pimpl{ new LObjectImpl() }
{
	set_parent(parent);
}

LObject::~LObject()
{
	if (pimpl->m_parent)
	{
		pimpl->m_parent->remove_child(this);
	}

	delete pimpl;
}

void LObject::add_child(LObject* child)
{
	pimpl->add_child(child);
}

std::vector<LObject*>& LObject::children()
{
	return pimpl->children();
}

void LObject::disconnect_destroyed(LConnectionID connection)
{
	pimpl->disconnect_destroyed(connection);
}

//template<typename T>
//inline std::vector<T*> LObject::find_children(bool recursive)
//{
//	return pimpl->find_children<T>(recursive);
//}

LString LObject::object_name() const
{
	return pimpl->object_name();
}

LConnectionID LObject::on_destroyed(std::function<void()> callback)
{
	return pimpl->on_destroyed(callback);
}

LObject* LObject::parent() const
{
	return pimpl->parent();
}

void LObject::remove_child(LObject* child)
{
	pimpl->remove_child(child);
}

void LObject::set_object_name(const LString& object_name)
{
	pimpl->set_object_name(object_name);
}

void LObject::set_parent(LObject* parent)
{
	if (pimpl->m_parent != nullptr)
	{
		pimpl->m_parent->remove_child(this);
	}

	pimpl->m_parent = parent;

	if (pimpl->m_parent != nullptr)
	{
		pimpl->m_parent->add_child(this);
	}
}
