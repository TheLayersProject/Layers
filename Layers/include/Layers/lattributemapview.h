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

#ifndef LATTRIBUTEMAPVIEW_H
#define LATTRIBUTEMAPVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lthemeable.h"
#include "lattributemapmodel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LAttributeMapView :
	public QTreeView, public LThemeable
{
	Q_OBJECT

signals:
	void selected_map_item_changed(LAttribute* attr);

public:
	LAttributeMapView(QWidget* parent = nullptr);

	//~LAttributeMapView();

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	void set_attributes(
		LAttributeMap attributes, const QStringList& filter_paths);

	virtual void update() override;

protected:
	virtual void selectionChanged(
		const QItemSelection& selected,
		const QItemSelection& deselected) override;

private:
	LAttribute* m_fill{
		new LAttribute("Fill", "#ffffff", this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", "#000000", this) };

	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };

	LAttributeMapModel* m_model{ new LAttributeMapModel };

	//QMetaObject::Connection m_model_update_connection;
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPVIEW_H  
