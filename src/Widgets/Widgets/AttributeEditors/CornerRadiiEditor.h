#ifndef CORNERRADIIEDITOR_H
#define CORNERRADIIEDITOR_H

#include "AttributeEditorGroup.h"
#include "LineEditor.h"
#include "MiniSlider.h"

namespace Layers
{
	class CornerRadiiEditor : public AttributeEditorGroup
	{
		Q_OBJECT

	public:
		CornerRadiiEditor(CornerRadiiAttributes* linked_corner_radii, QWidget* parent = nullptr);

	public slots:
		void set_current_editing_state(const QString& state);

	private:
		void setup_layout();

		AttributeEditor* m_attribute_widget;

		MiniSlider* m_tl_slider{ new MiniSlider(30.0) };
		MiniSlider* m_tr_slider{ new MiniSlider(30.0) };
		MiniSlider* m_bl_slider{ new MiniSlider(30.0) };
		MiniSlider* m_br_slider{ new MiniSlider(30.0) };

		LineEditor* m_tl_line_editor{ new LineEditor };
		LineEditor* m_tr_line_editor{ new LineEditor };
		LineEditor* m_bl_line_editor{ new LineEditor };
		LineEditor* m_br_line_editor{ new LineEditor };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_example_widget{ new Widget };
	};
}

#endif // CORNERRADIIEDITOR_H
