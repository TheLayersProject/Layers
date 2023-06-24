#ifndef LCOLOR_H
#define LCOLOR_H

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

enum class LAYERS_EXPORT HSV { Hue, Saturation, Value };

LAYERS_EXPORT extern const int MAX_H;
LAYERS_EXPORT extern const int MAX_SV;
LAYERS_EXPORT extern const int MAX_RGB;

LAYERS_NAMESPACE_END

#endif // LCOLOR_H
