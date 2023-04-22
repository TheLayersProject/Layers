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
		WidgetEditor(Themeable* themeable, QWidget* parent = nullptr);
		~WidgetEditor();

		void add_modifier_widget(AttributeEditor* attribute_widget);

		void add_widget_button(WidgetButton* button);

		void add_widget_button_group(WidgetButtonGroup* button_group);

		Themeable* themeable() const;

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

		Themeable* m_themeable;
	};
}

#endif // WIDGETEDITOR_H
