/*
 * Copyright (C) 2024 The Layers Project
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

#include <Layers/lcontroller.h>

#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/lpaths.h>
#include <Layers/ltheme.h>

using Layers::LDefinition;
using Layers::LString;
using Layers::LTheme;
using Layers::LController;

class LController::Impl
{
public:
	std::map<LString, LTheme*> themes;
	LTheme* active_theme{ nullptr };

	std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>> definition_builders;

	LDefinition* root_definition{ new LDefinition  };

	Impl()
	{
		init_themes();
	}

	~Impl()
	{
		for (auto& theme : themes)
			delete theme.second;
	}

	void add_theme(LTheme* theme)
	{
		if (theme)
			themes[theme->display_id()] = theme;
	}

	std::map<std::filesystem::path, std::string> load_definition_path(
		const std::filesystem::path& path)
	{
		std::map<std::filesystem::path, std::string> file_strings;

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			if (entry.is_regular_file() && entry.path().filename().string()[0] != '_')
			{
				file_strings[entry.path()] = load_json_file(entry.path());
			}
			else if (entry.is_directory())
			{
				std::map<std::filesystem::path, std::string> child_file_strings = 
					load_definition_path(entry.path());

				file_strings.insert(child_file_strings.begin(), child_file_strings.end());
			}
		}

		return file_strings;
	}

	void load_definitions(const std::filesystem::path& path)
	{
		// Load and Parse Aliases
		std::map<std::filesystem::path, std::string> file_strings = load_definition_path(path);
		parse_aliases(path, file_strings);

		// Build Definition Builders

		std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>> unresolved_builders =
			build_definition_builders(file_strings);

		// Build Definitions

		build_definitions(unresolved_builders);

		//// Resolve Links

		//root_definition->resolve_links();

		int x = 26;
	}

	void build_definitions(std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>>& unresolved_builders)
	{
		std::vector<LDefinition*> unparented_definitions;

		while (!unresolved_builders.empty())
		{
			std::set<std::filesystem::path> resolvable_paths;

			for (const auto& [path, file_builders] : unresolved_builders)
			{
				bool ready_to_finalize = true;

				for (const auto& [key, builder] : file_builders)
				{
					if (!builder.base_path.empty())
					{
						if (definition_builders.count(builder.base_path))
						{
							if (!definition_builders[builder.base_path].count(builder.base_name.c_str()))
								ready_to_finalize = false;
						}
						else
							ready_to_finalize = false;
					}
				}

				if (ready_to_finalize)
				{
					resolvable_paths.insert(path);
					//break;
				}
			}

			// If none of the paths can resolve, break the loop
			if (resolvable_paths.empty())
				break;

			for (const auto& path : resolvable_paths)
			{
				for (auto& [key, builder] : unresolved_builders[path])
				{
					// Merge Attributes

					if (!builder.base_path.empty())
					{
						LDefinitionBuilder& base_builder =
							definition_builders[builder.base_path][builder.base_name];

						builder.attributes = merge_attributes(base_builder.attributes, builder.attributes);
					}

					// Create Definition

					LDefinition* def = new LDefinition(key, builder.attributes, path);

					// Append Definition

					if (std::string(key.c_str()).find("/") != std::string::npos)
						unparented_definitions.push_back(def);
					else
						root_definition->append_child(def);

					// Store Builder

					definition_builders[path][key] = builder;
				}

				unresolved_builders.erase(path);
			}
		}

		// Resolve Parents

		for (const auto& unparented_def : unparented_definitions)
		{
			LString unparented_def_name =
				unparented_def->object_name();

			auto name_list = split<std::deque<LString>>(
				unparented_def->object_name(), '/');
			LString new_name = name_list.back();
			name_list.pop_back();

			if (LDefinition* parent_def = root_definition->find_item(name_list))
			{
				unparented_def->set_object_name(new_name);
				unparented_def->set_parent(parent_def);
				parent_def->append_child(unparented_def);
			}
		}
	}

	LJsonObject merge_attributes(const LJsonObject& base_attributes, const LJsonObject& attributes)
	{
		LJsonObject merged_attributes = base_attributes;

		for (const auto& [key, attr_val] : attributes)
		{
			if (merged_attributes.count(key))
			{
				if (attr_val.is_object())
				{
					LJsonObject attr_obj = attr_val.to_object();

					if (attr_obj.count("states"))
					{
						// Append states that are not already present
						// Override states that are already present
					}
				}
				else
					merged_attributes[key] = attr_val;
			}
			else
				merged_attributes[key] = attr_val;
		}

		return merged_attributes;
	}

	void parse_aliases(const std::filesystem::path& path, std::map<std::filesystem::path, std::string>& file_strings)
	{
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			if (entry.is_regular_file() && entry.path().filename() == "_aliases.json")
			{
				std::string aliases_data = load_json_file(entry.path());
				aliases_data = remove_whitespace(aliases_data);

				std::map<LString, LString> aliases;
				LJsonLexer aliases_lexer = LJsonLexer(aliases_data);
				LJsonParser aliases_parser = LJsonParser(aliases_lexer);
				LJsonObject aliases_object = aliases_parser.parse_object();

				for (const auto& [key, object_val] : aliases_object)
					aliases[key] = object_val.to_string();

				for (const auto& [alias_key, alias] : aliases)
				{
					for (auto& [file_path, file_string] : file_strings)
					{
						size_t pos = 0;
						while ((pos = file_string.find(alias_key.c_str(), pos)) != std::string::npos)
						{
							file_string.replace(pos, std::string(alias_key.c_str()).length(), std::string(alias.c_str()));
							pos += std::string(alias.c_str()).length();
						}
					}
				}
			}
		}
	}

	void process_json_object(
		std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>>& definition_builders,
		const std::filesystem::path& file_path,
		const LJsonObject& json_obj,
		const LString& parent_path = "") 
	{
		for (const auto& [key, value] : json_obj) {
			LString current_path = parent_path.empty() ? key : parent_path + "/" + key;

			LDefinitionBuilder definition_builder;

			// Check if this object includes another definition
			if (value.is_string())
			{
				std::string include(value.to_string().c_str());
				size_t delim_pos = include.find("::");
				std::string file_part = include.substr(0, delim_pos);
				std::string widget_name = include.substr(delim_pos + 2);

				// Check if the path contains a slash character
				if (file_part.find('/') != std::string::npos ||
					file_part.find('\\') != std::string::npos)
				{
					definition_builder.base_path = definitions_path() / file_part;
				}
				else
				{
					// File is a relative path within the same project directory
					definition_builder.base_path = file_path.parent_path() / file_part;
				}

				definition_builder.base_name = widget_name.c_str();
			}
			else if (value.is_object())
			{
				LJsonObject value_obj = value.to_object();

				if (value_obj.count("_include"))
				{
					std::string include(value_obj["_include"].to_string().c_str());
					size_t delim_pos = include.find("::");
					std::string file_part = include.substr(0, delim_pos);
					std::string widget_name = include.substr(delim_pos + 2);

					// Check if the path contains a slash character
					if (file_part.find('/') != std::string::npos ||
						file_part.find('\\') != std::string::npos)
					{
						definition_builder.base_path = definitions_path() / file_part;
					}
					else
					{
						// File is a relative path within the same project directory
						definition_builder.base_path = file_path.parent_path() / file_part;
					}

					definition_builder.base_name = widget_name.c_str();
				}

				if (value_obj.count("attributes"))
				{
					definition_builder.attributes = value_obj["attributes"].to_object();
				}

				// Recursively process children if they exist
				if (value_obj.count("children"))
				{
					process_json_object(
						definition_builders,
						file_path,
						value_obj["children"].to_object(),
						current_path);
				}
			}

			definition_builders[file_path][current_path] = definition_builder;
		}
	}

	std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>> build_definition_builders(
		const std::map<std::filesystem::path, std::string>& file_strings)
	{
		std::map<std::filesystem::path, std::map<LString, LDefinitionBuilder>> definition_builders;

		for (const auto& [file_path, content] : file_strings) {
			// Parse the JSON content
			LJsonLexer lexer(content);
			LJsonParser parser(lexer);
			LJsonObject root = parser.parse_object();

			// Process the JSON object to build the definition builders
			for (const auto& [key, value] : root) {
				process_json_object(definition_builders, file_path, root);
			}
		}
		return definition_builders;
	}

	LTheme* load_theme(const std::filesystem::path& directory)
	{
		std::map<std::filesystem::path, std::string> file_strings = 
			load_definition_path(directory);

		// There should only be a single theme file, theme.json

		std::filesystem::path file_path = std::filesystem::path(directory / "theme.json");

		if (file_strings.count(file_path))
		{
			LJsonLexer lexer(file_strings[file_path]);
			LJsonParser parser(lexer);
			LJsonObject json_object = parser.parse_object();

			for (const auto& [key, value] : json_object)
				return new LTheme(key, value, file_path);

				// path_definitions[file_path].push_back(def);

				// for (const std::filesystem::path& dep : def->dependencies())
				// 	if (!dep.empty())
				// 		file_dependencies.insert(dep);

			// if (!file_dependencies.empty())
			// 	dependencies[file_path] = file_dependencies;
		}

		return nullptr;
	}

	void init_themes()
	{
		/*
			TODO: Might need to handle case where theme files labeled "dark" or
			"light" appear in the custom themes directory.
		*/

		// Load prebuilt theme files
		// TEMP: Disabled
		// themes["Dark"] =
		// 	load_theme(std::filesystem::path("./themes/Dark"));
		// 	//new LTheme(std::filesystem::path("./themes/Dark"));
		// themes["Light"] =
		// 	load_theme(std::filesystem::path("./themes/Dark"));
		// 	//new LTheme(std::filesystem::path("./themes/Light"));

		std::filesystem::path latest_path = latest_T_version_path();

		for (const auto& dir_entry :
			std::filesystem::directory_iterator(latest_path))
		{
			if (dir_entry.is_directory())
			   add_theme(load_theme(dir_entry.path()));
		}
	}

    void resolve_base(LDefinition* definition)
    {
        if (definition->has_unresolved_base())
            definition->set_base(root_definition->find_item(definition->base_name()));

        for (const auto& [child_name, child_def] : definition->children())
            resolve_base(child_def);
    }
};

