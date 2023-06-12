#ifndef LTHEMECOMPATIBILITYITEMDELEGATE_H
#define LTHEMECOMPATIBILITYITEMDELEGATE_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include <LayersCore/lsvgrenderer.h>

#include "lgridlineitemdelegate.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LThemeCompatibilityItemDelegate : public LGridlineItemDelegate
{
	Q_OBJECT

public:
	LThemeCompatibilityItemDelegate(QObject* parent = nullptr);

	void paint(
		QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

private:
	LSvgRenderer* m_check_svg{ new LSvgRenderer(":/images/check.svg", this) };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMPATIBILITYITEMDELEGATE_H  
