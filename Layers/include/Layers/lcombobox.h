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

#ifndef LCOMBOBOX_H
#define LCOMBOBOX_H

#include <QComboBox>
#include <QPainterPath>

#include "layers_global.h"
#include "layers_exports.h"

#include "lpaint.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LComboBox : public QComboBox, public LThemeable
{
	Q_OBJECT

public:
	LComboBox(QWidget* parent = nullptr);

	LAttribute* border_fill() const;

	LAttribute* border_thickness() const;

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	LAttribute* corner_radius() const;

	LAttribute* fill() const;

	void setFixedHeight(int h);

	void setFixedSize(const QSize& s);

	void setFixedSize(int w, int h);

	void setFixedWidth(int w);

	virtual void showPopup() override;

	LAttribute* text_color() const;

	virtual void update() override;

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	bool is_view_positioned_above() const;

	void paint_box(QPainter* painter);

	virtual void paintEvent(QPaintEvent* event) override;

	LAttribute* m_border_fill
		{ new LAttribute("Border.Fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness
		{ new LAttribute("Border.Thickness", 0.0, this) };

	LAttribute* m_corner_radius
		{ new LAttribute("Corner Radius", 4.0, this) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor("#31323b"), this)};

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor("#e1e1e1"), this) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOX_H
