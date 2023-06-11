#ifndef LFILLEDITOR_H
#define LFILLEDITOR_H

#include "layerswidgetsexports.h"

#include "lattributeeditor.h"
#include "lfillcontrol.h"
#include "llabel.h"

namespace Layers
{
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
}

#endif // LFILLEDITOR_H
