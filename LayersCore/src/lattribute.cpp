#include <LayersCore/lattribute.h>

using Layers::LAttribute;
using Layers::LVariant;

LAttribute::LAttribute(const QString& name,
	bool disabled) :
	m_data{ new LData(LVariant()) },
	LAbstractAttribute(name, disabled) { }

LAttribute::LAttribute(const QString& name, LVariant variant,
	bool disabled) :
	m_data{ new LData(variant) },
	LAbstractAttribute(name, disabled)
{
	establish_data_connection();
}

LAttribute::LAttribute(const QString& name, LVariantMap variant_map,
	bool disabled) :
	m_data{ new LData(variant_map) },
	m_state{ variant_map.firstKey() },
	LAbstractAttribute(name, disabled)
{
	establish_data_connection();
}

LAttribute::LAttribute(const QString& name, QJsonObject json_object,
	bool disabled) :
	m_data{ new LData(json_object) },
	LAbstractAttribute(name, disabled)
{
	establish_data_connection();
}

LAttribute::LAttribute(const LAttribute& attribute) :
	LAbstractAttribute(attribute.m_name, attribute.m_disabled)
{
	m_data = new LData(*attribute.m_data);

	establish_data_connection();
}

LAttribute::~LAttribute()
{
	QObject::disconnect(m_data_connection);
	QObject::disconnect(m_reentanglement_connection);

	if (!m_is_entangled)
		delete m_data;
}

bool LAttribute::contains_state(const QString& state) const
{
	return m_data->contains_state(state);
}

void LAttribute::copy(const LAttribute& attribute)
{
	m_data->copy(*attribute.m_data);

	if (m_data->is_multi_valued() && m_state.isEmpty())
		m_state = m_data->states().first();

	m_disabled = attribute.m_disabled;
	
	emit changed();
}

void LAttribute::entangle_with(LAttribute& attribute)
{
	if (!m_is_entangled)
	{
		m_is_entangled = true;
		delete m_data;
	}

	m_data = attribute.m_data;

	if (m_data->states().isEmpty() && m_state != "")
		m_state = "";
	else if (!m_data->states().isEmpty() && m_state == "")
		m_state = m_data->states().first();

	establish_data_connection();
	establish_reentanglement_connection(attribute);

	emit entangled();
	emit changed();
}

void LAttribute::init_variant_map(const LVariantMap& variant_map)
{
	m_data->init_variant_map(variant_map);

	m_state = variant_map.firstKey();
}

bool LAttribute::is_entangled() const
{
	return m_is_entangled;
}

bool LAttribute::is_multi_valued() const
{
	return m_data->is_multi_valued();
}

void LAttribute::set_state(const QString& state)
{
	m_state = state;

	emit changed();
}

void LAttribute::set_value(LVariant variant, const QString& state)
{
	if (!is_multi_valued())
		m_data->set_value(variant);

	else
	{
		if (state == "")
			m_data->set_value(variant, m_state);
		else
			m_data->set_value(variant, state);
	}
}

QString LAttribute::state() const
{
	return m_state;
}

QStringList LAttribute::states() const
{
	return m_data->states();
}

const char* LAttribute::typeName() const
{
	return m_data->typeName();
}

QJsonObject LAttribute::to_json_object()
{
	QJsonObject json_object = m_data->to_json_object();

	if (m_disabled)
		json_object.insert("disabled", m_disabled);

	return json_object;
}

void LAttribute::establish_data_connection()
{
	QObject::disconnect(m_data_connection);
	m_data_connection = connect(
		m_data, &LData::changed, [this]
		{ emit changed(); });
}

void LAttribute::establish_reentanglement_connection(LAttribute& attribute)
{
	QObject::disconnect(m_reentanglement_connection);
	m_reentanglement_connection = connect(
		&attribute, &LAttribute::entangled, [this, &attribute]
		{ entangle_with(attribute); });
}
