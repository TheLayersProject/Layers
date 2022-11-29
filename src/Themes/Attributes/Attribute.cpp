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

Attribute::Attribute(const Attribute& a)
{
	if (a.m_variant)
	{
		m_variant = new Variant(*a.m_variant);

		variant_connections.append(
			connect(m_variant, &Variant::changed, [this] { emit value_changed(); })
		);
	}
	else
	{
		m_state_variant_map = new QMap<QString, Variant>();

		m_state_variant_map->insert(*a.m_state_variant_map);

		for (const QString& state : m_state_variant_map->keys())
			variant_connections.append(
				connect(&(*m_state_variant_map)[state], &Variant::changed, [this] {
					emit value_changed();
					})
			);
	}

	m_disabled = a.m_disabled;
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

bool Attribute::owns_variant() const
{
	return m_owns_variant;
}

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

void Attribute::set_value(QVariant qvariant, bool retain_type)
{
	/* Should this function still work with stateful attributes and just change
	   the variant associated with the current state? */

	/* NOTE: qvariant is explicitly converted to the type that this Attribute
	   already stores. This is necessary because the initial type of an Attribute
	   needs to be maintained. */

	if (m_variant && *m_variant != qvariant)
	{
		if (m_variant->typeName() == qvariant.typeName())
			*m_variant = qvariant;
		else
		{
			if (retain_type)
			{
				if (QString(m_variant->typeName()) == "bool")
					*m_variant = QVariant::fromValue(qvariant.value<bool>());

				else if (QString(m_variant->typeName()) == "double")
					*m_variant = QVariant::fromValue(qvariant.value<double>());

				else if (QString(m_variant->typeName()) == "QColor")
					*m_variant = QVariant::fromValue(qvariant.value<QColor>());

				else if (QString(m_variant->typeName()) == "QList<std::pair<double,QColor>>")
					*m_variant = QVariant::fromValue(qvariant.value<QGradientStops>());

				else if (QString(m_variant->typeName()) == "QString")
					*m_variant = QVariant::fromValue(qvariant.value<QString>());
			}
			else *m_variant = qvariant;
		}
		
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
		/* TODO: A stateful attribute can have variants with different value
		   types. But this function only returns one typename, so there's a
		   chance it will not work properly. */
		return (*m_state_variant_map)[m_state].typeName();
	else
		return m_variant->typeName();
}

QJsonObject Attribute::to_json_object()
{
	QJsonObject json_object;

	json_object.insert("name", m_name);
	if (m_disabled) json_object.insert("disabled", m_disabled);

	if (is_stateful())
	{
		QJsonObject value_json_object;

		QJsonObject state_value_pairs_json_object;

		for (const QString& state : m_state_variant_map->keys())
		{
			QJsonValue insert_value;

			Variant& variant = (*m_state_variant_map)[state];

			if (QString(variant.typeName()) == "bool")
				insert_value = QJsonValue(variant.value<bool>());

			else if (QString(variant.typeName()) == "double")
				insert_value = QJsonValue(variant.value<double>());

			else if (QString(variant.typeName()) == "QColor")
			{
				QColor color = variant.value<QColor>();

				if (color.alpha() == 255)
					insert_value = QJsonValue(variant.value<QColor>().name());
				else
					insert_value = QJsonValue(variant.value<QColor>().name(QColor::HexArgb));
			}

			else if (QString(variant.typeName()) == "QList<std::pair<double,QColor>>")
			{
				QJsonObject gradient_wrapper_json_object;

				QJsonObject gradient_json_object;

				QGradientStops gradient_stops = variant.value<QGradientStops>();

				int stop_counter = 1;

				for (const QGradientStop& gradient_stop : gradient_stops)
				{
					QJsonObject gradient_stop_json_object;

					gradient_stop_json_object.insert("point", gradient_stop.first);
					gradient_stop_json_object.insert("color", gradient_stop.second.name());

					gradient_json_object.insert(QString("stop-") + QString::number(stop_counter++), gradient_stop_json_object);
				}

				gradient_wrapper_json_object.insert("gradient", gradient_json_object);

				insert_value = gradient_wrapper_json_object;
			}

			state_value_pairs_json_object.insert(state, insert_value);
		}

		value_json_object.insert("state_value_pairs", state_value_pairs_json_object);

		json_object.insert("value", value_json_object);
	}
	else
	{
		QJsonValue insert_value;

		if (QString(m_variant->typeName()) == "bool")
			insert_value = QJsonValue(m_variant->value<bool>());

		else if (QString(m_variant->typeName()) == "double")
			insert_value = QJsonValue(m_variant->value<double>());

		else if (QString(m_variant->typeName()) == "QColor")
		{
			QColor color = m_variant->value<QColor>();

			if (color.alpha() == 255)
				insert_value = QJsonValue(m_variant->value<QColor>().name());
			else
				insert_value = QJsonValue(m_variant->value<QColor>().name(QColor::HexArgb));
		}
		else if (QString(m_variant->typeName()) == "QList<std::pair<double,QColor>>")
		{
			QJsonObject gradient_wrapper_json_object;

			QJsonObject gradient_json_object;

			QGradientStops gradient_stops = m_variant->value<QGradientStops>();

			int stop_counter = 1;

			for (const QGradientStop& gradient_stop : gradient_stops)
			{
				QJsonObject gradient_stop_json_object;

				gradient_stop_json_object.insert("point", gradient_stop.first);
				gradient_stop_json_object.insert("color", gradient_stop.second.name());

				gradient_json_object.insert(QString("stop-") + QString::number(stop_counter++), gradient_stop_json_object);
			}

			gradient_wrapper_json_object.insert("gradient", gradient_json_object);

			insert_value = gradient_wrapper_json_object;
		}

		json_object.insert("value", insert_value);
	}

	return json_object;
}

Variant* Attribute::variant() const
{
	return m_variant;
}
