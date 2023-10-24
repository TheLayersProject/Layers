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

#ifndef LTHEME_H
#define LTHEME_H

#include <filesystem>

#include "layers_global.h"
#include "layers_exports.h"

#include "ljson.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

struct LAYERS_EXPORT LThemeLineageData
{
	QString name;
	QString uuid;
	bool has_app_implementation_available = false;
};

class LAYERS_EXPORT LTheme
{
public:
	LTheme();

	LTheme(const std::filesystem::path& path);

	LTheme(const std::string& name, bool editable = true);

	LTheme(const std::string& name, std::string uuid, bool editable);

	~LTheme();

	void append_to_lineage(const std::string& theme_id);

	void clear();

	std::filesystem::path path() const;

	std::string display_id() const;

	bool editable() const;

	LThemeItem* find_item(const std::string& path);

	LThemeItem* find_item(const std::deque<std::string>& name_list);

	bool has_implementation(const std::string& app_display_id) const;

	std::vector<std::string> lineage() const;

	void load(const std::string& app_id);

	std::string name() const;

	std::string publisher() const;

	LThemeItem* root_item() const;

	void save();

	void save_meta_file();

	void set_dir(const std::filesystem::path& path);

	void set_name(const std::string& new_name);

	void set_publisher(const std::string& publisher);

	std::string uuid() const;

private:
	void load_file(const std::string& file_name);

	void load_dir(const std::filesystem::path& path);

	LThemeItem* init_item(const std::string& name,
		LJsonObject item_object, const std::string& file_name,
		LThemeItem* parent = nullptr);

	void resolve_links(LThemeItem* item);

	void resolve_parents();

	LThemeItem* m_root_item{ nullptr };

	std::map<std::string, LThemeItem*> m_unparented_theme_items;

	std::map<std::string, std::vector<LThemeItem*>> m_file_items;

	std::filesystem::path m_path;

	bool m_editable{ true };

	std::vector<std::string> m_lineage;

	std::string m_name;

	std::string m_publisher;

	std::string m_local_user;

	//QUuid m_uuid;
	std::string m_uuid;
};
LAYERS_NAMESPACE_END

#endif // LTHEME_H
