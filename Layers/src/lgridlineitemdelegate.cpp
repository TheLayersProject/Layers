#include <Layers/lgridlineitemdelegate.h>

#include <QPainter>

using Layers::LBorderAttributes;
using Layers::LGridlineItemDelegate;

LGridlineItemDelegate::LGridlineItemDelegate(QObject* parent) :
	QStyledItemDelegate(parent)
{
	init_attributes();

	set_name("Cells");
}

LBorderAttributes* LGridlineItemDelegate::grid() const
{
	return m_grid;
}

void LGridlineItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QStyledItemDelegate::paint(painter, option, index);

	QColor grid_fill = m_grid->fill()->as<QColor>();

	int grid_thickness = m_grid->thickness()->as<int>();

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

void LGridlineItemDelegate::init_attributes()
{
	m_attr_data.attr_groups.insert({
		{ "grid", m_grid }
		});

	connect(m_grid->fill(), &LAttribute::changed, [this] { emit changed(); });
	connect(m_grid->thickness(), &LAttribute::changed, [this] { emit changed(); });

	m_grid->fill()->set_value(QColor("#808080"));
	m_grid->thickness()->set_value(3.0);
}
