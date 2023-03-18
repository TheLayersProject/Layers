#include "Attribute.h"

using Layers::Attribute;
using Layers::Variant;

Attribute::Attribute(const QString& name, bool disabled) :
	Entity(name, disabled) { }

Attribute::Attribute(const QString& name, Variant variant, bool disabled) :
	m_data{ new Data(variant) }, Entity(name, disabled)
{
	establish_data_connection();
}

Attribute::Attribute(const QString& name, VariantMap variant_map, bool disabled) :
	m_data{ new Data(variant_map) }, Entity(name, disabled)
{
	establish_data_connection();
}

Attribute::Attribute(const Attribute& a) : Entity(a.m_name, a.m_disabled)
{
	m_data = new Data(*a.m_data);

	establish_data_connection();
}

Attribute::~Attribute()
{
	QObject::disconnect(m_data_connection);

	QObject::disconnect(m_reentanglement_connection);

	if (!m_is_entangled)
	{
		delete m_data;
		m_data = nullptr;
	}
}

bool Attribute::contains_state(const QString& state) const
{
	return m_data->contains_state(state);
}

void Attribute::copy(const Attribute& attr)
{
	m_data->copy(*attr.m_data);

	m_disabled = attr.m_disabled;
	
	emit value_changed();
}

void Attribute::establish_data_connection()
{
	QObject::disconnect(m_data_connection);
	m_data_connection = connect(
		m_data, &Data::changed, [this] { emit value_changed(); }
	);
}

void Attribute::entangle_with(Attribute& attribute)
{
	QObject::disconnect(m_reentanglement_connection);
	m_reentanglement_connection = 
		connect(&attribute, &Attribute::entangled, [this, &attribute] {
			entangle_with(attribute);
		});

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

	emit entangled();
	emit value_changed();
}

void Attribute::init_variant_map(const VariantMap& variant_map)
{
	m_data->init_variant_map(variant_map);

	m_state = variant_map.firstKey();
}

bool Attribute::is_entangled() const
{
	return m_is_entangled;
}

bool Attribute::is_multi_valued() const
{
	return m_data->is_multi_valued();
}

void Attribute::set_state(const QString& state)
{
	m_state = state;

	emit value_changed();
}

void Attribute::set_value(Variant variant, const QString& state)
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

QString Attribute::state() const
{
	return m_state;
}

QStringList Attribute::states() const
{
	return m_data->states();
}

const char* Attribute::typeName() const
{
	return m_data->typeName();
}

QJsonObject Attribute::to_json_object()
{
	QJsonObject json_object = m_data->to_json_object();

	if (m_disabled)
		json_object.insert("disabled", m_disabled);

	return json_object;
}
