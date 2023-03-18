//#include "Layouts.h"
#include "Widget.h"

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::Widget;

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFocusPolicy(Qt::ClickFocus);

	connect(m_border->thickness(), &Entity::value_changed, [this] {
		if (layout())
		{
			//if (VerticalLayout* vl = dynamic_cast<VerticalLayout*>(layout()))
			//	vl->set_border_margin(m_border->thickness()->as<double>());
			//else if (HorizontalLayout* hl = dynamic_cast<HorizontalLayout*>(layout()))
			//	hl->set_border_margin(m_border->thickness()->as<double>());
		}
		});
}

void Widget::init_attributes()
{
	ThemeableBox::init_attributes();

	for (Entity* entity : m_entities)
		establish_update_connection(entity);
		//entity->setup_widget_update_connection(this);
}

bool Widget::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Enter)
	{
		m_hovering = true;
		update();
		emit hover_enter();
	}
	else if (event->type() == QEvent::Leave)
	{
		m_hovering = false;
		update();
		emit hover_leave();
	}
	else if (event->type() == QEvent::MouseMove)
	{
		emit hover_move();
	}

	return false;
}

void Widget::paintEvent(QPaintEvent* event)
{
	paint(this);
}
