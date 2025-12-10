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

#include <Layers/lcontroller.h>

#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/lconnector.h>
#include <Layers/lresources.h>
//#include <Layers/lstyle.h>
#include <Layers/ltheme.h>

using Layers::LStyle;
using Layers::LString;
using Layers::LStringList;
using Layers::LStyle;
using Layers::LStyleList;
using Layers::LTheme;
using Layers::LController;

using DependencyGraph = std::map<LStyle*, std::vector<LStyle*>>;
using DependencyCount = std::map<LStyle*, int>;

struct DependencyData
{
	DependencyGraph graph;
	DependencyCount indegree;
};

class LController::Impl
{
public:
    std::unique_ptr<LStyle> root_style{ std::make_unique<LStyle>() };

    std::map<LString, std::unique_ptr<LStyle>> custom_styles;
    std::map<LString, std::unique_ptr<LTheme>> themes;

    LStyleList active_custom_styles;
    LTheme* active_theme{ nullptr };

    std::map<LString, std::unique_ptr<LStyle>> unparented_styles;

    LConnector<LTheme*> connector_theme_added;

    void add_custom_style(std::unique_ptr<LStyle> custom_style)
    {
        if (custom_style)
            custom_styles[custom_style->object_name()] = std::move(custom_style);
    }

    void add_theme(std::unique_ptr<LTheme> theme)
    {
        if (theme)
        {
            connector_theme_added.execute(theme.get());
            themes[theme->display_id()] = std::move(theme);
        }
    }

    // 2. Return std::map<path, json> instead of LJsonObject
    std::map<std::filesystem::path, json> build_file_objects(
        const std::map<std::filesystem::path, std::string>& file_strings)
    {
        std::map<std::filesystem::path, json> file_objects;

        for (const auto& [file_path, content] : file_strings)
        {
            try
            {
                // nlohmann::json::parse handles whitespace and errors
                file_objects[file_path] = json::parse(content);
            }
            catch (const json::parse_error& e)
            {
                std::cerr << "JSON Parse Error in " << file_path << ": " << e.what() << std::endl;
            }
        }

        return file_objects;
    }

    DependencyData build_dependency_data(const std::set<LStyle*>& styles)
    {
        DependencyGraph graph;
        DependencyCount indegree;

        for (LStyle* def : styles)
        {
            graph[def];
            indegree[def];

            for (LStyle* base : def->dependencies())
            {
                if (styles.find(base) == styles.end())
                    continue;

                graph[base].push_back(def);
                ++indegree[def];
            }
        }

        return { graph, indegree };
    }

    std::vector<LStyle*> topological_sort(DependencyData& dep_data)
    {
        std::vector<LStyle*> sorted;
        std::deque<LStyle*> queue;

        for (auto& [def, count] : dep_data.indegree)
            if (count == 0)
                queue.push_back(def);

        while (!queue.empty())
        {
            LStyle* def = queue.front();
            queue.pop_front();
            sorted.push_back(def);

            for (LStyle* dependent : dep_data.graph.at(def))
                if (--dep_data.indegree[dependent] == 0)
                    queue.push_back(dependent);
        }

        for (const auto& [def, count] : dep_data.indegree)
            if (count > 0)
                throw std::runtime_error("Cycle detected in dependency graph");

        return sorted;
    }

    std::set<LStyle*> build_styles(
        const std::map<std::filesystem::path, json>& file_objects)
    {
        std::set<LStyle*> styles;

        for (const auto& [file_path, object] : file_objects)
        {
            for (const auto& [key, value] : object.items())
            {
                // LStyle constructor now accepts (LString, json, path)
                std::unique_ptr<LStyle> def =
                    std::make_unique<LStyle>(key, value, "");

                styles.insert(def.get());

                if (key.find('/') != std::string::npos)
                {
                    unparented_styles[key] = std::move(def);
                }
                else
                {
                    root_style->add_child(std::move(def));
                }
            }
        }

        return styles;
    }

