#include "../../../include/Attribute.h"

using Layers::Attribute;
using Layers::Variant;

Attribute::Attribute(const QString& name, bool disabled) :
	Entity(name, disabled) { }

Attribute::Attribute(const QString& name, QVariant qvariant, bool disabled) :
	m_data{ new Data(qvariant) }, Entity(name, disabled)
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
	disconnect(m_data_connection);
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
	disconnect(m_data_connection);
	m_data_connection = connect(
		m_data, &Data::changed, [this] { emit value_changed(); }
	);
}

void Attribute::entangle_with(Attribute& attribute)
{
	// TODO: Likely need to store this connection and disconnect in destructor
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

bool Attribute::is_stateful() const
{
	return m_data->is_stateful();
}

void Attribute::set_state(const QString& state)
{
	m_state = state;
}

void Attribute::set_value(QVariant qvariant, const QString& state)
{
	if (!is_stateful())
		m_data->set_value(qvariant);

	else
	{
		if (state == "")
			m_data->set_value(qvariant, m_state);
		else
			m_data->set_value(qvariant, state);
	}
}

void Attribute::setup_widget_update_connection(QWidget* widget)
{
	connect(this, &Entity::value_changed, [widget] { widget->update(); });
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
