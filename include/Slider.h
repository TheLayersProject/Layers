#ifndef SLIDER_H
#define SLIDER_H

#include "Widget.h"

namespace Layers
{
	class Slider : public Widget
	{
		Q_OBJECT

	signals:
		void value_changed(int value);

	public:
		Slider(int limit, QWidget* parent = nullptr);

		void set_value(int value);

		void update_handle_pos();
		void update_theme_dependencies();

		Attribute a_value{ Attribute("Value", QVariant::fromValue(0)) };

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_limit{ 99 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};
}

#endif // SLIDER_H
