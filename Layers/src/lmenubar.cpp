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

#include <Layers/lmenubar.h>

#include <QStyleOptionMenuItem>

using Layers::LAttribute;
using Layers::LMenuBar;

LMenuBar::LMenuBar(QWidget* parent) : QMenuBar(parent)
{
	update();

	QFont f = font();
	f.setPointSize(12);
	setFont(f);
}

LAttribute* LMenuBar::selected_text_color() const
{
	return m_selected_text_color;
}

LAttribute* LMenuBar::text_color() const
{
	return m_text_color;
}

void LMenuBar::update()
{
	setStyleSheet(build_stylesheet());
}

QString LMenuBar::build_stylesheet()
{
	return
		"QMenuBar {"
		"background: transparent;"
		"color: " +
			QString::fromStdString(m_text_color->as<std::string>()) + ";"
		"}"

		"QMenuBar::item {"
		"spacing: 3px;"
		"padding: 1px 4px;"
		"background: transparent;"
		"color: " +
			QString::fromStdString(m_text_color->as<std::string>()) + ";"
		"}"

		"QMenuBar::item:selected {"
		"background: transparent;"
		"color: " +
			QString::fromStdString(
				m_selected_text_color->as<std::string>()) + ";"
		"}"

		"QMenuBar::item:pressed {"
		"background: transparent;"
		"}";
}
