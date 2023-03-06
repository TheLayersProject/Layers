#include "../../include/ThemeCompatibilityItemDelegate.h"

#include <QPainter>

using Layers::SvgRenderer;
using Layers::ThemeCompatibilityItemDelegate;

ThemeCompatibilityItemDelegate::ThemeCompatibilityItemDelegate(QObject* parent) :
	ThemeableItemDelegate(parent)
{
	init_attributes();

	m_check_image.fill(qRgba(0, 0, 0, 0));

	QPainter check_image_painter(&m_check_image);
	m_check_svg->render(&check_image_painter);

	connect(&m_check_svg->a_common_color, &Entity::value_changed, [this] {
		QPainter check_image_painter(&m_check_image);
		m_check_svg->render(&check_image_painter);
		});

	m_check_svg->set_name("checkmark_svg");
	m_check_svg->set_proper_name("Checkmark SVG");
}

void ThemeCompatibilityItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	ThemeableItemDelegate::paint(painter, option, index);

	if (index.column() == index.model()->columnCount() - 1)
	{
		if (index.data(Qt::DecorationRole).toBool())
		{
			int centered_x = option.rect.x() + (option.rect.width() / 2) - 10;
			int centered_y = option.rect.y() + (option.rect.height() / 2) - 10;

			painter->drawImage(centered_x, centered_y, m_check_image);
		}
	}
}

SvgRenderer* ThemeCompatibilityItemDelegate::check_svg() const
{
	return m_check_svg;
}

void ThemeCompatibilityItemDelegate::init_attributes()
{
	m_check_svg->a_use_common_color.set_value(QVariant::fromValue(true));
}
