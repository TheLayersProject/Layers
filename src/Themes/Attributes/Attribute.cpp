#include "../../../include/Attribute.h"

using Layers::Attribute;
using Layers::Variant;

Attribute::Attribute(const QString& name, bool disabled) :
	AttributeType(name, disabled) { }

Attribute::Attribute(const QString& name, QVariant qvariant, bool disabled) :
	m_data{ new Data(qvariant) }, AttributeType(name, disabled)
{
	establish_data_connection();
}

Attribute::Attribute(const QString& name, QMap<QString, Variant> state_variant_map, bool disabled) :
	m_data{ new Data(state_variant_map) }, AttributeType(name, disabled)
{
	establish_data_connection();
}

Attribute::Attribute(const Attribute& a) : AttributeType(a.m_name, a.m_disabled)
{
	m_data = new Data(*a.m_data);

	establish_data_connection();
}

Attribute::~Attribute()
{
	disconnect(m_data_connection);
}

void Layers::Attribute::clear_data_if_owner()
{
	if (m_owns_data)
	{
		m_owns_data = false;

		delete m_data;
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
	disconnect(m_data_connection);
	m_data_connection = connect(
		m_data, &Data::changed, [this] { emit value_changed(); }
	);
}

void Attribute::get_data_from(Attribute& attribute)
{
	// TODO: Likely need to store this connection and disconnect in destructor
	connect(&attribute, &Attribute::ownership_changed, [this, &attribute] {
		get_data_from(attribute);
		});

	clear_data_if_owner();

	m_data = attribute.m_data;

	if (m_data->states().isEmpty() && m_state != "")
		m_state = "";
	else if (!m_data->states().isEmpty() && m_state == "")
		m_state = m_data->states().first();

	establish_data_connection();

	emit ownership_changed();
	emit value_changed();
}

void Attribute::init_state_variant_map(const QMap<QString, Variant>& state_variant_map)
{
	m_data->init_state_variant_map(state_variant_map);
}

bool Attribute::is_stateful() const
{
	return m_data->is_stateful();
}

bool Attribute::owns_data() const
{
	return m_owns_data;
}

void Attribute::set_state(const QString& state)
{
	m_state = state;
}

void Attribute::set_value(QVariant qvariant, bool retain_type)
{
	m_data->set_value(qvariant, retain_type);
}

void Attribute::set_value(const QString& state, QVariant qvariant)
{
	m_data->set_value(state, qvariant);
}

void Attribute::setup_widget_update_connection(QWidget* widget)
{
	connect(this, &AttributeType::value_changed, [widget] { widget->update(); });
}

QString Attribute::state() const
{
	return m_state;
}

QList<QString> Attribute::states() const
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
