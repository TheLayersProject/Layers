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

#ifndef LOBJECT_H
#define LOBJECT_H

#include <string>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lconnections.h"

LAYERS_NAMESPACE_BEGIN

class LObject
{
public:
	LObject(LObject* parent = nullptr);

	virtual ~LObject();

	void add_child(LObject* child);

	std::vector<LObject*>& children();

	void disconnect_destroyed(LConnectionID connection);

	template <typename T>
	std::vector<T*> find_children(bool recursive = false);

	std::string object_name() const;

	LConnectionID on_destroyed(std::function<void()> callback);

	LObject* parent() const;

	void remove_child(LObject* child);

	void set_object_name(const std::string& object_name);

	void set_parent(LObject* parent);

private:
	std::string m_object_name;

	LObject* m_parent{ nullptr };
	std::vector<LObject*> m_children;

	LConnections m_destroyed_connections;
	LConnectionID m_destroyed_connections_next_id;
};

template <typename T>
void find_children_helper(LObject* parent, std::vector<T*>& children, bool recursive)
{
	for (LObject* child : parent->children())
	{
		if (T* typed_child = dynamic_cast<T*>(child))
		{
			children.push_back(typed_child);
		}

		if (recursive)
		{
			find_children_helper(child, children, recursive);
		}
	}
}

template<typename T>
inline std::vector<T*> LObject::find_children(bool recursive)
{
	std::vector<T*> children;
	find_children_helper(this, children, recursive);
	return children;
}

LAYERS_NAMESPACE_END

#endif // LOBJECT_H