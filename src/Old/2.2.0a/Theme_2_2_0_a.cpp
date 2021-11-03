#include "../../../include/old.h"
#include "../../../include/Themeable.h"

using Layers::Attribute_Set_2_2_0_a;
using Layers::Stateless_Attribute_2_2_0_a;
using Layers::Stateful_Attribute_2_2_0_a;
using Layers::Theme_2_2_0_a;
using Layers::Themeable;

Theme_2_2_0_a::Theme_2_2_0_a() :
	m_name{ "" }, m_is_custom{ true }
{
}

Theme_2_2_0_a::Theme_2_2_0_a(const QString& name, bool is_custom) :
	m_name{ name }, m_is_custom{ is_custom }
{

}

void Theme_2_2_0_a::add_attribute_set(const QString& themeable_tag, Attribute_Set_2_2_0_a attribute_set)
{
	m_attribute_sets[themeable_tag] = attribute_set;
}

void Theme_2_2_0_a::add_stateful_attribute(const QString& themeable_tag, const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = Attribute_Set_2_2_0_a();

	Attribute_Set_2_2_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_stateful_attribute(Stateful_Attribute_2_2_0_a(attribute_name, state_value_map));
}

void Theme_2_2_0_a::add_stateless_attribute(const QString& themeable_tag, const QString& attribute_name, QVariant value)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = Attribute_Set_2_2_0_a();

	Attribute_Set_2_2_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_stateless_attribute(Stateless_Attribute_2_2_0_a(attribute_name, value));
}

Attribute_Set_2_2_0_a& Theme_2_2_0_a::attribute_set(const QString& themeable_tag)
{
	return m_attribute_sets[themeable_tag];
}

QHash<QString, Attribute_Set_2_2_0_a>& Theme_2_2_0_a::attribute_sets()
{
	return m_attribute_sets;
}

Stateless_Attribute_2_2_0_a* Theme_2_2_0_a::stateless_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	Attribute_Set_2_2_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (attribute_set.contains(attribute_name))
		return attribute_set.stateless_attribute(attribute_name);

	return nullptr;
}

bool Theme_2_2_0_a::contains_attributes_for_tag(const QString& themeable_tag)
{
	return m_attribute_sets.contains(themeable_tag);
}

bool Theme_2_2_0_a::contains_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	return m_attribute_sets[themeable_tag].contains(attribute_name);
}

void Theme_2_2_0_a::copy_attribute_sets_from(Theme_2_2_0_a& theme)
{
	m_attribute_sets = theme.m_attribute_sets;
}

bool Theme_2_2_0_a::is_custom()
{
	return m_is_custom;
}

QString& Theme_2_2_0_a::name()
{
	return m_name;
}

void Theme_2_2_0_a::set_name(const QString& new_name)
{
	m_name = new_name;
}

Stateful_Attribute_2_2_0_a* Theme_2_2_0_a::stateful_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	Attribute_Set_2_2_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (attribute_set.contains(attribute_name))
		return attribute_set.stateful_attribute(attribute_name);

	return nullptr;
}
