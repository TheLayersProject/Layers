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

#ifndef LATTRIBUTE_H
#define LATTRIBUTE_H

#include <functional>
#include <map>
#include <string>
#include <variant>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "layers_global.h"
#include "layers_exports.h"

#include "lconnections.h"
#include "lcontroller.h"
#include "llink.h"
#include "lobject.h"
#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

using LVariant = std::variant<
	std::monostate,				// 0
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
	LAttribute(const LString& name);

	LAttribute(const LString& name, double value);

	LAttribute(const LString& name, const char* value);

	LAttribute(const LString& name, const LVariant& value);

	LAttribute(const LString& name, const json& value);

	virtual ~LAttribute();

	template<typename T>
	T as(
		const LStringList& state_combo = LStringList(),
		LStyle* context = nullptr);

	template<typename T>
	const T* as_if(
		const LStringList& state_combo = LStringList(),
		LStyle* context = nullptr);

	void break_link(bool update = true);

	void clear_style_attribute();

	void create_link(LAttribute* link_attr);

	void create_link(LLink* link);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	void disconnect_change(const LConnectionID& connection);

	void disconnect_link_change(const LConnectionID& connection);

	bool has_states() const;

	LConnectionID on_change(std::function<void()> callback);

	LConnectionID on_link_change(std::function<void()> callback);

	LString path() const;

	void resolve_links();

	void set_style_attribute(LAttribute* style_attribute);

	void set_value(const char* value);

	void set_value(const LVariant& value);

	LAttribute* state(const LStringList& state_combo);

	LAttributeMap states(bool include_parent_states = true) const;

	LLink* link() const;

	LAttribute* style_attribute() const;

	json to_json_object() const;
	json to_json_value() const;

	size_t type_index() const;

	const LVariant& value();

private:
	void update_link_dependencies();

	class Impl;
	Impl* pimpl;
};

template<typename T>
T LAttribute::as(const LStringList& state_combo, LStyle* context)
{
	if (style_attribute())
		return style_attribute()->as<T>(state_combo);
	
	if (!states().empty() && !state_combo.empty())
		if (LAttribute* state_attr = state(state_combo))
			return state_attr->as<T>();
	
	if (link())
	{
		if (link()->attribute())
		{
			return link()->attribute()->as<T>(state_combo, context);
		}
		else if (link()->relative_path() != "")
		{
			if (LAttribute* res_attr = link()->resolve(context))
			{
				return res_attr->as<T>();
			}
		}
	}

	return std::get<T>(value());
}

template<typename T>
const T* LAttribute::as_if(const LStringList& state_combo, LStyle* context)
{
	if (style_attribute())
		return style_attribute()->as_if<T>(state_combo);

	if (!states().empty() && !state_combo.empty())
		if (LAttribute* state_attr = state(state_combo))
			return state_attr->as_if<T>();

	if (link())
	{
		if (link()->attribute())
		{
			return link()->attribute()->as_if<T>(state_combo, context);
		}
		else if (link()->relative_path() != "")
		{
			if (LAttribute* res_attr = link()->resolve(context))
			{
				return res_attr->as_if<T>();
			}
		}
	}

	return std::get_if<T>(&value());
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
