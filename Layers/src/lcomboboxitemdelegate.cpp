/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Layers/lcomboboxitemdelegate.h>

#include <QPainter>

using Layers::LAttribute;
using Layers::LComboBoxItemDelegate;

LComboBoxItemDelegate::LComboBoxItemDelegate(QObject* parent) :
	QStyledItemDelegate(parent)
{
	add_state_pool(m_select_states);
	init_attributes();
	setObjectName("Items");
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
			cr_tl = m_corner_radius->as<double>();
			cr_tr = cr_tl;
		}
	}
	else
	{
		if (index.row() == index.model()->rowCount() - 1)
		{
			cr_bl = m_corner_radius->as<double>();
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

LAttribute* LComboBoxItemDelegate::corner_radius() const
{
	return m_corner_radius;
}

LAttribute* LComboBoxItemDelegate::fill() const
{
	return m_fill;
}

void LComboBoxItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QColor fill_color = (option.state & QStyle::State_HasFocus) ?
		QColor(QString::fromStdString(
			m_fill->as<std::string>({ "Selected" }))) :
		QColor(QString::fromStdString(m_fill->as<std::string>()));

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

	painter->fillPath(item_text_path,
		QColor(QString::fromStdString(m_text_color->as<std::string>())));
}

void LComboBoxItemDelegate::set_is_above_control(bool condition)
{
	m_is_above_control = condition;
}

LAttribute* LComboBoxItemDelegate::text_color() const
{
	return m_text_color;
}

void LComboBoxItemDelegate::init_attributes()
{
	m_fill->create_override("Selected", "#3c3d47");
}
