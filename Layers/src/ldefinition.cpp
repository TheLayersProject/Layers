/*
 * Copyright (C) 2025 The Layers Project
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

#include <Layers/ldefinition.h>

#include <string>
#include <vector>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/lobjectfactory.h>
#include <Layers/lpaths.h>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LDefinitionMap;
using Layers::LJsonObject;
using Layers::LString;
using Layers::LDefinition;

class LDefinition::Impl
{
public:
	LDefinition* base{ nullptr };
	std::filesystem::path base_path;
	LString base_name;

	LJsonValue value;
	std::filesystem::path file_path;

	//std::map<LString, LDefinition*> m_children;
	//std::map<LString, LAttribute*> m_attributes;

	LDefinition* style_definition{ nullptr };

	bool m_is_overridable{ false };

	Impl() {}

	Impl(
		LDefinition* self,
		const LJsonValue& value,
		const std::filesystem::path& file_path) :
		file_path{ file_path },
		value{ value }
	{
		// Handle dependency parsing
		auto parse_include = [&](const LString& include_str)
			-> std::pair<std::filesystem::path, LString>
			{
				std::string include(include_str.c_str());
				size_t delim_pos = include.find("::");
				std::string file_part = include.substr(0, delim_pos);
				std::string widget_name = include.substr(delim_pos + 2);
				std::pair<std::filesystem::path, LString> dep_data;

				// Check if the path contains a slash character
				if (file_part.find('/') != std::string::npos ||
					file_part.find('\\') != std::string::npos)
				{
					// External dependency - append definitions_path() to it
					dep_data.first = definitions_path() / file_part;
				}
				else
				{
					// File is a relative path within the same project directory
					dep_data.first = file_path.parent_path() / file_part;
				}

				// Store the widget name in the pair's second value
				dep_data.second = LString(widget_name.c_str());

				return dep_data;
			};

		if (value.is_string())
		{
			// String-based inheritance (e.g., "Widget": "qlbox.json::Box")
			std::pair<std::filesystem::path, LString> base_data = 
				parse_include(value.to_string());

				base_path = base_data.first;
				base_name = base_data.second;
		}
		else if (value.is_object())
		{
			LJsonObject object = value.to_object();

			if (object.find("_include") != object.end())
			{
				// Object-based inheritance (e.g., "Dialog": { "_include": "qlbox.json::Box", ... })
				std::pair<std::filesystem::path, LString> base_data = 
					parse_include(object["_include"].to_string());

				base_path = base_data.first;
				base_name = base_data.second;
			}

			if (object.find("attributes") != object.end())
			{
				LJsonObject json_attrs = object["attributes"].to_object();

				for (const auto& [key, json_attr] : json_attrs)
				{
					//m_attributes[key] = new LAttribute(key, json_attr, self);
					lMake<LAttribute>(self, key, json_attr);
				}
			}

			if (object.find("children") != object.end())
			{
				for (const auto& [key, value] : object["children"].to_object())
				{
					lMake<LDefinition>(self, key, value, file_path);
				}
			}
				//for (const auto& [key, value] : object["children"].to_object())
				//	append_child(new LDefinition(key, value, file_path, self));
		}
	}

	LString file_name() const
	{
		return LString(file_path.filename().string().c_str());
	}

	void merge_from(LDefinition* base, LDefinition* self)
	{
		LAttributeMap attributes = self->attributes();
		LDefinitionMap children = self->children();

		// Merge attributes from base
		for (const auto& [base_key, base_attr] : base->attributes())
		{
			/*
				If *this* definition defines an attribute with the same name as
				a base attribute, then its value/link should automatically take
				precedence over the base attribute.

				However, there may be cases where the derivative attribute only
				defines additional states. To handle this, the derivative
				attribute will acquire the base's value/link as well as any
				base states.
			*/
			if (attributes.count(base_key))
			{
				if (attributes[base_key]->value().index() == 0 &&
					!attributes[base_key]->link())
				{
					if (base_attr->link())
						attributes[base_key]->create_link(base_attr->link());
					else
						attributes[base_key]->set_value(base_attr->value());
				}
				for (const auto& [state, state_attr] : base_attr->states())
				{
					if (!attributes[base_key]->states().count(state))
					{
						//attributes[base_key]->create_state(state, state_attr->value());
						lMake<LAttribute>(attributes[base_key], state, state_attr->value());
					}
				}
			}
			/*
				The following is still being considered.

				The attributes map is not a reference, so adding the base_attr
				here does not actually add the base to this definition's attribute
				list.

				NOTE:
				This might be handled now that attributes() includes base
				attributes!
			*/
			//else
			//{
			//	attributes[base_key] = base_attr;
			//}
		}

		// Recursively merge children
		for (const auto& [base_child_name, base_child] : base->children())
		{
			if (children.count(base_child_name))
			{
				children[base_child_name]->pimpl->merge_from(base_child, children[base_child_name]);
			}
			//else
			//{
			//	m_children[base_child_name] = base_child;
			//}
		}
	}

	bool is_overridable() const
	{
		return m_is_overridable;
	}
};

