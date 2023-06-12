#ifndef LFILLEDITOR_H
#define LFILLEDITOR_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include "lattributeeditor.h"
#include "lfillcontrol.h"
#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LFillEditor : public LAttributeEditor
{
	Q_OBJECT

public:
	LFillEditor(LAttribute* attribute, QWidget* parent = nullptr);

	LFillControl* fill_control() const;

public slots:
	virtual void set_current_editing_state(const QString& state) override;

private:
	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_attribute_label{ new LLabel };
};
LAYERS_NAMESPACE_END

#endif // LFILLEDITOR_H
