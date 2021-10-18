#include "Layers.h"

using Layers::AttributeSet;
using Layers::StatelessAttribute;
using Layers::StatefulAttribute;
using Layers::Theme;
using Layers::Themeable;

Theme::Theme()
{
}

Theme::Theme(const QString& name, bool is_custom) :
	m_name{ name }, m_is_custom{ is_custom }
{

}

void Theme::add_attribute_set(const QString& themeable_tag, AttributeSet attribute_set)
{
	m_attribute_sets[themeable_tag] = attribute_set;
}

void Theme::add_stateful_attribute(const QString& themeable_tag, const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = AttributeSet();

	AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_attribute(StatefulAttribute(attribute_name, state_value_map));
}

void Theme::add_stateless_attribute(const QString& themeable_tag, const QString& attribute_name, QVariant value)
{
	if (!m_attribute_sets.contains(themeable_tag))
		m_attribute_sets[themeable_tag] = AttributeSet();

	AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	if (!attribute_set.contains(attribute_name))
		attribute_set.add_attribute(StatelessAttribute(attribute_name, value));
}

AttributeSet& Theme::attribute_set(const QString& themeable_tag)
{
	return m_attribute_sets[themeable_tag];
}

QHash<QString, AttributeSet>& Theme::attribute_sets()
{
	return m_attribute_sets;
}

void Theme::consume(Theme&& theme)
{
	for (const QString& themeable_tag : theme.attribute_sets().keys())
	{
		if (!m_attribute_sets.contains(themeable_tag))
			m_attribute_sets[themeable_tag] = AttributeSet();

		AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

		for (StatelessAttribute& stateless_attribute : theme.attribute_sets()[themeable_tag].stateless_attributes())
			if (!attribute_set.contains_stateless_attribute(stateless_attribute.name()))
				attribute_set.add_attribute(stateless_attribute);

		for (StatefulAttribute& stateful_attribute : theme.attribute_sets()[themeable_tag].stateful_attributes())
			if (!attribute_set.contains_stateful_attribute(stateful_attribute.name()))
				attribute_set.add_attribute(stateful_attribute);
	}
}

StatelessAttribute* Theme::stateless_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	if (attribute_set.contains(attribute_name))
		return attribute_set.stateless_attribute(attribute_name);

	return nullptr;
}

bool Theme::contains_attributes_for_tag(const QString& themeable_tag)
{
	return m_attribute_sets.contains(themeable_tag);
}

bool Theme::contains_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	return m_attribute_sets[themeable_tag].contains(attribute_name);
}

void Theme::copy_attribute_sets_from(Theme& theme)
{
	m_attribute_sets = theme.m_attribute_sets;
}

void Theme::copy_attribute_values_of(Themeable* themeable)
{
	if (m_attribute_sets.contains(themeable->theme_tag()))
		m_attribute_sets[themeable->theme_tag()].copy_values_from(themeable->attribute_set());
}

bool Theme::is_custom()
{
	return m_is_custom;
}

QString& Theme::name()
{
	return m_name;
}

void Theme::set_name(const QString& new_name)
{
	m_name = new_name;
}

StatefulAttribute* Theme::stateful_attribute(const QString& themeable_tag, const QString& attribute_name)
{
	AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	if (attribute_set.contains(attribute_name))
		return attribute_set.stateful_attribute(attribute_name);

	return nullptr;
}
