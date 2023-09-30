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

#ifndef LGRADIENTEDITOR
#define LGRADIENTEDITOR

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lcolorcontrol.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LGradientEditorItem;

class LAYERS_EXPORT LGradientEditor : public LWidget
{
	Q_OBJECT

public:
	LGradientEditor(QGradientStops gradient_stops, QWidget* parent = nullptr);

	~LGradientEditor();

	QGradientStops gradient_stops() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	LGradientEditorItem* create_item(const QGradientStop& stop);

	void init_attributes(const QGradientStops& gradient_stops);
	void init_items(const QGradientStops& gradient_stops);
	void init_add_stop_buttons();

	void update_gradient();
	void update_indexes();
	void update_positions();

	QList<LGradientEditorItem*> m_items;
	QList<LButton*> m_add_stop_buttons;

	LGradientEditorItem* m_drag_item{ nullptr };
	LGradientEditorItem* m_replace_item{ nullptr };

	int m_drag_ctrl_initial_x{ 0 };
	QPoint m_click_pos;
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTEDITOR
