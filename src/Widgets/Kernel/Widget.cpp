#include "Widget.h"

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::Widget;

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	init_attributes();

	setFocusPolicy(Qt::ClickFocus);

	connect(m_border->thickness(), &AbstractAttribute::value_changed, [this] {
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

	for (AbstractAttribute* entity : m_attributes)
		establish_update_connection(entity);
		//entity->setup_widget_update_connection(this);
}

void Widget::paintEvent(QPaintEvent* event)
{
	paint(this);
}
