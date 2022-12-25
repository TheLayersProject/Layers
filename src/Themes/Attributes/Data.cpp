#include "../../../include/Data.h"

using Layers::Data;
using Layers::Variant;

Data::Data(QVariant qvariant) :
	m_variant{ new Variant(qvariant) }
{
	connect(m_variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(QMap<QString, Variant> state_variant_map) :
	m_state_variant_map{ new QMap<QString, Variant>(state_variant_map) }
{
	for (const Variant& variant : *m_state_variant_map)
		connect(&variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(const Data& d)
{
	if (d.m_variant)
		m_variant = new Variant(*d.m_variant);
	else
		m_state_variant_map =
			new QMap<QString, Variant>(*d.m_state_variant_map);
}

Data::~Data()
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}
	else if (m_state_variant_map)
	{
		delete m_state_variant_map;
		m_state_variant_map = nullptr;
	}
}

bool Data::contains_state(const QString& state) const
{
	if (m_state_variant_map)
		return m_state_variant_map->contains(state);

	return false;
}

void Data::copy(const Data& data)
{
	if (data.m_variant)
	{
		if (m_state_variant_map)
		{
			delete m_state_variant_map;

			m_state_variant_map = nullptr;

			m_variant = new Variant(*data.m_variant);
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

			m_state_variant_map = new QMap<QString, Variant>(*data.m_state_variant_map);
		}
		else
		{
			m_state_variant_map->clear();

			m_state_variant_map->insert(*data.m_state_variant_map);
		}
	}
}

void Data::init_state_variant_map(const QMap<QString, Variant>& state_variant_map)
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}

	if (m_state_variant_map) m_state_variant_map->clear();
	else m_state_variant_map = new QMap<QString, Variant>();

	m_state_variant_map->insert(state_variant_map);
}

bool Data::is_stateful() const
{
	if (m_state_variant_map)
		return !m_state_variant_map->isEmpty();

	return false;
}

void Data::set_value(QVariant qvariant, bool retain_type)
{
	/* Should this function still work with stateful data and just change
	   the variant associated with the current state? */

	/* NOTE: qvariant is explicitly converted to the type that this Data
		already stores. This is necessary because the initial type of Data values
		needs to be maintained. */

	if (m_variant && *m_variant != qvariant)
	{
		if (m_variant->typeName() == qvariant.typeName())
			*m_variant = qvariant;
		else
		{
			if (retain_type)
			{
				if (QString(m_variant->typeName()) == "bool")
					*m_variant = QVariant::fromValue(qvariant.value<bool>());

				else if (QString(m_variant->typeName()) == "double")
					*m_variant = QVariant::fromValue(qvariant.value<double>());

				else if (QString(m_variant->typeName()) == "QColor")
					*m_variant = QVariant::fromValue(qvariant.value<QColor>());

				else if (QString(m_variant->typeName()) == "QList<std::pair<double,QColor>>")
					*m_variant = QVariant::fromValue(qvariant.value<QGradientStops>());

				else if (QString(m_variant->typeName()) == "QString")
					*m_variant = QVariant::fromValue(qvariant.value<QString>());
			}
			else *m_variant = qvariant;
		}
	}
}

void Data::set_value(const QString& state, QVariant qvariant)
{
	if (m_state_variant_map)
	{
		if (m_state_variant_map->contains(state))
		{
			if ((*m_state_variant_map)[state] != qvariant)
			{
				(*m_state_variant_map)[state] = qvariant;
			}
		}
		else qDebug() << "WARNING: Failed to set attribute value: State does not exist.";
	}
	else qDebug() << "WARNING: Failed to set attribute value: State provided but Attribute is not stateful.";
}

QList<QString> Data::states() const
{
	if (m_state_variant_map)
		return m_state_variant_map->keys();

	return QList<QString>();
}

QJsonObject Data::to_json_object()
{
	QJsonObject json_object;

	if (is_stateful())
	{
		QJsonObject value_json_object;

		QJsonObject state_value_pairs_json_object;

		for (const QString& state : m_state_variant_map->keys())
		{
			QJsonValue insert_value;

			Variant& variant = (*m_state_variant_map)[state];

			if (QString(variant.typeName()) == "bool")
				insert_value = QJsonValue(variant.value<bool>());

			else if (QString(variant.typeName()) == "double")
				insert_value = QJsonValue(variant.value<double>());

			else if (QString(variant.typeName()) == "QColor")
			{
				QColor color = variant.value<QColor>();

				if (color.alpha() == 255)
					insert_value = QJsonValue(variant.value<QColor>().name());
				else
					insert_value = QJsonValue(variant.value<QColor>().name(QColor::HexArgb));
			}

			else if (QString(variant.typeName()) == "QList<std::pair<double,QColor>>")
			{
				QJsonObject gradient_wrapper_json_object;

				QJsonObject gradient_json_object;

				QGradientStops gradient_stops = variant.value<QGradientStops>();

				int stop_counter = 1;

				for (const QGradientStop& gradient_stop : gradient_stops)
				{
					QJsonObject gradient_stop_json_object;

					gradient_stop_json_object.insert("point", gradient_stop.first);
					gradient_stop_json_object.insert("color", gradient_stop.second.name());

					gradient_json_object.insert(QString("stop-") + QString::number(stop_counter++), gradient_stop_json_object);
				}

				gradient_wrapper_json_object.insert("gradient", gradient_json_object);

				insert_value = gradient_wrapper_json_object;
			}

			state_value_pairs_json_object.insert(state, insert_value);
		}

		value_json_object.insert("state_value_pairs", state_value_pairs_json_object);

		json_object.insert("value", value_json_object);
	}
	else
	{
		QJsonValue insert_value;

		if (QString(m_variant->typeName()) == "bool")
			insert_value = QJsonValue(m_variant->value<bool>());

		else if (QString(m_variant->typeName()) == "double")
			insert_value = QJsonValue(m_variant->value<double>());

		else if (QString(m_variant->typeName()) == "QColor")
		{
			QColor color = m_variant->value<QColor>();

			if (color.alpha() == 255)
				insert_value = QJsonValue(m_variant->value<QColor>().name());
			else
				insert_value = QJsonValue(m_variant->value<QColor>().name(QColor::HexArgb));
		}
		else if (QString(m_variant->typeName()) == "QList<std::pair<double,QColor>>")
		{
			QJsonObject gradient_wrapper_json_object;

			QJsonObject gradient_json_object;

			QGradientStops gradient_stops = m_variant->value<QGradientStops>();

			int stop_counter = 1;

			for (const QGradientStop& gradient_stop : gradient_stops)
			{
				QJsonObject gradient_stop_json_object;

				gradient_stop_json_object.insert("point", gradient_stop.first);
				gradient_stop_json_object.insert("color", gradient_stop.second.name());

				gradient_json_object.insert(QString("stop-") + QString::number(stop_counter++), gradient_stop_json_object);
			}

			gradient_wrapper_json_object.insert("gradient", gradient_json_object);

			insert_value = gradient_wrapper_json_object;
		}

		json_object.insert("value", insert_value);
	}

	return json_object;
}

const char* Data::typeName() const
{
	if (m_state_variant_map)
		/* NOTE: Stateful Data could have Variants with different value
		   types. But this function only returns one typename, so there's a
		   chance it will not work properly. */
		return (*m_state_variant_map)[m_state_variant_map->firstKey()].typeName();
	else
		return m_variant->typeName();
}
