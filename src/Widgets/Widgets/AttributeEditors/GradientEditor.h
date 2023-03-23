#ifndef GRADIENTEDITOR_H
#define GRADIENTEDITOR_H

#include "AttributeEditor.h"
#include "GradientControl.h"
#include "Label.h"

namespace Layers
{
	class GradientEditor : public AttributeEditor
	{
		Q_OBJECT

	public:
		GradientEditor(const QString& attribute_label_text, Attribute* attribute, QWidget* parent = nullptr);

	private:
		GradientControl* m_gradient_control{ new GradientControl };

		Label* m_attribute_label;
	};
}

#endif // GRADIENTEDITOR_H
