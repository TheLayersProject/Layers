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

#ifndef LGROWINGDOTPROGRESSINDICATOR_H
#define LGROWINGDOTPROGRESSINDICATOR_H

#include <QTimer>
#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGrowingDotProgressIndicator :
	public QWidget, public LThemeable
{
	Q_OBJECT

signals:
	void timeout();

public:
	LGrowingDotProgressIndicator(QWidget* parent = nullptr);

	~LGrowingDotProgressIndicator();

	void start(int msec);

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	QTimer* m_progress_timer{ new QTimer };
	QTimer* m_update_timer{ new QTimer };

	QMetaObject::Connection m_progress_timer_timeout_connection;
	QMetaObject::Connection m_update_timer_timeout_connection;

	LAttribute* m_color{
		new LAttribute("Color", QColor(Qt::lightGray), this) };
};
LAYERS_NAMESPACE_END

#endif // LGROWINGDOTPROGRESSINDICATOR_H
