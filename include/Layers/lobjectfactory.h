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

#ifndef LOBJECTFACTORY_H
#define LOBJECTFACTORY_H

#include "lobject.h"

#include <cassert>

LAYERS_NAMESPACE_BEGIN

template <typename T, typename... Args>
T* lMake(LObject* parent, Args&&... args)
{
    static_assert(std::is_base_of<LObject, T>::value, "T must be an LObject");
    assert(parent && "Parent must not be null");

    parent->add_child(std::make_unique<T>(std::forward<Args>(args)..., parent));

	return static_cast<T*>(parent->children().back().get());
}

LAYERS_NAMESPACE_END

#endif // LOBJECTFACTORY_H
