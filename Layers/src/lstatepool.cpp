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

#include <Layers/lstatepool.h>

using Layers::LStatePool;

LStatePool::LStatePool(const QString& name, QObject* parent) :
	m_name{ name },
	QObject(parent)
{ }

LStatePool::LStatePool(const QString& name, QStringList states,
	QObject* parent) :
	m_name{ name },
	QObject(parent)
{
	for (const QString& state : states)
		if (!state.isEmpty())
			m_states.append(state);

	if (!m_states.isEmpty())
		m_state = m_states.first();
}

void LStatePool::add_state(const QString& state)
{
	if (!state.isEmpty())
	{
		m_states.append(state);

		if (m_state.isEmpty())
			m_state = state;
	}
}

void LStatePool::set_state(const QString& state)
{
	if (m_state != state && m_states.contains(state))
	{
		m_state = state;

		emit changed();
	}
}

QString LStatePool::state() const
{
	return m_state;
}
