#include "../../../include/AttributeSet.h"

using Layers::Attribute;
using Layers::AttributeSet;

void AttributeSet::add_attribute(Attribute* attribute)
{
	m_attributes[attribute->name()] = attribute;
}

Attribute* AttributeSet::attribute(const QString& attribute_name)
{
	if (m_attributes.contains(attribute_name))
		return m_attributes[attribute_name];

	return nullptr;
}

QVariant* AttributeSet::attribute_value(const QString& attribute_name)
{
	if (m_attributes.contains(attribute_name))
	{
		return &m_attributes[attribute_name]->value();

	}

	return nullptr;
}

QMap<QString, Attribute*>& AttributeSet::attributes()
{
	return m_attributes;
}

bool AttributeSet::contains(const QString& attribute_name)
{
	return m_attributes.contains(attribute_name);
}

void AttributeSet::copy_values_from(AttributeSet& other_attribute_set)
{
	for (Attribute* attr : m_attributes)
	{
		if (other_attribute_set.contains(attr->name()))
		{
			if (attr->values().isEmpty())
				attr->set_value(other_attribute_set.attribute(attr->name())->value());
			else
				attr->set_values(other_attribute_set.attribute(attr->name())->values());
		}
	}
}

void AttributeSet::remove_attribute(const QString& attribute_name)
{
	if (contains(attribute_name))
	{
		QMap<QString, Attribute*> new_attributes;

		for (Attribute* attr : m_attributes)
		{
			if (attr->name() != attribute_name)
				new_attributes[attr->name()] = attr;
			else
				attr->deleteLater();
		}

		m_attributes.swap(new_attributes);
	}
	else qDebug() << "WARNING: Failed to remove attribute: '" + attribute_name + "' not found in attribute set.";
}

bool AttributeSet::replace_with_proxy(const QString& attribute_name, Attribute* proxy_attribute)
{
	if (m_attributes.contains(attribute_name))
	{
		delete m_attributes[attribute_name];

		m_attributes.insert(attribute_name, proxy_attribute);

		return true;
	}

	return false;
}

void AttributeSet::replace_all_with(AttributeSet& other_attribute_set)
{
	for (const QString& attr_name : m_attributes.keys())
		if (other_attribute_set.m_attributes.contains(attr_name))
			replace_with_proxy(attr_name, other_attribute_set.attribute(attr_name));
}

void AttributeSet::set_state(const QString& state)
{
	for (Attribute* attr : m_attributes)
		if (!attr->values().isEmpty())
			attr->set_state(state);
}

QList<QString> AttributeSet::states() const
{
	QList<QString> states = QList<QString>();

	for (Attribute* attr : m_attributes)
		for (const QString& state : attr->states())
			if (!states.contains(state)) states.append(state);

	return states;
}
