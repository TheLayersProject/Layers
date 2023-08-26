#include <Layers/lgridlineitemdelegate.h>

#include <QPainter>

using Layers::LAttribute;
using Layers::LGridlineItemDelegate;

LGridlineItemDelegate::LGridlineItemDelegate(QObject* parent) :
	QStyledItemDelegate(parent)
{
	setObjectName("Cells");
}

LAttribute* LGridlineItemDelegate::grid_fill() const
{
	return m_grid_fill;
}

LAttribute* LGridlineItemDelegate::grid_thickness() const
{
	return m_grid_thickness;
}

void LGridlineItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QStyledItemDelegate::paint(painter, option, index);

	QColor grid_fill = m_grid_fill->as<QColor>();

	int grid_thickness = m_grid_thickness->as<int>();

	if (index.row() < index.model()->rowCount() - 1)
	{
		QRect border_rect_bottom = QRect(
			option.rect.x(),
			option.rect.y() + option.rect.height() - grid_thickness,
			option.rect.width(),
			grid_thickness
		);
		painter->fillRect(border_rect_bottom, grid_fill);
	}

	if (index.column() < index.model()->columnCount() - 1)
	{
		QRect border_rect_right = QRect(
			option.rect.x() + option.rect.width() - grid_thickness,
			option.rect.y(),
			grid_thickness,
			option.rect.height()
		);
		painter->fillRect(border_rect_right, grid_fill);
	}
}
