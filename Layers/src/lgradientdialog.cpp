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

#include <Layers/lgradientdialog.h>

#include <QMouseEvent>

#include <Layers/lapplication.h>

using Layers::LColorControl;
using Layers::LGradientDialog;
using Layers::LThemeable;

LGradientDialog::LGradientDialog(
	QGradientStops gradient_stops, QWidget* parent) :
	m_gradient_editor{ new LGradientEditor(gradient_stops) },
	LDialog("Gradient", parent)
{
	init_layout();
	set_icon(LGraphic(":/images/gradient_icon.svg"));
	setObjectName("Gradient Dialog");
	resize(450, minimumSizeHint().height());

	m_apply_button->setObjectName("Apply Button");
	m_apply_button->set_font_size_f(10.5);
	m_apply_button->set_padding(6);
	m_apply_button->setFixedHeight(30);

	connect(m_apply_button, &LButton::clicked,
		[this] { done(QDialog::Accepted); });
}

QGradientStops LGradientDialog::gradient_stops() const
{
	return m_gradient_editor->gradient_stops();
}

void LGradientDialog::init_layout()
{
	QVBoxLayout* layout = new QVBoxLayout;
	layout->setContentsMargins(7, 20, 7, 7);
	layout->setSpacing(12);
	layout->addWidget(m_gradient_editor);
	layout->addWidget(m_apply_button);
	layout->setAlignment(m_apply_button, Qt::AlignRight);
	setLayout(layout);

	/*
		Activate layout since position information is needed during
		initialization.
	*/
	layout->activate();
}
