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

#include <QHash>
#include <QJsonObject>
#include <QObject>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

using LAttributeList = QList<LAttribute*>;
using LAttributeMap = QMap<QString, LAttribute*>;

class LAYERS_EXPORT LAttribute : public QObject
{
	Q_OBJECT

signals:
	void changed();

	void link_changed();

public:
	LAttribute(const QString& name,
		QObject* parent = nullptr);

	LAttribute(const QString& name, QVariant value,
		QObject* parent = nullptr);

	LAttribute(const QString& name, QJsonObject json_object,
		QObject* parent = nullptr);

	LAttribute(const LAttribute& attribute);

	~LAttribute();

	template<typename T>
	T as(const QStringList& state_combo = QStringList());

	void break_link();

	void clear_overrides();

	void clear_theme_attribute();

	void create_override(const QString& name, QVariant value);

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	bool has_overrides() const;

	QJsonObject& json_object();

	LAttribute* link_attribute() const;

	QString link_path() const;

	LAttribute* override_attribute(const QStringList& state_combo);

	LAttributeMap overrides() const;

	QString path() const;

	void set_link_attribute(LAttribute* link_attr);

	void set_link_path(const QString& link_path);

	void set_theme_attribute(LAttribute* theme_attr);

	void set_value(QVariant value);

	QJsonObject to_json_object();

	QJsonValue to_json_value();

	QString typeName(const QStringList& state_combo = QStringList());

	QVariant value();

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

	QString m_link_path;

	LAttributeMap m_overrides;

	QVariant m_value;

	QJsonObject m_json_object;
};

template<typename T>
inline T LAttribute::as(const QStringList& state_combo)
{
	if (m_theme_attr)
		return m_theme_attr->as<T>(state_combo);

	if (!m_overrides.isEmpty() && !state_combo.isEmpty())
		if (LAttribute* override_attr = override_attribute(state_combo))
			return override_attr->as<T>();

	if (m_link_attr)
		return m_link_attr->as<T>();

	return m_value.value<T>();
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
