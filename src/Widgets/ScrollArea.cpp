#include "../../include/ScrollArea.h"

#include <QEvent>

using Layers::ScrollArea;

ScrollArea::ScrollArea(QWidget* parent) : Widget(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->setStyleSheet("QScrollArea { background-color:transparent; border:none; }");
	m_scroll_area->setHorizontalScrollBar(m_horizontal_scrollbar);
	m_scroll_area->setVerticalScrollBar(m_vertical_scrollbar);
	m_scroll_area->setFixedSize(size());
}

void ScrollArea::issue_update()
{
	update();
}

void ScrollArea::setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
	m_scroll_area->setHorizontalScrollBarPolicy(policy);
}

void ScrollArea::setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy)
{
	m_scroll_area->setVerticalScrollBarPolicy(policy);
}

void ScrollArea::setWidget(QWidget* widget)
{
	widget->setStyleSheet("background-color:transparent;");

	m_scroll_area->setWidget(widget);
}

bool ScrollArea::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
		m_scroll_area->setFixedSize(size());

	return false;
}
