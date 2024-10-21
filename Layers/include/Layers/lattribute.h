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

#ifndef LATTRIBUTE_H
#define LATTRIBUTE_H

#include <functional>
#include <map>
#include <string>
#include <variant>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lalgorithms.h" // TODO: Might be able to remove this include?
#include "lconnections.h"
#include "lcontroller.h"
#include "ldefinable.h"
#include "ljson.h"
#include "llink.h"
#include "lobject.h"
#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

class LInvalidVariant {};

using LVariant = std::variant<
	LInvalidVariant,			// 0
	double,						// 1
	bool,						// 2
	LString,					// 3
	std::vector<LString>>;		// 4

class LAttribute;
using LAttributeList = std::vector<LAttribute*>;
using LAttributeMap = std::map<LString, LAttribute*>;

class LAYERS_EXPORT LAttribute : public LObject
{
public:
	LAttribute(const LString& name,
		LObject* parent = nullptr);

	LAttribute(const LString& name, double value,
		LObject* parent = nullptr);

	LAttribute(const LString& name, const char* value,
		LObject* parent = nullptr);

	LAttribute(const LString& name, const LVariant& value,
		LObject* parent = nullptr);

	LAttribute(const LString& name, LJsonValue value,
		LObject* parent = nullptr);

	~LAttribute();

	template<typename T>
	T as(const LString& state_name = "", LDefinition* definition = nullptr);
	//T as(const std::vector<LString>& state_combo = std::vector<LString>());

	template<typename T>
	const T* as_if(const LString& state_name = "", LDefinition* definition = nullptr);
	//const T* as_if(const std::vector<LString>& state_combo = std::vector<LString>());

	void break_link();

	void clear_states();

	void clear_theme_attribute();

	void create_link(LAttribute* link_attr);

	void create_state(const LString& name, const char* value);

	void create_state(const LString& name, LVariant value);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	void disconnect_change(const LConnectionID& connection);

	void disconnect_link_change(const LConnectionID& connection);

	//LLink* dynamic_link() const;

	bool has_states() const;

	//LJsonObject& json_object();

	//LAttribute* link_attribute() const;

	//LString link_path() const;

	LConnectionID on_change(std::function<void()> callback);

	LConnectionID on_link_change(std::function<void()> callback);

	LAttribute* state(const LString& name);

	LAttributeMap states() const;

	LString path() const;

	void resolve_links(LDefinition* definition);

	//void set_link_attribute(LAttribute* link_attr);

	//void set_link_path(const LString& link_path);

	void set_definition_attribute(LAttribute* definition_attribute);

	void set_value(const char* value);

	void set_value(const LVariant& value);

	LLink* link() const;

	LAttribute* definition_attribute() const;

	LJsonObject to_json_object();

	LJsonValue to_json_value();

	size_t type_index() const;

	const LVariant& value();

private:
	void update_dependencies();

	class Impl;
	Impl* pimpl;
};

template<typename T>
T LAttribute::as(const LString& state_name, LDefinition* definition)
{
	/*
		TODO:
		Need to consider all cases that need definition context.
		For now, context is only passed when a definition attribute is present
		(in cases where this is likely a definable attribute), when the
		base attribute value is returned, and when a link resolution exists for
		the context.
	*/

	if (definition_attribute())
		return definition_attribute()->as<T>(state_name, definition);

	// TEMP
	if (definition && definition->object_name() == "Close Button" && object_name() == "Fill")
	{
		int i = 0;
	}
	
	LAttributeMap _states = states();

	LStringList state_names = split<LStringList>(state_name, '::');

	for (LString state_n : state_names)
	{
		if (_states.count(state_n))
			return _states[state_n]->as<T>("", definition);
	}

	//if (state_name != "" && _states.count(state_name))
	//	return _states[state_name]->as<T>("", definition);
	
	if (link())
	{
		if (link()->attribute())
			return link()->attribute()->as<T>();

		else if (link()->resolutions().count(definition))
		{
			LResolution res = link()->resolutions()[definition];

        	return res.target_attribute->as<T>("", res.target_definition);
		}
	}

	if (value().index() == 0)
	{
		if (definition->base())
			return definition->base()->find_attribute(object_name())->as<T>(state_name, definition);

		/*
			- Check if base attribute exists and return its value
		*/
	}

	return std::get<T>(value());
}

// template<typename T>
// T LAttribute::as(LDefinition* definition)
// {
// //T LAttribute::as(const std::vector<LString>& state_combo) {
// 	if (definition_attribute())
// 		return definition_attribute()->as<T>(definition);

// 	// TEMP: Disabling override valuation
// 	// if (!overrides().empty() && !state_combo.empty())
// 	// 	if (LAttribute* override_attr = override_attribute(definable))
// 	// 		return override_attr->as<T>();

// 	if (dynamic_link())
// 	{
// 		LStringList link_parts =
// 			split<LStringList>(dynamic_link()->path(), '/');

// 		/*
// 			NOTE:
// 			The following assumes that dynamic links always begin with double-
// 			dot notation and that there is always only 1 of them. Other cases
// 			have not yet been considered.
// 		*/
// 		if (link_parts[0] == "..")
// 		{
// 			if (LObject* parent_parent_obj = definition->parent())
// 			{
// 				if (LDefinition* parent_parent_as_def = dynamic_cast<LDefinition*>(parent_parent_obj))
// 				{
// 					for (const auto& [key, attr] : parent_parent_as_def->attributes())
// 						if (attr->object_name() == link_parts[1])
// 							return attr->as<T>(parent_parent_as_def);
// 				}
// 			}
// 			else
// 			{
// 				auto static_link_parts =
// 					split<std::deque<LString>>(static_link()->path(), '/');
// 				LString static_link_attr_name = static_link_parts.back();
// 				static_link_parts.pop_back();

// 				if (LDefinition* def = lController.find_definition(static_link_parts))
// 					for (const auto& [attr_name, attr] : def->attributes())
// 						if (attr_name == static_link_attr_name)
// 							return attr->as<T>();
// 			}
// 		}
// 	}
// 	// TODO: Need to handle static link

// 	//if (link_attribute())
// 	//	return link_attribute()->as<T>();

// 	return std::get<T>(value());
// }

template<typename T>
const T* LAttribute::as_if(const LString& state_name, LDefinition* definition)
{
//const T* LAttribute::as_if(const std::vector<LString>& state_combo) {
	// if (definition_attribute())
	// 	return definition_attribute()->as_if<T>(defintion);

	// // if (!overrides().empty() && !state_combo.empty()) {
	// // 	if (LAttribute* override_attr = override_attribute(definable))
	// // 		return override_attr->as_if<T>();
	// // }

	// // if (link_attribute())
	// // 	return link_attribute()->as_if<T>();

	// return std::get_if<T>(&value());

	if (definition_attribute())
		return definition_attribute()->as_if<T>(state_name, definition);

	LAttributeMap _states = states();

	if (state_name != "" && _states.count(state_name))
		return _states[state_name]->as_if<T>();
	
	if (link())
	{
		if (link()->attribute())
			return link()->attribute()->as_if<T>();

		else if (link()->resolutions().count(definition))
		{
			LResolution res = link()->resolutions()[definition];

        	return res.target_attribute->as_if<T>(state_name, res.target_definition);
		}
	}

	return std::get_if<T>(&value());
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
