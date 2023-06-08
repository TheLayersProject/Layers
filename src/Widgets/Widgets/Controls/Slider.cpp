#include "Slider.h"

#include <QApplication>
#include <QMouseEvent>
#include <QVBoxLayout>

using Layers::Attribute;
using Layers::Slider;

Slider::Slider(QWidget* parent) :
	m_is_ratio_slider{ true }, Widget(parent)
{
	init();
}

Slider::Slider(int limit, QWidget* parent) :
	m_is_ratio_slider{ false }, m_limit{ limit }, Widget(parent)
{
	init();
}

void Slider::set_limit(int limit)
{
	m_limit = limit;

	update_handle_pos();
}

Attribute& Slider::value()
{
	return a_value;
}

bool Slider::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress && m_handle->underMouse())
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			m_dragging_handle = true;

			m_mouse_click_position = mouse_event->pos();
			m_value_on_click = a_value.as<double>();
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease && m_handle->underMouse())
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			m_dragging_handle = false;
		}
	}

	if (event->type() == QEvent::MouseMove && m_dragging_handle == true)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		QPoint delta = mouse_event->pos() - m_mouse_click_position;

		if (m_is_ratio_slider)
		{
			float range = float(width() - m_handle->width());

			float ratio = 1 / range;

			double new_value = float(m_value_on_click) + (float(delta.x()) * ratio);

			if (new_value < 0.0)
			{
				if (a_value.as<double>() != 0.0)
				{
					a_value.set_value(0.0);
				}
			}
			else if (new_value > 1.0)
			{
				if (a_value.as<double>() != 1.0)
				{
					a_value.set_value(1.0);
				}
			}
			else
			{
				a_value.set_value(new_value);
			}
		}
		else
		{
			double drag_increment = double(m_bar->width() - m_handle->width()) / double(m_limit);

			double new_value = m_value_on_click + float(delta.x() / drag_increment);

			if (new_value < 0.0)
				a_value.set_value(0.0);

			else if (new_value > m_limit)
				a_value.set_value(double(m_limit));

			else
				a_value.set_value(new_value);
		}
	}

	return false;
}

void Slider::init()
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(244, 40);

	m_bar->setFixedHeight(5);
	m_bar->set_name("bar");
	m_bar->set_margin(23, 0, 23, 0);

	m_handle->setFixedSize(40, 40);
	m_handle->set_name("handle");
	m_handle->set_margin(15, 5, 15, 5);

	init_layout();
}

void Slider::init_attributes()
{
	connect(&a_value, &AbstractAttribute::changed, [this] { update_handle_pos(); });

	m_corner_radii->top_left()->set_value(10.0); // Need to check these values
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	m_bar->fill()->set_value(QColor(Qt::lightGray));
	m_bar->corner_radii()->top_left()->set_value(2.0);
	m_bar->corner_radii()->top_right()->set_value(2.0);
	m_bar->corner_radii()->bottom_left()->set_value(2.0);
	m_bar->corner_radii()->bottom_right()->set_value(2.0);

	m_handle->fill()->set_value(QColor(Qt::darkGray));
	m_handle->corner_radii()->top_left()->set_value(3.0);
	m_handle->corner_radii()->top_right()->set_value(3.0);
	m_handle->corner_radii()->bottom_left()->set_value(3.0);
	m_handle->corner_radii()->bottom_right()->set_value(3.0);
}

void Slider::init_layout()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_bar);

	setLayout(main_layout);

	m_handle->raise();
}

void Slider::update_handle_pos()
{
	if (m_is_ratio_slider)
	{
		float range = float(width() - m_handle->width());

		float ratio = 1 / range;

		m_handle->move(a_value.as<double>() / ratio, m_handle->y());
	}
	else
	{
		double drag_increment = double(width() - m_handle->width()) / double(m_limit);

		m_handle->move(drag_increment * a_value.as<double>(), m_handle->y());
	}
}
