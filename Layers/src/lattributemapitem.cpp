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

#include <Layers/lattributemapitem.h>

using Layers::LAttribute;
using Layers::LAttributeMapItem;

LAttributeMapItem::LAttributeMapItem(
	LAttribute* attribute, LAttributeMapItem* parent
) :
	m_attribute{ attribute },
	m_parent{ parent },
	QObject(parent)
{
}

void LAttributeMapItem::append_child(LAttributeMapItem* child)
{
	m_child_attr_items[child->m_attribute->objectName()] = child;
}

LAttribute* LAttributeMapItem::attribute() const
{
	return m_attribute;
}

LAttributeMapItem* LAttributeMapItem::child(int number)
{
	if (number < 0 || number >= m_child_attr_items.size())
		return nullptr;
	return m_child_attr_items[m_child_attr_items.keys().at(number)];
}

int LAttributeMapItem::child_count() const
{
	return m_child_attr_items.count();
}

QMap<QString, LAttributeMapItem*>& LAttributeMapItem::child_attribute_items()
{
	return m_child_attr_items;
}

LAttributeMapItem* LAttributeMapItem::parent()
{
	return m_parent;
}

int LAttributeMapItem::index() const
{
	if (m_parent)
	{
		QStringList keys = m_parent->m_child_attr_items.keys();

		for (int i = 0; i < keys.size(); i++)
		{
			LAttributeMapItem* parent_child_attr_item =
				m_parent->m_child_attr_items[keys.at(i)];

			if (parent_child_attr_item == this)
				return i;
		}
	}

	return 0;
}
