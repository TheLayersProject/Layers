#ifndef LPATHS_H
#define LPATHS_H

#include <QString>

#include "layers_global.h"
#include "layerscore_exports.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_CORE_EXPORT QString app_path(const QString& app_name);
LAYERS_CORE_EXPORT QString latest_T_version_path();
LAYERS_CORE_EXPORT QString layers_path();
LAYERS_CORE_EXPORT QString themes_path();
LAYERS_CORE_EXPORT QString T1_path();
LAYERS_CORE_EXPORT QString local_app_data_path();

LAYERS_NAMESPACE_END

#endif // LPATHS_H