LController::LController() : pimpl(new Impl) {}

LController::~LController()
{
	delete pimpl;
}

LTheme* LController::active_theme() const
{
	return pimpl->active_theme;
}

void LController::add_theme(LTheme* theme)
{
	pimpl->add_theme(theme);
}

LDefinition* LController::find_definition(const LString& path)
{
	if (path == "Theme")
		return active_theme();

	return pimpl->root_definition->find_item(path);
}

LDefinition* LController::find_definition(std::deque<LString> name_list)
{
	if (!name_list.empty() && name_list[0] == "Theme")
		return active_theme();

	return pimpl->root_definition->find_item(name_list);
}

LController& LController::instance()
{
	static LController instance;
	return instance;
}

void LController::include(const LString& path)
{
	pimpl->load_definitions(definitions_path() / std::string(path.c_str()));
}

bool LController::set_active_theme(LTheme* theme)
{
	if (pimpl->active_theme != theme)
	{
		//LTheme* previous_active_theme = pimpl->active_theme;

		pimpl->active_theme = theme;

		// if (previous_active_theme)
		// 	previous_active_theme->clear();

		pimpl->root_definition->resolve_links();

		return true;
	}

	return false;
}

LTheme* LController::theme(const LString& themeId) const
{
	auto it = pimpl->themes.find(themeId);
	return it != pimpl->themes.end() ? it->second : nullptr;
}

std::map<LString, LTheme*> LController::themes() const
{
	return pimpl->themes;
}
