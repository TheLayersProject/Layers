#include "Layers.h"

QString Layers::app_data_dir()
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

QString Layers::layers_dir()
{
	//return QString(app_data_dir() + "Layers\\"); // Production
	return QString(app_data_dir() + "Layers-alpha\\"); // Alpha
}

QString Layers::layers_themes_dir()
{
	return QString(layers_dir() + "Themes\\");
}
