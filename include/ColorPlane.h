#ifndef COLORPLANE_H
#define COLORPLANE_H

#include <QWidget>

#include "Attribute.h"
#include "calculate.h"
#include "color.h"
#include "Widget.h"

namespace Layers
{
	class ColorPlane : public QWidget
	{
		Q_OBJECT

	signals:
		void active_mode_changed();

	public:
		ColorPlane(QWidget* parent = nullptr);

		HSV active_hsv() const;

		float pos_as_ratio(int pos, int available_space);

		void set_active_hsv(HSV new_active_hsv);

		void setFixedHeight(int h);
		void setFixedSize(const QSize& s);
		void setFixedSize(int w, int h);
		void setFixedWidth(int w);

		void update_color(float x_pos_ratio, float y_pos_ratio);

		void update_height_dependencies();
		void update_width_dependencies();

		Attribute color{ Attribute("color", QColor("#ff0000"))};

		Attribute z_value{ Attribute("z_value", QVariant::fromValue(0.0)) };

	public slots:
		void update_cursor_position();
		void update_z_value();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void handle_mouse_event(QPoint& mouse_pos);

		void init_attributes();

		HSV m_active_hsv{ HSV::Hue };

		Widget* m_cursor{ new Widget(this) };

		int m_draw_height{ 245 };
		int m_draw_width{ 245 };

		const int margin{ 5 };

		bool m_dragging{ false };
	};
}

#endif // COLORPLANE_H