#include <Layers/lcolorplane.h>

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

using Layers::LAttribute;
using Layers::LColorPlane;
using Layers::HSV;

LColorPlane::LColorPlane(QWidget* parent)
	: QWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(255, 255);

	m_cursor->setFixedSize(10, 10);
	m_cursor->move(width() - margin - (m_cursor->width() / 2), 0);

	connect(this, &LColorPlane::active_mode_changed,
		this, &LColorPlane::update_z_value);
}

HSV LColorPlane::active_hsv() const
{
	return m_active_hsv;
}

LAttribute& LColorPlane::color()
{
	return m_color;
}

float LColorPlane::pos_as_ratio(int pos, int available_space)
{
	return
		float(pos - margin) /
			float(available_space - (margin * 2) - 1);
}

void LColorPlane::set_active_hsv(HSV new_active_hsv)
{
	m_active_hsv = new_active_hsv;

	update();

	update_cursor_position();

	emit active_mode_changed();
}

void LColorPlane::setFixedHeight(int h)
{
	QWidget::setFixedHeight(h);

	update_height_dependencies();
}

void LColorPlane::setFixedSize(const QSize& s)
{
	QWidget::setFixedSize(s);

	update_height_dependencies();
	update_width_dependencies();
}

void LColorPlane::setFixedSize(int w, int h)
{
	QWidget::setFixedSize(w, h);

	update_height_dependencies();
	update_width_dependencies();
}

void LColorPlane::setFixedWidth(int w)
{
	QWidget::setFixedWidth(w);

	update_width_dependencies();
}

LAttribute& LColorPlane::z_value()
{
	return m_z_value;
}

bool LColorPlane::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		QPoint mouse_pos = mouse_event->pos();

		if (mouse_event->button() & Qt::LeftButton)
		{
			m_dragging = true;

			handle_mouse_event(mouse_pos);
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease && m_dragging)
	{
		m_dragging = false;
	}
	else if (event->type() == QEvent::MouseMove && m_dragging)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		QPoint mouse_pos = mouse_event->pos();

		handle_mouse_event(mouse_pos);
	}

	return false;
}

void LColorPlane::paintEvent(QPaintEvent* event)
{
	QImage image;
	QColor paint_color;
	QPainter painter(this);

	switch (m_active_hsv)
	{
	case HSV::Hue:
	{
		image = QImage(MAX_SV + 1, MAX_SV + 1, QImage::Format_RGB32);

		int h = m_color.as<QColor>().hue();

		for (int s = 0; s <= MAX_SV; s++) {
			for (int v = 0; v <= MAX_SV; v++) {
				paint_color.setHsv(h, s, v);
				image.setPixel(s, MAX_SV - v, paint_color.rgb());
			}
		}
		break;
	}
	case HSV::Saturation:
	{
		image = QImage(MAX_H + 1, MAX_SV + 1, QImage::Format_RGB32);

		int s = m_color.as<QColor>().saturation();

		for (int h = 0; h <= MAX_H; h++) {
			for (int v = 0; v <= MAX_SV; v++) {
				paint_color.setHsv(h, s, v);
				image.setPixel(h, MAX_SV - v, paint_color.rgb());
			}
		}
		break;
	}
	case HSV::Value:
	{
		image = QImage(MAX_H + 1, MAX_SV + 1, QImage::Format_RGB32);

		int v = m_color.as<QColor>().value();

		for (int h = 0; h <= MAX_H; h++) {
			for (int s = 0; s <= MAX_SV; s++) {
				paint_color.setHsv(h, s, v);
				image.setPixel(h, MAX_SV - s, paint_color.rgb());
			}
		}
		break;
	}
	}

	painter.drawImage(
		QRect(margin, margin, m_draw_width, m_draw_height),
		image);
}

