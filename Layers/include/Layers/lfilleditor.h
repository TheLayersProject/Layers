#ifndef LFILLEDITOR_H
#define LFILLEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lfillcontrol.h"
#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LFillEditor : public LAttributeEditor
{
	Q_OBJECT

public:
	LFillEditor(LAttribute* attribute, QWidget* parent = nullptr);

	LFillControl* fill_control() const;

private:
	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_attribute_label{ new LLabel };
};
LAYERS_NAMESPACE_END

#endif // LFILLEDITOR_H
