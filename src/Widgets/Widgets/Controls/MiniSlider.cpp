#include "MiniSlider.h"

#include <QApplication>
#include <QMouseEvent>
#include <QVBoxLayout>

using Layers::MiniSlider;

MiniSlider::MiniSlider(double limit, QWidget* parent) :
	m_limit{ limit },
	Widget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(45, 45);

	m_bar->setFixedHeight(3);
	m_bar->set_name("bar");
	m_bar->set_proper_name("Bar");

	m_handle->move(5, 16);
	m_handle->setFixedSize(5, 13);
	m_handle->set_name("handle");
	m_handle->set_proper_name("Handle");

	connect(&a_value, &AbstractAttribute::changed, [this] { update_handle_pos(); });

	setup_layout();
}

void MiniSlider::set_limit(double limit)
{
	m_limit = limit;

	update_handle_pos();
}

void MiniSlider::init_attributes()
{
	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);

	m_bar->set_margin(5, 0, 5, 0);
	m_bar->corner_radii()->top_left()->set_value(2.0);
	m_bar->corner_radii()->top_right()->set_value(2.0);
	m_bar->corner_radii()->bottom_left()->set_value(2.0);
	m_bar->corner_radii()->bottom_right()->set_value(2.0);

	m_handle->corner_radii()->top_left()->set_value(2.0);
	m_handle->corner_radii()->top_right()->set_value(2.0);
	m_handle->corner_radii()->bottom_left()->set_value(2.0);
	m_handle->corner_radii()->bottom_right()->set_value(2.0);

	// TODO: TEMP!
	m_fill->set_value(QColor(Qt::lightGray));

	m_bar->fill()->set_value(QColor(Qt::blue));

	m_handle->fill()->set_value(QColor(Qt::red));
}

void MiniSlider::update_handle_pos()
{
	// 10 is left + right margin; NEW IDEA: Instead of margins, use m_bar->pos() and m_bar->pos() + m_barwidth() (Each end of the bar)
	double drag_increment = double(width() - m_handle->width() - 10) / double(m_limit);

	m_handle->move(drag_increment * a_value.as<double>() + 5, m_handle->y()); // 5 is left margin
}

void MiniSlider::set_current_editting_state(const QString& state)
{
	a_value.set_state(state);

	update_handle_pos();

	// Might need to do more here or add state support is other functions in this document
}

bool MiniSlider::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			QApplication::setOverrideCursor(Qt::BlankCursor);
			//QApplication::changeOverrideCursor(cursor);

			m_dragging_handle = true;

			m_mouse_click_position = mouse_event->pos();
			m_value_on_click = a_value.as<double>();
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			QApplication::restoreOverrideCursor();

			m_dragging_handle = false;

			QCursor::setPos(mapToGlobal(QPoint(width() / 2, height() / 2)));
			//QCursor::setPos(mapToGlobal(m_mouse_click_position));
		}
	}

	if (event->type() == QEvent::MouseMove && m_dragging_handle == true)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		QPoint delta = mouse_event->pos() - m_mouse_click_position;

		if (delta.x() % m_mouse_move_scale == 0)
		{
			double drag_increment = double(width() - m_handle->width() - 10) / double(m_limit); //double(m_bar->width() - m_handle->width()) / double(range_difference());

			double new_value = m_value_on_click + int((delta.x() / m_mouse_move_scale) / drag_increment);

			if (new_value < 0.0)
				a_value.set_value(0.0);

			else if (new_value > m_limit)
				a_value.set_value(m_limit);

			else
				a_value.set_value(new_value);
		}
	}

	return false;
}

void MiniSlider::setup_layout()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_bar);

	setLayout(main_layout);

	m_handle->raise();
}
