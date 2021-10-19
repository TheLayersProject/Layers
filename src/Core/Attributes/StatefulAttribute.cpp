#include "../../Layers.h"

using Layers::StatefulAttribute;
using Layers::Themeable;

StatefulAttribute::StatefulAttribute() :
	m_state{ "" }, Attribute("")
{
}

StatefulAttribute::StatefulAttribute(const QString& name, QMap<QString, QVariant> state_value_map) :
	m_state{ state_value_map.firstKey() }, Attribute(name)
{
	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

bool StatefulAttribute::contains_state(const QString& state) const
{
	return m_values.contains(state);
}

void StatefulAttribute::set_state(const QString& state)
{
	if (m_values.contains(state)) m_state = state;
}

void StatefulAttribute::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state)) m_values[state] = value;
	else qDebug() << "ERROR: Failed to set attribute value: State does not exist.";
}

void StatefulAttribute::set_values(const QMap<QString, QVariant>& values)
{
	m_values = values;
}

QString StatefulAttribute::state() const
{
	return m_state;
}

QList<QString> StatefulAttribute::states() const
{
	return m_values.keys();
}

QVariant* StatefulAttribute::value(const QString& state)
{
	if (m_values.contains(state)) return &m_values[state];
	else
	{
		qDebug() << "ERROR: Failed to find obtain attribute value: State does not exist.";

		return nullptr;
	}
}

QVariant& StatefulAttribute::value()
{
	return m_values[m_state];
}

QMap<QString, QVariant>& StatefulAttribute::values()
{
	return m_values;
}
