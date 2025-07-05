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

#include <Layers/lcontroller.h>

#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/lconnector.h>
#include <Layers/lresources.h>
#include <Layers/lobjectfactory.h>
#include <Layers/lpaths.h>
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
	std::unique_ptr<LStyle> root_style{
		std::make_unique<LStyle>() };

	std::map<LString, LStyle*> custom_styles;
	std::map<LString, std::unique_ptr<LTheme>> themes;

	LStyleList active_custom_styles;
	LTheme* active_theme{ nullptr };

	std::map<LString, std::unique_ptr<LStyle>> unparented_styles;

	LConnector<LTheme*> connector_theme_added;

	void add_custom_style(LStyle* custom_style)
	{
		if (custom_style)
		custom_styles[custom_style->object_name()] = custom_style;
	}

	void add_theme(std::unique_ptr<LTheme> theme)
	{
		if (theme)
		{
			connector_theme_added.execute(theme.get());
			themes[theme->display_id()] = std::move(theme);
		}
	}

	std::map<std::filesystem::path, LJsonObject> build_file_objects(
		const std::map<std::filesystem::path, std::string>& file_strings)
	{
		std::map<std::filesystem::path, LJsonObject> file_objects;

		for (const auto& [file_path, content] : file_strings)
		{
			LJsonLexer lexer(content);
			LJsonParser parser(lexer);

			file_objects[file_path] = parser.parse_object();
		}

		return file_objects;
	}

	DependencyData build_dependency_data(
		const std::set<LStyle*>& styles)
	{
		DependencyGraph graph;
		DependencyCount indegree;

		for (LStyle* def : styles)
		{
			graph[def];
			indegree[def];

			for (LStyle* base : def->dependencies())
			{
				// Skip already resolved dependencies
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

		// Start with nodes with no unresolved dependencies in the current set
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

		// Check for cycles among unresolved dependencies
		for (const auto& [def, count] : dep_data.indegree)
			if (count > 0)
				throw std::runtime_error("Cycle detected in dependency graph");

		return sorted;
	}

	/*
		TODO:
		Consider returning a set of style references instead of pointers
	*/
	std::set<LStyle*> build_styles(
		const std::map<std::filesystem::path, LJsonObject>& file_objects)
	{
		std::set<LStyle*> styles;

		for (const auto& [file_path, object] : file_objects)
			for (const auto& [key, value] : object)
			{
				std::unique_ptr<LStyle> def =
					std::make_unique<LStyle>(key, value, "");

				styles.insert(def.get());

				if (std::string(key.c_str()).find("/") != std::string::npos)
				{
					unparented_styles[key] = std::move(def);
				}
				else
				{
					def->set_parent(root_style.get());
					root_style->add_child(std::move(def));
					//root_style->append_child(def);
				}
			}

		return styles;
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

	std::map<std::filesystem::path, std::string> load_style_path(
		const std::filesystem::path& path)
	{
		std::map<std::filesystem::path, std::string> file_strings;

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			// Needs to only load files that end with .json

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
		// Convert file strings to JSON objects
		auto file_objects = build_file_objects(file_strings);

		// Build and process styles
		std::set<LStyle*> unresolved_styles = build_styles(file_objects);
		for (LStyle* def : unresolved_styles)
			resolve_base(def);

		// Build dependency graph and topologically sort
		DependencyData dep_data = build_dependency_data(unresolved_styles);
		std::vector<LStyle*> ordered_styles = topological_sort(dep_data);

		// Finalize styles
		for (LStyle* def : ordered_styles)
			def->finalize();

		// Resolve parent-child relationships as in your current implementation
		for (auto& [_, unparented_def] : unparented_styles)
		{
			LString unparented_def_name = unparented_def->object_name();
			auto name_list = split<std::deque<LString>>(unparented_def->object_name(), '/');
			LString new_name = name_list.back();
			name_list.pop_back();

			if (LStyle* parent_def = root_style->find_item(name_list))
			{
				unparented_def->set_object_name(new_name);
				unparented_def->set_parent(parent_def);
				parent_def->add_child(std::move(unparented_def));
			}
		}

		// Remove empty unparented styles
		for (auto it = unparented_styles.begin();
			it != unparented_styles.end(); )
		{
			if (it->second == nullptr)
			{
				it = unparented_styles.erase(it);
			}
			else ++it;
		}

		/*
			TODO:
			Handle situation where there might be leftover unparented
			styles.
		*/
	}


	void load_styles(const std::filesystem::path& path)
	{
		// Load and Parse Aliases
		std::map<std::filesystem::path, std::string> file_strings = load_style_path(path);

		parse_aliases(path, file_strings);

		process_style_set(path, file_strings);
	}

	void load_internal_styles(const LString& path)
	{
		std::map<LString, LResource> set_resources = lResourceManager.resources(path);

		// Convert resources to file strings

		std::map<std::filesystem::path, std::string> file_strings;

		for (const auto& [resource_path, resource] : set_resources)
		{
			std::string resource_string(
				reinterpret_cast<const char*>(resource.data), resource.size);

			file_strings[std::filesystem::path(resource_path.c_str())] =
				remove_whitespace(resource_string);
		}

		process_style_set(path.c_str(), file_strings);
	}

	LStyle* load_custom_style(const std::filesystem::path& style_file_path)
	{
		std::string style_file_str = load_json_file(style_file_path);

		LJsonLexer lexer(style_file_str);
		LJsonParser parser(lexer);
		LJsonObject json_object = parser.parse_object();

		LStyle* style = new LStyle(
			style_file_path.filename().string().c_str(),
			json_object,
			style_file_path);

		for (const auto& [key, value] : json_object)
		{
			if (!key.starts_with("_"))
			{
				lMake<LStyle>(style, key, value, style_file_path);
				//style->append_child(new LStyle(key, value, style_file_path));
			}
		}

		return style;
	}

	void load_custom_styles(const std::filesystem::path& path)
	{
		for (const auto& dir_entry :
			std::filesystem::directory_iterator(path))
		{
			if (dir_entry.is_regular_file())
				add_custom_style(load_custom_style(dir_entry.path()));
		}
	}

	std::unique_ptr<LTheme> load_theme(const std::filesystem::path& directory)
	{
		std::map<std::filesystem::path, std::string> file_strings = 
			load_style_path(directory);

		// There should only be a single theme file, theme.json

		std::filesystem::path file_path = std::filesystem::path(directory / "theme.json");

		if (file_strings.count(file_path))
		{
			LJsonLexer lexer(file_strings[file_path]);
			LJsonParser parser(lexer);
			LJsonObject json_object = parser.parse_object();

			for (const auto& [key, value] : json_object)
				return std::make_unique<LTheme>(key, value, file_path);
		}

		return std::unique_ptr<LTheme>();
	}

	std::unique_ptr<LTheme> load_theme(const std::string& file_string)
	{
		LJsonLexer lexer(file_string);
		LJsonParser parser(lexer);
		LJsonObject json_object = parser.parse_object();

		for (const auto& [key, value] : json_object)
			return std::make_unique<LTheme>(key, value, "");

		return std::unique_ptr<LTheme>();
	}

	void load_themes(const std::filesystem::path& path)
	{
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
	pimpl->load_styles(std::string(path.c_str()));

	//if (is_application)
	//	pimpl->load_styles(styles_path() / std::string(path.c_str()));
}

void LController::include_internal(const LString& path)
{
	pimpl->load_internal_styles(path.c_str());
}

bool LController::set_active_theme(LTheme* theme)
{
	if (pimpl->active_theme != theme)
	{
		pimpl->active_theme = theme;

		pimpl->root_style->resolve_links();

		LStylable::flush_updates();

		return true;
	}

	return false;
}

std::map<LString, LStyle*> LController::styles() const
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
	LStyle* style = pimpl->custom_styles[style_id];

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
