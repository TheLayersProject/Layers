#ifndef LTHEMECOMPATIBILITYITEMDELEGATE_H
#define LTHEMECOMPATIBILITYITEMDELEGATE_H

#include "layerswidgetsexports.h"

#include <LayersCore/lsvgrenderer.h>

#include "lgridlineitemdelegate.h"

namespace Layers
{
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
}

#endif // LTHEMECOMPATIBILITYITEMDELEGATE_H  
