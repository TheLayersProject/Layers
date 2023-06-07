#ifndef MINISLIDER_H
#define MINISLIDER_H

#include "Widget.h"

namespace Layers
{
	class MiniSlider : public Widget
	{
		Q_OBJECT

	public:
		MiniSlider(double limit = 99.0, QWidget* parent = nullptr);

		void set_limit(double limit);

		void update_handle_pos();

		Attribute a_value{ Attribute("value", QVariant::fromValue(0.0)) };

	public slots:
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		double m_limit;

		int m_mouse_move_scale{ 5 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};
}

#endif // MINISLIDER_H
