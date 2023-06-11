#ifndef LNUMBEREDITOR_H
#define LNUMBEREDITOR_H

#include <QIntValidator>

#include "layerswidgetsexports.h"

#include "lattributeeditor.h"
#include "llabel.h"
#include "llineeditor.h"
#include "lminislider.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LNumberEditor : public LAttributeEditor
	{
		Q_OBJECT

	public:
		LNumberEditor(LAttribute* attribute, QIntValidator* int_validator, QWidget* parent = nullptr);

		void set_unit_label_text(const QString& unit_string);

	private:
		void init_layout();

		LLabel* m_attribute_label{ new LLabel };
		//LLabel* m_unit_label{ new LLabel };

		LLineEditor* m_line_editor{ new LLineEditor };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		LMiniSlider* m_slider{ new LMiniSlider };
	};
}

#endif // LNUMBEREDITOR_H
