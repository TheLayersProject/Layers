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

#include <Layers/lattributemapmodel.h>

using Layers::LAttributeMapItem;
using Layers::LAttributeMapModel;

LAttributeMapModel::LAttributeMapModel(QObject* parent) :
	QAbstractItemModel(parent)
{
}

LAttributeMapModel::~LAttributeMapModel()
{
	delete m_root_item;
}

QVariant LAttributeMapModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	else if (role == Qt::DisplayRole)
		return get_item(index)->attribute()->objectName();

	else if (role == Qt::UserRole)
		return QVariant::fromValue(get_item(index)->attribute());

	return QVariant();
}

QModelIndex LAttributeMapModel::index(
	int row, int column, const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	LAttributeMapItem* parent_item = get_item(parent);
	if (!parent_item)
		return QModelIndex();

	LAttributeMapItem* child_item = parent_item->child(row);
	if (child_item)
		return createIndex(row, column, child_item);

	return QModelIndex();
}

QModelIndex LAttributeMapModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
		return QModelIndex();

	LAttributeMapItem* child_item = get_item(index);
	LAttributeMapItem* parent_item = child_item ?
		child_item->parent() : nullptr;

	if (parent_item == m_root_item || !parent_item)
		return QModelIndex();

	return createIndex(parent_item->index(), 0, parent_item);
}

int LAttributeMapModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() > 0)
		return 0;

	const LAttributeMapItem* parent_item = get_item(parent);

	return parent_item ?
		parent_item->child_count() : 0;
}

int LAttributeMapModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 1;
}

void LAttributeMapModel::init_root_item(
	LAttributeMap attributes, const QStringList& filter_paths)
{
	beginResetModel();

	delete m_root_item;

	m_root_item = new LAttributeMapItem(nullptr);

	for (LAttribute* attr : attributes)
		if (!filter_paths.contains(attr->path()))
			m_root_item->append_child(
				init_item(attr, filter_paths, m_root_item));

	endResetModel();
}

LAttributeMapItem* LAttributeMapModel::init_item(
	LAttribute* attribute, const QStringList& filter_paths,
	LAttributeMapItem* parent)
{
	LAttributeMapItem* item = new LAttributeMapItem(attribute, parent);

	for (LAttribute* override_attr : attribute->overrides())
		item->append_child(init_item(override_attr, filter_paths, item));

	return item;
}

LAttributeMapItem* LAttributeMapModel::get_item(const QModelIndex& index) const
{
	if (index.isValid())
		if (LAttributeMapItem* item =
			static_cast<LAttributeMapItem*>(index.internalPointer()))
		{
			return item;
		}

	if (m_root_item)
		return m_root_item;

	return nullptr;
}
