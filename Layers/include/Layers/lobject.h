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

#ifndef LOBJECT_H
#define LOBJECT_H

#include <string>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lconnector.h"
#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

class LObject;

class LAYERS_EXPORT LObject
{
public:
	LObject(LObject* parent = nullptr);

	virtual ~LObject();

	void add_child(std::unique_ptr<LObject> child);

	std::vector<std::unique_ptr<LObject>>& children();

	const std::vector<std::unique_ptr<LObject>>& children() const;

	void disconnect_destroyed(const LConnectionID& connection);

	template <typename T>
	std::vector<T*> find_children(bool recursive = false) const;

	LString object_name() const;

	LConnectionID on_destroyed(std::function<void()> callback);

	LObject* parent() const;

	void remove_child(LObject* child);

	void set_object_name(const LString& object_name);

	void set_parent(LObject* parent);

private:
	template <typename T>
	void find_children_helper(
		const LObject* parent, std::vector<T*>& children, bool recursive) const;

	class Impl;
	std::unique_ptr<Impl> pimpl;
};

template <typename T>
inline void LObject::find_children_helper(
	const LObject* parent, std::vector<T*>& children, bool recursive) const
{
	for (const auto& child : parent->children())
	{
		if (T* typed_child = dynamic_cast<T*>(child.get()))
		{
			children.push_back(typed_child);
		}

		if (recursive)
		{
			find_children_helper(child.get(), children, recursive);
		}
	}

}

template <typename T>
inline std::vector<T*> LObject::find_children(bool recursive) const
{
	std::vector<T*> children;
	find_children_helper<T>(this, children, recursive);
	return children;
}

LAYERS_NAMESPACE_END

#endif // LOBJECT_H