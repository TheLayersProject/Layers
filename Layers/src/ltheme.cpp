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

#include <Layers/ltheme.h>

#include <fstream>

#include <Layers/lalgorithms.h>
#include <Layers/lgenerate.h>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LTheme;
using Layers::LThemeItem;

LTheme::LTheme() {}

LTheme::LTheme(const std::filesystem::path& path) :
	m_path{ path }
{
	std::ifstream meta_file(m_path / "meta.json");

	if (meta_file.is_open())
	{
		std::stringstream buffer;
		buffer << meta_file.rdbuf();
		std::string meta_data = buffer.str();
		meta_file.close();

		meta_data = remove_whitespace(meta_data);

		LJsonLexer meta_lexer = LJsonLexer(meta_data);
		LJsonParser meta_parser = LJsonParser(meta_lexer);
		LJsonObject meta_obj = meta_parser.parse_object();

		m_name = meta_obj["name"].to_string();

		if (meta_obj.find("uuid") != meta_obj.end())
			m_uuid = meta_obj["uuid"].to_string();

		if (meta_obj.find("publisher") != meta_obj.end())
			m_publisher = meta_obj["publisher"].to_string();

		if (meta_obj.find("editable") != meta_obj.end())
			m_editable = meta_obj["editable"].to_bool();

		if (meta_obj.find("lineage") != meta_obj.end())
			for (LJsonValue lineage_value : meta_obj["lineage"].to_array())
				append_to_lineage(lineage_value.to_string());
	}
	else
	{
		std::cerr << "Could not read theme 'meta.json' file" << std::endl;
	}
}

LTheme::LTheme(const std::string& name, bool editable) :
	m_name{ name },
	m_editable{ editable },
	m_uuid{ generate_uuid() }
{
}

LTheme::LTheme(const std::string& name, std::string uuid, bool editable) :
	m_name{ name },
	m_editable{ editable },
	m_uuid{ uuid }
{
}

LTheme::~LTheme()
{
	delete m_root_item;
}

void LTheme::append_to_lineage(const std::string& theme_id)
{
	m_lineage.push_back(theme_id);
}

void LTheme::clear()
{
	if (m_root_item)
	{
		delete m_root_item;
		m_root_item = nullptr;
	}

	m_file_items.clear();
}

std::filesystem::path LTheme::path() const
{
	return m_path;
}

std::string LTheme::display_id() const
{
	if (!m_publisher.empty())
	{
		return m_name + " (" + m_publisher + ")";
	}
	else if (!m_uuid.empty())
	{
		return m_name + " (" + m_uuid + ")";
	}

	return m_name;
}

bool LTheme::editable() const
{
	return m_editable;
}

LThemeItem* LTheme::find_item(const std::string& path)
{
	return m_root_item->find_item(split<std::deque<std::string>>(path, '/'));
}

LThemeItem* LTheme::find_item(const std::deque<std::string>& name_list)
{
	return m_root_item->find_item(name_list);
}

bool LTheme::has_implementation(const std::string& app_display_id) const
{
	std::filesystem::path dir_path = m_path / app_display_id;
	return std::filesystem::exists(dir_path);
}

std::vector<std::string> LTheme::lineage() const
{
	return m_lineage;
}

void LTheme::load(const std::string& app_display_id)
{
	if (std::filesystem::exists(m_path))
	{
		clear();
		m_root_item = new LThemeItem("", {}, false, "");

		load_file((m_path / "app.json").string());

		load_dir(m_path / "Layers");

		std::filesystem::path implementation_dir = m_path / app_display_id;
		if (std::filesystem::exists(implementation_dir))
			load_dir(implementation_dir);

		resolve_parents();
		resolve_links(m_root_item);
	}
}

std::string LTheme::name() const
{
	return m_name;
}

std::string LTheme::publisher() const
{
	return m_publisher;
}

void LTheme::set_name(const std::string& new_name)
{
	m_name = new_name;
}

void LTheme::set_publisher(const std::string& publisher)
{
	m_publisher = publisher;
}

void LTheme::save_meta_file()
{
	LJsonObject json_object;

	LJsonArray lineage_array;

	for (const auto& theme_id : m_lineage)
	{
		lineage_array.emplace_back(theme_id);
	}

	json_object["lineage"] = lineage_array;
	json_object["name"] = m_name;
	json_object["uuid"] = m_uuid;

	if (!m_publisher.empty())
	{
		json_object["publisher"] = m_publisher;
	}

	LJsonValue json_value(json_object);

	std::ofstream meta_file(m_path / "meta.json");

	if (!meta_file.is_open())
	{
		std::cerr << "Could not create theme 'meta.json' file" << std::endl;
		return;
	}

	meta_file << json_value.to_output();
	meta_file.close();
}

void LTheme::set_dir(const std::filesystem::path& path)
{
	m_path = path;
}

