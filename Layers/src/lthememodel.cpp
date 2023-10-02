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

#include <Layers/lthememodel.h>

using Layers::LThemeItem;
using Layers::LThemeModel;

LThemeModel::LThemeModel(QObject* parent) :
	QAbstractItemModel(parent)
{
}

int LThemeModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 1;
}

QVariant LThemeModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	else if (role == Qt::DisplayRole)
		return get_item(index)->objectName();

	else if (role == Qt::UserRole)
		return QVariant::fromValue(get_item(index));

	return QVariant();
}

QModelIndex LThemeModel::index(
	int row, int column, const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	LThemeItem* parent_item = get_item(parent);
	if (!parent_item)
		return QModelIndex();

	LThemeItem* child_item = parent_item->child(row);
	if (child_item)
		return createIndex(row, column, child_item);

	return QModelIndex();
}

QModelIndex LThemeModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
		return QModelIndex();

	LThemeItem* child_item = get_item(index);
	LThemeItem* parent_item =
		child_item ? dynamic_cast<LThemeItem*>(child_item->parent()) : nullptr;

	if (parent_item == m_theme->root_item() || !parent_item)
		return QModelIndex();

	return createIndex(parent_item->index(), 0, parent_item);
}

int LThemeModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() > 0)
		return 0;

	const LThemeItem* parent_item = get_item(parent);

	return parent_item ?
		parent_item->child_count() : 0;
}

void LThemeModel::set_theme(LTheme* theme)
{
	beginResetModel();
	m_theme = theme;
	endResetModel();
}

LThemeItem* LThemeModel::get_item(const QModelIndex& index) const
{
	if (index.isValid())
		if (LThemeItem* item =
			static_cast<LThemeItem*>(index.internalPointer()))
		{
			return item;
		}

	if (m_theme)
		return m_theme->root_item();

	return nullptr;
}
