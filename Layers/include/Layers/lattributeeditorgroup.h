#ifndef LATTRIBUTEEDITORGROUP_H
#define LATTRIBUTEEDITORGROUP_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LAttributeEditorGroup Example](attribute_editor_group.png)
	
	An LAttributeEditorGroup is an LWidget that provides a collapsible
	LAttributeEditor container widget.

	The editor group has a collapse button (represented with an arrow icon)
	which is used to expand/collapse the contained attribute editors. It also
	has a label for the group's name.

	The editor group is intended to contain attribute editors associated with
	attributes that are considered *grouped together*.
*/
class LAYERS_EXPORT LAttributeEditorGroup : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs an attribute editor group labeled with *name*.
	*/
	LAttributeEditorGroup(const QString& name, QWidget* parent = nullptr);

	/*!
		Adds *attribute_editor* to this editor group.
	*/
	void add_attribute_editor(LAttributeEditor* attribute_editor);

private:
	void init_layout();

	void set_collapsed(bool collapsed = true);

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
