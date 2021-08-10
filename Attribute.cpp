#include "Layers.h"

using Layers::Attribute;
using Layers::Themeable;

Attribute::Attribute(const QString& name) :
	m_name{ name }
{
}

QString& Attribute::name()
{
	return m_name;
}

Themeable* Attribute::parent_themeable() const
{
	return m_parent_themeable;
}

void Attribute::set_parent_themeable(Themeable* parent_themeable)
{
	m_parent_themeable = parent_themeable;
}
