#ifndef MINISLIDER_H
#define MINISLIDER_H

#include "Widget.h"

namespace Layers
{
	/*!
		A MiniSlider is a Widget that provides a mechanism for a user to
		control a numerical value within a set range.
	*/
	class MiniSlider : public Widget
	{
		Q_OBJECT

	public:
		/*!
			Constructs a mini-slider with a fixed *limit*.
		*/
		MiniSlider(double limit = 99.0, QWidget* parent = nullptr);

		/*!
			Sets the upper limit of the slider.
		*/
		void set_limit(double limit);

		/*!
			Returns a reference to the value attribute of the slider.
		*/
		Attribute& value();

	public slots:
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

	private:
		void init_layout();

		void update_handle_pos();

		Attribute a_value{ Attribute("value", QVariant::fromValue(0.0)) };

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
