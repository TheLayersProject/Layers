#ifndef LATTRIBUTEEDITORGROUP_H
#define LATTRIBUTEEDITORGROUP_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LAttributeEditorGroup : public LWidget
{
	Q_OBJECT

public:
	LAttributeEditorGroup(const QString& name, QWidget* parent = nullptr);

	void add_attribute_editor(LAttributeEditor* attribute_editor);

	void set_collapsed(bool collapsed = true);

private:
	void init_layout();

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	bool m_collapsed{ true };

	LLabel* m_label{ new LLabel };

	QList<LAttributeEditor*> m_attribute_editors;

	QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITORGROUP_H
