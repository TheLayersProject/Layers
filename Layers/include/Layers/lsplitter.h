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

#ifndef LSPLITTER_H
#define LSPLITTER_H

#include <QSplitter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LSplitter : public QSplitter, public LThemeable
{
	Q_OBJECT

public:
	LSplitter(QWidget* parent = nullptr);

	LSplitter(Qt::Orientation orientation, QWidget* parent = nullptr);

private:
	void init();
};
LAYERS_NAMESPACE_END

#endif // LSPLITTER_H
