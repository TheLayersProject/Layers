#include <Layers/lattribute.h>

#include <QGradientStops>
#include <QJsonArray>
#include <QJsonObject>

#include <Layers/lapplication.h>

using Layers::LAttribute;
using Layers::LAttributeList;
using Layers::LAttributeMap;

LAttribute::LAttribute(const QString& name, QObject* parent) :
	m_name{ name },
	QObject(parent) { }

LAttribute::LAttribute(const QString& name, QVariant value, QObject* parent) :
	m_value{ value },
	m_name{ name },
	QObject(parent)
{
	connect(this, &LAttribute::changed, [this]
	{
		if (this->parent())
			if (LThemeable* t = dynamic_cast<LThemeable*>(this->parent()))
				t->update();
	});
}

LAttribute::LAttribute(const QString& name, QJsonObject json_object, QObject* parent) :
	m_name{ name },
	QObject(parent)
{
	if (json_object.contains("linked_to"))
	{
		m_uplink_tag = json_object.value("linked_to").toString();

		m_value = QVariant();
	}
	else if (json_object.contains("value"))
	{
		QJsonValue json_value = json_object.value("value");

		if (json_value.isBool())
			m_value = QVariant::fromValue(json_value.toBool());

		else if (json_value.isDouble())
			m_value = QVariant::fromValue(json_value.toDouble());

		else if (json_value.isString())
		{
			QString value_str = json_value.toString();

			if (value_str.startsWith("#"))
				m_value = QVariant::fromValue(QColor(value_str));
		}
		else if (json_value.isObject())
		{
			QJsonObject value_object = json_value.toObject();

			if (value_object.contains("gradient"))
			{
				QJsonArray gradient_array = value_object.value("gradient").toArray();

				QGradientStops gradient_stops;

				for (QJsonValueConstRef array_value : gradient_array)
				{
					QString array_string = array_value.toString();

					QStringList string_parts = array_string.split(":");

					gradient_stops.append(
						QGradientStop(
							string_parts[0].toDouble(),
							string_parts[1]
						)
					);
				}

				m_value = QVariant::fromValue(gradient_stops);
			}
		}
	}
	
	if (json_object.contains("overrides"))
	{
		QJsonObject overrides_object =
			json_object.value("overrides").toObject();

		for (const QString& key : overrides_object.keys())
			m_overrides[key] =
				new LAttribute(key, overrides_object.value(key).toObject(), this);
	}
}

LAttribute::LAttribute(const LAttribute& attribute) :
	m_uplink_tag{ attribute.m_uplink_tag },
	m_name{ attribute.m_name },
	m_value{ attribute.m_value },
	QObject()
{
	if (!attribute.m_overrides.isEmpty())
		for (LAttribute* override_attr : attribute.m_overrides)
		{
			LAttribute* copy_override_attr = new LAttribute(*override_attr);

			copy_override_attr->setParent(this);

			m_overrides[override_attr->name()] = copy_override_attr;
		}
}

LAttribute::~LAttribute()
{
	QObject::disconnect(m_uplink_connection);

	if (m_uplink_attr)
	{
		if (m_uplink_attr->m_downlink_attributes.contains(this))
			m_uplink_attr->m_downlink_attributes.removeOne(this);

		m_uplink_attr = nullptr;
	}
}

void LAttribute::add_override(const QString& name, QVariant value)
{
	LAttribute* override_attr = new LAttribute(name, value, this);

	m_overrides[name] = override_attr;

	connect(override_attr, &LAttribute::changed, [this]
		{ emit changed(); });
}

void LAttribute::clear_overrides()
{
	if (!m_overrides.isEmpty())
	{
		for (LAttribute* override_attr : m_overrides)
			delete override_attr;

		m_overrides.clear();
	}
}

void LAttribute::copy(const LAttribute& attribute)
{
	clear_overrides();

	m_uplink_tag = attribute.m_uplink_tag;
	m_value = attribute.m_value;

	if (!attribute.m_overrides.isEmpty())
		for (LAttribute* override_attr : attribute.m_overrides)
		{
			LAttribute* copy_override_attr = new LAttribute(override_attr->name());
			copy_override_attr->copy(*override_attr);
			copy_override_attr->setParent(this);

			connect(copy_override_attr, &LAttribute::changed, [this]
				{ emit changed(); });

			m_overrides[override_attr->name()] = copy_override_attr;
		}
	
	emit changed();
}

