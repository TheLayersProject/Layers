#ifndef WIDGETEDITOR_H
#define WIDGETEDITOR_H

#include "Button.h"
#include "WidgetButtonGroup.h"

namespace Layers
{
	class AttributeEditor;
	class AttributeEditorGroup;
	class ColorEditor;
	class CornerRadiiEditor;
	class FillEditor;
	//class GradientEditor;
	class NumberEditor;
	class StateEditor;

	class WidgetEditor : public Widget
	{
		Q_OBJECT

	public:
		WidgetEditor(Themeable* themeable, bool init_buttons = true, QWidget* parent = nullptr);
		~WidgetEditor();

		void add_modifier_widget(AttributeEditor* attribute_widget);

		void add_widget_button(WidgetButton* button);

		void add_widget_button_group(WidgetButtonGroup* button_group);

		void replace_all_aw_group_attrs_with(AttributeEditorGroup* control_aw_group);
		void replace_all_color_awidgets_attrs_with(ColorEditor* control_color_aw);
		void replace_all_fill_awidgets_attrs_with(FillEditor* control_fill_aw);
		void replace_all_number_awidgets_attrs_with(NumberEditor* control_number_aw);
		void replace_all_state_awidgets_attrs_with(StateEditor* control_state_aw);
		void replace_all_widget_buttons_attrs_with(WidgetButton* control_widget_button);
		void replace_all_widget_button_groups_attrs_with(WidgetButtonGroup* control_widget_button_group);
		void replace_all_corner_radii_aw_attrs_with(CornerRadiiEditor* control_corner_radii_aw);

	private:
		void init_attribute_editors();

		void init_attributes();

		void setup_layout();

		bool m_layout_setup{ false };
		bool m_showing_primary{ true };

		StateEditor* m_state_aw{ nullptr };

		QHBoxLayout* m_attributes_label_layout{ new QHBoxLayout };
		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_widgets_layout{ new QVBoxLayout };
		QVBoxLayout* m_widget_buttons_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All", true) };
		Button* m_show_primary_button{ new Button("Show Primary", true) };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_widgets_label{ new Label("Widgets:") };

		QList<AttributeEditor*> m_modifier_widgets{ QList<AttributeEditor*>() };

		QList<AttributeEditorGroup*> m_aw_groups{ QList<AttributeEditorGroup*>() };
		QList<ColorEditor*> m_color_awidgets{ QList<ColorEditor*>() };
		QList<CornerRadiiEditor*> m_corner_radii_awidgets{ QList<CornerRadiiEditor*>() };
		QList<FillEditor*> m_fill_awidgets{ QList<FillEditor*>() };
		QList<NumberEditor*> m_number_awidgets{ QList<NumberEditor*>() };
		QList<StateEditor*> m_state_awidgets{ QList<StateEditor*>() };
		QList<WidgetButton*> m_widget_buttons{ QList<WidgetButton*>() };
		QList<WidgetButtonGroup*> m_widget_button_groups{ QList<WidgetButtonGroup*>() };

		Themeable* m_themeable;
	};
}

#endif // WIDGETEDITOR_H
