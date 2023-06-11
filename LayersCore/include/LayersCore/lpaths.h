#ifndef LPATHS_H
#define LPATHS_H

#include <QString>

#include "layerscoreexports.h"

namespace Layers
{
	LAYERS_CORE_EXPORT QString app_path(const QString& app_name);
	LAYERS_CORE_EXPORT QString latest_T_version_path();
	LAYERS_CORE_EXPORT QString layers_path();
	LAYERS_CORE_EXPORT QString themes_path();
	LAYERS_CORE_EXPORT QString T1_path();
	LAYERS_CORE_EXPORT QString local_app_data_path();
}

#endif // LPATHS_H
