#ifndef LWIDGETEDITOR_H
#define LWIDGETEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lcoloreditor.h"
#include "lcornerradiieditor.h"
#include "lfilleditor.h"
#include "lnumbereditor.h"
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

	LAttributeEditor* create_editor(LAttribute* attribute);

	void init_attribute_editors();

	void init_attributes();

	void init_layout();

	LAttributeEditorGroup* m_control_attribute_editor_group{
		new LAttributeEditorGroup("", this)};

	LCornerRadiiEditor* m_control_corner_radii_editor{
		new LCornerRadiiEditor("", LAttributeMap(), this)};

	LFillEditor* m_control_fill_editor{
		new LFillEditor(new LAttribute("", QColor()), this) };

	LNumberEditor* m_control_number_editor{
		new LNumberEditor(new LAttribute("", QVariant::fromValue(0)), new QIntValidator, this) };

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

	//QList<LAttributeEditor*> m_modifier_widgets;

	LThemeable* m_themeable;
};
LAYERS_NAMESPACE_END

#endif // LWIDGETEDITOR_H
