#ifndef COLORPLANE_H
#define COLORPLANE_H

#include <QWidget>

#include "Attribute.h"
#include "calculate.h"
#include "color.h"
#include "Widget.h"

namespace Layers
{
	/*!
		A ColorPlane is a QWidget that serves as a two-dimensional slider for
		selecting a color from an HSV cylinder.

		The %ColorPlane can only represent two dimensions of an HSV cylinder
		at a time. Because of this, a Z-value attribute is included to control
		the third dimension.

		### Controlling HSV Dimensions

		The dimensions represented by the plane as well as the Z-value
		attribute depend on the active HSV. The active HSV defines which HSV
		dimension the Z-value attribute controls, while the remaining
		dimensions are controlled by the plane. For example, if the active HSV
		is set to 'Saturation', then the saturation is controlled by the
		Z-value attribute, while the hue and value are controlled by the plane.

		### Entangling the Z-Value Attribute

		Since the Z-value is represented with an Attribute, it can be entangled
		and controlled by another widget, like a Slider.
	*/
	class ColorPlane : public QWidget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the active-HSV is changed.
		*/
		void active_mode_changed();

	public:
		/*!
			Constructs a color plane.
		*/
		ColorPlane(QWidget* parent = nullptr);

		/*!
			Returns the active HSV.
		*/
		HSV active_hsv() const;

		/*!
			Returns a reference to the color attribute.
		*/
		Attribute& color();

		/*!
			Sets the active HSV to *new_active_hsv*.
		*/
		void set_active_hsv(HSV new_active_hsv);

		/*!
			Sets both the minimum and maximum heights of the widget to *h*
			without changing the widths.
		*/
		void setFixedHeight(int h);

		/*!
			Sets both the minimum and maximum sizes of the widget to *s*,
			thereby preventing it from ever growing or shrinking.
		*/
		void setFixedSize(const QSize& s);

		/*!
			Sets the width of the widget to *w* and the height to *h*.
		*/
		void setFixedSize(int w, int h);

		/*!
			Sets both the minimum and maximum width of the widget to *w*
			without changing the heights.
		*/
		void setFixedWidth(int w);

		/*!
			Returns a reference to the Z-value attribute.
		*/
		Attribute& z_value();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void paintEvent(QPaintEvent* event) override;

	private slots:
		void update_cursor_position();
		void update_z_value();

	private:
		void handle_mouse_event(QPoint& mouse_pos);

		void init_attributes();

		float pos_as_ratio(int pos, int available_space);

		void update_color(float x_pos_ratio, float y_pos_ratio);

		void update_height_dependencies();
		void update_width_dependencies();

		Attribute m_color{ Attribute("color", QColor("#ff0000")) };
		Attribute m_z_value{ Attribute("z_value", QVariant::fromValue(0.0)) };

		HSV m_active_hsv{ HSV::Hue };

		Widget* m_cursor{ new Widget(this) };

		int m_draw_height{ 245 };
		int m_draw_width{ 245 };

		const int margin{ 5 };

		bool m_dragging{ false };
	};
}

#endif // COLORPLANE_H