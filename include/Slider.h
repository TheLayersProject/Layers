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
		Slider(QWidget* parent = nullptr);
		Slider(int limit, QWidget* parent = nullptr);

		void set_limit(int limit);

		void set_value(double value);

		Attribute a_value{ Attribute("value", QVariant::fromValue(0.0)) };

	public slots:
		void update_handle_pos();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void init();

		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_limit{ 99 };
		double m_value_on_click{ 0.0 };

		bool m_dragging_handle{ false };

		bool m_is_ratio_slider;

		QPoint m_mouse_click_position{ QPoint() };
	};
}

#endif // SLIDER_H
