#include "../../../include/Attributes.h"

using Layers::StatelessAttribute;

StatelessAttribute::StatelessAttribute() : Attribute("")
{
}

StatelessAttribute::StatelessAttribute(const QString& name, QVariant value) :
	m_value{ value }, Attribute(name)
{
}

void StatelessAttribute::set_value(QVariant value, bool block_emit)
{
	if (m_value != value)
	{
		m_value = value;

		emit value_changed();
	}

	//if (!block_emit) emit value_changed();
}

QVariant& StatelessAttribute::value()
{
	return m_value;
}
