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

#include "lmainwindowtitlebar.h"

using Layers::LButton;
using Layers::LTab;
using Layers::LTabBar;
using Layers::LMainWindowTitlebar;

LMainWindowTitlebar::LMainWindowTitlebar(QWidget* parent) :
	LWidget(parent)
{
	setFixedHeight(40);

	setObjectName("Titlebar");

	m_menu_tab_bar->setObjectName("Menu Tab Bar");

	m_settings_button->setObjectName("Settings Button");

	m_minimize_button->setObjectName("Minimize Button");

	m_maximize_button->setObjectName("Maximize Button");

	m_exit_button->setObjectName("Exit Button");

	init_layout();
}

LTabBar* LMainWindowTitlebar::menu_tab_bar() const
{
	return m_menu_tab_bar;
}

LButton* LMainWindowTitlebar::settings_button() const
{
	return m_settings_button;
}

LButton* LMainWindowTitlebar::minimize_button() const
{
	return m_minimize_button;
}

LButton* LMainWindowTitlebar::maximize_button() const
{
	return m_maximize_button;
}

LButton* LMainWindowTitlebar::exit_button() const
{
	return m_exit_button;
}

void LMainWindowTitlebar::init_layout()
{
	// Main Layout
	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_menu_tab_bar);
	main_layout->addStretch();
	main_layout->addWidget(m_settings_button);
	main_layout->addWidget(m_minimize_button);
	main_layout->addWidget(m_maximize_button);
	main_layout->addWidget(m_exit_button);

	setLayout(main_layout);
}
