#ifndef LGRADIENTEDITOR_H
#define LGRADIENTEDITOR_H

#include "layerswidgetsexports.h"

#include "lattributeeditor.h"
#include "lgradientcontrol.h"
#include "llabel.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LGradientEditor : public LAttributeEditor
	{
		Q_OBJECT

	public:
		LGradientEditor(const QString& attribute_label_text, LAttribute* attribute, QWidget* parent = nullptr);

	private:
		LGradientControl* m_gradient_control{ new LGradientControl };

		LLabel* m_attribute_label;
	};
}

#endif // LGRADIENTEDITOR_H
