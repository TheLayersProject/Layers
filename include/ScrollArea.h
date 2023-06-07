#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>

#include "ScrollBar.h"
#include "Widget.h"

namespace Layers
{
	/*!
		A ScrollArea is a QScrollArea and a Themeable that provides a
		scrollable view for another widget.
	*/
	class ScrollArea : public QScrollArea, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a scroll area.
		*/
		ScrollArea(QWidget* parent = nullptr);

		/*!
			Returns a list of child themeables.

			This function overrides Themeable::child_themeables() to include
			the scroll bars and the scroll area widget's child themeables.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Sets the scroll area's *widget*.
		*/
		void setWidget(QWidget* widget);

	private:
		ScrollBar* m_horizontal_scrollbar{ new ScrollBar };
		ScrollBar* m_vertical_scrollbar{ new ScrollBar };
	};
}

#endif // SCROLLAREA_H
