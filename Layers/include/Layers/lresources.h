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

#ifndef LRESOURCES_H
#define LRESOURCES_H

#include "layers_global.h"
#include "layers_exports.h"

#include <map>

#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

struct LResource
{
    const unsigned char* data;
    size_t size;
};

class LAYERS_EXPORT LResourceManager
{
public:
    void init(const void* entries, size_t count);

    static LResourceManager& instance();

    LResource resource(const LString& path) const;

    std::map<LString, LResource> resources(const LString& path) const;

private:
    LResourceManager();
    ~LResourceManager();

    LResourceManager(const LResourceManager&) = delete;
    LResourceManager& operator=(const LResourceManager&) = delete;

    class Impl;
    Impl* pimpl;
};

#define lResourceManager (Layers::LResourceManager::instance())
#define LRC (Layers::LResourceManager::resource)

LAYERS_NAMESPACE_END

#endif // LRESOURCES_H
