#ifndef COLOREDITOR_H
#define COLOREDITOR_H

#include "AttributeEditor.h"
#include "ColorControl.h"
#include "Label.h"

namespace Layers
{
	class ColorEditor : public AttributeEditor
	{
		Q_OBJECT

	public:
		ColorEditor(Attribute* attribute, QWidget* parent = nullptr);

		ColorControl* color_control() const;

	public slots:
		void set_current_editing_state(const QString& state);

	private:
		ColorControl* m_color_control{ new ColorControl };

		Label* m_attribute_label{ new Label };
	};
}

#endif // COLOREDITOR_H
