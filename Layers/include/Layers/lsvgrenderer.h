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

#ifndef LSVGRENDERER_H
#define LSVGRENDERER_H

#include <QColor>
#include <QSvgRenderer>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LSvgRenderer : public QSvgRenderer, public LThemeable
{
	Q_OBJECT

public:
	LSvgRenderer(const QString& file_path, QObject* parent = nullptr);

	LSvgRenderer(const LSvgRenderer& svg_renderer);

	~LSvgRenderer();

	LAttribute* color() const;

private:
	void init_svg_elements_list();

	void rebuild_svg_str();

	void update();

	LAttribute* m_color
		{ new LAttribute("Color", QColor(Qt::black), this) };

	QStringList m_svg_elements;

	QString m_svg_str;
};
LAYERS_NAMESPACE_END

#endif // LSVGRENDERER_H
