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

#ifndef LSTYLABLE_H
#define LSTYLABLE_H

#include <cassert>
#include <unordered_set>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lobject.h"
#include "lstring.h"
#include "lstyle.h"

LAYERS_NAMESPACE_BEGIN

class LAYERS_EXPORT LStylable
{
public:
	LStylable();

	LStylable(const LStylable& other);

	virtual ~LStylable();

	void add_attribute(std::unique_ptr<LAttribute> attribute);

	void add_share_stylable(LStylable* stylable);

	virtual void apply_style(
		LStyle* style, bool is_top_level = true);

	const std::vector<std::unique_ptr<LAttribute>>& attributes() const;

	virtual std::vector<LStylable*> child_stylables(
		bool recursive = false) = 0;

	LStyle* style() const;

	static void flush_updates();

	virtual LString name() = 0;

	virtual LString path() = 0;

	virtual void update() = 0;

private:
	class Impl;
	Impl* pimpl;

	void mark_dirty();

	bool is_dirty{ false };

	static std::unordered_set<LStylable*>& dirty_stylables();

	//static std::unordered_set<LStylable*> dirty_stylables;
};

template <typename... Args>
LAttribute* lMakeDefinableAttribute(LStylable* parent, Args&&... args)
{
	assert(parent && "Parent must not be null");

	parent->add_attribute(
		std::make_unique<LAttribute>(std::forward<Args>(args)...));

	return parent->attributes().back().get();
}

LAYERS_NAMESPACE_END

#endif // LSTYLABLE_H
