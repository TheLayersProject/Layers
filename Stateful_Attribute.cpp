#include "Layers.h"

using Layers::Stateful_Attribute;
using Layers::Themeable;

Stateful_Attribute::Stateful_Attribute() :
	m_state{ "" }, Attribute("")
{
}

Stateful_Attribute::Stateful_Attribute(const QString& name, QMap<QString, QVariant> state_value_map) :
	m_state{ state_value_map.firstKey() }, Attribute(name)
{
	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

bool Stateful_Attribute::contains_state(const QString& state) const
{
	return m_values.contains(state);
}

void Stateful_Attribute::set_state(const QString& state)
{
	if (m_values.contains(state)) m_state = state;
}

void Stateful_Attribute::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state)) m_values[state] = value;
	else qDebug() << "ERROR: Failed to set attribute value: State does not exist.";
}

void Stateful_Attribute::set_values(const QMap<QString, QVariant>& values)
{
	m_values = values;
}

QString Stateful_Attribute::state() const
{
	return m_state;
}

QList<QString> Stateful_Attribute::states() const
{
	return m_values.keys();
}

QVariant* Stateful_Attribute::value(const QString& state)
{
	if (m_values.contains(state)) return &m_values[state];
	else
	{
		qDebug() << "ERROR: Failed to find obtain attribute value: State does not exist.";

		return nullptr;
	}
}

QVariant& Stateful_Attribute::value()
{
	return m_values[m_state];
}

QMap<QString, QVariant>& Stateful_Attribute::values()
{
	return m_values;
}
