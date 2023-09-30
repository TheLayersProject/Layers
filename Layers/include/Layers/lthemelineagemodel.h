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

#ifndef LTHEMELINEAGEMODEL_H
#define LTHEMELINEAGEMODEL_H

#include <QAbstractTableModel>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltheme.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeLineageModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	LThemeLineageModel(QObject* parent = nullptr);

	void append(const LThemeLineageData& lineage_data);

	void clear();

	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual QVariant data(
		const QModelIndex& index, int role) const override;

	virtual QVariant headerData(
		int section, Qt::Orientation orientation, int role) const override;

	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

private:
	QList<LThemeLineageData> m_lineage_data{ QList<LThemeLineageData>() };
};
LAYERS_NAMESPACE_END

#endif // LTHEMELINEAGEMODEL_H  
