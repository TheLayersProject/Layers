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

#ifndef LLABEL_H
#define LLABEL_H

#include <QLabel>
#include <QTimer>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lgraphic.h>
#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LLabel : public QLabel, public LThemeable
{
	Q_OBJECT

public:
	LLabel(QWidget* parent = nullptr);

	LLabel(const QString& text, QWidget* parent = nullptr);

	LLabel(const LGraphic& graphic, QWidget* parent = nullptr);

	~LLabel();

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	LAttribute* fill() const;

	LGraphic* graphic() const;

	void set_font_size(int size);

	void set_font_size_f(qreal size);

	virtual QSize sizeHint() const override;

	LAttribute* text_color() const;

	virtual void update() override;

protected:
	void paintEvent(QPaintEvent* event);

private:
	void init();
	void init_attributes();

	int m_frame{ 0 };

	LGraphic* m_graphic{ nullptr };

	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black)) };

	QMetaObject::Connection m_repaint_connection;

	QTimer m_timer;
};
LAYERS_NAMESPACE_END

#endif // LLABEL_H
