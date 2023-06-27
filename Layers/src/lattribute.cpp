#include <Layers/lattribute.h>

#include <QGradientStops>
#include <QJsonArray>
#include <QJsonObject>

#include <Layers/lapplication.h>

using Layers::LAttribute;

LAttribute::LAttribute(const QString& name) :
	m_name{ name },
	QObject() { }

LAttribute::LAttribute(const QString& name, QVariant value) :
	m_value{ value },
	m_name{ name },
	QObject()
{
	establish_link_connection();
}

LAttribute::LAttribute(const QString& name, QJsonObject json_object) :
	m_name{ name },
	QObject()
{
	if (json_object.contains("linked_to"))
	{
		m_link = json_object.value("linked_to").toString();

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
				new LAttribute(key, overrides_object.value(key).toObject());
	}

	establish_link_connection();
}

LAttribute::LAttribute(const LAttribute& attribute) :
	m_link{ attribute.m_link },
	m_name{ attribute.m_name },
	m_value{ attribute.m_value },
	QObject()
{
	if (!attribute.m_overrides.isEmpty())
	{
		for (LAttribute* override_attr : attribute.m_overrides)
			m_overrides[override_attr->name()] = new LAttribute(*override_attr);
	}

	establish_link_connection();
}

LAttribute::~LAttribute()
{
	QObject::disconnect(m_link_connection);
}

void LAttribute::add_override(const QString& name, QVariant value)
{
	m_overrides[name] = new LAttribute(name, value);
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
	m_link = attribute.m_link;
	m_value = attribute.m_value;

	clear_overrides();

	if (!attribute.m_overrides.isEmpty())
	{
		for (LAttribute* override_attr : attribute.m_overrides)
			m_overrides[override_attr->name()] = new LAttribute(*override_attr);
	}
	
	emit changed();
}

void LAttribute::establish_link(LAttribute& attr)
{
	m_value = QVariant();

	clear_overrides();

	m_linked_attr = &attr;

	establish_link_connection();

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

bool LAttribute::has_overrides() const
{
	return !m_overrides.isEmpty();
}

QString LAttribute::name()
{
	return m_name;
}

void LAttribute::set_value(QVariant value)
{
	if (m_linked_attr)
		m_linked_attr->set_value(value);
	else if (m_value != value)
		m_value = value;

	emit changed();
}

const char* LAttribute::typeName() const
{
	if (m_linked_attr)
		return m_linked_attr->typeName();

	return m_value.typeName();
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

void LAttribute::establish_link_connection()
{
	QObject::disconnect(m_link_connection);

	m_link_connection = connect(m_linked_attr, &LAttribute::changed,
		[this] { emit changed(); });
}