    // 5. Refactor merge using json types
    json merge_attributes(const json& base_attributes, const json& attributes)
    {
        json merged_attributes = base_attributes;

        for (const auto& [key, attr_val] : attributes.items())
        {
            if (merged_attributes.contains(key))
            {
                if (attr_val.is_object())
                {
                    // Logic for deep merging states if needed
                    // For now, mirroring your existing logic (which was incomplete in source)
                    /*
                    json& base_obj = merged_attributes[key];
                    if (attr_val.contains("states")) { ... }
                    */
                    // Fallback to overwrite for now, or implement deep merge here
                     merged_attributes[key] = attr_val;
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
                // No need for remove_whitespace(aliases_data); json::parse handles it.

                std::map<LString, LString> aliases;
                try 
                {
                    json aliases_object = json::parse(aliases_data);

                    for (const auto& [key, val] : aliases_object.items())
                        aliases[key] = val.get<std::string>();
                }
                catch (const json::parse_error& e)
                {
                    std::cerr << "Error parsing aliases: " << e.what() << std::endl;
                    continue;
                }

                for (const auto& [alias_key, alias] : aliases)
                {
                    for (auto& [file_path, file_string] : file_strings)
                    {
                        size_t pos = 0;
                        while ((pos = file_string.find(alias_key, pos)) != std::string::npos)
                        {
                            file_string.replace(pos, alias_key.length(), alias);
                            pos += alias.length();
                        }
                    }
                }
            }
        }
    }

    std::map<std::filesystem::path, std::string> load_style_path(
        const std::filesystem::path& path)
    {
        std::map<std::filesystem::path, std::string> file_strings;

        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            if (entry.path().extension() != ".json")
                continue;

            if (entry.is_regular_file() && entry.path().filename().string()[0] != '_')
            {
                file_strings[entry.path()] = load_json_file(entry.path());
            }
            else if (entry.is_directory())
            {
                std::map<std::filesystem::path, std::string> child_file_strings =
                    load_style_path(entry.path());

                file_strings.insert(child_file_strings.begin(), child_file_strings.end());
            }
        }

        return file_strings;
    }

    void process_style_set(
        const std::filesystem::path& path,
        std::map<std::filesystem::path, std::string>& file_strings)
    {
        auto file_objects = build_file_objects(file_strings);

        std::set<LStyle*> unresolved_styles = build_styles(file_objects);
        for (LStyle* def : unresolved_styles)
            resolve_base(def);

        DependencyData dep_data = build_dependency_data(unresolved_styles);
        std::vector<LStyle*> ordered_styles = topological_sort(dep_data);

        for (LStyle* def : ordered_styles)
            def->finalize();

        // Resolve unparented styles
        for (auto& [_, unparented_def] : unparented_styles)
        {
            LString unparented_def_name = unparented_def->object_name();
            auto name_list = split<std::deque<LString>>(unparented_def->object_name(), '/');
            LString new_name = name_list.back();
            name_list.pop_back();

            if (LStyle* parent_def = root_style->find_item(name_list))
            {
                unparented_def->set_object_name(new_name);
                parent_def->add_child(std::move(unparented_def));
            }
        }

        // Cleanup empty unique_ptrs from map
        for (auto it = unparented_styles.begin(); it != unparented_styles.end(); )
        {
            if (it->second == nullptr)
                it = unparented_styles.erase(it);
            else 
                ++it;
        }
    }

    void load_styles(const std::filesystem::path& path)
    {
        std::map<std::filesystem::path, std::string> file_strings = load_style_path(path);
        parse_aliases(path, file_strings);
        process_style_set(path, file_strings);
    }

    void load_internal_styles(const LString& path)
    {
        std::map<LString, LResource> set_resources = lResourceManager.resources(path);
        std::map<std::filesystem::path, std::string> file_strings;

        for (const auto& [resource_path, resource] : set_resources)
        {
            // Ensure null termination safe string creation
            std::string resource_string(
                reinterpret_cast<const char*>(resource.data), resource.size);

            file_strings[std::filesystem::path(resource_path)] =
                remove_whitespace(resource_string); 
                // remove_whitespace kept here ONLY if you rely on it for aliases string replacement logic later
        }

        process_style_set(path, file_strings);
    }

    std::unique_ptr<LStyle> load_custom_style(const std::filesystem::path& style_file_path)
    {
        std::string style_file_str = load_json_file(style_file_path);
        
        try 
        {
            // 6. Parsing logic updated
            json file_json = json::parse(style_file_str);

            for (const auto& [key, value] : file_json.items())
                return std::make_unique<LStyle>(key, value, style_file_path);
        }
        catch (const json::parse_error& e)
        {
            std::cerr << "Failed to parse custom style " << style_file_path << ": " << e.what() << std::endl;
            return nullptr;
        }
    }

