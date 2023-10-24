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

#ifndef LGRADIENTDIALOG_H
#define LGRADIENTDIALOG_H

#include <QTimer>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lcolorcontrol.h"
#include "ldialog.h"
#include "lgradienteditor.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGradientDialog : public LDialog
{
	Q_OBJECT

public:
	LGradientDialog(std::vector<std::string> stops, QWidget* parent = nullptr);

	std::vector<std::string> stops() const;

private:
	void init_layout();

	LGradientEditor* m_gradient_editor;

	LButton* m_apply_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Apply") };
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTDIALOG_H
