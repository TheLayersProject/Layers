#ifndef DIRECTORIES_H
#define DIRECTORIES_H

#include <QString>

namespace Layers
{
	QString app_path(const QString& app_name);
	QString latest_T_version_path();
	QString layers_path();
	QString themes_path();
	QString T1_path();
	QString local_app_data_path();
}

#endif // DIRECTORIES_H
