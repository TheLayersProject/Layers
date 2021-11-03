#include "../../../include/old.h"

using Layers::Attribute_Set_2_1_0_a;
using Layers::Theme_2_1_0_a;

Theme_2_1_0_a::Theme_2_1_0_a() :
	m_name{ "" }, m_is_custom{ true }
{
}

Theme_2_1_0_a::Theme_2_1_0_a(const QString& name, bool is_custom) :
	m_name{ name }, m_is_custom{ is_custom }
{
}

void Theme_2_1_0_a::add_stateful_attribute(const QString& themeable_tag, const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = Attribute_Set_2_1_0_a();

	Attribute_Set_2_1_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_stateful_attribute(Stateful_Attribute_2_1_0_a(attribute_name, state_value_map));
}

void Theme_2_1_0_a::add_stateless_attribute(const QString& themeable_tag, const QString& attribute_name, QVariant value)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = Attribute_Set_2_1_0_a();

	Attribute_Set_2_1_0_a& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_stateless_attribute(Stateless_Attribute_2_1_0_a(attribute_name, value));
}

QHash<QString, Attribute_Set_2_1_0_a>& Theme_2_1_0_a::attribute_sets()
{
	return m_attribute_sets;
}

bool Theme_2_1_0_a::is_custom()
{
	return m_is_custom;
}

QString& Theme_2_1_0_a::name()
{
	return m_name;
}
