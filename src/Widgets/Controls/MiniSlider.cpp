#include "../../../include/MiniSlider.h"

#include <QApplication>
#include <QMouseEvent>
#include <QVBoxLayout>

using Layers::MiniSlider;

MiniSlider::MiniSlider(int limit, QWidget* parent) :
	m_limit{ limit },
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

	connect(m_attribute_set.stateless_attribute("value"), &Attribute::value_changed, [this] { update_handle_pos(); });

	setup_layout();
}

void MiniSlider::init_attributes()
{
	add_stateless_attribute("value", 0);
	set_stateless_attribute_value("background_disabled", false);
	set_stateless_attribute_value("corner_radius_tl", 5); // Need to check these values
	set_stateless_attribute_value("corner_radius_tr", 5);
	set_stateless_attribute_value("corner_radius_bl", 5);
	set_stateless_attribute_value("corner_radius_br", 5);

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

void MiniSlider::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_bar);
	add_child_themeable_reference(m_handle);
}

void MiniSlider::set_attribute(Attribute* attribute)
{
	m_stateful_attribute = dynamic_cast<StatefulAttribute*>(attribute);
	m_stateless_attribute = dynamic_cast<StatelessAttribute*>(attribute);

	if (m_stateless_attribute)
	{
		connect(m_stateless_attribute, &Attribute::value_changed, [this]
			{
				set_stateless_attribute_value("value", m_stateless_attribute->value());
			});

		connect(m_attribute_set.stateless_attribute("value"), &Attribute::value_changed, [this]
			{
				m_stateless_attribute->set_value(m_attribute_set.stateless_attribute("value")->value(), true);
			});
	}
	else if (m_stateful_attribute)
	{
		m_attribute_states = m_stateful_attribute->states();

		m_current_editting_state = m_attribute_states.first();

		connect(m_stateful_attribute, &Attribute::value_changed, [this]
			{
				set_stateless_attribute_value("value", *m_stateful_attribute->value(m_current_editting_state));
			});

		connect(m_attribute_set.stateless_attribute("value"), &Attribute::value_changed, [this]
			{
				m_stateful_attribute->set_value(m_current_editting_state, m_attribute_set.stateless_attribute("value")->value(), true);
			});
	}
}

void MiniSlider::update_handle_pos()
{
	// 10 is left + right margin; NEW IDEA: Instead of margins, use m_bar->pos() and m_bar->pos() + m_barwidth() (Each end of the bar)
	double drag_increment = double(width() - m_handle->width() - 10) / double(m_limit);

	m_handle->move(drag_increment * m_attribute_set.attribute_value("value")->value<int>() + 5, m_handle->y()); // 5 is left margin
}

void MiniSlider::update_theme_dependencies()
{
	update_handle_pos();
}

void MiniSlider::set_current_editting_state(const QString& state)
{
	if (m_attribute_states.contains(state) && m_current_editting_state != state)
	{
		m_current_editting_state = state;

		set_stateless_attribute_value("value", *m_stateful_attribute->value(m_current_editting_state));

		//update_handle_pos();
	}
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
			double drag_increment = double(width() - m_handle->width() - 10) / double(m_limit); //double(m_bar->width() - m_handle->width()) / double(range_difference());

			int new_value = m_value_on_click + int((delta.x() / m_mouse_move_scale) / drag_increment);

			if (new_value < 0)
			{
				if (m_attribute_set.attribute_value("value")->value<int>() != 0)
					set_stateless_attribute_value("value", 0);
			}
			else if (new_value > m_limit)
			{
				if (m_attribute_set.attribute_value("value")->value<int>() != m_limit)
					set_stateless_attribute_value("value", m_limit);
			}
			else
				set_stateless_attribute_value("value", new_value);
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
