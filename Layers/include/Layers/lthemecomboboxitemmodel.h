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

#ifndef LTHEMECOMBOBOXITEMMODEL_H
#define LTHEMECOMBOBOXITEMMODEL_H

#include <QAbstractListModel>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltheme.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeComboBoxItemModel : public QAbstractListModel
{
	Q_OBJECT

public:
	LThemeComboBoxItemModel(QObject* parent = nullptr);

	void append(LTheme* theme);

	void clear();

	virtual QVariant data(const QModelIndex& index, int role) const override;

	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

private:
	QList<LTheme*> m_themes{ QList<LTheme*>() };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMMODEL_H  
