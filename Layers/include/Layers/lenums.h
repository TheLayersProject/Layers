#ifndef LENUMS_H
#define LENUMS_H

#include "layers_global.h"
#include "layers_exports.h"

#include <Qt>

LAYERS_NAMESPACE_BEGIN
enum LAYERS_EXPORT ThemeComboBoxDataRoles
{
	UuidIfExists = Qt::UserRole + 1,
	AppImplementationAvailable = Qt::UserRole + 2
};
LAYERS_NAMESPACE_END

#endif // LENUMS_H  
