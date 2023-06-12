#ifndef LATTRIBUTEEDITORGROUP_H
#define LATTRIBUTEEDITORGROUP_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include "lattributeeditor.h"
#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LAttributeEditorGroup : public LAttributeEditor
{
	Q_OBJECT

public:
	LAttributeEditorGroup(LAttributeGroup* attr_group, QWidget* parent = nullptr);

	void add_modifier_widget(LAttributeEditor* attribute_widget);

	void set_collapsed(bool collapsed = true);

	//virtual bool disabled() const;

public slots:
	virtual void set_current_editing_state(const QString& state) override;

private:
	void init_layout();

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	bool m_collapsed{ true };

	LLabel* m_label{ new LLabel };

	QList<LAttributeEditor*> m_child_attribute_widgets{ QList<LAttributeEditor*>() };

	QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITORGROUP_H
