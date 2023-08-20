#ifndef LSCROLLAREA_H
#define LSCROLLAREA_H

#include <QScrollArea>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LScrollArea is a QScrollArea and an LThemeable that provides a
	scrollable viewing area for another widget.

	LScrollBar is the default scroll-bar type used by %LScrollArea.
*/
class LAYERS_EXPORT LScrollArea : public QScrollArea, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a scroll area.
	*/
	LScrollArea(QWidget* parent = nullptr);

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		scroll bars and the scroll area widget's child themeables.
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
LAYERS_NAMESPACE_END

#endif // LSCROLLAREA_H
