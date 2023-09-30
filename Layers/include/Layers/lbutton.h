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
/*!
	An LButton is a LWidget that provides the user with a way to interact with
	the software to perform certain actions. Users interact with buttons by
	clicking them.
*/
class LAYERS_EXPORT LButton : public LWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the user clicks on the button.
	*/
	void clicked();

public:
	/*!
		Constructs a button with a graphic and text.
	*/
	LButton(const LGraphic& graphic, const QString& text,
		QWidget* parent = nullptr);

	/*!
		Constructs a button with a graphic.

		By default, the fill is disabled.
	*/
	LButton(const LGraphic& graphic, QWidget* parent = nullptr);

	/*!
		Constructs a button with text.
	*/
	LButton(const QString& text, QWidget* parent = nullptr);

	/*!
		Constructs a button with two graphics. The graphic that is displayed
		depends on whether the button is set to an enabled state or not.

		By default, the fill is disabled.
	*/
	LButton(const LGraphic& graphic, const LGraphic& graphic_after,
		QWidget* parent = nullptr);

	/*!
		Returns true if the button is disabled. Otherwise, returns false.
	*/
	bool disabled() const;

	/*!
		Returns a pointer to the button's graphic. If the button does not have
		a graphic, then nullptr is returned.
	*/
	LLabel* graphic_label() const;

	/*!
		Disables or enables the button depending on *cond*.
	*/
	void set_disabled(bool cond = true);

	/*!
		Sets the font size of the button's text.
	*/
	void set_font_size(int size);
	
	/*!
		Sets the font size of the button's text.
	*/
	void set_font_size_f(qreal size);

	/*!
		Sets the button padding with a single value.
	*/
	void set_padding(int padding);

	/*!
		Sets the button padding with individual values.
	*/
	void set_padding(int left, int top, int right, int bottom);

	/*!
		Toggles the visibility of the graphics.

		This function only works if the button was constructed with two
		graphics.
	*/
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
