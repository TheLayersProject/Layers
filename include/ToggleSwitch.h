#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Widget.h"

namespace Layers
{
	class Label;

	/*!
		A ToggleSwitch is a Widget that provides the user with a way to control
		an on/off state.
	*/
	class ToggleSwitch : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the switch is toggled.
		*/
		void toggled_event();

	public:
		/*!
			Constructs a toggle switch.

			The *vertical* parameter is used to determine the orientation of
			the switch. The switch is in horizontal orientation by default.
		*/
		ToggleSwitch(bool vertical = false, QWidget* parent = nullptr);

		/*!
			Sets both the minimum and maximum heights of the widget to *h*
			without changing the widths.
		*/
		void setFixedHeight(int h);

		/*!
			Sets the toggle state of the switch.
		*/
		void set_toggled(bool toggled);

		/*!
			Toggles the switch.

			The *emit_toggled_event* parameter is used to determine if the
			toggled_event() signal should be emitted. It is true by default.
		*/
		void toggle(bool emit_toggled_event = true);

		/*!
			Returns the toggle state of the switch.
		*/
		bool toggled() const;

		Attribute a_padding_left{ Attribute("Left Padding", QVariant::fromValue(2.0)) };
		Attribute a_padding_top{ Attribute("Top Padding", QVariant::fromValue(2.0)) };
		Attribute a_padding_right{ Attribute("Right Padding", QVariant::fromValue(2.0)) };
		Attribute a_padding_bottom{ Attribute("Bottom Padding", QVariant::fromValue(2.0)) };

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init_attributes();

		void init_layout();

		void update_layout_margins();

		void update_spacer_size();

		QHBoxLayout* m_layout_h{ nullptr };

		QVBoxLayout* m_layout_v{ nullptr };

		Widget* m_spacer{ new Widget };
		Widget* m_square{ new Widget };

		bool m_vertical{ false };
	};
}

#endif // TOGGLESWITCH_H
