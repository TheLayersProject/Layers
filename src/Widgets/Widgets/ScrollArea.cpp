#include "ScrollArea.h"

#include <QEvent>

using Layers::ScrollArea;
using Layers::ScrollBar;
using Layers::Themeable;

ScrollArea::ScrollArea(QWidget* parent) : Widget(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	m_scroll_area->setWidgetResizable(true);
	m_scroll_area->setStyleSheet("QScrollArea { background-color:transparent; border:none; }");
	m_scroll_area->setHorizontalScrollBar(m_horizontal_scrollbar);
	m_scroll_area->setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->set_name("Horizontal ScrollBar");

	m_vertical_scrollbar->set_name("Vertical ScrollBar");
}

QList<Themeable*> ScrollArea::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables = Themeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	if (Themeable* themeable_widget = dynamic_cast<Themeable*>(widget()))
	{
		child_themeables.append(themeable_widget);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> widget_child_objects = widget()->findChildren<QObject*>(options);

			for (QObject* widget_child_object : widget_child_objects)
				if (Themeable* child_themeable = dynamic_cast<Themeable*>(widget_child_object))
					child_themeables.append(child_themeable);
		}
	}

	return child_themeables;
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
	m_scroll_area->setWidget(widget);

	widget->setStyleSheet("background-color:transparent;");
}

QWidget* ScrollArea::takeWidget() const
{
	return m_scroll_area->takeWidget();
}

ScrollBar* ScrollArea::vertical_scrollbar() const
{
	return m_vertical_scrollbar;
}

QWidget* ScrollArea::widget() const
{
	return m_scroll_area->widget();
}

bool ScrollArea::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
		m_scroll_area->setFixedSize(size());

	return false;
}
