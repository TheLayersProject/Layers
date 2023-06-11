#ifndef LCOLOREDITOR_H
#define LCOLOREDITOR_H

#include "layerswidgetsexports.h"

#include "lattributeeditor.h"
#include "lcolorcontrol.h"
#include "llabel.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LColorEditor : public LAttributeEditor
	{
		Q_OBJECT

	public:
		LColorEditor(LAttribute* attribute, QWidget* parent = nullptr);

		LColorControl* color_control() const;

	public slots:
		void set_current_editing_state(const QString& state);

	private:
		LColorControl* m_color_control{ new LColorControl };

		LLabel* m_attribute_label{ new LLabel };
	};
}

#endif // LCOLOREDITOR_H
