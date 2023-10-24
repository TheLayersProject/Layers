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

#ifndef LSLIDER_H
#define LSLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LSlider : public LWidget
{
	Q_OBJECT

public:
	LSlider(QWidget* parent = nullptr);

	LSlider(int limit, QWidget* parent = nullptr);

	void set_limit(int limit);

	LAttribute* value();

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();

	void init_attributes();

	void init_layout();

	void update_handle_pos();

	LAttribute* m_value
		{ new LAttribute("value", 0.0, this) };

	LWidget* m_bar{ new LWidget };
	LWidget* m_handle{ new LWidget(this) };

	int m_limit{ 99 };
	double m_value_on_click{ 0.0 };

	bool m_dragging_handle{ false };

	bool m_is_decimal_slider;

	QPoint m_mouse_click_position{ QPoint() };
};
LAYERS_NAMESPACE_END

#endif // LSLIDER_H
