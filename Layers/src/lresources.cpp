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

#include <Layers/lresources.h>

#include <string>

using Layers::LResource;
using Layers::LResourceManager;
using Layers::LString;

// Define a ResourceEntry structure that matches what your resource compiler generates.
// (In your generated file, you might already have a similar struct. Adjust the names as needed.)
struct ResourceEntry
{
	const char* path;
	const unsigned char* data;
	size_t size;
};

class LResourceManager::Impl
{
public:
	std::map<LString, LResource> resource_map;
};

void LResourceManager::init(const void* entries, size_t count)
{
	const ResourceEntry* resEntries = static_cast<const ResourceEntry*>(entries);

	for (size_t i = 0; i < count; ++i) {
		// Insert into the map using the virtual path as the key.
		pimpl->resource_map[LString(resEntries[i].path)] =
			{ resEntries[i].data, resEntries[i].size };
	}
}

LResourceManager& LResourceManager::instance()
{
	static LResourceManager instance;
	return instance;
}

LResource LResourceManager::resource(const LString& path) const
{
	return pimpl->resource_map.at(path.c_str());
}

std::map<LString, LResource> LResourceManager::resources(const LString& path) const
{
	std::map<LString, LResource> result;

	std::string path_std_str = std::string(path.c_str());

	for (auto& [entry_path, entry] : pimpl->resource_map)
	{
		// Check if the resource path starts with the specified prefix.
		if (std::string(entry_path.c_str()).compare(0, path_std_str.size(), path_std_str) == 0)
		{
			result[entry_path] = (entry);
		}
	}
	return result;
}

LResourceManager::LResourceManager() : pimpl{ std::make_unique<Impl>() } {}

LResourceManager::~LResourceManager() = default;
