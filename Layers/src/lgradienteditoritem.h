#ifndef LGRADIENTEDITORITEM
#define LGRADIENTEDITORITEM

#include <QGradientStop>

#include <Layers/layers_global.h>

#include <Layers/LColorControl.h>

LAYERS_NAMESPACE_BEGIN

struct LGradientEditorItem
{
	QGradientStop stop;
	LColorControl* control;
};

inline bool compare_items(
	LGradientEditorItem* left, LGradientEditorItem* right)
{
	return left->control->x() < right->control->x();
}

LAYERS_NAMESPACE_END

#endif // LGRADIENTEDITORITEM
