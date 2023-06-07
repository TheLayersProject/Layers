#include "ScrollArea.h"

#include <QEvent>

using Layers::ScrollArea;
using Layers::ScrollBar;
using Layers::Themeable;

ScrollArea::ScrollArea(QWidget* parent) : QScrollArea(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	setWidgetResizable(true);
	setStyleSheet("QScrollArea { background-color:transparent; border:none; }");
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setVerticalScrollBar(m_vertical_scrollbar);

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

void ScrollArea::setWidget(QWidget* widget)
{
	QScrollArea::setWidget(widget);

	widget->setStyleSheet("background-color:transparent;");
}
