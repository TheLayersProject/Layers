#ifndef LPAINT_H
#define LPAINT_H

#include <QPainter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lcalculate.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN

LAYERS_EXPORT constexpr QPoint lpoint(int p)
{
	return QPoint(p, p);
}

LAYERS_EXPORT constexpr QSize lsize(int s)
{
	return QSize(s, s);
}

struct LAYERS_EXPORT LCornerRadii
{
	int top_left{ 0 };
	int top_right{ 0 };
	int bottom_left{ 0 };
	int bottom_right{ 0 };
};

LAYERS_NAMESPACE_END

#endif // LPAINT_H
