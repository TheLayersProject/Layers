#include "../../../include/Attribute.h"

using Layers::Attribute;

Attribute::Attribute(const QString& name, bool disabled) :
	m_name{ name }, m_disabled{ new bool(disabled) }, AttributeLayoutItem() { }

Attribute::Attribute(const QString& name, QVariant value, bool disabled) :
	m_name{ name }, m_value{ new QVariant(value) }, m_disabled{ new bool(disabled) }, AttributeLayoutItem() { }

Attribute::Attribute(const QString& name, QMap<QString, QVariant> state_value_map, bool disabled) :
	m_name{ name }, m_state{ state_value_map.firstKey() },
	m_values{ new QMap<QString, QVariant>(state_value_map)}, m_disabled{ new bool(disabled) }, AttributeLayoutItem() { }

Attribute::~Attribute()
{
	if (m_overriding_attr)
		disconnect(m_override_update_connection);
}

bool Attribute::contains_state(const QString& state) const
{
	if (m_values) return m_values->contains(state);

	return false;
}

void Attribute::copy_values_from(const Attribute& attr)
{
	// NOTE: Will want to keep track of whether the value(s) belong to this Attribute
	// or point to another Attribute's value(s). If this Attribute doesn't own the value(s),
	// then you will not want to delete them.

	if (!m_overriding_attr)
	{
		if (attr.m_value)
		{
			if (m_values)
			{
				delete m_values;

				m_values = nullptr;

				m_value = new QVariant(*attr.m_value);
			}
			else
				m_value->setValue(*attr.m_value);
		}
		else
		{
			if (m_value)
			{
				delete m_value;

				m_value = nullptr;

				m_values = new QMap<QString, QVariant>(*attr.m_values);
			}
			else
			{
				m_values->clear();

				m_values->insert(*attr.m_values);
			}
		}

		m_disabled = attr.m_disabled;

		// TODO: TESTING; HAVE NOT COMPLETELY CONSIDERED THIS:
		emit value_changed();

		//m_state = attr->m_state;
		// Should current state of attr also be copied?
	}
}

bool Attribute::disabled() const
{   
	return *m_disabled;
}

QString& Attribute::name() { return m_name; }

void Attribute::get_values_from(Attribute& replacement_attr)
{
	// Need to check if the replacement_attr itself is using an overriding_attr.
	// If so, you will not want to delete the m_value(s) pointer

	// TODO: Look into this. You put this check here to prevent the CornerRadiiAW's example_widget
	// from getting the values from the sliders, and then turning around and getting the values from 
	// the replace_all_attributes_with() call. This might cause other things to not work as expected.
	if (!m_overriding_attr)
	{
		m_overriding_attr = &replacement_attr;

		if (m_overriding_attr->m_value)
		{
			if (m_value) delete m_value;
			else {
				delete m_values;
				m_values = nullptr;
			}

			m_value = m_overriding_attr->m_value;
		}
		else
		{
			if (m_value) {
				delete m_value;
				m_value = nullptr;
			}
			else delete m_values;

			m_values = m_overriding_attr->m_values;
		}

		delete m_disabled;
		m_disabled = m_overriding_attr->m_disabled;

		emit value_changed();

		m_override_update_connection = connect(m_overriding_attr, &Attribute::value_changed, [this]
			{
				if (m_overriding_attr->m_value)
					m_value = m_overriding_attr->m_value;
				else
					m_values = m_overriding_attr->m_values;

				m_disabled = m_overriding_attr->m_disabled;

				emit value_changed();
			});
	}
}

void Attribute::set_disabled(bool disabled)
{
	m_disabled = new bool(disabled);
}

void Attribute::set_state(const QString& state)
{
	if (contains_state(state)) m_state = state;
}

void Attribute::set_value(QVariant value)
{
	if (m_value && *m_value != value)
	{
		*m_value = value;

		emit value_changed();
	}
}

void Attribute::set_value(const QString& state, QVariant value)
{
	if (m_values)
	{
		if (m_values->contains(state))
		{
			if ((*m_values)[state] != value)
			{
				(*m_values)[state] = value;

				emit value_changed();
			}
		}
		else qDebug() << "WARNING: Failed to set attribute value: State does not exist.";
	}
	else qDebug() << "WARNING: Failed to set attribute value: State provided but Attribute is not stateful.";
}

void Attribute::set_values(const QMap<QString, QVariant>& values)
{
	// TODO: Should this function check if the incoming 'values' map has the same values as 'm_values'?
	// Also, should it emit value_changed?

	if (m_value)
	{
		delete m_value;

		m_value = nullptr;
	}
	if (m_values) delete m_values;

	m_values = new QMap<QString, QVariant>(values);

	m_state = m_values->firstKey();
}

QString Attribute::state() const
{
	return m_state;
}

QList<QString> Attribute::states() const
{
	if (m_values) return m_values->keys();

	return QList<QString>();
}

const char* Attribute::typeName() const
{
	if (m_values) return (*m_values)[m_state].typeName();
	else
	{
		return m_value->typeName();
	}
}

QMap<QString, QVariant>* Attribute::values()
{
	return m_values;
}
