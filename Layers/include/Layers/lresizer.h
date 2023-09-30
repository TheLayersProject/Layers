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

#ifndef LRESIZER_H
#define LRESIZER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
enum class LAYERS_EXPORT LSizeDimension { Width, Height };

class LAYERS_EXPORT LResizer : public QWidget, public LThemeable
{
	Q_OBJECT

public:
	LResizer(LSizeDimension resize_dimension, QWidget* parent = nullptr);

	void set_widget(QWidget* widget, int lower_limit, int upper_limit);

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	LSizeDimension m_resize_dimension;

	LSvgRenderer* m_icon_svg{ nullptr };

	QSize m_icon_size;

	LStatePool* m_select_states
		{ new LStatePool("Select", { "Selected", "Unselected" }) };

	QPoint m_click_pos;
	QSize m_click_size;

	QWidget* m_widget{ nullptr };

	int m_lower_limit{ 0 };
	int m_upper_limit{ 1000 };
};
LAYERS_NAMESPACE_END

#endif // LRESIZER_H