void LColorPlane::update_cursor_position()
{
	QColor c = m_color.as<QColor>();

	float w_ratio = 1.f / float(width() - (margin * 2) - 1);
	float h_ratio = 1.f / float(height() - (margin * 2) - 1);

	QPoint new_cursor_location;

	switch (m_active_hsv)
	{
	case HSV::Hue:
		new_cursor_location = QPoint(
			c.saturationF() / w_ratio, (1.f - c.valueF()) / h_ratio);
		break;
	case HSV::Saturation:
		new_cursor_location = QPoint(
			c.hueF() / w_ratio, (1.f - c.valueF()) / h_ratio);
		break;
	case HSV::Value:
		new_cursor_location = QPoint(
			c.hueF() / w_ratio, (1.f - c.saturationF()) / h_ratio);
		break;
	}

	new_cursor_location += QPoint(margin, margin);
	new_cursor_location -= QPoint(m_cursor->width() / 2, m_cursor->height() / 2);
	m_cursor->move(new_cursor_location);
}

void LColorPlane::update_z_value()
{
	switch (m_active_hsv)
	{
	case HSV::Hue:
		m_z_value.set_value(double(m_color.as<QColor>().hue()));
		break;
	case HSV::Saturation:
		m_z_value.set_value(double(m_color.as<QColor>().saturation()));
		break;
	case HSV::Value:
		m_z_value.set_value(double(m_color.as<QColor>().value()));
		break;
	}
}

void LColorPlane::handle_mouse_event(QPoint& mouse_pos)
{
	float x_pos_ratio = 0.f;
	float y_pos_ratio = 0.f;

	// Handle X
	if (mouse_pos.x() < margin)
		x_pos_ratio = 0.f;
	else if (mouse_pos.x() >= width() - margin)
		x_pos_ratio = 1.f;
	else
		x_pos_ratio = pos_as_ratio(mouse_pos.x(), width());

	// Handle Y
	if (mouse_pos.y() < margin)
		y_pos_ratio = 0.f;
	else if (mouse_pos.y() >= height() - margin)
		y_pos_ratio = 1.f;
	else
		y_pos_ratio = pos_as_ratio(mouse_pos.y(), height());

	// Update color
	update_color(x_pos_ratio, y_pos_ratio);
}

void LColorPlane::init_attributes()
{
	connect(&m_z_value, &LAttribute::changed, [this] {
		QColor c = m_color.as<QColor>();

		switch (m_active_hsv)
		{
		case HSV::Hue:
			c.setHsv(m_z_value.as<int>(), c.saturation(), c.value());
			break;
		case HSV::Saturation:
			c.setHsv(c.hue(), m_z_value.as<int>(), c.value());
			break;
		case HSV::Value:
			c.setHsv(c.hue(), c.saturation(), m_z_value.as<int>());
			break;
		}

		m_color.set_value(c);
		});

	connect(&m_color, &LAttribute::changed, [this]
		{
			update_cursor_position();
			//update_z_value();
			update();
		});

	//color.setup_widget_update_connection(this);

	m_cursor->fill()->establish_link(m_color);
	m_cursor->border()->fill()->set_value(QColor(Qt::lightGray));
	m_cursor->border()->thickness()->set_value(2.0);
	m_cursor->corner_radii()->top_left()->set_value(2.0);
	m_cursor->corner_radii()->top_right()->set_value(2.0);
	m_cursor->corner_radii()->bottom_left()->set_value(2.0);
	m_cursor->corner_radii()->bottom_right()->set_value(2.0);
}

void LColorPlane::update_color(float x_pos_ratio, float y_pos_ratio)
{
	QColor c = m_color.as<QColor>();

	switch (m_active_hsv)
	{
	case HSV::Hue:
		c.setHsvF(c.hueF(), x_pos_ratio, 1.f - y_pos_ratio);
		break;
	case HSV::Saturation:
		c.setHsvF(x_pos_ratio, c.saturationF(), 1.f - y_pos_ratio);
		break;
	case HSV::Value:
		c.setHsvF(x_pos_ratio, 1.f - y_pos_ratio, c.valueF());
		break;
	}

	m_color.set_value(c);
}

void LColorPlane::update_height_dependencies()
{
	m_draw_height = height() - (margin * 2);

	update_cursor_position();
}

void LColorPlane::update_width_dependencies()
{
	m_draw_width = width() - (margin * 2);

	update_cursor_position();
}
