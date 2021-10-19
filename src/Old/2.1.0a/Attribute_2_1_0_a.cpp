#include "../../Layers.h"

using Layers::Attribute_2_1_0_a;

Attribute_2_1_0_a::Attribute_2_1_0_a(const QString& name) :
	m_name{ name }
{
}

QString& Attribute_2_1_0_a::name()
{
	return m_name;
}
