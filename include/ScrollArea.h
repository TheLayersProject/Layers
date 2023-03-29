#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>

#include "ScrollBar.h"
#include "Widget.h"

namespace Layers
{
	class ScrollArea : public Widget
	{
		Q_OBJECT

	public:
		ScrollArea(QWidget* parent = nullptr);
		//~ScrollArea();

		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

		ScrollBar* horizontal_scrollbar() const;

		void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setWidget(QWidget* widget);

		QWidget* takeWidget() const;

		ScrollBar* vertical_scrollbar() const;

		QWidget* widget() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		QScrollArea* m_scroll_area{ new QScrollArea(this) };

		ScrollBar* m_control_horizontal_scrollbar{ new ScrollBar(this) };
		ScrollBar* m_control_vertical_scrollbar{ new ScrollBar(this) };

		ScrollBar* m_horizontal_scrollbar{ new ScrollBar };
		ScrollBar* m_vertical_scrollbar{ new ScrollBar };
	};
}

#endif // SCROLLAREA_H
