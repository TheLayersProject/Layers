#include <LayersWidgets/lwidget.h>

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::LWidget;

LWidget::LWidget(QWidget* parent) :
	QWidget(parent)
{
	init_attributes();

	setFocusPolicy(Qt::ClickFocus);
}

void LWidget::paintEvent(QPaintEvent* event)
{
	paint(this);
}
