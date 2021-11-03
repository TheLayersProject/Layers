#include "../../../include/old.h"

using Layers::Stateless_Attribute_2_2_0_a;

Stateless_Attribute_2_2_0_a::Stateless_Attribute_2_2_0_a() : Attribute_2_2_0_a("")
{
}

Stateless_Attribute_2_2_0_a::Stateless_Attribute_2_2_0_a(const QString& name, QVariant value) :
	m_value{ value }, Attribute_2_2_0_a(name)
{
}

void Stateless_Attribute_2_2_0_a::set_value(QVariant value)
{
	m_value = value;
}

QVariant& Stateless_Attribute_2_2_0_a::value()
{
	return m_value;
}
