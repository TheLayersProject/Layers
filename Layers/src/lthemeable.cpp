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

#include <Layers/lthemeable.h>

#include <QWidget>

#include <Layers/lgraphic.h>

using Layers::LAttribute;
using Layers::LGraphic;
using Layers::LStatePool;
using Layers::LThemeItem;
using Layers::LThemeable;

void LThemeable::add_share_themeable(LThemeable* themeable)
{
	if (themeable)
	{
		if (m_current_theme_item)
			themeable->apply_theme_item(m_current_theme_item);

		m_share_themeables.append(themeable);
	}
}

void LThemeable::add_state_pool(LStatePool* state_pool, bool include_children)
{
	m_state_pools.append(state_pool);

	state_pool->connect(state_pool, &LStatePool::changed,
		[this] { update(); });

	if (include_children)
		for (LThemeable* child_themeable : child_themeables())
			child_themeable->add_state_pool(state_pool, include_children);
}

void LThemeable::apply_theme_item(LThemeItem* theme_item)
{
	if (theme_item)
	{
		if (_name() == theme_item->objectName())
		{
			m_current_theme_item = theme_item;

			if (!theme_item->attributes().isEmpty())
				for (LAttribute* attr : child_attributes())
					if (theme_item->attributes().contains(attr->objectName()))
						attr->set_theme_attribute(
							theme_item->attributes()[attr->objectName()]);

			if (!theme_item->children().isEmpty())
				for (LThemeable* child_t : child_themeables())
					if (theme_item->children().contains(child_t->_name()))
						child_t->apply_theme_item(
							theme_item->children()[child_t->_name()]);

			for (LThemeable* themeable : m_share_themeables)
				themeable->apply_theme_item(m_current_theme_item);
		}
	}
	else
	{
		m_current_theme_item = nullptr;

		for (LAttribute* attr : child_attributes())
			attr->clear_theme_attribute();

		for (LThemeable* child_t : child_themeables())
			child_t->apply_theme_item(nullptr);
	}
}

QList<LAttribute*> LThemeable::child_attributes(Qt::FindChildOptions options)
{
	QList<LAttribute*> child_attributes;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		child_attributes.append(
			object->findChildren<LAttribute*>(Qt::FindDirectChildrenOnly));

		if (options == Qt::FindChildrenRecursively)
		{
			for (LThemeable* child_themeable : child_themeables())
				child_attributes.append(
					child_themeable->child_attributes(options));
		}
	}

	return child_attributes;
}

QList<LThemeable*> LThemeable::child_themeables(Qt::FindChildOptions options)
{
	/*	IMPORTANT NOTE:
		This function only calls QObject::findChildren() with
		Qt::FindDirectChildrenOnly, even if *options* is
		Qt::FindChildrenRecursively. Recursion is handled after finding
		the direct children and calling child_themeables() on them.

		This is important because child_themeables() is a virtual function and
		calling QObject::findChildren() with Qt::FindChildrenRecursively will
		cause subsequent child_themeables() calls to be missed.
	*/

	QList<LThemeable*> child_themeables;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		QList<QObject*> child_objects =
			object->findChildren<QObject*>(Qt::FindDirectChildrenOnly);

		for (QObject* child_object : child_objects)
		{
			if (LThemeable* child_themeable =
				dynamic_cast<LThemeable*>(child_object))
			{
				child_themeables.append(child_themeable);

				if (options == Qt::FindChildrenRecursively)
					child_themeables.append(
						child_themeable->child_themeables(options));
			}
		}
	}

	return child_themeables;
}

LThemeItem* LThemeable::current_theme_item() const
{
	return m_current_theme_item;
}

QString LThemeable::path()
{
	QString path;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		if (LThemeable* parent_t = _parent_themeable())
			path = parent_t->path();
		else if (QWidget* widget = dynamic_cast<QWidget*>(this))
			if (widget->isWindow())
				path = "App";


		if (path.isEmpty())
			path.append(object->objectName());
		else
			path.append("/" + object->objectName());
	}

	return path;
}

QList<LStatePool*> LThemeable::state_pools() const
{
	return m_state_pools;
}

QStringList LThemeable::state_combo() const
{
	QStringList state_combo;

	for (LStatePool* state_pool : m_state_pools)
		state_combo.append(state_pool->state());

	return state_combo;
}

void LThemeable::update()
{
	if (QWidget* widget = dynamic_cast<QWidget*>(this))
		widget->update();
}

LThemeable* LThemeable::_parent_themeable()
{
	if (QObject* object = dynamic_cast<QObject*>(this))
		if (QObject* parent = object->parent())
			if (LThemeable* parent_themeable =
				dynamic_cast<LThemeable*>(parent))
			{
				return parent_themeable;
			}

	return nullptr;
}

QString LThemeable::_name()
{
	if (QObject* object = dynamic_cast<QObject*>(this))
		return object->objectName();

	return QString();
}
