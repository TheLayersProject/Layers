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

#ifndef LDEFINABLE_H
#define LDEFINABLE_H

#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lobject.h"
#include "lstring.h"
#include "ldefinition.h"

LAYERS_NAMESPACE_BEGIN

class LAYERS_EXPORT LDefinable : public LObject
{
public:
	LDefinable();

	LDefinable(const LDefinable& other);

	~LDefinable();

	void add_share_definable(LDefinable* themeable);

	virtual void apply_definition(LDefinition* definition);

	virtual std::vector<LDefinable*> child_definables(
		bool recursive = false) = 0;

	LDefinition* definition() const;

	virtual LString path() = 0;

	virtual void update() = 0;

private:
	class Impl;
	Impl* pimpl;
};
LAYERS_NAMESPACE_END

#endif // LDEFINABLE_H
