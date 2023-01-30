#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>
//#include <QScrollBar>

#include "ScrollBar.h"
#include "Widget.h"

namespace Layers
{
	class ScrollArea : public Widget
	{
		Q_OBJECT

	public:
		ScrollArea(QWidget* parent = nullptr);

		ScrollBar* horizontal_scrollbar() const;

		void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setWidget(QWidget* widget);

		ScrollBar* vertical_scrollbar() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_child_themeable_list();

		QScrollArea* m_scroll_area{ new QScrollArea(this) };

		ScrollBar* m_horizontal_scrollbar{ new ScrollBar };
		ScrollBar* m_vertical_scrollbar{ new ScrollBar };
	};
}

#endif // SCROLLAREA_H