LAttributeList LAttribute::downlink_attributes() const
{
	return m_downlink_attributes;
}

bool LAttribute::has_overrides() const
{
	return !m_overrides.isEmpty();
}

QString LAttribute::name() const
{
	return m_name;
}

LAttributeMap LAttribute::overrides() const
{
	return m_overrides;
}

void LAttribute::resolve_uplink()
{
	if (!m_uplink_tag.isEmpty())
		if (LAttribute* uplink_attr = layersApp->attribute(m_uplink_tag))
			set_uplink_attribute(uplink_attr);

	emit changed();
}

void LAttribute::set_uplink_attribute(LAttribute* uplink_attr)
{
	m_value = QVariant();

	QObject::disconnect(m_uplink_connection);

	if (m_uplink_attr)
	{
		if (m_uplink_attr->m_downlink_attributes.contains(this))
			m_uplink_attr->m_downlink_attributes.removeOne(this);

		m_uplink_attr = nullptr;
	}

	m_uplink_attr = uplink_attr;

	m_uplink_attr->m_downlink_attributes.append(this);

	establish_uplink_connection();

	emit linked();
	emit changed();
}

void LAttribute::set_value(QVariant value)
{
	if (m_uplink_attr)
		m_uplink_attr->set_value(value);
	else if (m_value != value)
		m_value = value;

	emit changed();
}

QString LAttribute::tag() const
{
	if (parent())
	{
		if (LAttribute* parent_attr = dynamic_cast<LAttribute*>(parent()))
			return parent_attr->tag() + "." + m_name;
		else if (LThemeable* parent_themeable = dynamic_cast<LThemeable*>(parent()))
			return parent_themeable->tag() + "/" + m_name;
	}
		
	return m_name;
}

const char* LAttribute::typeName() const
{
	if (m_uplink_attr)
		return m_uplink_attr->typeName();

	return m_value.typeName();
}

QJsonObject LAttribute::to_json_object()
{
	qDebug() << "Name:" << m_name;

	QJsonObject json_object;

	if (!m_uplink_tag.isEmpty())
	{
		qDebug() << "### ATTRIBUTE LINKED ###";
		qDebug() << "Name:" << m_name;

		json_object.insert("linked_to", m_uplink_tag);
	}
	else if (m_value.isValid())
	{
		json_object.insert("value", to_json_value());
	}

	if (has_overrides())
	{
		QJsonObject overrides_json_object;

		for (LAttribute* override_attr : m_overrides)
			overrides_json_object.insert(
				override_attr->name(), override_attr->to_json_object());

		json_object.insert("overrides", overrides_json_object);
	}

	return json_object;
}

QJsonValue LAttribute::to_json_value()
{
	QJsonValue json_value;

	if (QString(typeName()) == "bool")
		json_value = QJsonValue(m_value.value<bool>());

	else if (QString(typeName()) == "double")
		json_value = QJsonValue(m_value.value<double>());

	else if (QString(typeName()) == "QString")
		json_value = QJsonValue(m_value.value<QString>());

	else if (QString(typeName()) == "QColor")
	{
		QColor color = m_value.value<QColor>();

		if (color.alpha() == 255)
			json_value = QJsonValue(color.name());
		else
			json_value = QJsonValue(color.name(QColor::HexArgb));
	}
	else if (QString(typeName()) == "QList<std::pair<double,QColor>>")
	{
		QJsonObject gradient_json_object;
		QJsonArray gradient_json_array;

		QGradientStops gradient_stops = m_value.value<QGradientStops>();

		for (const QGradientStop& stop : gradient_stops)
		{
			QString stop_string =
				QString::number(stop.first) + ":" + stop.second.name();

			gradient_json_array.append(QJsonValue(stop_string));
		}

		gradient_json_object.insert("gradient", gradient_json_array);

		json_value = gradient_json_object;
	}

	return json_value;
}

LAttribute* LAttribute::uplink_attribute() const
{
	return m_uplink_attr;
}

void LAttribute::establish_uplink_connection()
{
	QObject::disconnect(m_uplink_connection);

	m_uplink_connection = connect(m_uplink_attr, &LAttribute::changed,
		[this] { emit changed(); });
}
