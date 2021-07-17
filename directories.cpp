#include "Layers.h"

QString Layers::app_path(const QString& app_name)
{
	return QString(local_app_data_path() + app_name + "\\");
}

QString Layers::app_themes_path(const QString& app_name)
{
	return QString(app_path(app_name) + "Themes\\");
}

QString Layers::deprecated_layers_path()
{
	return QString(local_app_data_path() + "Layers-alpha\\"); // Alpha
}

QString Layers::deprecated_layers_themes_path()
{
	return QString(deprecated_layers_path() + "Themes\\");
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
