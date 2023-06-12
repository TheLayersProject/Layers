#ifndef LCORNERRADIIEDITOR_H
#define LCORNERRADIIEDITOR_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include "lattributeeditorgroup.h"
#include "llineeditor.h"
#include "lminislider.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LCornerRadiiEditor : public LAttributeEditorGroup
{
	Q_OBJECT

public:
	LCornerRadiiEditor(LCornerRadiiAttributes* linked_corner_radii, QWidget* parent = nullptr);

public slots:
	void set_current_editing_state(const QString& state);

private:
	void init_layout();

	LAttributeEditor* m_attribute_widget;

	LMiniSlider* m_tl_slider{ new LMiniSlider(30.0) };
	LMiniSlider* m_tr_slider{ new LMiniSlider(30.0) };
	LMiniSlider* m_bl_slider{ new LMiniSlider(30.0) };
	LMiniSlider* m_br_slider{ new LMiniSlider(30.0) };

	LLineEditor* m_tl_line_editor{ new LLineEditor };
	LLineEditor* m_tr_line_editor{ new LLineEditor };
	LLineEditor* m_bl_line_editor{ new LLineEditor };
	LLineEditor* m_br_line_editor{ new LLineEditor };

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	LWidget* m_example_widget{ new LWidget };
};
LAYERS_NAMESPACE_END

#endif // LCORNERRADIIEDITOR_H
