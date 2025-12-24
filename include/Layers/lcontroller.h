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

#ifndef LCONTROLLER_H
#define LCONTROLLER_H

#include <deque>
#include <map>
#include <filesystem>
#include <functional>
#include <vector>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

class LStyle;
class LTheme;

using LStyleList = std::vector<LStyle*>;

class LAYERS_EXPORT LController
{
public:
    LController();
    ~LController();
    LController(const LController&) = delete;
    LController& operator=(const LController&) = delete;

    LStyleList active_custom_styles();

    LTheme* active_theme() const;

    void add_theme(std::unique_ptr<LTheme> theme);

    LStyle* find_style(const LString& path);

	LStyle* find_style(std::deque<LString> name_list);

    void include(const LString& path, bool is_application = false);

    void include_internal(const LString& path);

    static LController& instance();

    std::unique_ptr<LTheme> load_theme(const std::string& file_string);

	void load_themes(const std::filesystem::path& path);

    void load_user_styles(const std::filesystem::path& path);

	void on_theme_added(std::function<void(LTheme*)> callback);

    LStyle* root_style() const;

    bool set_active_theme(LTheme* theme);

    std::map<LString, std::unique_ptr<LStyle>>& styles() const;

    LTheme* theme(const LString& themeId) const;

    std::map<LString, std::unique_ptr<LTheme>>& themes() const;

    bool toggle_custom_style(const LString& style_id);

private:
    class Impl;
    Impl* pimpl;
};

#define lController (Layers::LController::instance())
#define lTheme (Layers::LController::instance().active_theme())

LAYERS_NAMESPACE_END

#endif // LCONTROLLER_H
