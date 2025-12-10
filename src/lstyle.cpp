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

#include <Layers/lstyle.h>

#include <string>
#include <vector>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LStyleMap;
using Layers::LString;
using Layers::LStyle;

class LStyle::Impl
{
public:
	LStyle* base{ nullptr };
	std::filesystem::path base_path;
	LString base_name;

	LString publisher;

	json value;
	std::filesystem::path file_path;

	// Stores unrecognized '_' prefixed keys
	json extensions;

	LStyle* style_definition{ nullptr };

	LConnector<> connector_style_applied;

	bool m_is_overridable{ false };

	Impl() {}

	Impl(
		LStyle* self,
		const json& value,
		const std::filesystem::path& file_path) :
		file_path{ file_path },
		value{ value }
	{
		// Handle dependency parsing
		auto parse_include = [&](const std::string& include_str)
            -> std::pair<std::filesystem::path, LString>
            {
                size_t delim_pos = include_str.find("::");
                std::string file_part = include_str.substr(0, delim_pos);
                std::string widget_name = include_str.substr(delim_pos + 2);
                std::pair<std::filesystem::path, LString> dep_data;

                if (file_part.find('/') != std::string::npos ||
                    file_part.find('\\') != std::string::npos)
                {
                    //dep_data.first = styles_path() / file_part;
					dep_data.first = file_part;
                }
                else
                {
                    dep_data.first = file_path.parent_path() / file_part;
                }

                dep_data.second = widget_name;
                return dep_data;
            };

		if (value.is_string())
		{
			// String-based inheritance (e.g., "Widget": "qlbox.json::Box")
			std::pair<std::filesystem::path, LString> base_data = 
				parse_include(value.get<std::string>());

				base_path = base_data.first;
				base_name = base_data.second;
		}
		else if (value.is_object())
		{
			if (value.contains("_meta"))
			{
				auto meta = value["_meta"];

				if (meta.contains("_publisher"))
				{
					publisher = meta["_publisher"].get<std::string>();
				}
			}

			if (value.contains("_include"))
			{
				// Object-based inheritance (e.g., "Dialog": { "_include": "qlbox.json::Box", ... })
				auto base_data = parse_include(value["_include"].get<std::string>());
                base_path = base_data.first;
                base_name = base_data.second;
			}

			if (value.contains("attributes"))
			{
				for (const auto& [key, json_attr] : value["attributes"].items())
				{
					//m_attributes[key] = new LAttribute(key, json_attr, self);
					lMake<LAttribute>(self, key, json_attr);
				}
			}

			if (value.contains("children"))
			{
				for (const auto& [key, value] : value["children"].items())
				{
					lMake<LStyle>(self, key, value, file_path);
				}
			}

			for (const auto& [key, val] : value.items())
			{
					if (!key.empty() && key[0] == '_' &&
							key != "_meta" && 
							key != "_include")
					{
							extensions[key] = val;
					}
			}
		}
	}

	LString file_name() const
	{
		return file_path.filename().string();
	}

