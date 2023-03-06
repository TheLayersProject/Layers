#ifndef TABLE_H
#define TABLE_H

#include "ThemeableItemDelegate.h"
#include "SvgRenderer.h"
//#include "Themeable.h"

namespace Layers
{
	class ThemeCompatibilityItemDelegate : public ThemeableItemDelegate
	{
		Q_OBJECT

	public:
		ThemeCompatibilityItemDelegate(QObject* parent = nullptr);

		void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const;

		using ThemeableItemDelegate::sizeHint;
		using ThemeableItemDelegate::createEditor;
		using ThemeableItemDelegate::setEditorData;
		using ThemeableItemDelegate::setModelData;
		using ThemeableItemDelegate::updateEditorGeometry;

		SvgRenderer* check_svg() const;

	private:
		void init_attributes();

		SvgRenderer* m_check_svg{ new SvgRenderer(":/svgs/check.svg", this) };

		QImage m_check_image{ QImage(20, 15, QImage::Format_ARGB32) };
	};
}

#endif // THEMECOMPATIBILITYITEMDELEGATE_H  
