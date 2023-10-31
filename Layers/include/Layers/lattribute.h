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

class LAttributeImpl
{
public:
	LAttributeImpl(const LString& name);

	LAttributeImpl(const LString& name, const char* value);

	LAttributeImpl(const LString& name, const LVariant& value);

	LAttributeImpl(const LString& name, LJsonObject json_object);

	//LAttributeImpl(const LAttribute& attribute);

	~LAttributeImpl();

	//template<typename T>
	//LAYERS_EXPORT T _as(const std::vector<LString>& state_combo = std::vector<LString>());

	//template<typename T>
	//LAYERS_EXPORT T* _as_if(const std::vector<LString>& state_combo = std::vector<LString>());

	void _break_link(LObject* parent);

	void _clear_theme_attribute();

	void _create_override(const LString& name, LAttribute* override_attr);

	LAttributeList _dependent_attributes(
		bool include_indirect_dependencies = false) const;

	void _disconnect_change(LConnectionID connection);

	void _disconnect_link_change(LConnectionID connection);

	bool _has_overrides() const;

	LJsonObject& _json_object();

	LAttribute* _link_attribute() const;

	LString _link_path() const;

	LConnectionID _on_change(std::function<void()> callback);

	LConnectionID _on_link_change(std::function<void()> callback);

	LAttribute* _override_attribute(
		const std::vector<LString>& state_combo);

	LAttributeMap _overrides() const;

	void _set_link_attribute(LObject* parent, LAttribute* link_attr);

	void _set_link_path(const LString& link_path);

	void _set_theme_attribute(LObject* parent, LAttribute* theme_attr);

	void _set_value(LObject* parent, LVariant value);

	LJsonObject _to_json_object();

	LJsonValue _to_json_value();

	size_t _type_index() const;

	LVariant _value();

	void _update_dependencies(LObject* parent);

	void _update_link_dependencies();

	void _update_json_object();

	LConnectionID m_link_destroyed_connection;
	LConnectionID m_theme_connection;

	LAttributeList m_dependent_attrs;

	LAttribute* m_theme_attr{ nullptr };

	LAttribute* m_link_attr{ nullptr };

	LString m_link_path;

	LAttributeMap m_overrides;

	LVariant m_value;

	LJsonObject m_json_object;

	LConnections m_change_connections;
	LConnectionID m_change_connections_next_id;

	LConnections m_link_change_connections;
	LConnectionID m_link_change_connections_next_id;
};

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

	//LAttribute(const LAttribute& attribute);

	~LAttribute();

	template<typename T>
	T as(const std::vector<LString>& state_combo = std::vector<LString>());

	template<typename T>
	T* as_if(const std::vector<LString>& state_combo = std::vector<LString>());

	void break_link();

	void clear_overrides();

	void clear_theme_attribute();

	void create_override(const LString& name, const char* value);

	void create_override(const LString& name, LVariant value);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	void disconnect_change(LConnectionID connection);

	void disconnect_link_change(LConnectionID connection);

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

	void set_value(LVariant value);

	LJsonObject to_json_object();

	LJsonValue to_json_value();

	size_t type_index() const;

	LVariant value();

private:
	void update_dependencies();

	friend class LAttributeImpl;
	LAttributeImpl* pimpl;
};

//template<typename T>
//inline T LAttributeImpl::_as(const std::vector<LString>& state_combo)
//{
//	if (m_theme_attr)
//		return m_theme_attr->as<T>(state_combo);
//
//	if (!m_overrides.empty() && !state_combo.empty())
//		if (LAttribute* override_attr = _override_attribute(state_combo))
//			return override_attr->as<T>();
//
//	if (m_link_attr)
//		return m_link_attr->as<T>();
//
//	return std::get<T>(m_value);
//}
//
//template<typename T>
//inline T* LAttributeImpl::_as_if(const std::vector<LString>& state_combo)
//{
//	if (m_theme_attr)
//		return m_theme_attr->as_if<T>(state_combo);
//
//	if (!m_overrides.empty() && !state_combo.empty())
//		if (LAttribute* override_attr = _override_attribute(state_combo))
//			return override_attr->as_if<T>();
//
//	if (m_link_attr)
//		return m_link_attr->as_if<T>();
//
//	return std::get_if<T>(&m_value);
//}

template<typename T>
inline T LAttribute::as(const std::vector<LString>& state_combo)
{
	//return pimpl->_as<T>(state_combo);

	if (pimpl->m_theme_attr)
		return pimpl->m_theme_attr->as<T>(state_combo);

	if (!pimpl->m_overrides.empty() && !state_combo.empty())
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as<T>();

	if (pimpl->m_link_attr)
		return pimpl->m_link_attr->as<T>();

	return std::get<T>(pimpl->m_value);
}

template<typename T>
inline T* LAttribute::as_if(const std::vector<LString>& state_combo)
{
	//return pimpl->_as_if<T>(state_combo);

	if (pimpl->m_theme_attr)
		return pimpl->m_theme_attr->as_if<T>(state_combo);

	if (!pimpl->m_overrides.empty() && !state_combo.empty())
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as_if<T>();

	if (pimpl->m_link_attr)
		return pimpl->m_link_attr->as_if<T>();

	return std::get_if<T>(&pimpl->m_value);
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
