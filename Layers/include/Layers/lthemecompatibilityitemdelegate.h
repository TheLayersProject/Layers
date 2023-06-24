#ifndef LTHEMECOMPATIBILITYITEMDELEGATE_H
#define LTHEMECOMPATIBILITYITEMDELEGATE_H

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lsvgrenderer.h>

#include "lgridlineitemdelegate.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeCompatibilityItemDelegate : public LGridlineItemDelegate
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
