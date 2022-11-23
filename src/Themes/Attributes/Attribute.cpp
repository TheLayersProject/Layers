#include "../../../include/Attribute.h"

using Layers::Attribute;
using Layers::Variant;

Attribute::Attribute(const QString& name, bool disabled) :
	m_name{ name }, m_disabled{ disabled }, AttributeLayoutItem() { }

Attribute::Attribute(const QString& name, QVariant qvariant, bool disabled) :
	m_name{ name }, m_variant{ new Variant(qvariant) }, m_disabled{ disabled }, AttributeLayoutItem()
{
	variant_connections.append(
		connect(m_variant, &Variant::changed, [this] { emit value_changed(); })
	);
}

Attribute::Attribute(const QString& name, QMap<QString, Variant> state_variant_map, bool disabled) :
	m_name{ name },
	m_state_variant_map{ new QMap<QString, Variant>(state_variant_map) }, m_disabled{ disabled }, AttributeLayoutItem()
{
	for (const QString& state : m_state_variant_map->keys())
		variant_connections.append(
			connect(&(*m_state_variant_map)[state], &Variant::changed, [this] {
				emit value_changed();
			})
		);
}

Attribute::~Attribute()
{
	for (QMetaObject::Connection variant_connection : variant_connections)
		disconnect(variant_connection);
}

void Layers::Attribute::clear_variant_if_owner()
{
	if (m_owns_variant)
	{
		m_owns_variant = false;

		if (m_variant)
		{
			delete m_variant;
			m_variant = nullptr;
		}
		else if (m_state_variant_map)
		{
			delete m_state_variant_map;
			m_state_variant_map = nullptr;
		}
	}
}

bool Attribute::contains_state(const QString& state) const
{
	return m_state_variant_map->contains(state);
}

void Attribute::copy_value_from(const Attribute& attr)
{
	if (attr.m_variant)
	{
		if (m_state_variant_map)
		{
			delete m_state_variant_map;

			m_state_variant_map = nullptr;

			m_variant = new Variant(*attr.m_variant);
		}
		else
			*m_variant = *attr.m_variant; //m_variant->setValue(*attr.m_variant);
	}
	else
	{
		if (m_variant)
		{
			delete m_variant;

			m_variant = nullptr;

			m_state_variant_map = new QMap<QString, Variant>(*attr.m_state_variant_map);
		}
		else
		{
			m_state_variant_map->clear();

			m_state_variant_map->insert(*attr.m_state_variant_map);
		}
	}

	m_disabled = attr.m_disabled;
	
	emit value_changed();
}

bool Attribute::disabled() const
{
	return m_disabled;
}

QString& Attribute::name() { return m_name; }

void Attribute::get_variant_from(Attribute& attribute)
{
	// TODO: Likely need to store this connection and disconnect in destructor
	connect(&attribute, &Attribute::variant_changed, [this, &attribute] {
		get_variant_from(attribute);
		});

	if (attribute.m_variant)
	{
		set_variant(*attribute.m_variant);

		for (QMetaObject::Connection variant_connection : variant_connections)
			disconnect(variant_connection);

		variant_connections.clear();

		variant_connections.append(
			connect(m_variant, &Variant::changed, [this] { emit value_changed(); })
		);
	}
	else if (attribute.m_state_variant_map)
	{
		set_state_variant_map(*attribute.m_state_variant_map);

		for (QMetaObject::Connection variant_connection : variant_connections)
			disconnect(variant_connection);

		variant_connections.clear();

		for (const QString& state : m_state_variant_map->keys())
			variant_connections.append(
				connect(&(*m_state_variant_map)[state], &Variant::changed, [this] {
					emit value_changed();
					})
			);
	}

	emit variant_changed();
	emit value_changed();
}

//void Attribute::get_variant_from(Attribute& attribute)
//{
//	if (attribute.m_variant)
//	{
//		set_variant(*attribute.m_variant);
//
//		for (QMetaObject::Connection variant_connection : variant_connections)
//			disconnect(variant_connection);
//
//		variant_connections.clear();
//
//		variant_connections.append(
//			connect(m_variant, &Variant::changed, [this] { emit value_changed(); })
//		);
//	}
//	else if (attribute.m_state_variant_map)
//	{
//		set_state_variant_map(*attribute.m_state_variant_map);
//
//		for (QMetaObject::Connection variant_connection : variant_connections)
//			disconnect(variant_connection);
//
//		variant_connections.clear();
//
//		for (const QString& state : m_state_variant_map->keys())
//			variant_connections.append(
//				connect(&(*m_state_variant_map)[state], &Variant::changed, [this] {
//					emit value_changed();
//					})
//			);
//	}
//}

void Attribute::init_state_variant_map(const QMap<QString, Variant>& state_variant_map)
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}

	if (m_state_variant_map) m_state_variant_map->clear();
	else m_state_variant_map = new QMap<QString, Variant>();

	m_state_variant_map->insert(state_variant_map);
}

bool Attribute::is_stateful() const
{
	if (m_state_variant_map)
		return !m_state_variant_map->isEmpty();

	return false;
}

void Attribute::set_disabled(bool disabled)
{
	//m_disabled = new bool(disabled);
	m_disabled = disabled;

	emit value_changed();
}

void Attribute::set_state(const QString& state)
{
	m_state = state;
}

void Attribute::set_state_variant_map(QMap<QString, Variant>& state_variant_map)
{
	// TODO: Should this function check if the incoming 'values' map has the same values as 'm_values'?
	// Also, should it emit value_changed?

	clear_variant_if_owner();

	m_state_variant_map = &state_variant_map;

	if (!m_state_variant_map->keys().contains(m_state))
		m_state = m_state_variant_map->firstKey();
}

void Attribute::set_value(QVariant qvariant)
{
	/* Should this function still work with stateful attributes and just change
	   the variant associated with the current state? */

	if (m_variant && *m_variant != qvariant)
	{
		*m_variant = qvariant;
		
		emit value_changed();
	}
}

void Attribute::set_value(const QString& state, QVariant variant)
{
	if (m_state_variant_map)
	{
		if (m_state_variant_map->contains(state))
		{
			if ((*m_state_variant_map)[state] != variant)
			{
				(*m_state_variant_map)[state] = variant;
		
				emit value_changed();
			}
		}
		else qDebug() << "WARNING: Failed to set attribute value: State does not exist.";
	}
	else qDebug() << "WARNING: Failed to set attribute value: State provided but Attribute is not stateful.";
}

void Attribute::set_variant(Variant& variant)
{
	clear_variant_if_owner();

	m_state = "";

	m_variant = &variant;
}

QString Attribute::state() const
{
	return m_state;
}

QList<QString> Attribute::states() const
{
	if (m_state_variant_map)
		return m_state_variant_map->keys();

	return QList<QString>();
}

const char* Attribute::typeName() const
{
	if (m_state_variant_map)
		return (*m_state_variant_map)[m_state].typeName();
	else
		return m_variant->typeName();
}

Variant* Attribute::variant() const
{
	return m_variant;
}
