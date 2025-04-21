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

#include <Layers/llogger.h>

#include <iostream>

static Layers::LogFunction log_function = nullptr;

void Layers::set_log_function(LogFunction fn)
{
    log_function = fn;
}

void Layers::log(const LString& message)
{
    if (log_function)
        log_function(message);
    else
        std::cout << "[Layers] " << message.c_str() << std::endl;
}
