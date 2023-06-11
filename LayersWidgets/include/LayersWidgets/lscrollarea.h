#ifndef LSCROLLAREA_H
#define LSCROLLAREA_H

#include <QScrollArea>

#include "layerswidgetsexports.h"

#include "lscrollbar.h"
#include "lwidget.h"

namespace Layers
{
	/*!
		A LScrollArea is a QScrollArea and a LThemeable that provides a
		scrollable view for another widget.
	*/
	class LAYERS_WIDGETS_EXPORT LScrollArea : public QScrollArea, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a scroll area.
		*/
		LScrollArea(QWidget* parent = nullptr);

		/*!
			Returns a list of child themeables.

			This function overrides LThemeable::child_themeables() to include
			the scroll bars and the scroll area widget's child themeables.
		*/
		virtual QList<LThemeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Sets the scroll area's *widget*.
		*/
		void setWidget(QWidget* widget);

	private:
		LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
		LScrollBar* m_vertical_scrollbar{ new LScrollBar };
	};
}

#endif // LSCROLLAREA_H
