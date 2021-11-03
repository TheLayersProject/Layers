#include "../../../include/Attribute.h"

using Layers::Attribute;

Attribute::Attribute(const QString& name, QObject* parent) :
	m_name{ name }, QObject(parent)
{

}

Attribute::Attribute(const QString& name, QVariant value, QObject* parent) :
	m_name{ name }, m_value{ value }, QObject(parent)
{

}

Attribute::Attribute(const QString& name, QMap<QString, QVariant> state_value_map, QObject* parent) :
	m_name{ name }, m_state{ state_value_map.firstKey() }, QObject(parent)
{
	for (const QString& state : state_value_map.keys())
		m_values[state] = state_value_map[state];
}

bool Attribute::contains_state(const QString& state) const
{
	return m_values.contains(state);
}

QString& Attribute::name() { return m_name; }

void Attribute::set_state(const QString& state)
{
	if (m_values.contains(state)) m_state = state;
}

void Attribute::set_value(QVariant value)
{
	if (m_value != value)
	{
		m_value = value;

		emit value_changed();
	}
}

void Attribute::set_value(const QString& state, QVariant value)
{
	if (m_values.contains(state))
	{
		if (m_values[state] != value)
		{
			m_values[state] = value;

			emit value_changed();
		}
	}
	else qDebug() << "WARNING: Failed to set attribute value: State does not exist.";
}

void Attribute::set_values(const QMap<QString, QVariant>& values)
{
	// TODO: Should this function check if the incoming 'values' map has the same values as 'm_values'?
	// Also, should it emit value_changed?

	m_values = values;
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
	if (m_values.isEmpty()) return m_value;
	else
	{
		return m_values[m_state];
	}
}

QVariant* Attribute::value(const QString& state)
{
	if (m_values.contains(state)) return &m_values[state];
	else
	{
		qDebug() << "WARNING: Failed to obtain attribute value: State does not exist.";

		return nullptr;
	}
}

QMap<QString, QVariant>& Attribute::values()
{
	return m_values;
}
