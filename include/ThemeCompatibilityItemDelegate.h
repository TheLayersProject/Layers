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

		void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const;

		SvgRenderer* check_svg() const;

	private:
		void init_attributes();

		SvgRenderer* m_check_svg{ new SvgRenderer(":/svgs/check.svg", this) };

		QImage m_check_image{ QImage(20, 15, QImage::Format_ARGB32) };
	};
}

#endif // THEMECOMPATIBILITYITEMDELEGATE_H  
