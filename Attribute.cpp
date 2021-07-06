#include "Layers.h"

using Layers::Attribute;
using Layers::Themeable;

Attribute::Attribute() :
	m_name{ "" }, m_state{ "" }
{
}

Attribute::Attribute(const QString& name, QVariant value) :
	m_name{ name }, m_state{ "Default" }
{
	m_values[m_state] = value;
}

Attribute::Attribute(const QString& name, const QString& state, QVariant value) :
	m_name{ name }, m_state{ state }
{
	m_is_stateful = true;

	m_values[m_state] = value;
}

Attribute::Attribute(const QString& name, QMap<QString, QVariant> state_value_map) :
	m_name{ name }, m_state{ state_value_map.firstKey() }
{
	m_is_stateful = true;

	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

void Attribute::add_state_and_value(const QString& state, QVariant value)
{
	if (!m_values.contains(state)) m_values[state] = value;
}

void Attribute::apply_theme_attribute(Attribute& theme_attribute)
{
	for (const QString& state : states())
		if (theme_attribute.contains(state))
			set_value(state, theme_attribute.value(state));
}

bool Attribute::contains(const QString& key) const
{
	return m_values.contains(key);
}

bool Attribute::is_stateful() const
{
	return m_is_stateful;
}

void Attribute::make_stateful(QMap<QString, QVariant> state_value_map)
{
	m_is_stateful = true;

	QMap<QString, QVariant> new_values;

	for (const QString& state : state_value_map.keys())
		new_values[state] = state_value_map[state];

	m_values.swap(new_values);

	m_state = m_values.firstKey();
}

QString& Attribute::name()
{
	return m_name;
}

Themeable* Attribute::parent_themeable() const
{
	return m_parent_themeable;
}

void Attribute::set_common(QVariant value)
{
	QMap<QString, QVariant> new_values;

	new_values["Common"] = value;

	m_values.swap(new_values);

	m_state = "Common";
}

void Attribute::set_parent_themeable(Themeable* parent_themeable)
{
	m_parent_themeable = parent_themeable;
}

void Attribute::set_state(const QString& state)
{
	if (m_state != "Common") m_state = state;
}

void Attribute::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state)) m_values[state] = value;
}

QString Attribute::state() const
{
	return m_state;
}

QList<QString> Attribute::states() const
{
	return m_values.keys();
}

QVariant& Attribute::value()
{
	return value(m_state);
}

QVariant& Attribute::value(const QString& state)
{
	if (m_values.contains(state)) return m_values[state];
}
