#ifndef THEMECOMPATIBILITYITEMDELEGATE_H
#define THEMECOMPATIBILITYITEMDELEGATE_H

#include "GridlineItemDelegate.h"
#include "SvgRenderer.h"

namespace Layers
{
	class ThemeCompatibilityItemDelegate : public GridlineItemDelegate
	{
		Q_OBJECT

	public:
		ThemeCompatibilityItemDelegate(QObject* parent = nullptr);

		void paint(
			QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const;

	private:
		SvgRenderer* m_check_svg{ new SvgRenderer(":/svgs/check.svg", this) };
	};
}

#endif // THEMECOMPATIBILITYITEMDELEGATE_H  
