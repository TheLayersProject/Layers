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

#ifndef LSTYLE_H
#define LSTYLE_H

#include <deque>
#include <set>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "layers_global.h"
#include "layers_exports.h"

#include "lstring.h"
#include "lobject.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;
class LStyle;
using LStyleList = std::vector<LStyle*>;
using LStyleMap = std::map<LString, LStyle*>;

class LAYERS_EXPORT LStyle : public LObject
{
public:
	LStyle();

	LStyle(
		const LString& name,
		const json& value,
		const std::filesystem::path& file_path);

	~LStyle();

	void apply_style(LStyle* style_def);

	std::vector<LString> attribute_group_names() const;

	std::map<LString, LAttribute*> attributes(int type_index = -1) const;

	LStyle* base() const;

	LString base_name() const;

	LStyle* child(int index) const;

	size_t child_count() const;

	std::map<LString, LStyle*> children() const;

	void clear_style();

	std::set<LStyle*> dependencies();

	json extension(const LString& key) const;
	
	const json& extensions() const;

	LString file_name() const;

	void finalize();

	LAttribute* find_attribute(const LString& attr_name);

	LStyle* find_item(const LString& path);

	LStyle* find_item(std::deque<LString> name_list);

	bool has_extension(const LString& key) const;

	bool has_unresolved_base() const;

	int index() const;

	bool is_overridable() const;

	void on_style_applied(std::function<void()> callback);

	LString path() const;

	LStyle* parent() const;

	LString publisher() const;

	void resolve_links();

	void set_base(LStyle* base_def);

	void set_publisher(const LString& publisher);

	LStyle* style() const;

	json to_json_object() const;

private:
	class Impl;
	Impl* pimpl;
};

LAYERS_NAMESPACE_END

#endif // LSTYLE_H