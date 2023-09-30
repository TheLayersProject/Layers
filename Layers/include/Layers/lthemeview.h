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

#ifndef LTHEMEVIEW_H
#define LTHEMEVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lthemeable.h"
#include "lthememodel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeView :
	public QTreeView, public LThemeable
{
	Q_OBJECT

signals:
	void selected_theme_item_changed(LThemeItem* theme_item);

public:
	LThemeView(QWidget* parent = nullptr);

	~LThemeView();

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	virtual void update() override;

protected:
	virtual void selectionChanged(
		const QItemSelection& selected,
		const QItemSelection& deselected) override;

private:
	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };

	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };

	LThemeModel* m_model{ new LThemeModel };

	QMetaObject::Connection m_model_update_connection;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEVIEW_H  