    void load_custom_styles(const std::filesystem::path& path)
    {
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            if (entry.is_directory())
            {
                // Check if enry contains style.json file
                std::filesystem::path style_file_path = entry.path() / "style.json";

                if (std::filesystem::exists(style_file_path))
                {
                    add_custom_style(load_custom_style(style_file_path));
                }
            }
        }
    }

    std::unique_ptr<LTheme> load_theme(const std::filesystem::path& directory)
    {
        std::map<std::filesystem::path, std::string> file_strings = 
            load_style_path(directory);

        std::filesystem::path file_path = directory / "theme.json";

        if (file_strings.count(file_path))
        {
            try
            {
                json json_object = json::parse(file_strings[file_path]);

                for (const auto& [key, value] : json_object.items())
                    return std::make_unique<LTheme>(key, value, file_path);
            }
            catch (const json::parse_error& e)
            {
                std::cerr << "Failed to parse theme " << directory << ": " << e.what() << std::endl;
            }
        }

        return nullptr;
    }

    std::unique_ptr<LTheme> load_theme(const std::string& file_string)
    {
        try
        {
            json json_object = json::parse(file_string);
            for (const auto& [key, value] : json_object.items())
                return std::make_unique<LTheme>(key, value, "");
        }
        catch (...) {}

        return nullptr;
    }

    void load_themes(const std::filesystem::path& path)
    {
        if (!std::filesystem::exists(path)) return;

        for (const auto& dir_entry : std::filesystem::directory_iterator(path))
        {
            if (dir_entry.is_directory())
            {
                add_theme(std::move(load_theme(dir_entry.path())));
            }
        }
    }

    void resolve_base(LStyle* style)
    {
        if (style->has_unresolved_base())
            style->set_base(root_style->find_item(style->base_name()));

        for (const auto& [child_name, child_def] : style->children())
            resolve_base(child_def);
    }
};

LController::LController() : pimpl{ new Impl() } {}

LController::~LController()
{
	delete pimpl;
}

LStyleList LController::active_custom_styles()
{
	return pimpl->active_custom_styles;
}

LTheme* LController::active_theme() const
{
	return pimpl->active_theme;
}

void LController::add_theme(std::unique_ptr<LTheme> theme)
{
	pimpl->add_theme(std::move(theme));
}

LStyle* LController::find_style(const LString& path)
{
	if (path == "Theme")
		return active_theme();

	return pimpl->root_style->find_item(path);
}

LStyle* LController::find_style(std::deque<LString> name_list)
{
	if (!name_list.empty() && name_list[0] == "Theme")
		return active_theme();

	return pimpl->root_style->find_item(name_list);
}

LController& LController::instance()
{
	static LController instance;
	return instance;
}

std::unique_ptr<LTheme> LController::load_theme(const std::string& file_string)
{
	return pimpl->load_theme(file_string);
}

void LController::load_themes(const std::filesystem::path& path)
{
	pimpl->load_themes(path);
}

void LController::load_user_styles(const std::filesystem::path& path)
{
    pimpl->load_custom_styles(path);
}

void LController::on_theme_added(std::function<void(LTheme*)> callback)
{
	pimpl->connector_theme_added.connect(callback);
}

LStyle* LController::root_style() const
{
	return pimpl->root_style.get();
}

void LController::include(const LString& path, bool is_application)
{
	pimpl->load_styles(path);

	//if (is_application)
	//	pimpl->load_styles(styles_path() / path));
}

void LController::include_internal(const LString& path)
{
	pimpl->load_internal_styles(path);
}

bool LController::set_active_theme(LTheme* theme)
{
	if (pimpl->active_theme != theme)
	{
		pimpl->active_theme = theme;

		pimpl->root_style->resolve_links();

		return true;
	}

	return false;
}

std::map<LString, std::unique_ptr<LStyle>>& LController::styles() const
{
	return pimpl->custom_styles;
}

LTheme* LController::theme(const LString& themeId) const
{
	auto it = pimpl->themes.find(themeId);
	return it != pimpl->themes.end() ? it->second.get() : nullptr;
}

std::map<LString, std::unique_ptr<LTheme>>& LController::themes() const
{
	return pimpl->themes;
}

bool LController::toggle_custom_style(const LString& style_id)
{
	LStyle* style = pimpl->custom_styles[style_id].get();

	if (std::count(pimpl->active_custom_styles.begin(), pimpl->active_custom_styles.end(), style))
	{
		// Style is already active, so it needs to be toggled off here!

		for (const auto& [style_def_name, style_def] : style->children())
		{
			if (LStyle* def = pimpl->root_style->find_item(style_def_name))
			{
				def->clear_style();
			}
		}

		auto it = std::find(pimpl->active_custom_styles.begin(), pimpl->active_custom_styles.end(), style);
		if (it != pimpl->active_custom_styles.end())
		{
			pimpl->active_custom_styles.erase(it);
		}

		return false;
	}

	// Otherwise, the style needs to be toggled on

	for (const auto& [style_def_name, style_def] : style->children())
	{
		if (LStyle* def = pimpl->root_style->find_item(style_def_name))
		{
			def->apply_style(style_def);
		}
	}

	pimpl->active_custom_styles.push_back(style);

	return true;
}
