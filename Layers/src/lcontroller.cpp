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

	LDefinition* root_definition{ new LDefinition("", LJsonValue(), "") };

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

	// void finalize_attributes(LDefinition* def)
	// {
	// 	/* 
	// 		TODO:
	// 		The attributes() function needs to only operate on
	// 		local attributes, not base attributes.
	// 	*/
	// 	for (auto [attr_name, attr] : def->attributes())
	// 		attr->finalize();

	// 	for (auto [child_name, child] : def->children())
	// 		finalize_attributes(child);
	// }

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
        std::map<std::filesystem::path, std::string> file_strings = 
			load_definition_path(path);

		std::map<std::filesystem::path, std::set<std::filesystem::path>>
            dependencies;

        std::map<std::filesystem::path, std::vector<LDefinition*>>
            path_definitions;
		
        std::vector<LDefinition*> unparented_definitions;

		// Parse aliases

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
							pos += std::string(alias.c_str()).length(); // Move past the last replaced substring
						}
					}
				}
			}
		}

        // Init Definitions

        for (const auto& [file_path, file_string] : file_strings)
        {
            LJsonLexer lexer(file_string);
			LJsonParser parser(lexer);
			LJsonObject json_object = parser.parse_object();

            std::set<std::filesystem::path> file_dependencies;

            for (const auto& [key, value] : json_object)
            {
                LDefinition* def = new LDefinition(key, value, file_path);

                path_definitions[file_path].push_back(def);

                for (const std::filesystem::path& dep : def->dependencies())
                    if (!dep.empty())
                        file_dependencies.insert(dep);
            }

            if (!file_dependencies.empty())
                dependencies[file_path] = file_dependencies;
        }

        // Resolve Parents

        for (const auto& [path, definitions] : path_definitions)
            for (const auto& def : definitions)
            {
                if (std::string(def->object_name().c_str()).find("/") != std::string::npos)
                    unparented_definitions.push_back(def);
                else
                    root_definition->append_child(def);
            }

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

        // Resolve Inheritances

        while (!dependencies.empty())
        {
            std::set<std::filesystem::path> resolvable_paths;

            for (const auto& [path, file_dependencies] : dependencies)
            {
                bool ready_to_finalize = true;

                for (const auto& dep : file_dependencies)
                    if (dependencies.count(dep))
                        ready_to_finalize = false;

                if (ready_to_finalize)
                    resolvable_paths.insert(path);
            }

            // If none of the paths can resolve, break the loop
            if (resolvable_paths.empty())
                break;

            for (const auto& path : resolvable_paths)
            {
                for (const auto& definition : path_definitions[path])
                    resolve_base(definition);

                dependencies.erase(path);
            }
        }

		// Copy Base

		//for (const auto& [path, definitions] : path_definitions)
		//	for (const auto& def : definitions)
		//		def->copy_base();

		// Finalize Attributes

		//for (const auto& [path, definitions] : path_definitions)
  //          for (const auto& def : definitions)
		//		def->finalize_attributes();
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

    // void resolve_links(LDefinition* definition)
	// {
	// 	auto resolve = [this](LAttribute* attr)
	// 		{
	// 			if (!attr->link_path().empty())
	// 			{
	// 				auto name_list =
	// 					split<std::deque<LString>>(attr->link_path(), '/');
	// 				LString attr_name = name_list.back();
	// 				name_list.pop_back();

	// 				if (LDefinition* item = root__linksdefinition->find_item(name_list))
	// 				{
	// 					for (const auto& [key, item_attr] : item->attributes())
	// 					{
	// 						if (item_attr->object_name() == attr_name)
	// 						{
	// 							attr->set_link_attribute(item_attr);
	// 							return;
	// 						}
	// 						else
	// 						{
	// 							for (const auto& [override_key, override_attr] :
	// 								item_attr->overrides())
	// 							{
	// 								if (item_attr->object_name() + "." +
	// 									override_attr->object_name() == attr_name)
	// 								{
	// 									attr->set_link_attribute(override_attr);
	// 									return;
	// 								}
	// 							}
	// 						}
	// 					}
	// 				}
	// 			}
	// 		};

	// 	for (const auto& [key, attr] : definition->attributes())
	// 	{
	// 		resolve(attr);

	// 		for (const auto& [override_key, override_attr] : attr->overrides())
	// 			resolve(override_attr);
	// 	}

	// 	for (const auto& [key, child_def] : definition->children())
	// 		resolve_links(child_def);
	// }
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
