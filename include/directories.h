#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#include <QString>

namespace Layers
{
	QString app_path(const QString& app_name);
	QString app_themes_path(const QString& app_name);
	QString deprecated_layers_path();
	QString deprecated_layers_themes_path();
	QString local_app_data_path();
}

#endif // DIRECTORIES_H
