#ifndef LCOLOREDITOR_H
#define LCOLOREDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lcolorcontrol.h"
#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LColorEditor : public LAttributeEditor
{
	Q_OBJECT

public:
	LColorEditor(LAttribute* attribute, QWidget* parent = nullptr);

	LColorControl* color_control() const;

private:
	LColorControl* m_color_control{ new LColorControl };

	LLabel* m_attribute_label{ new LLabel };
};
LAYERS_NAMESPACE_END

#endif // LCOLOREDITOR_H
