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

#ifndef LCOLORCONTROL_H
#define LCOLORCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LColorControl : public LWidget
{
	Q_OBJECT

signals:
	void color_changed();

public:
	LColorControl(QWidget* parent = nullptr);

	~LColorControl();

	void click();

	void disable_clicking(bool cond = true);

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	bool clicking_disabled{ false };
	bool open_on_release{ false };

	QMetaObject::Connection attribute_connection;

	QStringList m_attribute_states;
};
LAYERS_NAMESPACE_END

#endif // LCOLORCONTROL_H
