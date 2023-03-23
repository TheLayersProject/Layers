#ifndef NUMBEREDITOR_H
#define NUMBEREDITOR_H

#include <QIntValidator>

#include "AttributeEditor.h"
#include "Label.h"
#include "LineEditor.h"
#include "MiniSlider.h"

namespace Layers
{
	class NumberEditor : public AttributeEditor
	{
		Q_OBJECT

	public:
		NumberEditor(Attribute* attribute, QIntValidator* int_validator, QWidget* parent = nullptr);

		void set_unit_label_text(const QString& unit_string);

	private:
		void setup_layout();

		Label* m_attribute_label{ new Label };
		//Label* m_unit_label{ new Label };

		LineEditor* m_line_editor{ new LineEditor };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		MiniSlider* m_slider{ new MiniSlider };
	};
}

#endif // NUMBEREDITOR_H
