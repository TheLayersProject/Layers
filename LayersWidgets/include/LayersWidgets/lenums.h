#ifndef LENUMS_H
#define LENUMS_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include <Qt>

LAYERS_NAMESPACE_BEGIN
enum LAYERS_WIDGETS_EXPORT ThemeComboBoxDataRoles
{
	UuidIfExists = Qt::UserRole + 1,
	AppImplementationAvailable = Qt::UserRole + 2
};
LAYERS_NAMESPACE_END

#endif // LENUMS_H  
