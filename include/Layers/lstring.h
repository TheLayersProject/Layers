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

#ifndef LSTRING_H
#define LSTRING_H

#include <string>
#include <vector>
#include <algorithm>
#include "layers_global.h"

LAYERS_NAMESPACE_BEGIN

using LString = std::string;
using LStringList = std::vector<std::string>;

inline bool starts_with(const LString& str, const LString& prefix)
{
    return str.rfind(prefix, 0) == 0;
}

inline LString remove_substring(LString str, const std::string& sub)
{
    if (sub.empty()) return str;
    size_t pos = str.find(sub);
    if (pos != std::string::npos)
        str.erase(pos, sub.length());
    return str;
}

LAYERS_NAMESPACE_END

#endif // LSTRING_H
