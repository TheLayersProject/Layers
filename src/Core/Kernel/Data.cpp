#include "Data.h"

using Layers::Data;
using Layers::Variant;

Data::Data(Variant variant) :
	m_variant{ new Variant(variant) }
{
	connect(m_variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(VariantMap variant_map) :
	m_variant_map{ new VariantMap(variant_map) }
{
	for (const Variant& variant : *m_variant_map)
		connect(&variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(QJsonObject json_object)
{
	if (json_object.contains("value"))
	{
		m_variant = new Variant(json_object.value("value"));

		connect(m_variant, &Variant::changed, [this] { emit changed(); });
	}
	else if (json_object.contains("values"))
	{
		QJsonObject values_object = json_object.value("values").toObject();

		m_variant_map = new VariantMap;

		for (const QString& state : values_object.keys())
		{
			(*m_variant_map)[state] = Variant(values_object.value(state));

			connect(&(*m_variant_map)[state], &Variant::changed,
				[this] { emit changed(); });
		}
	}
}

Data::Data(const Data& data)
{
	if (data.m_variant)
		m_variant = new Variant(*data.m_variant);
	else
		m_variant_map = new VariantMap(*data.m_variant_map);
}

Data::~Data()
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}
	else if (m_variant_map)
	{
		delete m_variant_map;
		m_variant_map = nullptr;
	}
}

bool Data::contains_state(const QString& state) const
{
	if (m_variant_map)
		return m_variant_map->contains(state);

	return false;
}

void Data::copy(const Data& data)
{
	if (data.m_variant)
	{
		if (m_variant_map)
		{
			delete m_variant_map;
			m_variant_map = nullptr;

			m_variant = new Variant(*data.m_variant);

			connect(m_variant, &Variant::changed, [this] { emit changed(); });
		}
		else
			*m_variant = *data.m_variant;
	}
	else
	{
		if (m_variant)
		{
			delete m_variant;
			m_variant = nullptr;

			m_variant_map = new VariantMap(*data.m_variant_map);

			for (const Variant& variant : *m_variant_map)
				connect(&variant, &Variant::changed, [this] { emit changed(); });
		}
		else
			/*
				NOTE:The following does not check that the states match.
				Not sure if it needs to.
			*/
			for (const QString& state : m_variant_map->keys())
				(*m_variant_map)[state] = (*data.m_variant_map)[state];
	}
}

void Data::init_variant_map(const VariantMap& variant_map)
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}

	if (m_variant_map) m_variant_map->clear();
	else m_variant_map = new VariantMap();

	m_variant_map->insert(variant_map);

	for (const Variant& variant : *m_variant_map)
		connect(&variant, &Variant::changed, [this] { emit changed(); });
}

bool Data::is_multi_valued() const
{
	return m_variant_map;
}

void Data::set_value(Variant variant, const QString& state)
{
	if (m_variant && *m_variant != variant)
		*m_variant = variant;

	else if (m_variant_map)
	{
		if (state == "")
		{
			if ((*m_variant_map).first() != variant)
				(*m_variant_map).first() = variant;
		}
		else if (m_variant_map->contains(state))
		{
			if ((*m_variant_map)[state] != variant)
				(*m_variant_map)[state] = variant;
		}
		else qDebug() << "WARNING: Data::set_value() failed: State does not exist.";
	}
}

QStringList Data::states() const
{
	if (m_variant_map)
		return m_variant_map->keys();

	return QStringList();
}

QJsonObject Data::to_json_object()
{
	QJsonObject json_object;

	if (is_multi_valued())
	{
		QJsonObject values_json_object;

		for (const QString& state : m_variant_map->keys())
			values_json_object.insert(
				state, (*m_variant_map)[state].to_json_value());

		json_object.insert("values", values_json_object);
	}
	else
		json_object.insert("value", m_variant->to_json_value());

	return json_object;
}

const char* Data::typeName() const
{
	if (m_variant_map)
		/* NOTE: Stateful Data could have Variants with different value
		   types. But this function only returns one typename, so there's a
		   chance it will not work properly. */
		return (*m_variant_map).first().typeName();
	else
		return m_variant->typeName();
}
