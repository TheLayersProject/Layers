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

#ifndef LGRAPHIC_H
#define LGRAPHIC_H

#include <QImage>

#include "layers_global.h"
#include "layers_exports.h"

#include "limagesequence.h"
#include "lsvgrenderer.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGraphic
{
public:
	LGraphic(const QString& file_path, QSize size = QSize());

	LGraphic(const QImage& image);

	LGraphic(const LGraphic& graphic);

	~LGraphic();

	QImage* image() const;

	LImageSequence* image_sequence() const;

	QSize size() const;

	LSvgRenderer* svg_renderer() const;

private:
	QSize m_size;

	LImageSequence* m_image_sequence{ nullptr };

	QImage* m_image{ nullptr };

	LSvgRenderer* m_svg_renderer{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LGRAPHIC_H
