#ifndef LCOLOR_H
#define LCOLOR_H

#include "layers_global.h"
#include "layerscore_exports.h"

LAYERS_NAMESPACE_BEGIN

enum class LAYERS_CORE_EXPORT HSV { Hue, Saturation, Value };

LAYERS_CORE_EXPORT extern const int MAX_H;
LAYERS_CORE_EXPORT extern const int MAX_SV;
LAYERS_CORE_EXPORT extern const int MAX_RGB;

LAYERS_NAMESPACE_END

#endif // LCOLOR_H
