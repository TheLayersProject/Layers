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

#ifndef LTHEMEABLE_H
#define LTHEMEABLE_H

#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lobject.h"
#include "lstring.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LAYERS_EXPORT LThemeable : public LObject
{
public:
	LThemeable();

	LThemeable(const LThemeable& other);

	~LThemeable();

	void add_share_themeable(LThemeable* themeable);

	virtual void apply_theme_item(LThemeItem* theme_item);

	virtual std::vector<LThemeable*> child_themeables(
		bool recursive = false) = 0;

	LThemeItem* current_theme_item() const;

	virtual LString path() = 0;

	virtual void update() = 0;

private:
	class Impl;
	Impl* pimpl;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLE_H
