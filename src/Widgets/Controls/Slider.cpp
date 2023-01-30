#include "../../../include/Slider.h"

#include <QApplication>
#include <QMouseEvent>
#include <QVBoxLayout>

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

void Slider::init_attributes()
{
	connect(&a_value, &Entity::value_changed, [this] { update_handle_pos(); });

	corner_radii.top_left.set_value(10.0); // Need to check these values
	corner_radii.top_right.set_value(10.0);
	corner_radii.bottom_left.set_value(10.0);
	corner_radii.bottom_right.set_value(10.0);

	m_bar->a_fill.set_value(QColor(Qt::lightGray));
	m_bar->corner_radii.top_left.set_value(2.0);
	m_bar->corner_radii.top_right.set_value(2.0);
	m_bar->corner_radii.bottom_left.set_value(2.0);
	m_bar->corner_radii.bottom_right.set_value(2.0);

	m_handle->a_fill.set_value(QColor(Qt::darkGray));
	m_handle->corner_radii.top_left.set_value(3.0);
	m_handle->corner_radii.top_right.set_value(3.0);
	m_handle->corner_radii.bottom_left.set_value(3.0);
	m_handle->corner_radii.bottom_right.set_value(3.0);
}

void Slider::init_child_themeable_list()
{
	add_child_themeable_pointer(m_bar);
	add_child_themeable_pointer(m_handle);
}

void Slider::set_value(double value)
{
	a_value.set_value(QVariant::fromValue(value));

	emit value_changed(value);
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

			qDebug() << "New Value: " + QString::number(new_value);

			if (new_value < 0.0)
			{
				if (a_value.as<double>() != 0)
				{
					set_value(0.0);
				}
			}
			else if (new_value > 1.0)
			{
				if (a_value.as<double>() != 1.0)
				{
					set_value(1.0);
				}
			}
			else
			{
				set_value(new_value);
			}
		}
		else
		{
			double drag_increment = double(m_bar->width() - m_handle->width()) / double(m_limit);

			int new_value = m_value_on_click + int(delta.x() / drag_increment);

			if (new_value < 0)
				set_value(0);

			else if (new_value > m_limit)
				set_value(m_limit);

			else
				set_value(new_value);
		}
	}

	return false;
}

void Slider::init()
{
	init_attributes();
	init_child_themeable_list();

	installEventFilter(this);
	setFixedSize(244, 45);

	m_bar->setFixedHeight(5);
	m_bar->set_name("bar");
	m_bar->set_margin(23, 0, 23, 0);

	m_handle->setFixedSize(45, 45);
	m_handle->set_name("handle");
	m_handle->set_margin(15, 5, 15, 5);

	setup_layout();
}

void Slider::setup_layout()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_bar);

	setLayout(main_layout);

	m_handle->raise();
}
