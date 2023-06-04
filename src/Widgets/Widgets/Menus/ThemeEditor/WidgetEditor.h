#ifndef WIDGETEDITOR_H
#define WIDGETEDITOR_H

#include "Button.h"
#include "WidgetButtonGroup.h"

#include "Widgets/Widgets/AttributeEditors/AttributeEditorGroup.h"
#include "Widgets/Widgets/AttributeEditors/ColorEditor.h"
#include "Widgets/Widgets/AttributeEditors/CornerRadiiEditor.h"
#include "Widgets/Widgets/AttributeEditors/FillEditor.h"
#include "Widgets/Widgets/AttributeEditors/NumberEditor.h"
#include "Widgets/Widgets/AttributeEditors/StateEditor.h"

namespace Layers
{
	class ThemeEditor;

	class WidgetEditor : public Widget
	{
		Q_OBJECT

	public:
		WidgetEditor(Themeable* themeable, ThemeEditor* parent_theme_editor, QWidget* parent = nullptr);
		~WidgetEditor();

		Themeable* themeable() const;

	private:
		void add_attribute_editor(AttributeEditor* editor);

		void add_widget_button(WidgetButton* button);

		void add_widget_button_group(WidgetButtonGroup* button_group);

		AttributeEditor* create_editor(Attribute* attribute);

		void handle_editor(AbstractAttribute* abs_attr, AttributeEditor* editor);

		void init_attribute_editors();

		void init_attributes();

		void setup_layout();

		AttributeEditorGroup* m_control_attribute_editor_group{
			new AttributeEditorGroup(new AttributeGroup(""), this)};

		CornerRadiiEditor* m_control_corner_radii_editor{
			new CornerRadiiEditor(new CornerRadiiAttributes, this) };

		FillEditor* m_control_fill_editor{
			new FillEditor(new Attribute("", QColor()), this) };

		NumberEditor* m_control_number_editor{
			new NumberEditor(new Attribute("", QVariant::fromValue(0)), new QIntValidator, this) };

		StateEditor* m_control_state_editor{
			new StateEditor(this) };

		WidgetButton* m_control_widget_button{
			new WidgetButton(Graphic(":/svgs/exit.svg"), "", this)};

		WidgetButtonGroup* m_control_widget_button_group{
			new WidgetButtonGroup("", QList<WidgetButton*>(), this) };

		bool m_layout_setup{ false };
		bool m_showing_primary{ true };

		StateEditor* m_state_editor{ nullptr };

		QHBoxLayout* m_attributes_label_layout{ new QHBoxLayout };
		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_widgets_layout{ new QVBoxLayout };
		QVBoxLayout* m_widget_buttons_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All") };
		Button* m_show_enabled_button{ new Button("Show Enabled") };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_widgets_label{ new Label("Widgets:") };

		QList<AttributeEditor*> m_modifier_widgets{ QList<AttributeEditor*>() };

		Themeable* m_themeable;
	};
}

#endif // WIDGETEDITOR_H
