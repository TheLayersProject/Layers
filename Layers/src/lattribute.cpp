#include <Layers/lattribute.h>

#include <Layers/lapplication.h>

using Layers::LAttribute;
using Layers::LVariant;

LAttribute::LAttribute(const QString& name) :
	m_data{ new LData(LVariant()) },
	m_name{ name },
	QObject() { }

LAttribute::LAttribute(const QString& name, LVariant variant) :
	m_data{ new LData(variant) },
	m_name{ name },
	QObject()
{
	establish_data_connection();
}

LAttribute::LAttribute(const QString& name, LVariantMap variant_map) :
	m_data{ new LData(variant_map) },
	m_name{ name },
	m_state{ variant_map.firstKey() },
	QObject()
{
	establish_data_connection();
}

LAttribute::LAttribute(const QString& name, QJsonObject json_object) :
	m_data{ new LData(json_object) },
	m_name{ name },
	QObject()
{
	if (json_object.contains("linked_to"))
		m_link = json_object.value("linked_to").toString();

	establish_data_connection();
}

LAttribute::LAttribute(const LAttribute& attribute) :
	m_link{ attribute.m_link },
	m_data{ new LData(*attribute.m_data) },
	m_name{ attribute.m_name },
	QObject()
{
	establish_data_connection();
}

LAttribute::~LAttribute()
{
	QObject::disconnect(m_data_connection);
	QObject::disconnect(m_reentanglement_connection);

	if (!m_link_established)
		delete m_data;
}

bool LAttribute::contains_state(const QString& state) const
{
	return m_data->contains_state(state);
}

void LAttribute::copy(const LAttribute& attribute)
{
	if (!attribute.m_link.isEmpty())
		m_link = attribute.m_link;

	m_data->copy(*attribute.m_data);

	if (m_data->is_multi_valued() && m_state.isEmpty())
		m_state = m_data->states().first();
	
	emit changed();
}

void LAttribute::establish_link(LAttribute& attr)
{
	if (!m_link_established)
	{
		m_link_established = true;
		delete m_data;
	}

	m_data = attr.m_data;

	if (m_data->states().isEmpty() && m_state != "")
		m_state = "";
	else if (!m_data->states().isEmpty() && m_state == "")
		m_state = m_data->states().first();

	establish_data_connection();
	establish_reentanglement_connection(attr);

	emit linked();
	emit changed();
}

void LAttribute::set_link_new(const QString& link)
{
	m_link = link;

	LAttribute* link_attr = layersApp->attribute(link);

	if (link_attr)
		establish_link(*link_attr);
}

void LAttribute::init_variant_map(const LVariantMap& variant_map)
{
	m_data->init_variant_map(variant_map);

	m_state = variant_map.firstKey();
}

bool LAttribute::link_established() const
{
	return m_link_established;
}

bool LAttribute::is_multi_valued() const
{
	return m_data->is_multi_valued();
}

QString LAttribute::name()
{
	return m_name;
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
	qDebug() << "Name:" << m_name;

	QJsonObject json_object;

	if (!m_link.isEmpty())
	{
		qDebug() << "### ATTRIBUTE LINKED ###";
		qDebug() << "Name:" << m_name;

		json_object.insert("linked_to", m_link);
	}
	else
		json_object = m_data->to_json_object();

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
		&attribute, &LAttribute::linked, [this, &attribute]
		{ establish_link(attribute); });
}
