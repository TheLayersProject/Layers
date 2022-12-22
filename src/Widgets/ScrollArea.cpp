#include "../../include/ScrollArea.h"

#include <QEvent>

using Layers::ScrollArea;
using Layers::ScrollBar;

ScrollArea::ScrollArea(QWidget* parent) : Widget(parent)
{
	init_child_themeable_reference_list();

	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_horizontal_scrollbar->set_name("horizontal_scrollbar");
	m_horizontal_scrollbar->set_proper_name("Horizontal Scrollbar");

	m_vertical_scrollbar->set_name("vertical_scrollbar");
	m_vertical_scrollbar->set_proper_name("Vertical Scrollbar");

	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->setStyleSheet("QScrollArea { background-color:transparent; border:none; }");
	m_scroll_area->setHorizontalScrollBar(m_horizontal_scrollbar);
	m_scroll_area->setVerticalScrollBar(m_vertical_scrollbar);
	m_scroll_area->setFixedSize(size());
}

ScrollBar* ScrollArea::horizontal_scrollbar() const
{
	return m_horizontal_scrollbar;
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

ScrollBar* ScrollArea::vertical_scrollbar() const
{
	return m_vertical_scrollbar;
}

bool ScrollArea::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
		m_scroll_area->setFixedSize(size());

	return false;
}

void ScrollArea::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_horizontal_scrollbar);
	store_child_themeable_pointer(m_vertical_scrollbar);
}
