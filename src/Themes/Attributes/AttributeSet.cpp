#include "../../../include/AttributeSet.h"
#include "../../../include/Themeable.h"

using Layers::Attribute;
using Layers::AttributeSet;
using Layers::StatelessAttribute;
using Layers::StatefulAttribute;
using Layers::Themeable;

void AttributeSet::add_stateless_attribute(StatelessAttribute* attribute)
{
	m_stateless_attributes[attribute->name()] = attribute;
}

void AttributeSet::add_stateful_attribute(StatefulAttribute* attribute)
{
	m_stateful_attributes[attribute->name()] = attribute;
}

Attribute* AttributeSet::attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return m_stateless_attributes[attribute_name];
	else if (m_stateful_attributes.contains(attribute_name)) return m_stateful_attributes[attribute_name];

	return nullptr;
}

QVariant* AttributeSet::attribute_value(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return &m_stateless_attributes[attribute_name]->value();
	else if (m_stateful_attributes.contains(attribute_name)) return &m_stateful_attributes[attribute_name]->value();

	return nullptr;
}

bool AttributeSet::contains(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return true;
	else if (m_stateful_attributes.contains(attribute_name)) return true;

	return false;
}

bool AttributeSet::contains_stateful_attribute(const QString& attribute_name)
{
	return m_stateful_attributes.contains(attribute_name);
}

bool AttributeSet::contains_stateless_attribute(const QString& attribute_name)
{
	return m_stateless_attributes.contains(attribute_name);
}

void AttributeSet::copy_values_from(AttributeSet& other_attribute_set)
{
	for (StatefulAttribute* stateful_attribute : m_stateful_attributes)
	{
		if (other_attribute_set.contains_stateful_attribute(stateful_attribute->name()))
			stateful_attribute->set_values(other_attribute_set.stateful_attribute(stateful_attribute->name())->values());
	}

	for (StatelessAttribute* stateless_attribute : m_stateless_attributes)
	{
		if (other_attribute_set.contains_stateless_attribute(stateless_attribute->name()))
			stateless_attribute->set_value(other_attribute_set.stateless_attribute(stateless_attribute->name())->value());
	}
}

void AttributeSet::remove_attribute(const QString& attribute_name)
{
	if (contains(attribute_name))
	{
		if (contains_stateful_attribute(attribute_name))
		{
			QMap<QString, StatefulAttribute*> new_stateful_attributes;

			for (StatefulAttribute* stateful_attribute : m_stateful_attributes)
			{
				if (stateful_attribute->name() != attribute_name)
					new_stateful_attributes[stateful_attribute->name()] = stateful_attribute;
				else
					stateful_attribute->deleteLater();
			}

			m_stateful_attributes.swap(new_stateful_attributes);
		}
		else if (contains_stateless_attribute(attribute_name))
		{
			QMap<QString, StatelessAttribute*> new_stateless_attributes;

			for (StatelessAttribute* stateless_attribute : m_stateless_attributes)
			{
				if (stateless_attribute->name() != attribute_name)
					new_stateless_attributes[stateless_attribute->name()] = stateless_attribute;
				else
					stateless_attribute->deleteLater();
			}

			m_stateless_attributes.swap(new_stateless_attributes);
		}
	}
	else qDebug() << "WARNING: Failed to remove attribute: '" + attribute_name + "' not found in attribute set.";
}

bool AttributeSet::replace_with_proxy(const QString& attribute_name, Attribute* proxy_attribute)
{
	if (contains(attribute_name))
	{
		if (m_stateful_attributes.contains(attribute_name))
			delete m_stateful_attributes[attribute_name];
		else
			delete m_stateless_attributes[attribute_name];

		if (StatefulAttribute* stateful_attr = dynamic_cast<StatefulAttribute*>(proxy_attribute))
			m_stateful_attributes.insert(attribute_name, stateful_attr);
		else if (StatelessAttribute* stateless_attr = dynamic_cast<StatelessAttribute*>(proxy_attribute))
			m_stateless_attributes.insert(attribute_name, stateless_attr);

		return true;
	}

	return false;
}

void AttributeSet::replace_all_with(AttributeSet& other_attribute_set)
{
	for (const QString& stateless_attr_name : m_stateless_attributes.keys())
		if (other_attribute_set.m_stateless_attributes.contains(stateless_attr_name))
			replace_with_proxy(stateless_attr_name, other_attribute_set.stateless_attribute(stateless_attr_name));

	for (const QString& stateful_attr_name : m_stateful_attributes.keys())
		if (other_attribute_set.m_stateful_attributes.contains(stateful_attr_name))
			replace_with_proxy(stateful_attr_name, other_attribute_set.stateful_attribute(stateful_attr_name));
}

void AttributeSet::set_state(const QString& state)
{
	for (StatefulAttribute* stateful_attribute : m_stateful_attributes)
		stateful_attribute->set_state(state);
}

StatefulAttribute* AttributeSet::stateful_attribute(const QString& attribute_name)
{
	if (m_stateful_attributes.contains(attribute_name)) return m_stateful_attributes[attribute_name];

	return nullptr;
}

QMap<QString, StatefulAttribute*>& AttributeSet::stateful_attributes()
{
	return m_stateful_attributes;
}

StatelessAttribute* AttributeSet::stateless_attribute(const QString& attribute_name)
{
	if (m_stateless_attributes.contains(attribute_name)) return m_stateless_attributes[attribute_name];

	return nullptr;
}

QMap<QString, StatelessAttribute*>& AttributeSet::stateless_attributes()
{
	return m_stateless_attributes;
}

QList<QString> AttributeSet::states() const
{
	QList<QString> states = QList<QString>();

	for (StatefulAttribute* stateful_attribute : m_stateful_attributes)
		for (const QString& state : stateful_attribute->states())
			if (!states.contains(state)) states.append(state);

	return states;
}
