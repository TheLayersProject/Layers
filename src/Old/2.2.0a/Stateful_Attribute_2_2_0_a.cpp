#include "../../../include/old.h"

using Layers::Stateful_Attribute_2_2_0_a;
using Layers::Themeable;

Stateful_Attribute_2_2_0_a::Stateful_Attribute_2_2_0_a() :
	m_state{ "" }, Attribute_2_2_0_a("")
{
}

Stateful_Attribute_2_2_0_a::Stateful_Attribute_2_2_0_a(const QString& name, QMap<QString, QVariant> state_value_map) :
	m_state{ state_value_map.firstKey() }, Attribute_2_2_0_a(name)
{
	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

bool Stateful_Attribute_2_2_0_a::contains_state(const QString& state) const
{
	return m_values.contains(state);
}

void Stateful_Attribute_2_2_0_a::set_state(const QString& state)
{
	if (m_values.contains(state)) m_state = state;
}

void Stateful_Attribute_2_2_0_a::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state)) m_values[state] = value;
	else qDebug() << "ERROR: Failed to set attribute value: State does not exist.";
}

void Stateful_Attribute_2_2_0_a::set_values(const QMap<QString, QVariant>& values)
{
	m_values = values;
}

QString Stateful_Attribute_2_2_0_a::state() const
{
	return m_state;
}

QList<QString> Stateful_Attribute_2_2_0_a::states() const
{
	return m_values.keys();
}

QVariant* Stateful_Attribute_2_2_0_a::value(const QString& state)
{
	if (m_values.contains(state)) return &m_values[state];
	else
	{
		qDebug() << "ERROR: Failed to find obtain attribute value: State does not exist.";

		return nullptr;
	}
}

QVariant& Stateful_Attribute_2_2_0_a::value()
{
	return m_values[m_state];
}

QMap<QString, QVariant>& Stateful_Attribute_2_2_0_a::values()
{
	return m_values;
}
