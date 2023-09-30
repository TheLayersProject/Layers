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

#include <Layers/lthemecomboboxitemmodel.h>

#include <Layers/lapplication.h>

using Layers::LTheme;
using Layers::LThemeComboBoxItemModel;

LThemeComboBoxItemModel::LThemeComboBoxItemModel(QObject* parent) :
	QAbstractListModel(parent) {}

void LThemeComboBoxItemModel::append(LTheme* theme)
{
	beginInsertRows({}, m_themes.count(), m_themes.count());
	m_themes.append(theme);
	endInsertRows();
}

void LThemeComboBoxItemModel::clear()
{
	if (!m_themes.isEmpty())
	{
		beginResetModel();
		m_themes.clear();
		endResetModel();
	}
}

QVariant LThemeComboBoxItemModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	else if (role == Qt::DisplayRole)
		return m_themes[index.row()]->name();

	else if (role == Qt::UserRole)
		return QVariant::fromValue(m_themes[index.row()]);
	
	return QVariant();
}

int LThemeComboBoxItemModel::rowCount(const QModelIndex& parent) const
{
	if (!parent.isValid())
		return m_themes.count();
	else
		return 0;
}
