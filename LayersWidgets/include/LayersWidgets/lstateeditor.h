#ifndef LSTATEEDITOR_H
#define LSTATEEDITOR_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include "lattributeeditor.h"
#include "lcombobox.h"
#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LStateEditor : public LAttributeEditor
{
	Q_OBJECT

public:
	LStateEditor(QWidget* parent = nullptr);

	void add_modifier_widget(LAttributeEditor* attribute_widget);

	LComboBox* state_combobox() const;

	void populate_state_combobox(const QList<QString>& states);

private:
	void init_layout();

	LComboBox* m_state_combobox{ new LComboBox };

	LLabel* m_label{ new LLabel("State") };

	QList<LAttributeEditor*> m_child_attribute_widgets{ QList<LAttributeEditor*>() };

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LSTATEEDITOR_H
