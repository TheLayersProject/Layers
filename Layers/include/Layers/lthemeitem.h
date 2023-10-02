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

#ifndef LTHEMEITEM_H
#define LTHEMEITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
class LThemeItem : public QObject
{
	Q_OBJECT

public:
	LThemeItem(
		const QString& name,
		const LAttributeMap& attributes,
		bool is_overridable,
		const QString& file_name,
		LThemeItem* parent = nullptr);

	void append_child(LThemeItem* child);

	QStringList attribute_group_names() const;

	LAttributeMap attributes(const QString& type_name = "");

	LThemeItem* child(int index) const;

	int child_count() const;

	QMap<QString, LThemeItem*>& children();

	LThemeItem* find_item(const QString& path);

	LThemeItem* find_item(QStringList name_list);

	int index() const;

	bool is_overridable() const;

	QString path() const;

	QJsonObject to_json_object() const;

private:
	QMap<QString, LThemeItem*> m_children;

	LAttributeMap m_attributes;
	QString m_file_name;
	bool m_is_overridable{ false };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEITEM_H
