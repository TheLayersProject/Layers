#ifndef LAYERSCOREEXPORTS_H
#define LAYERSCOREEXPORTS_H

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

#endif // LAYERSCOREEXPORTS_H
