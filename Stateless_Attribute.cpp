#include "Layers.h"

using Layers::Stateless_Attribute;

Stateless_Attribute::Stateless_Attribute() : Attribute("")
{
}

Stateless_Attribute::Stateless_Attribute(const QString& name, QVariant value) :
	m_value{ value }, Attribute(name)
{
}

void Stateless_Attribute::set_value(QVariant value)
{
	m_value = value;
}

QVariant& Stateless_Attribute::value()
{
	return m_value;
}
