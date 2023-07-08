#ifndef LWIDGETEDITOR_H
#define LWIDGETEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lattributeeditorgroup.h"
#include "lbutton.h"
#include "lwidgetbuttongroup.h"

LAYERS_NAMESPACE_BEGIN

class LThemeEditor;

class LAYERS_EXPORT LWidgetEditor : public LWidget
{
	Q_OBJECT

public:
	LWidgetEditor(LThemeable* themeable, LThemeEditor* parent_theme_editor, QWidget* parent = nullptr);
	~LWidgetEditor();

	LThemeable* themeable() const;

private:
	void add_widget_button(LWidgetButton* button);

	void add_widget_button_group(LWidgetButtonGroup* button_group);

	void init_attribute_editors();

	void init_layout();

	LAttributeEditor* m_control_attr_editor{
		new LAttributeEditor(nullptr, this)};

	LAttributeEditorGroup* m_control_attr_editor_group{
		new LAttributeEditorGroup("", this)};

	LWidgetButton* m_control_widget_button{
		new LWidgetButton(LGraphic(":/images/exit.svg", QSize(20, 20)), "", this)};

	LWidgetButtonGroup* m_control_widget_button_group{
		new LWidgetButtonGroup("", QList<LWidgetButton*>(), this) };

	bool m_layout_setup{ false };
	bool m_showing_primary{ true };

	QHBoxLayout* m_attributes_label_layout{ new QHBoxLayout };
	QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
	QVBoxLayout* m_widgets_layout{ new QVBoxLayout };
	QVBoxLayout* m_widget_buttons_layout{ new QVBoxLayout };

	LLabel* m_attributes_label{ new LLabel("Attributes:") };
	LLabel* m_widgets_label{ new LLabel("Widgets:") };

	LThemeable* m_themeable;
};
LAYERS_NAMESPACE_END

#endif // LWIDGETEDITOR_H
