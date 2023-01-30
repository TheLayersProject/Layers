#include "../../../include/Data.h"

using Layers::Data;
using Layers::Variant;

Data::Data(QVariant qvariant) :
	m_variant{ new Variant(qvariant) }
{
	connect(m_variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(VariantMap variant_map) :
	m_variant_map{ new VariantMap(variant_map) }
{
	for (const Variant& variant : *m_variant_map)
		connect(&variant, &Variant::changed, [this] { emit changed(); });
}

Data::Data(const Data& d)
{
	if (d.m_variant)
		m_variant = new Variant(*d.m_variant);
	else
		m_variant_map =
			new VariantMap(*d.m_variant_map);
}

Data::~Data()
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}
	else if (m_variant_map)
	{
		delete m_variant_map;
		m_variant_map = nullptr;
	}
}

bool Data::contains_state(const QString& state) const
{
	if (m_variant_map)
		return m_variant_map->contains(state);

	return false;
}

void Data::copy(const Data& data)
{
	if (data.m_variant)
	{
		if (m_variant_map)
		{
			delete m_variant_map;
			m_variant_map = nullptr;

			m_variant = new Variant(*data.m_variant);

			connect(m_variant, &Variant::changed, [this] { emit changed(); });
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

			m_variant_map = new VariantMap(*data.m_variant_map);

			for (const Variant& variant : *m_variant_map)
				connect(&variant, &Variant::changed, [this] { emit changed(); });
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

void Data::init_variant_map(const VariantMap& variant_map)
{
	if (m_variant)
	{
		delete m_variant;
		m_variant = nullptr;
	}

	if (m_variant_map) m_variant_map->clear();
	else m_variant_map = new VariantMap();

	m_variant_map->insert(variant_map);

	for (const Variant& variant : *m_variant_map)
		connect(&variant, &Variant::changed, [this] { emit changed(); });
}

bool Data::is_stateful() const
{
	//if (m_variant_map)
	//	return !m_variant_map->isEmpty();

	return m_variant_map;
}

//void Data::set_value(QVariant qvariant)
//{
//	/* Should this function still work with stateful data and just change
//	   the variant associated with the current state? */
//
//	if (m_variant && *m_variant != qvariant)
//		*m_variant = qvariant;
//}

void Data::set_value(QVariant qvariant, const QString& state)
{
	if (m_variant && *m_variant != qvariant)
		*m_variant = qvariant;

	else if (m_variant_map)
	{
		if (state == "")
		{
			if ((*m_variant_map).first() != qvariant)
				(*m_variant_map).first() = qvariant;
		}
		else if (m_variant_map->contains(state))
		{
			if ((*m_variant_map)[state] != qvariant)
				(*m_variant_map)[state] = qvariant;
		}
		else qDebug() << "WARNING: Data::set_value() failed: State does not exist.";
	}
}

QStringList Data::states() const
{
	if (m_variant_map)
		return m_variant_map->keys();

	return QStringList();
}

QJsonObject Data::to_json_object()
{
	QJsonObject json_object;

	if (is_stateful())
	{
		QJsonObject value_json_object;

		QJsonObject state_value_pairs_json_object;

		for (const QString& state : m_variant_map->keys())
		{
			QJsonValue insert_value;

			Variant& variant = (*m_variant_map)[state];

			if (QString(variant.typeName()) == "bool")
				insert_value = QJsonValue(variant.value<bool>());

			else if (QString(variant.typeName()) == "double")
				insert_value = QJsonValue(variant.value<double>());

			else if (QString(variant.typeName()) == "QString")
				insert_value = QJsonValue(variant.value<QString>());

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

		else if (QString(m_variant->typeName()) == "QString")
			insert_value = QJsonValue(m_variant->value<QString>());

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
	if (m_variant_map)
		/* NOTE: Stateful Data could have Variants with different value
		   types. But this function only returns one typename, so there's a
		   chance it will not work properly. */
		return (*m_variant_map)[m_variant_map->firstKey()].typeName();
	else
		return m_variant->typeName();
}
