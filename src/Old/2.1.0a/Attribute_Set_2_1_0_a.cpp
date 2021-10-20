#include "../../../include/old.h"

using Layers::Attribute_Set_2_1_0_a;
using Layers::Stateless_Attribute_2_1_0_a;
using Layers::Stateful_Attribute_2_1_0_a;

void Attribute_Set_2_1_0_a::add_attribute(Stateless_Attribute_2_1_0_a attribute)
{
	m_stateless_attributes[attribute.name()] = attribute;
}

void Attribute_Set_2_1_0_a::add_attribute(Stateful_Attribute_2_1_0_a attribute)
{
	m_stateful_attributes[attribute.name()] = attribute;
}

bool Attribute_Set_2_1_0_a::contains(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return true;
	else if (m_stateful_attributes.contains(attribute_name)) return true;

	return false;
}

QMap<QString, Stateful_Attribute_2_1_0_a>& Attribute_Set_2_1_0_a::stateful_attributes()
{
	return m_stateful_attributes;
}

QMap<QString, Stateless_Attribute_2_1_0_a>& Attribute_Set_2_1_0_a::stateless_attributes()
{
	return m_stateless_attributes;
}
