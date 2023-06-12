#ifndef LAYERSCORE_EXPORTS_H
#define LAYERSCORE_EXPORTS_H

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LAYERS_CORE_LIB)
#  define LAYERS_CORE_EXPORT Q_DECL_EXPORT
# else
#  define LAYERS_CORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define LAYERS_CORE_EXPORT
#endif

#endif // LAYERSCORE_EXPORTS_H
