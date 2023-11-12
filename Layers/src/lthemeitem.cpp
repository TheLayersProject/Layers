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
using Layers::LString;
using Layers::LThemeItem;

class LThemeItem::Impl
{
public:
	Impl(
		const LAttributeMap& attributes,
		bool is_overridable,
		const LString& file_name) :
		m_attributes{ attributes },
		m_is_overridable{ is_overridable },
		m_file_name{ file_name } {}

	void append_child(LThemeItem* child)
	{
		m_children[child->object_name()] = child;
	}

	std::vector<LString> attribute_group_names() const
	{
		std::vector<LString> attribute_group_names;

		for (const auto& [key, attr] : m_attributes)
		{
			LString attr_name = attr->object_name();

			if (std::find(attr_name.begin(), attr_name.end(),
				'.') != attr_name.end())
			{
				auto group_name = split<std::vector<LString>>(
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

	LAttributeMap attributes(int type_index = -1)
	{
		if (type_index < 0)
			return m_attributes;

		LAttributeMap attrs;

		for (const auto& [key, attr] : m_attributes)
			if (attr->type_index() == type_index)
				attrs[attr->object_name()] = attr;

		return attrs;
	}

	LThemeItem* child(int index) const
	{
		if (index < 0 || index >= m_children.size())
			return nullptr;

		auto it = m_children.begin();
		std::advance(it, index);

		return it->second;
	}

	size_t child_count() const
	{
		return m_children.size();
	}

	std::map<LString, LThemeItem*>& children()
	{
		return m_children;
	}

	LThemeItem* find_item(std::deque<LString> name_list)
	{
		if (!name_list.empty())
		{
			LString name = *name_list.begin();
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

	bool is_overridable() const
	{
		return m_is_overridable;
	}

	LJsonObject to_json_object() const
	{
		LJsonObject item_object;
		LJsonObject attributes_object;
		LJsonObject children_object;

		for (const auto& [key, attr] : m_attributes)
			attributes_object[key] = attr->json_object();

		for (const auto& [key, child] : m_children)
			if (child->pimpl->m_file_name == m_file_name)
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

	std::map<LString, LThemeItem*> m_children;

	LAttributeMap m_attributes;
	LString m_file_name;
	bool m_is_overridable{ false };
};

LThemeItem::LThemeItem(
	const LString& name,
	const LAttributeMap& attributes,
	bool is_overridable,
	const LString& file_name,
	LThemeItem* parent
) :
	pimpl{ new Impl(attributes, is_overridable, file_name) },
	LObject(parent)
{
	set_object_name(name);

	for (const auto& [key, attr] : attributes)
		attr->set_parent(this);
}

LThemeItem::~LThemeItem()
{
	delete pimpl;
}

void LThemeItem::append_child(LThemeItem* child)
{
	pimpl->append_child(child);
}

std::vector<LString> LThemeItem::attribute_group_names() const
{
	return pimpl->attribute_group_names();
}

LAttributeMap LThemeItem::attributes(int type_index)
{
	return pimpl->attributes(type_index);
}

LThemeItem* LThemeItem::child(int index) const
{
	return pimpl->child(index);
}

size_t LThemeItem::child_count() const
{
	return pimpl->child_count();
}

std::map<LString, LThemeItem*>& LThemeItem::children()
{
	return pimpl->children();
}

LThemeItem* LThemeItem::find_item(const LString& path)
{
	return find_item(split<std::deque<LString>>(path, '/'));
}

LThemeItem* LThemeItem::find_item(std::deque<LString> name_list)
{
	return pimpl->find_item(name_list);
}

int LThemeItem::index() const
{
	if (LThemeItem* parent_item = dynamic_cast<LThemeItem*>(parent()))
	{
		int i = 0;
		for (auto it = parent_item->pimpl->m_children.begin();
			it != parent_item->pimpl->m_children.end(); ++it, ++i)
		{
			if (it->second == this)
				return i;
		}
	}
	return 0;
}

bool LThemeItem::is_overridable() const
{
	return pimpl->is_overridable();
}

LString LThemeItem::path() const
{
	std::vector<LString> path_names;

	path_names.push_back(object_name());

	LThemeItem* theme_item = dynamic_cast<LThemeItem*>(parent());

	while (theme_item)
	{
		LString name = theme_item->object_name();
		if (!name.empty())
			path_names.insert(path_names.begin(), name);

		theme_item = dynamic_cast<LThemeItem*>(theme_item->parent());
	}

	std::ostringstream joined_names;
	std::copy(path_names.begin(), path_names.end(),
		std::ostream_iterator<LString>(joined_names, "/"));
	std::string result = joined_names.str();

	return result.substr(0, result.length() - 1).c_str();
}

LJsonObject LThemeItem::to_json_object() const
{
	return pimpl->to_json_object();
}
