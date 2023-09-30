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

#ifndef LSTATEPOOL_H
#define LSTATEPOOL_H

#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LStatePool : public QObject
{
	Q_OBJECT

signals:
	void changed();

public:
	LStatePool(const QString& name, QObject* parent = nullptr);

	LStatePool(const QString& name, QStringList states,
		QObject* parent = nullptr);

	void add_state(const QString& state);

	void set_state(const QString& state);

	/*!
		Returns the active pool state.
	*/
	QString state() const;

private:
	QString m_name;

	QString m_state;

	QStringList m_states;
};
LAYERS_NAMESPACE_END

#endif // LSTATEPOOL_H
