#ifndef MINISLIDER_H
#define MINISLIDER_H

#include "Widget.h"

namespace Layers
{
	class MiniSlider : public Widget
	{
		Q_OBJECT

	public:
		MiniSlider(int limit, QWidget* parent = nullptr);

		void update_handle_pos();
		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_limit{ 99 };
		int m_mouse_move_scale{ 5 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};
}

#endif // MINISLIDER_H
