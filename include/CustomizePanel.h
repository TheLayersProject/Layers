#ifndef CUSTOMIZEPANEL_H
#define CUSTOMIZEPANEL_H

#include "Button.h"
#include "Combobox.h"
#include "Label.h"

namespace Layers
{
	class CustomizePanel : public Widget
	{
		Q_OBJECT

	public:
		CustomizePanel(Themeable* themeable, QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void add_element_button(Button* button, int index = -1);

		void apply_theme(Theme&) override;

		void setup_layout();

		void update_attribute_widget_background_colors();

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		bool m_layout_setup{ false };
		bool m_showing_primary{ true };

		QHBoxLayout* m_states_layout{ new QHBoxLayout };

		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_elements_layout{ new QVBoxLayout };
		QVBoxLayout* m_element_buttons_layout{ new QVBoxLayout };
		QVBoxLayout* m_stateful_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_stateless_attributes_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All", true) };
		Button* m_show_primary_button{ new Button("Show Primary", true) };

		Combobox* m_state_combobox{ new Combobox };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_elements_label{ new Label("Elements:") };
		Label* m_stateful_attributes_label{ new Label("Stateful Attributes:") };
		Label* m_stateless_attributes_label{ new Label("Stateless Attributes:") };
		Label* m_state_label{ new Label("State:") };

		QList<AttributeWidget*> m_stateless_attribute_widgets{ QList<AttributeWidget*>() };
		QList<AttributeWidget*> m_stateful_attribute_widgets{ QList<AttributeWidget*>() };
		QList<AttributeWidget*> m_attribute_widgets{ QList<AttributeWidget*>() };

		Themeable* m_themeable;
	};
}

#endif // CUSTOMIZEPANEL_H
