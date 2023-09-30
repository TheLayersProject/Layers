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

#ifndef LATTRIBUTEMAPMODEL_H
#define LATTRIBUTEMAPMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributemapitem.h"

LAYERS_NAMESPACE_BEGIN
class LAttributeMapModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    LAttributeMapModel(QObject* parent = nullptr);

    ~LAttributeMapModel();

    QVariant data(const QModelIndex& index, int role) const override;

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    void init_root_item(
        LAttributeMap attributes, const QStringList& filter_paths);

private:
    LAttributeMapItem* init_item(
        LAttribute* attribute, const QStringList& filter_paths,
        LAttributeMapItem* parent = nullptr);

    LAttributeMapItem* get_item(const QModelIndex& index) const;

    LAttributeMapItem* m_root_item{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPMODEL_H
