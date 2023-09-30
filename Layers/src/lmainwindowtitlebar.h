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

#ifndef LMAINWINDOWTITLEBAR_H
#define LMAINWINDOWTITLEBAR_H

#include <Layers/layers_global.h>

#include <Layers/ltabbar.h>

LAYERS_NAMESPACE_BEGIN
class LMainWindowTitlebar : public LWidget
{
	Q_OBJECT

public:
	LMainWindowTitlebar(QWidget* parent = nullptr);

	LTabBar* menu_tab_bar() const;

	LButton* settings_button() const;
	LButton* minimize_button() const;
	LButton* maximize_button() const;
	LButton* exit_button() const;

protected:
	void init_layout();

private:
	QHBoxLayout* main_layout = new QHBoxLayout;

	LButton* m_settings_button{
		new LButton(LGraphic(":/images/settings.svg", QSize(20, 20))) };

	LButton* m_minimize_button{
		new LButton(LGraphic(":/images/minimize.svg", QSize(20, 20))) };

	LButton* m_maximize_button{
		new LButton(LGraphic(":/images/maximize.svg", QSize(20, 20))) };

	LButton* m_exit_button{
		new LButton(LGraphic(":/images/exit.svg", QSize(20, 20))) };

	LTabBar* m_menu_tab_bar{ new LTabBar };
};
LAYERS_NAMESPACE_END

#endif // LMAINWINDOWTITLEBAR_H
