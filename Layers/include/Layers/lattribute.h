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

#include <map>

//#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

#include "lobject.h"
#include "ljson.h"

LAYERS_NAMESPACE_BEGIN

class LInvalidVariant {};

using LVariant = std::variant<
	LInvalidVariant,			// 0
	double,						// 1
	bool,						// 2
	std::string,				// 3
	std::vector<std::string>>;	// 4

class LAttribute;
using LAttributeList = std::vector<LAttribute*>;
using LAttributeMap = std::map<std::string, LAttribute*>;

class LAYERS_EXPORT LAttribute : public LObject
{
	Q_OBJECT

signals:
	void changed();

	void link_changed();

public:
	LAttribute(const std::string& name,
		LObject* parent = nullptr);

	LAttribute(const std::string& name, const char* value,
		LObject* parent = nullptr);

	LAttribute(const std::string& name, LVariant value,
		LObject* parent = nullptr);

	LAttribute(const std::string& name, LJsonObject json_object,
		LObject* parent = nullptr);

	LAttribute(const LAttribute& attribute);

	~LAttribute();

	template<typename T>
	T as(const QStringList& state_combo = QStringList());

	template<typename T>
	T* as_if(const QStringList& state_combo = QStringList());

	void break_link();

	void clear_overrides();

	void clear_theme_attribute();

	void create_override(const std::string& name, const char* value);

	void create_override(const std::string& name, LVariant value);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	bool has_overrides() const;

	LJsonObject& json_object();

	LAttribute* link_attribute() const;

	std::string link_path() const;

	LAttribute* override_attribute(const QStringList& state_combo);

	LAttributeMap overrides() const;

	std::string path() const;

	void set_link_attribute(LAttribute* link_attr);

	void set_link_path(const std::string& link_path);

	void set_theme_attribute(LAttribute* theme_attr);

	void set_value(const char* value);

	void set_value(LVariant value);

	LJsonObject to_json_object();

	LJsonValue to_json_value();

	int type_index() const;

	LVariant value();

private slots:
	void update_json_object();

private:
	void establish_link_connections();
	void establish_theme_connection();

	void emit_link_changed();

	QMetaObject::Connection m_link_connection;
	QMetaObject::Connection m_link_destroyed_connection;
	QMetaObject::Connection m_theme_connection;

	LAttributeList m_dependent_attrs;

	LAttribute* m_theme_attr{ nullptr };

	LAttribute* m_link_attr{ nullptr };

	std::string m_link_path;

	LAttributeMap m_overrides;

	LVariant m_value;

	LJsonObject m_json_object;
};

template<typename T>
inline T LAttribute::as(const QStringList& state_combo)
{
	if (m_theme_attr)
		return m_theme_attr->as<T>(state_combo);

	if (!m_overrides.empty() && !state_combo.isEmpty())
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as<T>();

	if (m_link_attr)
		return m_link_attr->as<T>();

	return std::get<T>(m_value);
}

template<typename T>
inline T* LAttribute::as_if(const QStringList& state_combo)
{
	if (m_theme_attr)
		return m_theme_attr->as_if<T>(state_combo);

	if (!m_overrides.empty() && !state_combo.isEmpty())
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as_if<T>();

	if (m_link_attr)
		return m_link_attr->as_if<T>();

	return std::get_if<T>(&m_value);
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
