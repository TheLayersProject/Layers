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
#include "lstring.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

class LAYERS_EXPORT LTheme
{
public:
	LTheme();

	LTheme(const std::filesystem::path& path);

	LTheme(const LString& name, bool editable = true);

	LTheme(const LString& name, const LString& uuid, bool editable);

	~LTheme();

	void append_to_lineage(const LString& theme_id);

	void clear();

	std::filesystem::path path() const;

	LString display_id() const;

	bool editable() const;

	LThemeItem* find_item(const LString& path);

	LThemeItem* find_item(const std::deque<LString>& name_list);

	bool has_implementation(const LString& app_display_id) const;

	std::vector<LString> lineage() const;

	void load(const LString& app_display_id);

	LString name() const;

	LString publisher() const;

	LThemeItem* root_item() const;

	void save();

	void save_meta_file();

	void set_dir(const std::filesystem::path& path);

	void set_name(const LString& new_name);

	void set_publisher(const LString& publisher);

	LString uuid() const;

private:
	class Impl;
	Impl* pimpl;
};
LAYERS_NAMESPACE_END

#endif // LTHEME_H
