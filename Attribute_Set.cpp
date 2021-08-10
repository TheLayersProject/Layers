#include "Layers.h"

using Layers::Attribute;
using Layers::Attribute_Set;
using Layers::Stateless_Attribute;
using Layers::Stateful_Attribute;

void Attribute_Set::add_attribute(Stateless_Attribute attribute)
{
	m_stateless_attributes[attribute.name()] = attribute;
}

void Attribute_Set::add_attribute(Stateful_Attribute attribute)
{
	m_stateful_attributes[attribute.name()] = attribute;
}

Attribute* Attribute_Set::attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name];
	else if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name];

	return nullptr;
}

QVariant* Attribute_Set::attribute_value(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name].value();
	else if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name].value();

	return nullptr;
}

bool Attribute_Set::contains(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return true;
	else if (m_stateful_attributes.contains(attribute_name)) return true;

	return false;
}

bool Attribute_Set::contains_stateful_attribute(const QString& attribute_name)
{
	return m_stateful_attributes.contains(attribute_name);
}

bool Attribute_Set::contains_stateless_attribute(const QString& attribute_name)
{
	return m_stateless_attributes.contains(attribute_name);
}

void Attribute_Set::copy_values_from(Attribute_Set& other_attribute_set)
{
	for (Stateful_Attribute& stateful_attribute : m_stateful_attributes)
	{
		if (other_attribute_set.contains_stateful_attribute(stateful_attribute.name()))
			stateful_attribute.set_values(other_attribute_set.stateful_attribute(stateful_attribute.name())->values());
	}

	for (Stateless_Attribute& stateless_attribute : m_stateless_attributes)
	{
		if (other_attribute_set.contains_stateless_attribute(stateless_attribute.name()))
			stateless_attribute.set_value(other_attribute_set.stateless_attribute(stateless_attribute.name())->value());
	}
}

void Attribute_Set::remove_attribute(const QString& attribute_name)
{
	if (contains(attribute_name))
	{
		if (contains_stateful_attribute(attribute_name))
		{
			QMap<QString, Stateful_Attribute> new_stateful_attributes;

			for (Stateful_Attribute& stateful_attribute : m_stateful_attributes)
				if (stateful_attribute.name() != attribute_name)
					new_stateful_attributes[stateful_attribute.name()] = stateful_attribute; // <- Might need to do copy construction here 

			m_stateful_attributes.swap(new_stateful_attributes);
		}
		else if (contains_stateless_attribute(attribute_name))
		{
			QMap<QString, Stateless_Attribute> new_stateless_attributes;

			for (Stateless_Attribute& stateless_attribute : m_stateless_attributes)
				if (stateless_attribute.name() != attribute_name)
					new_stateless_attributes[stateless_attribute.name()] = stateless_attribute; // <- Might need to do copy construction here 

			m_stateless_attributes.swap(new_stateless_attributes);
		}
	}
	else qDebug() << "WARNING: Failed to remove attribute: '" + attribute_name + "' not found in attribute set.";
}

void Attribute_Set::set_state(const QString& state)
{
	for (Stateful_Attribute& stateful_attribute : m_stateful_attributes)
		stateful_attribute.set_state(state);
}

Stateful_Attribute* Attribute_Set::stateful_attribute(const QString& attribute_name)
{
	if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name];

	return nullptr;
}

QMap<QString, Stateful_Attribute>& Attribute_Set::stateful_attributes()
{
	return m_stateful_attributes;
}

Stateless_Attribute* Attribute_Set::stateless_attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name];

	return nullptr;
}

QMap<QString, Stateless_Attribute>& Attribute_Set::stateless_attributes()
{
	return m_stateless_attributes;
}

QList<QString> Attribute_Set::states() const
{
	QList<QString> states = QList<QString>();

	for (const Stateful_Attribute& stateful_attribute : m_stateful_attributes)
		for (const QString& state : stateful_attribute.states())
			if (!states.contains(state)) states.append(state);

	return states;
}
