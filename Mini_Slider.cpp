#include "Layers.h"

using Layers::Mini_Slider;

Mini_Slider::Mini_Slider(int range_start, int range_end, QWidget* parent) :
	m_range_start{ range_start }, m_range_end{ range_end },
	Widget(parent)
{
	init_attributes();
	init_child_themeable_reference_list();

	installEventFilter(this);
	setFixedSize(45, 45);

	m_bar->setFixedHeight(3);
	m_bar->set_name("bar");
	m_bar->set_margin(5, 0, 5, 0);

	m_handle->move(5, 16);
	m_handle->setFixedSize(5, 13);
	m_handle->set_name("handle");

	setup_layout();
}

void Mini_Slider::init_attributes()
{
	set_stateless_attribute_value("background_disabled", false);
	set_stateless_attribute_value("corner_radius_tl", 5); // Need to check these values
	set_stateless_attribute_value("corner_radius_tr", 5);
	set_stateless_attribute_value("corner_radius_bl", 5);
	set_stateless_attribute_value("corner_radius_br", 5);
	add_stateless_attribute("value", 0);

	m_bar->set_stateless_attribute_value("corner_radius_tl", 2);
	m_bar->set_stateless_attribute_value("corner_radius_tr", 2);
	m_bar->set_stateless_attribute_value("corner_radius_bl", 2);
	m_bar->set_stateless_attribute_value("corner_radius_br", 2);

	m_handle->set_stateless_attribute_value("corner_radius_tl", 2);
	m_handle->set_stateless_attribute_value("corner_radius_tr", 2);
	m_handle->set_stateless_attribute_value("corner_radius_bl", 2);
	m_handle->set_stateless_attribute_value("corner_radius_br", 2);

	// TEMP!
	set_stateless_attribute_value("background_color", QColor(Qt::lightGray));

	m_bar->set_stateless_attribute_value("background_color", QColor(Qt::blue));

	m_handle->set_stateless_attribute_value("background_color", QColor(Qt::red));
}

void Mini_Slider::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_bar);
	add_child_themeable_reference(m_handle);
}

int Mini_Slider::range_difference()
{
	return m_range_end - m_range_start;
}

void Mini_Slider::update_handle_pos()
{
	// 10 is left + right margin; NEW IDEA: Instead of margins, use m_bar->pos() and m_bar->pos() + m_barwidth() (Each end of the bar)
	double drag_increment = double(width() - m_handle->width() - 10) / double(range_difference());

	m_handle->move(drag_increment * m_attribute_set.attribute_value("value")->value<int>() + 5, m_handle->y()); // 5 is left margin
}

void Mini_Slider::update_theme_dependencies()
{
	update_handle_pos();
}

bool Mini_Slider::eventFilter(QObject* object, QEvent* event)
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
			m_value_on_click = m_attribute_set.attribute_value("value")->value<int>();
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
			double drag_increment = double(width() - m_handle->width() - 10) / double(range_difference()); //double(m_bar->width() - m_handle->width()) / double(range_difference());

			int new_value = m_value_on_click + int((delta.x() / m_mouse_move_scale) / drag_increment);

			if (new_value < m_range_start)
			{
				if (m_attribute_set.attribute_value("value")->value<int>() != m_range_start)
				{
					set_stateless_attribute_value("value", m_range_start);
					update_handle_pos();
					share_attributes();
				}
			}
			else if (new_value > m_range_end)
			{
				if (m_attribute_set.attribute_value("value")->value<int>() != m_range_end)
				{
					set_stateless_attribute_value("value", m_range_end);
					update_handle_pos();
					share_attributes();
				}
			}
			else
			{
				set_stateless_attribute_value("value", new_value);
				update_handle_pos();
				share_attributes();
			}
		}
	}

	return false;
}

void Mini_Slider::setup_layout()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setMargin(0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_bar);

	setLayout(main_layout);

	m_handle->raise();
}
