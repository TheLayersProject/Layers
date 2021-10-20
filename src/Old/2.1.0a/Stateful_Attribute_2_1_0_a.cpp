#include "../../../include/old.h"

using Layers::Stateful_Attribute_2_1_0_a;

Stateful_Attribute_2_1_0_a::Stateful_Attribute_2_1_0_a() :
	m_state{ "" }, Attribute_2_1_0_a("")
{
}

Stateful_Attribute_2_1_0_a::Stateful_Attribute_2_1_0_a(const QString& name, QMap<QString, QVariant> state_value_map) :
	m_state{ state_value_map.firstKey() }, Attribute_2_1_0_a(name)
{
	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

QMap<QString, QVariant>& Stateful_Attribute_2_1_0_a::values()
{
	return m_values;
}
