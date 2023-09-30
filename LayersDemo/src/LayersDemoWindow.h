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

#ifndef LAYERSDEMOWINDOW_H
#define LAYERSDEMOWINDOW_H

#include <Layers/lmainwindow.h>

class LayersDemoWindow : public Layers::LMainWindow
{
	Q_OBJECT

public:
	LayersDemoWindow(QWidget* parent = nullptr);

private:
};

#endif // LAYERSDEMOWINDOW_H
