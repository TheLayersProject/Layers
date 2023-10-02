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

#include <Layers/lthemeitem.h>

using Layers::LAttributeMap;
using Layers::LThemeItem;

LThemeItem::LThemeItem(
	const QString& name,
	const LAttributeMap& attributes,
	bool is_overridable,
	const QString& file_name,
	LThemeItem* parent
) :
	m_attributes{ attributes },
	m_is_overridable{ is_overridable },
	m_file_name{ file_name },
	QObject(parent)
{
	setObjectName(name);

	for (LAttribute* attr : attributes)
		attr->setParent(this);
}

void LThemeItem::append_child(LThemeItem* child)
{
	m_children[child->objectName()] = child;
}

QStringList LThemeItem::attribute_group_names() const
{
	QStringList attribute_group_names;

	for (LAttribute* attr : m_attributes)
		if (attr->objectName().contains("."))
		{
			QString group_name = attr->objectName().split(".").first();

			if (!attribute_group_names.contains(group_name))
				attribute_group_names.append(attr->objectName().split(".").first());
		}

	return attribute_group_names;
}

LAttributeMap LThemeItem::attributes(const QString& type_name)
{
	if (type_name.isEmpty())
		return m_attributes;

	LAttributeMap attrs;

	for (LAttribute* attr : m_attributes)
		if (type_name == attr->typeName())
			attrs[attr->objectName()] = attr;

	return attrs;
}

LThemeItem* LThemeItem::child(int index) const
{
	if (index < 0 || index >= m_children.size())
		return nullptr;

	return m_children[m_children.keys().at(index)];
}

int LThemeItem::child_count() const
{
	return m_children.count();
}

QMap<QString, LThemeItem*>& LThemeItem::children()
{
	return m_children;
}

LThemeItem* LThemeItem::find_item(const QString& path)
{
	return find_item(path.split("/"));
}

LThemeItem* LThemeItem::find_item(QStringList name_list)
{
	if (!name_list.isEmpty())
	{
		QString name = name_list.takeFirst();

		for (LThemeItem* child_item : m_children)
		{
			if (child_item->objectName() == name)
			{
				if (name_list.isEmpty())
					return child_item;
				else
					return child_item->find_item(name_list);
			}
		}
	}

	return nullptr;
}

int LThemeItem::index() const
{
	if (LThemeItem* parent_item = dynamic_cast<LThemeItem*>(parent()))
	{
		QStringList keys = parent_item->m_children.keys();

		for (int i = 0; i < keys.size(); i++)
			if (parent_item->m_children[keys.at(i)] == this)
				return i;
	}

	return 0;
}

bool LThemeItem::is_overridable() const
{
	return m_is_overridable;
}

QString LThemeItem::path() const
{
	QStringList path_names;

	path_names.append(objectName());

	LThemeItem* theme_item = dynamic_cast<LThemeItem*>(parent());

	while (theme_item)
	{
		if (!theme_item->objectName().isEmpty())
			path_names.insert(0, theme_item->objectName());
		
		theme_item = dynamic_cast<LThemeItem*>(theme_item->parent());
	}

	return path_names.join("/");
}

QJsonObject LThemeItem::to_json_object() const
{
	QJsonObject item_object;
	QJsonObject attributes_object;
	QJsonObject children_object;

	for (const QString& key : m_attributes.keys())
		attributes_object.insert(key, m_attributes[key]->json_object());

	for (const QString& key : m_children.keys())
	{
		LThemeItem* child = m_children[key];

		if (child->m_file_name == m_file_name)
			children_object.insert(child->objectName(), child->to_json_object());
	}

	if (!attributes_object.isEmpty())
		item_object.insert("attributes", attributes_object);

	if (!children_object.isEmpty())
		item_object.insert("children", children_object);

	if (m_is_overridable)
		item_object.insert("is_overridable", QJsonValue(m_is_overridable));

	return item_object;
}
