#ifndef LENUMS_H
#define LENUMS_H

#include "layerswidgetsexports.h"

#include <Qt>

namespace Layers
{
	enum LAYERS_WIDGETS_EXPORT ThemeComboBoxDataRoles
	{
		UuidIfExists = Qt::UserRole + 1,
		AppImplementationAvailable = Qt::UserRole + 2
	};
}

#endif // LENUMS_H  
