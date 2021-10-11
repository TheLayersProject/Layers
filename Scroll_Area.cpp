#include "Layers.h"

using Layers::Scroll_Area;

Scroll_Area::Scroll_Area(QWidget* parent) :	Widget(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->setStyleSheet("QScrollArea { background-color:transparent; border:none; }");
	m_scroll_area->setHorizontalScrollBar(m_horizontal_scrollbar);
	m_scroll_area->setVerticalScrollBar(m_vertical_scrollbar);
	m_scroll_area->setFixedSize(size());
}

void Scroll_Area::issue_update()
{
	update();
}

void Scroll_Area::setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
	m_scroll_area->setHorizontalScrollBarPolicy(policy);
}

void Scroll_Area::setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
	m_scroll_area->setVerticalScrollBarPolicy(policy);
}

void Scroll_Area::setWidget(QWidget* widget)
{
	widget->setStyleSheet("background-color:transparent;");

	m_scroll_area->setWidget(widget);
}

bool Scroll_Area::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
		m_scroll_area->setFixedSize(size());

	return false;
}
