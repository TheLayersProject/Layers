#ifndef LAYERS_EXPORTS_H
#define LAYERS_EXPORTS_H

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LAYERS_LIB)
#  define LAYERS_EXPORT Q_DECL_EXPORT
# else
#  define LAYERS_EXPORT Q_DECL_IMPORT
# endif
#else
# define LAYERS_EXPORT
#endif

#endif // LAYERS_EXPORTS_H
