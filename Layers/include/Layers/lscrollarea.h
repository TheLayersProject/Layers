#ifndef LSCROLLAREA_H
#define LSCROLLAREA_H

#include <QScrollArea>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LScrollArea : public QScrollArea, public LThemeable
{
	Q_OBJECT

public:
	LScrollArea(QWidget* parent = nullptr);

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	void setWidget(QWidget* widget);

private:
	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };
};
LAYERS_NAMESPACE_END

#endif // LSCROLLAREA_H
