#include "../../../include/Attribute.h"

using Layers::Attribute;
using Layers::AttributeGroup;

AttributeGroup::AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes) :
	m_name{ name }, m_attributes { attributes }
{

}

QMap<QString, Attribute*>& AttributeGroup::attributes()
{
	return m_attributes;
}

QString AttributeGroup::name() const
{
	return m_name;
}