	void merge_from(LStyle* base, LStyle* self)
	{
		LAttributeMap attributes = self->attributes();
		LStyleMap children = self->children();

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

LStyle::LStyle() :
	pimpl{ new Impl() },
	LObject() {}

LStyle::LStyle(
	const LString& name,
	const json& value,
	const std::filesystem::path& file_path
) :
	pimpl{ new Impl(this, value, file_path) },
	LObject()
{
	set_object_name(name);

	//for (const auto& [key, attr] : attributes())
	//	attr->set_parent(this);

	//for (const auto& [name, definition] : children())
	//	definition->set_parent(this);
}

LStyle::~LStyle()
{
	delete pimpl;
}

//void LStyle::append_child(LStyle* child)
//{
//	pimpl->append_child(child);
//}

void LStyle::apply_style(LStyle* style_def)
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
				attr->set_style_attribute(it->second);
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

	pimpl->connector_style_applied.execute();

	//pimpl->apply_style(style_def);
}

std::vector<LString> LStyle::attribute_group_names() const
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

std::map<LString, LAttribute*> LStyle::attributes(int type_index) const
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

LStyle *LStyle::base() const
{
    return pimpl->base;
}
LString LStyle::base_name() const
{
	return pimpl->base_name;
}

LStyle* LStyle::child(int index) const
{
	const std::map<LString, LStyle*>& c = children();

	if (index < 0 || index >= c.size())
		return nullptr;

	auto it = c.begin();
	std::advance(it, index);

	return it->second;

	//return pimpl->child(index);
}

size_t LStyle::child_count() const
{
	return children().size();

	//return pimpl->child_count();
}

std::map<LString, LStyle*> LStyle::children() const
{
	std::map<LString, LStyle*> children;

	std::vector<LStyle*> children_list = find_children<LStyle>();

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
		LStyleMap base_children = pimpl->base->children();

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

void LStyle::clear_style()
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
					attr->clear_style_attribute();
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

	pimpl->connector_style_applied.execute();

	//pimpl->clear_style();
}

std::set<LStyle*> LStyle::dependencies()
{
	std::set<LStyle*> dependencies;

	if (pimpl->base)
		dependencies.insert(pimpl->base);

	for (const auto& [name, child_def] : children())
		for (const auto& child_dep : child_def->dependencies())
			if (child_dep)
				dependencies.insert(child_dep);

	return dependencies;

	//return pimpl->dependencies();
}

json LStyle::extension(const LString& key) const
{
    if (pimpl->extensions.contains(key))
        return pimpl->extensions[key];

    return json{};
}

const json& LStyle::extensions() const
{
    return pimpl->extensions;
}

LString LStyle::file_name() const
{
	return pimpl->file_name();
}

void LStyle::finalize()
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

LAttribute* LStyle::find_attribute(const LString& name)
{
	for (auto [attr_name, attr] : attributes())
	{
		if (attr_name == name)
			return attr;
	}

	return nullptr;

	//return pimpl->find_attribute(attr_name);
}

LStyle* LStyle::find_item(const LString& path)
{
	return find_item(split<std::deque<LString>>(path, '/'));
}

LStyle* LStyle::find_item(std::deque<LString> name_list)
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

bool LStyle::has_extension(const LString& key) const
{
    return pimpl->extensions.contains(key);
}

bool LStyle::has_unresolved_base() const
{
	if (!pimpl->base && !pimpl->base_path.empty() && !pimpl->base_name.empty())
		return true;
	
	return false;
}

int LStyle::index() const
{
	if (LStyle* parent_item = dynamic_cast<LStyle*>(parent()))
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

bool LStyle::is_overridable() const
{
	return pimpl->is_overridable();
}

void LStyle::on_style_applied(std::function<void()> callback)
{
	pimpl->connector_style_applied.connect(callback);
}

LString LStyle::path() const
{
	std::vector<LString> path_names;

	path_names.push_back(object_name());

	LStyle* definition = dynamic_cast<LStyle*>(parent());

	while (definition)
	{
		LString name = definition->object_name();
		if (!name.empty())
			path_names.insert(path_names.begin(), name);

		definition = dynamic_cast<LStyle*>(definition->parent());
	}

	std::ostringstream joined_names;
	std::copy(path_names.begin(), path_names.end(),
		std::ostream_iterator<LString>(joined_names, "/"));
	std::string result = joined_names.str();

	return result.substr(0, result.length() - 1);
}

LStyle* LStyle::parent() const
{
	if (LObject* p = LObject::parent())
	{
		if (LStyle* p_as_def = dynamic_cast<LStyle*>(p))
			return p_as_def;
	}

	return nullptr;
}

LString LStyle::publisher() const
{
	return pimpl->publisher;
}

void LStyle::resolve_links()
{
	for (const auto& [attr_name, attr] : attributes())
		attr->resolve_links();

	for (const auto& [def_name, def] : children())
		def->resolve_links();
}

void LStyle::set_base(LStyle* base_def)
{
	pimpl->base = base_def;
}

void LStyle::set_publisher(const LString& publisher)
{
	pimpl->publisher = publisher;
}

LStyle* LStyle::style() const
{
	return pimpl->style_definition;
}

json LStyle::to_json_object() const
{
    json item_object;
    json attributes_object;
    json children_object;

    // Serialize Attributes
    for (const auto& [key, attr] : attributes())
    {
        json attr_object = attr->to_json_object();

        // Check if we should unwrap the value (shorthand notation)
        // e.g. "Color": { "value": "#FFF" } -> "Color": "#FFF"
        if (attr_object.size() == 1 && attr_object.contains("value"))
        {
            attributes_object[key] = attr_object["value"];
        }
        else
        {
            attributes_object[key] = attr_object;
        }
    }

    // Serialize Children
    for (const auto& [key, child] : children())
    {
        if (child->pimpl->file_name() == file_name())
        {
            children_object[child->object_name()] = child->to_json_object();
        }
    }

    // Assemble final object
    if (!attributes_object.empty())
        item_object["attributes"] = attributes_object;

    if (!children_object.empty())
        item_object["children"] = children_object;

		for (const auto& [key, val] : pimpl->extensions.items())
        item_object[key] = val;

    return item_object;
}