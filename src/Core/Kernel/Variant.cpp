#include "Variant.h"

#include <QJsonArray>
#include <QJsonObject>

using Layers::Variant;

Variant::Variant() :
	m_qvariant{ QVariant() } { }

Variant::Variant(double value) :
	m_qvariant{ QVariant(value) } { }

Variant::Variant(const QColor& value) :
	m_qvariant{ QVariant(value) } { }

Variant::Variant(const QString& value) :
	m_qvariant{ QVariant(value) } { }

Variant::Variant(QVariant qvariant) :
	m_qvariant{ qvariant } { }

Variant::Variant(QJsonValue json_value)
{
	if (json_value.isBool())
		m_qvariant = QVariant::fromValue(json_value.toBool());

	else if (json_value.isDouble())
		m_qvariant = QVariant::fromValue(json_value.toDouble());

	else if (json_value.isString())
	{
		QString value_str = json_value.toString();

		if (value_str.startsWith("#"))
			m_qvariant = QVariant::fromValue(QColor(value_str));
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

			m_qvariant = QVariant::fromValue(gradient_stops);
		}
	} 
}

Variant::Variant(const Variant& variant)
{
	if (this != &variant)
		*this = variant.m_qvariant;
}

void Variant::operator=(const Variant& variant) {
	m_qvariant = variant.m_qvariant;

	emit changed();
}

bool Variant::operator!=(const Variant& variant) {
	return m_qvariant != variant.m_qvariant;
}

QJsonValue Variant::to_json_value()
{
	QJsonValue json_value;

	if (QString(typeName()) == "bool")
		json_value = QJsonValue(value<bool>());

	else if (QString(typeName()) == "double")
		json_value = QJsonValue(value<double>());

	else if (QString(typeName()) == "QString")
		json_value = QJsonValue(value<QString>());

	else if (QString(typeName()) == "QColor")
	{
		QColor color = value<QColor>();

		if (color.alpha() == 255)
			json_value = QJsonValue(color.name());
		else
			json_value = QJsonValue(color.name(QColor::HexArgb));
	}
	else if (QString(typeName()) == "QList<std::pair<double,QColor>>")
	{
		QJsonObject gradient_json_object;
		QJsonArray gradient_json_array;

		QGradientStops gradient_stops = value<QGradientStops>();

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

const char* Variant::typeName() const
{
	return m_qvariant.typeName();
}
