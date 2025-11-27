/*
 * Copyright (C) 2025 Huntr Software LLC
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
#include <memory>

#include "layers_global.h"
#include "layers_exports.h"

#include "lconnector.h"
#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

class LObject;

/*
	The LObject class is used to establish a hierarchy between Layers objects. 
*/
class LAYERS_EXPORT LObject
{
public:
	/*
		Constructs a Layers object.
	*/
	LObject();

	virtual ~LObject();

	/*
		Adds *child* to this object's list of child objects.
	*/
	void add_child(std::unique_ptr<LObject> child);

	/*
		Returns a vector containing pointers to the child objects associated
		with this object. 
	*/
	std::vector<std::unique_ptr<LObject>>& children();

	/*
		Returns a const vector containing pointers to the child objects
		associated with this object.
	*/
	const std::vector<std::unique_ptr<LObject>>& children() const;

	/*
		Disconnects the callback associated with *connection* to stop it from
		processing when this object gets destroyed. 
	*/
	void disconnect_destroyed(const LConnectionID& connection);

	/*
		Returns a vector containing pointers to the child objects, of type T,
		associated with this object. 

		If *recursive* is true, then the returned vector will include children
		of children.
	*/
	template <typename T>
	std::vector<T*> find_children(bool recursive = false) const;

	/*
		Returns the name of the object.
	*/
	LString object_name() const;

	/*
		Stores *callback* and processes it whenever this object gets destroyed.

		Returns an LConnectionID which can be used to disconnect the callback
		later through disconnect_destroyed().
	*/
	LConnectionID on_destroyed(std::function<void()> callback);

	/*
		Returns a pointer to the object's parent.

		Returns nullptr if no parent has been set.
	*/
	LObject* parent() const;

	/*
		Removes *child* from this object's list of child objects. 
	*/
	void remove_child(LObject* child);

	/*
		Sets the object's name to *new_name*.
	*/
	void set_object_name(const LString& new_name);

private:
	template <typename T>
	void find_children_helper(
		const LObject* parent, std::vector<T*>& children, bool recursive) const;

	class Impl;
	Impl* pimpl;
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

template <typename T, typename... Args>
T* lMake(LObject* parent, Args&&... args)
{
    static_assert(std::is_base_of<LObject, T>::value, "T must be an LObject");
    assert(parent && "Parent must not be null");

    parent->add_child(std::make_unique<T>(std::forward<Args>(args)...));

	return static_cast<T*>(parent->children().back().get());
}

LAYERS_NAMESPACE_END

#endif // LOBJECT_H