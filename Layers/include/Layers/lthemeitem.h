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

#ifndef LTHEMEITEM_H
#define LTHEMEITEM_H

#include <deque>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lstring.h"
#include "lobject.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeItem : public LObject
{
public:
	LThemeItem(
		const LString& name,
		const LAttributeMap& attributes,
		bool is_overridable,
		const LString& file_name,
		LThemeItem* parent = nullptr);

	~LThemeItem();

	void append_child(LThemeItem* child);

	std::vector<LString> attribute_group_names() const;

	LAttributeMap attributes(int type_index = -1);

	LThemeItem* child(int index) const;

	size_t child_count() const;

	std::map<LString, LThemeItem*>& children();

	LThemeItem* find_item(const LString& path);

	LThemeItem* find_item(std::deque<LString> name_list);

	int index() const;

	bool is_overridable() const;

	LString path() const;

	LJsonObject to_json_object() const;

private:
	class Impl;
	Impl* pimpl;
};

LAYERS_NAMESPACE_END

#endif // LTHEMEITEM_H