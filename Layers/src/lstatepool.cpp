#include <Layers/lstatepool.h>

using Layers::LStatePool;

LStatePool::LStatePool(const QString& name) :
	m_name{ name }
{ }

LStatePool::LStatePool(const QString& name, QStringList states) :
	m_name{ name }
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
	if (m_states.contains(state) && m_state != state)
	{
		m_state = state;

		emit changed();
	}
}

QString LStatePool::state() const
{
	return m_state;
}
