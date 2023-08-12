#include <Layers/lcomboboxitemdelegate.h>

#include <QPainter>

using Layers::LComboBoxItemDelegate;

LComboBoxItemDelegate::LComboBoxItemDelegate(QObject* parent) :
	QStyledItemDelegate(parent)
{
	add_state_pool(m_select_states);
	init_attributes();
	set_name("Items");
}

QPainterPath LComboBoxItemDelegate::background_path(
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QPainterPath background_path;

	int x = option.rect.x();
	int y = option.rect.y();

	int w = option.rect.width();
	int h = option.rect.height();

	int cr_tl = 0;
	int cr_tr = 0;
	int cr_bl = 0;
	int cr_br = 0;

	if (m_is_above_control)
	{
		if (index.row() == 0)
			{
			cr_tl = m_corner_radius->as<int>();
			cr_tr = cr_tl;
		}
	}
	else
	{
		if (index.row() == index.model()->rowCount() - 1)
		{
			cr_bl = m_corner_radius->as<int>();
			cr_br = cr_bl;
		}
	}

	int double_cr_tl = cr_tl * 2;
	int double_cr_tr = cr_tr * 2;
	int double_cr_bl = cr_bl * 2;
	int double_cr_br = cr_br * 2;

	// Move to start point
	background_path.moveTo(x, y + cr_tl);

	// Arc Top-Left
	background_path.arcTo(
		QRect(
			x, y,
			double_cr_tl, double_cr_tl
		),
		180, -90);

	// Line Top
	background_path.lineTo(x + w - cr_tr, y);

	// Arc Top-Right
	background_path.arcTo(
		QRect(
			x + w - double_cr_tr, y,
			double_cr_tr, double_cr_tr
		),
		90, -90);

	// Line Right
	background_path.lineTo(x + w, y + h - cr_br);

	// Arc Bottom-Right
	background_path.arcTo(
		QRect(
			x + w - double_cr_br, y + h - double_cr_br,
			double_cr_br, double_cr_br
		),
		0, -90);

	// Line Bottom
	background_path.lineTo(x + cr_bl, y + h);

	// Arc Bottom-Left
	background_path.arcTo(
		QRect(
			x, y + h - double_cr_bl,
			double_cr_bl, double_cr_bl
		),
		-90, -90);

	// Line Left
	background_path.lineTo(x, y + cr_tl);

	return background_path;
}

void LComboBoxItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QColor fill_color = (option.state & QStyle::State_HasFocus) ?
		m_fill->as<QColor>({ "Selected" }) : m_fill->as<QColor>();

	const QFontMetrics& item_font_metrics = option.fontMetrics;

	QPainterPath item_text_path;

	painter->setRenderHint(QPainter::Antialiasing);

	// Draw background
	painter->fillPath(background_path(option, index), fill_color);

	item_text_path.addText(
		QPoint(10, option.rect.center().y() + (item_font_metrics.height() / 2) - 2),
		option.font,
		index.data().toString()
	);

	painter->fillPath(item_text_path, m_text_color->as<QColor>());
}

void LComboBoxItemDelegate::set_is_above_control(bool condition)
{
	m_is_above_control = condition;
}

void LComboBoxItemDelegate::init_attributes()
{
	m_fill->create_override("Selected", QColor(Qt::lightGray));
}
