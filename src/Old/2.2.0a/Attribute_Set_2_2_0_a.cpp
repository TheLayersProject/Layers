#include "../../../include/old.h"

using Layers::Attribute_2_2_0_a;
using Layers::Attribute_Set_2_2_0_a;
using Layers::Stateless_Attribute_2_2_0_a;
using Layers::Stateful_Attribute_2_2_0_a;

void Attribute_Set_2_2_0_a::add_stateless_attribute(Stateless_Attribute_2_2_0_a attribute)
{
	m_stateless_attributes[attribute.name()] = attribute;
}

void Attribute_Set_2_2_0_a::add_stateful_attribute(Stateful_Attribute_2_2_0_a attribute)
{
	m_stateful_attributes[attribute.name()] = attribute;
}

Attribute_2_2_0_a* Attribute_Set_2_2_0_a::attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name];
	else if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name];

	return nullptr;
}

QVariant* Attribute_Set_2_2_0_a::attribute_value(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name].value();
	else if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name].value();

	return nullptr;
}

bool Attribute_Set_2_2_0_a::contains(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return true;
	else if (m_stateful_attributes.contains(attribute_name)) return true;

	return false;
}

bool Attribute_Set_2_2_0_a::contains_stateful_attribute(const QString& attribute_name)
{
	return m_stateful_attributes.contains(attribute_name);
}

bool Attribute_Set_2_2_0_a::contains_stateless_attribute(const QString& attribute_name)
{
	return m_stateless_attributes.contains(attribute_name);
}

void Attribute_Set_2_2_0_a::copy_values_from(Attribute_Set_2_2_0_a& other_attribute_set)
{
	for (Stateful_Attribute_2_2_0_a& stateful_attribute : m_stateful_attributes)
	{
		if (other_attribute_set.contains_stateful_attribute(stateful_attribute.name()))
			stateful_attribute.set_values(other_attribute_set.stateful_attribute(stateful_attribute.name())->values());
	}

	for (Stateless_Attribute_2_2_0_a& attribute : m_stateless_attributes)
	{
		if (other_attribute_set.contains_stateless_attribute(attribute.name()))
			attribute.set_value(other_attribute_set.attribute(attribute.name())->value());
	}
}

void Attribute_Set_2_2_0_a::remove_attribute(const QString& attribute_name)
{
	if (contains(attribute_name))
	{
		if (contains_stateful_attribute(attribute_name))
		{
			QMap<QString, Stateful_Attribute_2_2_0_a> new_stateful_attributes;

			for (Stateful_Attribute_2_2_0_a& stateful_attribute : m_stateful_attributes)
				if (stateful_attribute.name() != attribute_name)
					new_stateful_attributes[stateful_attribute.name()] = stateful_attribute; // <- Might need to do copy construction here 

			m_stateful_attributes.swap(new_stateful_attributes);
		}
		else if (contains_stateless_attribute(attribute_name))
		{
			QMap<QString, Stateless_Attribute_2_2_0_a> new_stateless_attributes;

			for (Stateless_Attribute_2_2_0_a& attribute : m_stateless_attributes)
				if (attribute.name() != attribute_name)
					new_stateless_attributes[attribute.name()] = attribute; // <- Might need to do copy construction here 

			m_stateless_attributes.swap(new_stateless_attributes);
		}
	}
	else qDebug() << "WARNING: Failed to remove attribute: '" + attribute_name + "' not found in attribute set.";
}

void Attribute_Set_2_2_0_a::set_state(const QString& state)
{
	for (Stateful_Attribute_2_2_0_a& stateful_attribute : m_stateful_attributes)
		stateful_attribute.set_state(state);
}

Stateful_Attribute_2_2_0_a* Attribute_Set_2_2_0_a::stateful_attribute(const QString& attribute_name)
{
	if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name];

	return nullptr;
}

QMap<QString, Stateful_Attribute_2_2_0_a>& Attribute_Set_2_2_0_a::stateful_attributes()
{
	return m_stateful_attributes;
}

Stateless_Attribute_2_2_0_a* Attribute_Set_2_2_0_a::stateless_attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name];

	return nullptr;
}

QMap<QString, Stateless_Attribute_2_2_0_a>& Attribute_Set_2_2_0_a::stateless_attributes()
{
	return m_stateless_attributes;
}

QList<QString> Attribute_Set_2_2_0_a::states() const
{
	QList<QString> states = QList<QString>();

	for (const Stateful_Attribute_2_2_0_a& stateful_attribute : m_stateful_attributes)
		for (const QString& state : stateful_attribute.states())
			if (!states.contains(state)) states.append(state);

	return states;
}
