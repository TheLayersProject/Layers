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

#ifndef LTABBAR_H
#define LTABBAR_H

#include <QHBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltab.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LTabBar : public LWidget
{
	Q_OBJECT

signals:
	void index_changed(int old_index, int new_index);

	void tab_closed(int index);

public:
	LTabBar(QWidget* parent = nullptr);

	void add_tab(const LGraphic& icon, const QString& text);

	void add_tab(const QString& text);

	int current_index() const;

	void set_current_index(int index);

	QList<LTab*> tabs() const;

private:
	void _add_tab(LTab* tab);

	void init_layout();

	int m_current_index{ -1 };

	QList<LTab*> m_tabs;

	QHBoxLayout* m_tab_layout{ new QHBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LTABBAR_H
