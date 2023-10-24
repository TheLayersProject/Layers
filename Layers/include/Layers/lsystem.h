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

#ifndef LUSER_H
#define LUSER_H

#include <string>

#include <windows.h>
#include <Lmcons.h>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_EXPORT inline std::string get_current_username()
{
    WCHAR buffer[UNLEN + 1];
    DWORD buffer_len = UNLEN + 1;

    if (GetUserNameW(buffer, &buffer_len))
    {
        std::wstring wstr(buffer);
        return std::string(wstr.begin(), wstr.end());
    }
    else
    {
        return std::string("unknown");
    }
}

LAYERS_NAMESPACE_END

#endif // !LUSER_H
