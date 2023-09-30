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

#include <Layers/lpaths.h>

QString Layers::app_path(const QString& app_name)
{
	return QString(local_app_data_path() + app_name + "\\");
}

QString Layers::latest_T_version_path()
{
	return T1_path();
}

QString Layers::layers_path()
{
	return QString(local_app_data_path() + "Layers\\");
}

QString Layers::themes_path()
{
	return QString(layers_path() + "Themes\\");
}

QString Layers::T1_path()
{
	return QString(themes_path() + "T1\\");
}

QString Layers::local_app_data_path()
{
	char* app_data_dir_char_ptr = nullptr;
	size_t app_data_dir_char_size = 0;
	_dupenv_s(&app_data_dir_char_ptr, &app_data_dir_char_size, "LOCALAPPDATA");
	std::string app_data_dir_string = "";
	if (app_data_dir_char_ptr) app_data_dir_string = app_data_dir_char_ptr;
	app_data_dir_string += "\\";
	delete(app_data_dir_char_ptr);
	return QString::fromStdString(app_data_dir_string);
}
