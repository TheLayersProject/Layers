#include "../../Layers.h"

using Layers::Stateless_Attribute_2_1_0_a;

Stateless_Attribute_2_1_0_a::Stateless_Attribute_2_1_0_a() : Attribute_2_1_0_a("")
{
}

Stateless_Attribute_2_1_0_a::Stateless_Attribute_2_1_0_a(const QString& name, QVariant value) :
	m_value{ value }, Attribute_2_1_0_a(name)
{
}

QVariant& Stateless_Attribute_2_1_0_a::value()
{
	return m_value;
}
