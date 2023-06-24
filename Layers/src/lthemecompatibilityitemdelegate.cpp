#include <Layers/lthemecompatibilityitemdelegate.h>

#include <QPainter>

using Layers::LSvgRenderer;
using Layers::LThemeCompatibilityItemDelegate;

LThemeCompatibilityItemDelegate::LThemeCompatibilityItemDelegate(QObject* parent) :
	LGridlineItemDelegate(parent)
{
	m_check_svg->set_name("Checkmark Svg");
}

void LThemeCompatibilityItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	LGridlineItemDelegate::paint(painter, option, index);

	if (index.column() == index.model()->columnCount() - 1)
	{
		if (index.data(Qt::DecorationRole).toBool())
		{
			int centered_x = option.rect.x() + (option.rect.width() / 2) - 10;
			int centered_y = option.rect.y() + (option.rect.height() / 2) - 10;

			m_check_svg->render(painter,
				QRectF(centered_x, centered_y, 20, 15));
		}
	}
}
