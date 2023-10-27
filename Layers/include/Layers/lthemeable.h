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

#ifndef LTHEMEABLE_H
#define LTHEMEABLE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lobject.h"
#include "lstatepool.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LGraphic;

class LAYERS_EXPORT LThemeable : public LObject
{
public:
	void add_share_themeable(LThemeable* themeable);

	void add_state_pool(LStatePool* state_pool, bool include_children = true);

	virtual void apply_theme_item(LThemeItem* theme_item);

	QList<LAttribute*> child_attributes(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	LThemeItem* current_theme_item() const;

	QString path();

	QList<LStatePool*> state_pools() const;

	std::vector<std::string> state_combo() const;

	virtual void update();

private:
	LThemeable* _parent_themeable();

	QString _name();

	LThemeItem* m_current_theme_item{ nullptr };

	QList<LThemeable*> m_share_themeables;

	QList<LStatePool*> m_state_pools;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLE_H
