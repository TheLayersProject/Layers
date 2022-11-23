#ifndef CUSTOMIZEPANEL_H
#define CUSTOMIZEPANEL_H

#include "AttributeWidgets.h"
#include "Button.h"
#include "Label.h"

namespace Layers
{
	class CustomizePanel : public Widget
	{
		Q_OBJECT

	public:
		CustomizePanel(Themeable* themeable, QWidget* parent = nullptr);
		~CustomizePanel();

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void add_widget_button(Button* button, int index = -1);

		void init_attribute_widgets();

		void replace_all_aw_group_attrs_with(AWGroup* control_aw_group);
		void replace_all_color_awidgets_attrs_with(ColorAW* control_color_aw);
		void replace_all_fill_awidgets_attrs_with(FillAW* control_fill_aw);
		void replace_all_number_awidgets_attrs_with(NumberAW* control_number_aw);
		void replace_all_state_awidgets_attrs_with(StateAW* control_state_aw);
		void replace_all_widget_buttons_attrs_with(Button* control_widget_button);
		void replace_corner_radii_aw_attrs_with(CornerRadiiAW* control_corner_radii_aw);

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		bool m_layout_setup{ false };
		bool m_showing_primary{ true };

		StateAW* m_state_aw{ nullptr };

		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_widgets_layout{ new QVBoxLayout };
		QVBoxLayout* m_widget_buttons_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All", true) };
		Button* m_show_primary_button{ new Button("Show Primary", true) };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_widgets_label{ new Label("Widgets:") };

		QList<AttributeWidget*> m_attribute_widgets{ QList<AttributeWidget*>() };

		QList<AWGroup*> m_aw_groups{ QList<AWGroup*>() };
		QList<ColorAW*> m_color_awidgets{ QList<ColorAW*>() };
		QList<FillAW*> m_fill_awidgets{ QList<FillAW*>() };
		QList<NumberAW*> m_number_awidgets{ QList<NumberAW*>() };
		QList<StateAW*> m_state_awidgets{ QList<StateAW*>() };
		QList<Button*> m_widget_buttons{ QList<Button*>() };

		CornerRadiiAW* m_corner_radii_aw{ nullptr };

		Themeable* m_themeable;
	};
}

#endif // CUSTOMIZEPANEL_H
