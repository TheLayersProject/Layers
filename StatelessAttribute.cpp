#include "Layers.h"

using Layers::StatelessAttribute;

StatelessAttribute::StatelessAttribute() : Attribute("")
{
}

StatelessAttribute::StatelessAttribute(const QString& name, QVariant value) :
	m_value{ value }, Attribute(name)
{
}

void StatelessAttribute::set_value(QVariant value)
{
	m_value = value;
}

QVariant& StatelessAttribute::value()
{
	return m_value;
}
