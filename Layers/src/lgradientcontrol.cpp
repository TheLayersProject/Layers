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

#include <Layers/lgradientcontrol.h>

#include <QMouseEvent>

#include <Layers/lapplication.h>
#include <Layers/lgradientdialog.h>

using Layers::LGradientControl;

LGradientControl::LGradientControl(QWidget* parent) : LWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
}

LGradientControl::~LGradientControl()
{
	delete m_fill;
}

bool LGradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress ||
		event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			LGradientDialog gradient_dialog(m_fill->as<std::vector<std::string>>());
			gradient_dialog.apply_theme_item(
				activeTheme()->find_item(gradient_dialog.path().toStdString()));

			center(&gradient_dialog, window());

			if (gradient_dialog.exec())
			{
				fill()->set_value(gradient_dialog.stops());

				emit gradient_changed();
			}
		}
	}

	return false;
}

void LGradientControl::init_attributes()
{
	// Remove control attribute
	m_fill->set_parent(nullptr);

	m_border_fill->set_value("#D6D6D6");
	m_border_thickness->set_value(2.0);
	m_corner_radii_top_left->set_value(5.0);
	m_corner_radii_top_right->set_value(5.0);
	m_corner_radii_bottom_left->set_value(5.0);
	m_corner_radii_bottom_right->set_value(5.0);
	m_margins_left->set_value(8.0);
	m_margins_top->set_value(8.0);
	m_margins_right->set_value(8.0);
	m_margins_bottom->set_value(8.0);

	m_fill->set_value(std::vector<std::string>({ "0:#ffffff", "1:#000000" }));
}