void LTheme::resolve_links(LThemeItem* item)
{
	auto resolve = [this](LAttribute* attr)
	{
		if (!attr->link_path().empty())
		{
			std::deque<std::string> name_list =
				split<std::deque<std::string>>(attr->link_path(), '/');
			std::string attr_name = name_list.back();
			name_list.pop_back();

			if (LThemeItem* item = m_root_item->find_item(name_list))
			{
				for (const auto& [key, item_attr] : item->attributes())
				{
					if (item_attr->object_name() == attr_name)
					{
						attr->set_link_attribute(item_attr);
						return;
					}
					else
					{
						for (const auto& [override_key, override_attr] :
							item_attr->overrides())
						{
							if (item_attr->object_name() + "." +
								override_attr->object_name() == attr_name)
							{
								attr->set_link_attribute(override_attr);
								return;
							}
						}
					}
				}
			}
		}
	};

	for (const auto& [key, attr] : item->attributes())
	{
		resolve(attr);

		for (const auto& [override_key, override_attr] : attr->overrides())
			resolve(override_attr);
	}

	for (const auto& [key, child_item] : item->children())
		resolve_links(child_item);
}

void LTheme::resolve_parents()
{
	for (const auto& [key, unparented_theme_item] : m_unparented_theme_items)
	{
		std::string unparented_theme_item_name =
			unparented_theme_item->object_name();

		auto name_list = split<std::deque<std::string>>(
				unparented_theme_item->object_name(), '/');
		std::string new_name = name_list.back();
		name_list.pop_back();

		if (LThemeItem* parent_item = m_root_item->find_item(name_list))
		{
			unparented_theme_item->set_object_name(new_name);
			unparented_theme_item->set_parent(parent_item);
			parent_item->append_child(unparented_theme_item);
		}
	}

	m_unparented_theme_items.clear();
}

LThemeItem* LTheme::root_item() const
{
	return m_root_item;
}

void LTheme::save()
{
	for (const auto& [file_name, file_items] : m_file_items)
	{
		LJsonObject object;

		for (LThemeItem* theme_item : file_items)
		{
			object[theme_item->path()] = theme_item->to_json_object();
		}

		std::ofstream theme_file(file_name);
		if (!theme_file.is_open())
		{
			std::cerr << "Could not write theme file: " << file_name << std::endl;
			continue;
		}

		theme_file << LJsonValue(object).to_output();
		theme_file.close();
	}
}

std::string LTheme::uuid() const
{
	return m_uuid;
}

void LTheme::load_file(const std::string& file_name)
{
	std::ifstream file(file_name, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << __FUNCTION__ << ": Could not read file: " << file_name << std::endl;
		return;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string data = buffer.str();
	file.close();

	data = remove_whitespace(data);

	LJsonLexer lexer = LJsonLexer(data);
	LJsonParser parser = LJsonParser(lexer);
	LJsonObject object = parser.parse_object();

	for (const auto& [key, object_val] : object)
	{
		if (key.find("/") != std::string::npos)
		{
			LThemeItem* new_item = init_item(
				key, object_val.to_object(), file_name);

			m_file_items[file_name].push_back(new_item);

			m_unparented_theme_items[key] = new_item;
		}
		else
		{
			LThemeItem* new_item = init_item(
				key, object_val.to_object(), file_name,
				m_root_item);

			m_file_items[file_name].push_back(new_item);

			m_root_item->append_child(new_item);
		}
	}
}

void LTheme::load_dir(const std::filesystem::path& path)
{
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		if (entry.is_regular_file())
		{
			load_file(entry.path().string());
		}
		else if (entry.is_directory())
		{
			load_dir(entry.path());
		}
	}
}

LThemeItem* LTheme::init_item(const std::string& name,
	LJsonObject item_object, const std::string& file_name, LThemeItem* parent)
{
	LAttributeMap attributes;

	if (item_object.find("attributes") != item_object.end())
	{
		LJsonObject attrs = item_object["attributes"].to_object();

		std::vector<std::string> attrs_keys;

		for (const auto& pair : attrs)
			attrs_keys.push_back(pair.first);
		
		for (const std::string& key : attrs_keys)
			attributes[key] = new LAttribute(
				key, attrs[key].to_object());
	}

	bool is_overridable = false;

	if (item_object.find("is_overridable") != item_object.end() &&
		item_object["is_overridable"].to_bool())
		is_overridable = true;

	LThemeItem* item = new LThemeItem(
		name, attributes, is_overridable, file_name, parent);

	if (item_object.find("children") != item_object.end())
	{
		LJsonObject children = item_object["children"].to_object();

		std::vector<std::string> children_keys;

		for (const auto& pair : children)
			children_keys.push_back(pair.first);

		for (const std::string& key : children_keys)
			item->append_child(
				init_item(key,
					children[key].to_object(), file_name, item));
	}

	return item;
}
