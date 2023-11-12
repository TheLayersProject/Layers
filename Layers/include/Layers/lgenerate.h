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

#ifndef LGENERATE_H
#define LGENERATE_H

#include <random>
#include <string>
#include <sstream>
#include <iomanip>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_EXPORT inline LString generate_uuid()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    for (int i = 0; i < 16; ++i) {
        ss << std::setw(2) << dis(gen);
        if (i == 3 || i == 5 || i == 7 || i == 9) {
            ss << "-";
        }
    }

    return ss.str().c_str();
}

LAYERS_NAMESPACE_END

#endif // !LGENERATE_H