LDefinition::LDefinition() :
	pimpl{ std::make_unique<Impl>() },
	LObject() {}

LDefinition::LDefinition(
	const LString& name,
	const LJsonValue& value,
	const std::filesystem::path& file_path,
	LObject* parent
) :
	pimpl{ std::make_unique<Impl>(this, value, file_path) },
	LObject(parent)
{
	set_object_name(name);

	//for (const auto& [key, attr] : attributes())
	//	attr->set_parent(this);

	//for (const auto& [name, definition] : children())
	//	definition->set_parent(this);
}

LDefinition::~LDefinition() = default;

//void LDefinition::append_child(LDefinition* child)
//{
//	pimpl->append_child(child);
//}

void LDefinition::apply_style(LDefinition* style_def)
{
	pimpl->style_definition = style_def;

	const auto& style_attrs = style_def->attributes();
	if (!style_attrs.empty())
	{
		for (const auto& [attr_name, attr] : attributes())
		{
			auto it = style_attrs.find(attr->object_name());
			if (it != style_attrs.end())
			{
				attr->set_definition_attribute(it->second);
			}
		}
	}

	const auto& style_children = style_def->children();
	if (!style_children.empty())
	{
		for (auto [child_name, child] : children())
		{
			auto it = style_children.find(child->object_name());
			if (it != style_children.end())
			{
				child->apply_style(it->second);
			}
		}
	}

	//pimpl->apply_style(style_def);
}

std::vector<LString> LDefinition::attribute_group_names() const
{
	std::vector<LString> attribute_group_names;

	for (const auto& [key, attr] : attributes())
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

	//return pimpl->attribute_group_names();
}

std::map<LString, LAttribute*> LDefinition::attributes(int type_index) const
{
	LAttributeMap attributes;

	std::vector<LAttribute*> attr_list = find_children<LAttribute>();

	for (const auto& attr : attr_list)
	{
		attributes[attr->object_name()] = attr;
	}

	// Need to add any base attributes with names that are not already in the
	// attributes map

	if (pimpl->base)
	{
		LAttributeMap base_attrs = pimpl->base->attributes();

		for (const auto& [key, attr] : base_attrs)
		{
			if (attributes.find(key) == attributes.end())
			{
				attributes[key] = attr;
			}
		}
	}

	if (type_index < 0)
		return attributes;

	LAttributeMap filtered_attrs;

	for (const auto& [key, attr] : attributes)
		if (attr->type_index() == type_index)
			filtered_attrs[key] = attr;

	return filtered_attrs;

	//return pimpl->attributes(this, type_index);
}

LDefinition *LDefinition::base() const
{
    return pimpl->base;
}
LString LDefinition::base_name() const
{
	return pimpl->base_name;
}

LDefinition* LDefinition::child(int index) const
{
	const std::map<LString, LDefinition*>& c = children();

	if (index < 0 || index >= c.size())
		return nullptr;

	auto it = c.begin();
	std::advance(it, index);

	return it->second;

	//return pimpl->child(index);
}

size_t LDefinition::child_count() const
{
	return children().size();

	//return pimpl->child_count();
}

std::map<LString, LDefinition*> LDefinition::children() const
{
	std::map<LString, LDefinition*> children;

	std::vector<LDefinition*> children_list = find_children<LDefinition>();

	for (const auto& child : children_list)
	{
		if (child->pimpl->file_name() == file_name())
		{
			children[child->object_name()] = child;
		}
	}

	// Need to add any base children with names that are not already in the
	// children map

	if (pimpl->base)
	{
		LDefinitionMap base_children = pimpl->base->children();

		for (const auto& [key, child] : base_children)
		{
			if (children.find(key) == children.end())
			{
				children[key] = child;
			}
		}
	}

	return children;

	//return pimpl->m_children;
}

void LDefinition::clear_style()
{
	if (pimpl->style_definition)
	{
		const auto& style_attrs = pimpl->style_definition->attributes();
		if (!style_attrs.empty())
		{
			for (const auto& [attr_name, attr] : attributes())
			{
				auto it = style_attrs.find(attr->object_name());
				if (it != style_attrs.end())
				{
					attr->clear_definition_attribute();
				}
			}
		}

		const auto& style_children = pimpl->style_definition->children();
		if (!style_children.empty())
		{
			for (auto [child_name, child] : children())
			{
				auto it = style_children.find(child->object_name());
				if (it != style_children.end())
				{
					child->clear_style();
				}
			}
		}

		pimpl->style_definition = nullptr;
	}

	//pimpl->clear_style();
}

