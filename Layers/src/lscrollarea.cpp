#include <Layers/lscrollarea.h>

#include <QEvent>

using Layers::LScrollArea;
using Layers::LScrollBar;
using Layers::LThemeable;

LScrollArea::LScrollArea(QWidget* parent) : QScrollArea(parent)
{
	installEventFilter(this);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	setWidgetResizable(true);
	setStyleSheet(
		"QScrollArea { background-color:transparent; border:none; }");
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->setObjectName("Horizontal ScrollBar");

	m_vertical_scrollbar->setObjectName("Vertical ScrollBar");
}

QList<LThemeable*> LScrollArea::child_themeables(
	Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables =
		LThemeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	if (LThemeable* themeable_widget = dynamic_cast<LThemeable*>(widget()))
	{
		child_themeables.append(themeable_widget);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> widget_child_objects =
				widget()->findChildren<QObject*>(options);

			for (QObject* widget_child_object : widget_child_objects)
				if (LThemeable* child_themeable =
					dynamic_cast<LThemeable*>(widget_child_object))
				{
					child_themeables.append(child_themeable);
				}
		}
	}

	return child_themeables;
}

void LScrollArea::setWidget(QWidget* widget)
{
	QScrollArea::setWidget(widget);

	widget->setStyleSheet("background-color:transparent;");
}
