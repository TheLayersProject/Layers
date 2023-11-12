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

#include "lconnections.h"
#include "ljson.h"
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

	LAttribute(const LString& name, const char* value,
		LObject* parent = nullptr);

	LAttribute(const LString& name, const LVariant& value,
		LObject* parent = nullptr);

	LAttribute(const LString& name, LJsonObject json_object,
		LObject* parent = nullptr);

	~LAttribute();

	template<typename T>
	T as(const std::vector<LString>& state_combo = std::vector<LString>());

	template<typename T>
	const T* as_if(const std::vector<LString>& state_combo = std::vector<LString>());

	void break_link();

	void clear_overrides();

	void clear_theme_attribute();

	void create_override(const LString& name, const char* value);

	void create_override(const LString& name, LVariant value);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	void disconnect_change(const LConnectionID& connection);

	void disconnect_link_change(const LConnectionID& connection);

	bool has_overrides() const;

	LJsonObject& json_object();

	LAttribute* link_attribute() const;

	LString link_path() const;

	LConnectionID on_change(std::function<void()> callback);

	LConnectionID on_link_change(std::function<void()> callback);

	LAttribute* override_attribute(
		const std::vector<LString>& state_combo);

	LAttributeMap overrides() const;

	LString path() const;

	void set_link_attribute(LAttribute* link_attr);

	void set_link_path(const LString& link_path);

	void set_theme_attribute(LAttribute* theme_attr);

	void set_value(const char* value);

	void set_value(const LVariant& value);

	LAttribute* theme_attribute() const;

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
T LAttribute::as(const std::vector<LString>& state_combo) {
	if (theme_attribute())
		return theme_attribute()->as<T>(state_combo);

	if (!overrides().empty() && !state_combo.empty()) {
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as<T>();
	}

	if (link_attribute())
		return link_attribute()->as<T>();

	return std::get<T>(value());
}

template<typename T>
const T* LAttribute::as_if(const std::vector<LString>& state_combo) {
	if (theme_attribute())
		return theme_attribute()->as_if<T>(state_combo);

	if (!overrides().empty() && !state_combo.empty()) {
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as_if<T>();
	}

	if (link_attribute())
		return link_attribute()->as_if<T>();

	return std::get_if<T>(&value());
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
