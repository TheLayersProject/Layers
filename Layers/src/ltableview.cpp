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

#include <Layers/ltableview.h>

#include <QPainter>

#include <Layers/lheaderview.h>
#include <Layers/lgridlineitemdelegate.h>

using Layers::LGridlineItemDelegate;
using Layers::LSvgRenderer;
using Layers::LTableView;
using Layers::LThemeable;

LTableView::LTableView(QWidget* parent) : QTableView(parent)
{
	update();

	//setItemDelegate(new LGridlineItemDelegate);

	setHorizontalHeader(new LHeaderView(Qt::Horizontal));

	horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setMinimumHeight(40);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	setShowGrid(false);
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	verticalHeader()->setDefaultSectionSize(48);
	verticalHeader()->hide();
}

QList<LThemeable*> LTableView::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables =
		LThemeable::child_themeables(options);

	if (LThemeable* child_themeable_item_delegate =
		dynamic_cast<LThemeable*>(itemDelegate()))
	{
		child_themeables.append(child_themeable_item_delegate);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> delegate_child_objects =
				itemDelegate()->findChildren<QObject*>(options);

			for (QObject* delegate_child_object : delegate_child_objects)
				if (LThemeable* child_themeable =
					dynamic_cast<LThemeable*>(delegate_child_object))
				{
					child_themeables.append(child_themeable);
				}
		}
	}

	return child_themeables;
}

void LTableView::setItemDelegate(QAbstractItemDelegate* item_delegate)
{
	if (LGridlineItemDelegate* themeable_item_delegate =
		dynamic_cast<LGridlineItemDelegate*>(item_delegate))
	{
		connect(themeable_item_delegate, &LGridlineItemDelegate::changed,
			[this] { QWidget::update(); });
	}
	
	QTableView::setItemDelegate(item_delegate);
}

void LTableView::update()
{
	QString style_sheet =
		"QTableView {"
		"background: " +
			QString::fromStdString(m_fill->as<std::string>()) + ";"
		"border: " + QString::number(m_border_thickness->as<double>()) + "px "
			"solid " +
				QString::fromStdString(m_border_fill->as<std::string>()) + ";"
		"border-top-left-radius: " +
			QString::number(m_corner_radii_top_left->as<double>()) + "px;"
		"border-top-right-radius: " +
			QString::number(m_corner_radii_top_right->as<double>()) + "px;"
		"border-bottom-left-radius: " +
			QString::number(m_corner_radii_bottom_left->as<double>()) + "px;"
		"border-bottom-right-radius: " +
			QString::number(m_corner_radii_bottom_right->as<double>()) + "px;"
		"color: " +
			QString::fromStdString(m_text_color->as<std::string>()) + ";"
		"}"

		"QTableView::item {"
		"background: " +
			QString::fromStdString(m_item_fill->as<std::string>()) + ";"
		"}";

	setStyleSheet(style_sheet);

	QWidget::update();
}

void LTableView::update_height()
{
	int visible_row_count = model()->rowCount() < m_visible_row_limit ?
		model()->rowCount() : m_visible_row_limit;

	int new_height = m_border_thickness->as<double>() * 2;

	new_height += horizontalHeader()->height();

	for (auto i = visible_row_count; i--;)
		new_height += verticalHeader()->sectionSize(i);

	setMaximumHeight(new_height);
}
