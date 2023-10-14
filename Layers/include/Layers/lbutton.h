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

#ifndef LBUTTON_H
#define LBUTTON_H

#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "llabel.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LButton : public LWidget
{
	Q_OBJECT

signals:
	void clicked();

public:
	LButton(const LGraphic& graphic, const QString& text,
		QWidget* parent = nullptr);

	LButton(const LGraphic& graphic, QWidget* parent = nullptr);

	LButton(const QString& text, QWidget* parent = nullptr);

	LButton(const LGraphic& graphic, const LGraphic& graphic_after,
		QWidget* parent = nullptr);

	bool disabled() const;

	LLabel* graphic_label() const;

	void set_disabled(bool cond = true);

	void set_font_size(int size);
	
	void set_font_size_f(qreal size);

	void set_padding(int padding);

	void set_padding(int left, int top, int right, int bottom);

	void toggle_graphics();

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();
	void init_layout();

	QHBoxLayout* main_layout{ new QHBoxLayout };

	QGraphicsOpacityEffect* m_button_opacity{ new QGraphicsOpacityEffect };

	bool m_disabled{ false };

	LLabel* m_graphic_label{ nullptr };
	LLabel* m_graphic_after_label{ nullptr };

	LLabel* m_text_label{ nullptr };

	LStatePool* m_select_states{
		new LStatePool("Select", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LBUTTON_H
