#include "Widget.h"

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::Widget;

Widget::Widget(QWidget* parent) :
	QWidget(parent)
{
	init_attributes();

	setFocusPolicy(Qt::ClickFocus);
}

void Widget::paintEvent(QPaintEvent* event)
{
	paint(this);
}
