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

#include <vector>
#include <string>

#include <Layers/lalgorithms.h>

using Layers::LAttributeMap;
using Layers::LJsonObject;
using Layers::LThemeItem;

LThemeItem::LThemeItem(
	const std::string &name,
	const LAttributeMap& attributes,
	bool is_overridable,
	const std::string& file_name,
	LThemeItem* parent
) :
	m_attributes{ attributes },
	m_is_overridable{ is_overridable },
	m_file_name{ file_name },
	LObject(parent)
{
	set_object_name(name);

	for (const auto& [key, attr] : attributes)
		attr->set_parent(this);
}

void LThemeItem::append_child(LThemeItem* child)
{
	m_children[child->object_name()] = child;
}

std::vector<std::string> LThemeItem::attribute_group_names() const
{
	std::vector<std::string> attribute_group_names;

	for (const auto& [key, attr] : m_attributes)
	{
		std::string attr_name = attr->object_name();

		if (std::find(attr_name.begin(), attr_name.end(),
			'.') != attr_name.end())
		{
			auto group_name = split<std::vector<std::string>>(
				attr_name, '.').front();

			if (std::find(attribute_group_names.begin(),
				attribute_group_names.end(),
				group_name) == attribute_group_names.end())
			{
				attribute_group_names.push_back(group_name);
			}
		}
	}

	return attribute_group_names;
}

LAttributeMap LThemeItem::attributes(int type_index)
{
	if (type_index < 0)
		return m_attributes;

	LAttributeMap attrs;

	for (const auto& [key, attr] : m_attributes)
		if (attr->type_index() == type_index)
			attrs[attr->object_name()] = attr;

	return attrs;
}

LThemeItem* LThemeItem::child(int index) const
{
	if (index < 0 || index >= m_children.size())
		return nullptr;

	auto it = m_children.begin();
	std::advance(it, index);

	return it->second;
}


size_t LThemeItem::child_count() const
{
	return m_children.size();
}

std::map<std::string, LThemeItem*>& LThemeItem::children()
{
	return m_children;
}

LThemeItem* LThemeItem::find_item(const std::string& path)
{
	return find_item(split<std::deque<std::string>>(path, '/'));
}

LThemeItem* LThemeItem::find_item(std::deque<std::string> name_list)
{
	if (!name_list.empty())
	{
		std::string name = *name_list.begin();
		name_list.pop_front();

		for (const auto& [key, child_item] : m_children)
		{
			if (child_item->object_name() == name)
			{
				if (name_list.empty())
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
		int i = 0;
		for (auto it = parent_item->m_children.begin();
			it != parent_item->m_children.end(); ++it, ++i)
		{
			if (it->second == this)
				return i;
		}
	}
	return 0;
}

bool LThemeItem::is_overridable() const
{
	return m_is_overridable;
}

std::string LThemeItem::path() const
{
	std::vector<std::string> path_names;

	path_names.push_back(object_name());

	LThemeItem* theme_item = dynamic_cast<LThemeItem*>(parent());

	while (theme_item)
	{
		std::string name = theme_item->object_name();
		if (!name.empty())
			path_names.insert(path_names.begin(), name);

		theme_item = dynamic_cast<LThemeItem*>(theme_item->parent());
	}

	std::ostringstream joined_names;
	std::copy(path_names.begin(), path_names.end(),
		std::ostream_iterator<std::string>(joined_names, "/"));
	std::string result = joined_names.str();

	return result.substr(0, result.length() - 1);
}

LJsonObject LThemeItem::to_json_object() const
{
	LJsonObject item_object;
	LJsonObject attributes_object;
	LJsonObject children_object;

	for (const auto& [key, attr] : m_attributes)
		attributes_object[key] = attr->json_object();

	for (const auto& [key, child] : m_children)
		if (child->m_file_name == m_file_name)
			children_object[child->object_name()] =
				child->to_json_object();

	if (!attributes_object.empty())
		item_object["attributes"] = attributes_object;

	if (!children_object.empty())
		item_object["children"] = children_object;

	if (m_is_overridable)
		item_object["is_overridable"] = m_is_overridable;

	return item_object;
}
