#include "../../../include/old.h"

using Layers::Attribute_2_2_0_a;
using Layers::Themeable;

Attribute_2_2_0_a::Attribute_2_2_0_a(const QString& name) :
	m_name{ name }
{
}

QString& Attribute_2_2_0_a::name()
{
	return m_name;
}

Themeable* Attribute_2_2_0_a::parent_themeable() const
{
	return m_parent_themeable;
}

void Attribute_2_2_0_a::set_parent_themeable(Themeable* parent_themeable)
{
	m_parent_themeable = parent_themeable;
}
