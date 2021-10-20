#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>
#include <QScrollBar>

#include "Widget.h"

namespace Layers
{
	class ScrollArea : public Widget
	{
		Q_OBJECT

	public:
		ScrollArea(QWidget* parent = nullptr);

		void issue_update();

		void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setWidget(QWidget* widget);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		QScrollArea* m_scroll_area{ new QScrollArea(this) };

		QScrollBar* m_horizontal_scrollbar{ new QScrollBar };
		QScrollBar* m_vertical_scrollbar{ new QScrollBar };
	};
}

#endif // SCROLLAREA_H
