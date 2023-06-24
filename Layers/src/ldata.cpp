#include <Layers/ldata.h>

using Layers::LData;
using Layers::LVariant;

LData::LData(LVariant variant) :
	m_variant{ new LVariant(variant) }
{
	connect(m_variant, &LVariant::changed, [this] { emit changed(); });
}

LData::LData(LVariantMap variant_map) :
	m_variant_map{ new LVariantMap(variant_map) }
{
	for (const LVariant& variant : *m_variant_map)
		connect(&variant, &LVariant::changed, [this] { emit changed(); });
}

LData::LData(QJsonObject json_object)
{
	if (json_object.contains("value"))
	{
		m_variant = new LVariant(json_object.value("value"));

		connect(m_variant, &LVariant::changed, [this] { emit changed(); });
	}
	else if (json_object.contains("values"))
	{
		QJsonObject values_object = json_object.value("values").toObject();

		m_variant_map = new LVariantMap;

		for (const QString& state : values_object.keys())
		{
			(*m_variant_map)[state] = LVariant(values_object.value(state));

			connect(&(*m_variant_map)[state], &LVariant::changed,
				[this] { emit changed(); });
		}
	}
	else if (json_object.contains("linked_to"))
	{
		m_variant = new LVariant(0.0);

		connect(m_variant, &LVariant::changed, [this] { emit changed(); });
	}
}

LData::LData(const LData& data)
{
	if (data.m_variant)
		m_variant = new LVariant(*data.m_variant);
	else
		m_variant_map = new LVariantMap(*data.m_variant_map);
}

LData::~LData()
{
	if (m_variant)
		delete m_variant;
	else if (m_variant_map)
		delete m_variant_map;
}

bool LData::contains_state(const QString& state) const
{
	if (m_variant_map)
		return m_variant_map->contains(state);

	return false;
}

void LData::copy(const LData& data)
{
	if (data.m_variant)
	{
		if (m_variant_map)
		{
			delete m_variant_map;
			m_variant_map = nullptr;

			m_variant = new LVariant(*data.m_variant);

			connect(m_variant, &LVariant::changed, [this] { emit changed(); });
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

			m_variant_map = new LVariantMap(*data.m_variant_map);

			for (const LVariant& variant : *m_variant_map)
				connect(&variant, &LVariant::changed, [this] { emit changed(); });
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

void LData::init_variant_map(const LVariantMap& variant_map)
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}

	if (m_variant_map) m_variant_map->clear();
	else m_variant_map = new LVariantMap();

	m_variant_map->insert(variant_map);

	for (const LVariant& variant : *m_variant_map)
		connect(&variant, &LVariant::changed, [this] { emit changed(); });
}

bool LData::is_multi_valued() const
{
	return m_variant_map;
}

void LData::set_value(LVariant variant, const QString& state)
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

QStringList LData::states() const
{
	if (m_variant_map)
		return m_variant_map->keys();

	return QStringList();
}

QJsonObject LData::to_json_object()
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

const char* LData::typeName() const
{
	if (m_variant_map)
		/* NOTE: Stateful Data could have Variants with different value
		   types. But this function only returns one typename, so there's a
		   chance it will not work properly. */
		return (*m_variant_map).first().typeName();
	else
		return m_variant->typeName();
}
