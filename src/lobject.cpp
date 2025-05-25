/*
 * Copyright (C) 2025 The Layers Project
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

#include <Layers/llogger.h>

using Layers::LConnectionID;
using Layers::LConnections;
using Layers::LObject;
using Layers::LString;

class LObject::Impl
{
public:
	~Impl()
	{
		connector_destroyed.execute();
	}

	void disconnect_destroyed(const LConnectionID& connection)
	{
		connector_destroyed.disconnect(connection);
	}

	LConnectionID on_destroyed(std::function<void()> callback)
	{
		return connector_destroyed.connect(callback);
	}

	void remove_child(LObject* child)
	{
		auto it = std::find_if(children.begin(), children.end(),
			[child](const std::unique_ptr<LObject>& ptr)
			{
				return ptr.get() == child;
			});

		if (it != children.end())
		{
			children.erase(it);
		}
	}

	void set_object_name(const LString& new_name)
	{
		object_name = new_name;
	}

	LString object_name;

	std::vector<std::unique_ptr<LObject>> children;
	LObject* parent{ nullptr };

	LConnector<> connector_destroyed;
};

LObject::LObject(LObject* parent) :
	pimpl{ new Impl() }
{
	set_parent(parent);
}

LObject::~LObject()
{
	Layers::log("~LObject(): Name: " + pimpl->object_name);

	delete pimpl;
}

void LObject::add_child(std::unique_ptr<LObject> child)
{
	pimpl->children.push_back(std::move(child));
}

std::vector<std::unique_ptr<LObject>>& LObject::children()
{
	return pimpl->children;
}

const std::vector<std::unique_ptr<LObject>>& LObject::children() const
{
	return pimpl->children;
}

void LObject::disconnect_destroyed(const LConnectionID& connection)
{
	pimpl->disconnect_destroyed(connection);
}

LString LObject::object_name() const
{
	return pimpl->object_name;
}

LConnectionID LObject::on_destroyed(std::function<void()> callback)
{
	return pimpl->on_destroyed(callback);
}

LObject* LObject::parent() const
{
	return pimpl->parent;
}

void LObject::remove_child(LObject* child)
{
	pimpl->remove_child(child);
}

void LObject::set_object_name(const LString& new_name)
{
	pimpl->set_object_name(new_name);
}

void LObject::set_parent(LObject* new_parent)
{
	if (pimpl->parent)
	{
		pimpl->parent->remove_child(this);
	}

	pimpl->parent = new_parent;
}
