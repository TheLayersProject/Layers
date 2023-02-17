#include "../../include/ColorPlane.h"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

using Layers::ColorPlane;

ColorPlane::ColorPlane(QWidget* parent)
	: QWidget(parent)
{
	init_attributes();

    installEventFilter(this);
	setFixedSize(255, 255);

	m_cursor->setFixedSize(10, 10);
    m_cursor->move(width() - margin - (m_cursor->width() / 2), 0);
}

ColorPlane::Mode ColorPlane::active_mode() const
{
	return m_active_mode;
}

float ColorPlane::pos_as_ratio(int pos, int available_space)
{
    return
        float(pos - margin) /
            float(available_space - (margin * 2) - 1);
}

void ColorPlane::set_active_mode(Mode new_active_hsv)
{
	m_active_mode = new_active_hsv;

    update_cursor_position();

	emit active_mode_changed();
}

void ColorPlane::setFixedHeight(int h)
{
    QWidget::setFixedHeight(h);

    update_height_dependencies();
}

void ColorPlane::setFixedSize(const QSize& s)
{
    QWidget::setFixedSize(s);

    update_height_dependencies();
    update_width_dependencies();
}

void ColorPlane::setFixedSize(int w, int h)
{
    QWidget::setFixedSize(w, h);

    update_height_dependencies();
    update_width_dependencies();
}

void ColorPlane::setFixedWidth(int w)
{
    QWidget::setFixedWidth(w);

    update_width_dependencies();
}

void ColorPlane::update_color(float x_pos_ratio, float y_pos_ratio)
{
    QColor c = color.as<QColor>();

    switch (m_active_mode)
    {
    case Mode::Hue:
        c.setHsvF(c.hueF(), x_pos_ratio, 1.f - y_pos_ratio);
        break;
    case Mode::Saturation:
        c.setHsvF(x_pos_ratio, c.saturationF(), 1.f - y_pos_ratio);
        break;
    case Mode::Value:
        c.setHsvF(x_pos_ratio, 1.f - y_pos_ratio, c.valueF());
        break;
    }

    color.set_value(c);
}

void ColorPlane::update_cursor_position()
{
    QColor c = color.as<QColor>();

    float w_ratio = 1.f / float(width() - (margin * 2) - 1);
    float h_ratio = 1.f / float(height() - (margin * 2) - 1);

    QPoint new_cursor_location;

    switch (m_active_mode)
    {
    case Mode::Hue:
        new_cursor_location = QPoint(
            c.saturationF() / w_ratio, (1.f - c.valueF()) / h_ratio);
        break;
    case Mode::Saturation:
        new_cursor_location = QPoint(
            c.hueF() / w_ratio, (1.f - c.valueF()) / h_ratio);
        break;
    case Mode::Value:
        new_cursor_location = QPoint(
            c.hueF() / w_ratio, (1.f - c.saturationF()) / h_ratio);
        break;
    }

    new_cursor_location += QPoint(margin, margin);
    new_cursor_location -= QPoint(m_cursor->width() / 2, m_cursor->height() / 2);
    m_cursor->move(new_cursor_location);
}

void ColorPlane::update_z_value()
{
    switch (m_active_mode)
    {
    case Mode::Hue:
        z_value.set_value(double(color.as<QColor>().hue()));
        break;
    case Mode::Saturation:
        z_value.set_value(double(color.as<QColor>().saturation()));
        break;
    case Mode::Value:
        z_value.set_value(double(color.as<QColor>().value()));
        break;
    }
}

void ColorPlane::update_height_dependencies()
{
    m_draw_height = height() - (margin * 2);

    update_cursor_position();
}

void ColorPlane::update_width_dependencies()
{
    m_draw_width = width() - (margin * 2);

    update_cursor_position();
}

bool ColorPlane::eventFilter(QObject* object, QEvent* event)
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

void ColorPlane::handle_mouse_event(QPoint& mouse_pos)
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

void ColorPlane::paintEvent(QPaintEvent* event)
{
	QImage image;
    QColor paint_color;
	QPainter painter(this);

	switch (m_active_mode)
	{
	case Mode::Hue:
    {
        image = QImage(max_SV + 1, max_SV + 1, QImage::Format_RGB32);

        int h = color.as<QColor>().hue();

        for (int s = 0; s <= max_SV; s++) {
            for (int v = 0; v <= max_SV; v++) {
                paint_color.setHsv(h, s, v);
                image.setPixel(s, max_SV - v, paint_color.rgb());
            }
        }
        break;
    }
	case Mode::Saturation:
    {
        image = QImage(max_H + 1, max_SV + 1, QImage::Format_RGB32);

        int s = color.as<QColor>().saturation();

        for (int h = 0; h <= max_H; h++) {
            for (int v = 0; v <= max_SV; v++) {
                paint_color.setHsv(h, s, v);
                image.setPixel(h, max_SV - v, paint_color.rgb());
            }
        }
        break;
    }
	case Mode::Value:
    {
        image = QImage(max_H + 1, max_SV + 1, QImage::Format_RGB32);

        int v = color.as<QColor>().value();

        for (int h = 0; h <= max_H; h++) {
            for (int s = 0; s <= max_SV; s++) {
                paint_color.setHsv(h, s, v);
                image.setPixel(h, max_SV - s, paint_color.rgb());
            }
        }
        break;
    }
	}

	painter.drawImage(
		QRect(margin, margin, m_draw_width, m_draw_height),
		image);
}

void ColorPlane::init_attributes()
{
    connect(&z_value, &Attribute::value_changed, [this] {
        QColor c = color.as<QColor>();

        switch (m_active_mode)
        {
        case Mode::Hue:
            c.setHsv(z_value.as<int>(), c.saturation(), c.value());
            break;
        case Mode::Saturation:
            c.setHsv(c.hue(), z_value.as<int>(), c.value());
            break;
        case Mode::Value:
            c.setHsv(c.hue(), c.saturation(), z_value.as<int>());
            break;
        }

        color.set_value(c);
        });
    
    connect(&color, &Attribute::value_changed, this, &ColorPlane::update_cursor_position);
    connect(&color, &Attribute::value_changed, this, &ColorPlane::update_z_value);

    connect(&color, &Attribute::value_changed, [this] { update(); });

    //color.setup_widget_update_connection(this);

    m_cursor->fill()->entangle_with(color);
    m_cursor->border()->fill()->set_value(QColor(Qt::lightGray));
    m_cursor->border()->thickness()->set_value(2.0);
	m_cursor->outline_color()->set_disabled(false);
	m_cursor->outline_color()->set_value(QColor(Qt::black));
	m_cursor->corner_radii()->top_left()->set_value(2.0);
	m_cursor->corner_radii()->top_right()->set_value(2.0);
	m_cursor->corner_radii()->bottom_left()->set_value(2.0);
	m_cursor->corner_radii()->bottom_right()->set_value(2.0);
}
