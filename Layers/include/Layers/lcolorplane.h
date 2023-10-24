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

#ifndef LCOLORPLANE_H
#define LCOLORPLANE_H

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lcalculate.h>
#include <Layers/lcolor.h>

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LColorPlane : public QWidget
{
	Q_OBJECT

signals:
	void z_dimension_changed();

public:
	LColorPlane(QWidget* parent = nullptr);

	LAttribute* color();

	void set_z_dimension(HSV z_dimension);

	void setFixedHeight(int h);

	void setFixedSize(const QSize& s);

	void setFixedSize(int w, int h);

	void setFixedWidth(int w);

	LAttribute* z_axis();

	HSV z_dimension() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void paintEvent(QPaintEvent* event) override;

private slots:
	void update_cursor_position();
	void update_z_axis();

private:
	void handle_mouse_event(QPoint& mouse_pos);

	void init_attributes();

	float pos_as_ratio(int pos, int available_space);

	void update_color(float x_pos_ratio, float y_pos_ratio);

	void update_height_dependencies();
	void update_width_dependencies();

	LAttribute* m_color
		{ new LAttribute("color", "#ff0000", this) };

	LAttribute* m_z_axis
		{ new LAttribute("z_axis", 0.0, this) };

	HSV m_z_dimension{ HSV::Hue };

	LWidget* m_cursor{ new LWidget(this) };

	int m_draw_height{ 245 };
	int m_draw_width{ 245 };

	const int margin{ 5 };

	bool m_dragging{ false };
};
LAYERS_NAMESPACE_END

#endif // LCOLORPLANE_H