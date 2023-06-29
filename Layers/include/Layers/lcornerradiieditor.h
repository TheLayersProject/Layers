#ifndef LCORNERRADIIEDITOR_H
#define LCORNERRADIIEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditorgroup.h"
#include "llineeditor.h"
#include "lminislider.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LCornerRadiiEditor : public LAttributeEditorGroup
{
	Q_OBJECT

public:
	LCornerRadiiEditor(
		const QString& name,
		LAttributeMap corner_radii,
		QWidget* parent = nullptr);

private:
	void init_layout();

	LAttributeEditor* m_attribute_editor;

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
