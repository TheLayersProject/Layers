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

#ifndef LATTRIBUTEMAPITEM_H
#define LATTRIBUTEMAPITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
class LAttributeMapItem : public QObject
{
    Q_OBJECT

public:
    LAttributeMapItem(LAttribute* attribute,
        LAttributeMapItem* parent = nullptr);

    void append_child(LAttributeMapItem* child);

    LAttribute* attribute() const;

    LAttributeMapItem* child(int number);

    int child_count() const;

    QMap<QString, LAttributeMapItem*>& child_attribute_items();

    LAttributeMapItem* parent();

    int index() const;

private:
    QMap<QString, LAttributeMapItem*> m_child_attr_items;
    LAttributeMapItem* m_parent{ nullptr };
    LAttribute* m_attribute{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPITEM_H