std::set<LDefinition*> LDefinition::dependencies()
{
	std::set<LDefinition*> dependencies;

	if (pimpl->base)
		dependencies.insert(pimpl->base);

	for (const auto& [name, child_def] : children())
		for (const auto& child_dep : child_def->dependencies())
			if (child_dep)
				dependencies.insert(child_dep);

	return dependencies;

	//return pimpl->dependencies();
}

LString LDefinition::file_name() const
{
	return pimpl->file_name();
}

void LDefinition::finalize()
{
	// Finalize all children first
	for (const auto& [child_name, child] : children())
	{
		child->finalize();
	}

	if (pimpl->base)
	{
		pimpl->merge_from(pimpl->base, this);
	}

	//pimpl->finalize();
}

LAttribute* LDefinition::find_attribute(const LString& name)
{
	for (auto [attr_name, attr] : attributes())
	{
		if (attr_name == name)
			return attr;
	}

	return nullptr;

	//return pimpl->find_attribute(attr_name);
}

LDefinition* LDefinition::find_item(const LString& path)
{
	return find_item(split<std::deque<LString>>(path, '/'));
}

LDefinition* LDefinition::find_item(std::deque<LString> name_list)
{
	if (!name_list.empty())
	{
		std::deque<LString> new_name_list = name_list;

		LString name = *new_name_list.begin();
		new_name_list.pop_front();

		// Check children
		for (const auto& [key, child_item] : children())
		{
			if (child_item->object_name() == name)
			{
				if (new_name_list.empty())
					return child_item;
				else
					return child_item->find_item(new_name_list);
			}
		}
	}

	return nullptr;

	//return pimpl->find_item(name_list);
}

bool LDefinition::has_unresolved_base() const
{
	if (!pimpl->base && !pimpl->base_path.empty() && !pimpl->base_name.empty())
		return true;
	
	return false;
}

int LDefinition::index() const
{
	if (LDefinition* parent_item = dynamic_cast<LDefinition*>(parent()))
	{
		auto parent_children = parent_item->children();

		int i = 0;
		for (auto it = parent_children.begin();
			it != parent_children.end(); ++it, ++i)
		{
			if (it->second == this)
				return i;
		}
	}
	return 0;
}

bool LDefinition::is_overridable() const
{
	return pimpl->is_overridable();
}

LString LDefinition::path() const
{
	std::vector<LString> path_names;

	path_names.push_back(object_name());

	LDefinition* definition = dynamic_cast<LDefinition*>(parent());

	while (definition)
	{
		LString name = definition->object_name();
		if (!name.empty())
			path_names.insert(path_names.begin(), name);

		definition = dynamic_cast<LDefinition*>(definition->parent());
	}

	std::ostringstream joined_names;
	std::copy(path_names.begin(), path_names.end(),
		std::ostream_iterator<LString>(joined_names, "/"));
	std::string result = joined_names.str();

	return result.substr(0, result.length() - 1).c_str();
}

LDefinition* LDefinition::parent() const
{
	if (LObject* p = LObject::parent())
	{
		if (LDefinition* p_as_def = dynamic_cast<LDefinition*>(p))
			return p_as_def;
	}

	return nullptr;
}

void LDefinition::resolve_links()
{
	for (const auto& [attr_name, attr] : attributes())
		attr->resolve_links();

	for (const auto& [def_name, def] : children())
		def->resolve_links();
}

void LDefinition::set_base(LDefinition* base_def)
{
	pimpl->base = base_def;
}

LJsonObject LDefinition::to_json_object() const
{
	LJsonObject item_object;
	LJsonObject attributes_object;
	LJsonObject children_object;

	for (const auto& [key, attr] : attributes())
	{
		LJsonObject attr_object = attr->to_json_object();

		if (attr_object.size() == 1 &&
			attr_object.begin()->first == "value")
		{
			attributes_object[key] = attr_object["value"];
		}
		else
		{
			attributes_object[key] = attr_object;
		}
	}

	for (const auto& [key, child] : children())
		if (child->pimpl->file_name() == file_name())
			children_object[child->object_name()] =
			child->to_json_object();

	if (!attributes_object.empty())
		item_object["attributes"] = attributes_object;

	if (!children_object.empty())
		item_object["children"] = children_object;

	return item_object;

	//return pimpl->to_json_object();
}
