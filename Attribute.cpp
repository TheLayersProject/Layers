#include "Layers.h"

using Layers::Attribute;
using Layers::Themeable;

Attribute::Attribute() :
	m_name{ "" }
{
}

Attribute::Attribute(const QString& name, QVariant value) :
	m_name{ name }, m_value{ value }
{
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
	if (m_is_stateful)
	{
		for (const QString& state : states())
			if (theme_attribute.contains_state(state))
				set_value(state, theme_attribute.value(state));
	}
	else set_value(theme_attribute.value());
}

bool Attribute::contains_state(const QString& state) const
{
	return m_values.contains(state);
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

void Attribute::set_parent_themeable(Themeable* parent_themeable)
{
	m_parent_themeable = parent_themeable;
}

void Attribute::set_state(const QString& state)
{
	if (m_is_stateful) m_state = state;
	else qDebug() << "ERROR: Failed to set attribute state: Attribute is not stateful.";
}

void Attribute::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state)) m_values[state] = value;
}

void Attribute::set_value(QVariant value)
{
	if (!m_is_stateful) m_value = value;
	else qDebug() << "ERROR: Failed to set attribute value. Attribute is stateful; use set_value() that requires a state.";
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
	if (!m_is_stateful) return m_value;
	else return value(m_state);
}

QVariant& Attribute::value(const QString& state)
{
	if (!m_is_stateful) qDebug() << "";
	else if (m_values.contains(state)) return m_values[state];
	else qDebug() << "ERROR: Failed to find obtain attribute value: State does not exist.";
}
