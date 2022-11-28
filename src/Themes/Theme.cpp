#include "../../../include/Theme.h"
#include "../../../include/Themeable.h"

#include <QJsonObject>

using Layers::Attribute;
using Layers::Theme;
using Layers::Themeable;

Theme::Theme()
{
}

Theme::Theme(const QString& name, bool is_custom) :
	m_name{ name }, m_is_custom{ is_custom }
{

}

Theme::Theme(const QJsonDocument& json_document)
{
	QJsonObject json_object = json_document.object();

	m_name = json_object.value("name").toString();

	QJsonObject data_object = json_object.value("data").toObject();

	for (const QString& themeable_tag : data_object.keys())
	{
		QJsonObject themeable_object = data_object.value(themeable_tag).toObject();

		QMap<QString, Attribute*> themeable_attributes;

		for (const QString& attr_key : themeable_object.keys())
		{
			QJsonObject attr_object = themeable_object.value(attr_key).toObject();

			QString attr_name = attr_object.value("name").toString();
			bool attr_disabled = false;
			
			if (attr_object.contains("disabled") && attr_object.value("disabled").toBool())
				attr_disabled = true;

			QJsonValue attr_value = attr_object.value("value");

			if (attr_value.isObject())
			{
				QJsonObject attr_value_object = attr_value.toObject();

				if (attr_value_object.contains("state_value_pairs")) // Is Stateful
				{
					QMap<QString, Variant> state_variant_map;

					QJsonObject state_value_pairs_object = attr_value_object.value("state_value_pairs").toObject();

					for (const QString& state : state_value_pairs_object.keys())
					{
						QJsonValue state_value = state_value_pairs_object.value(state);

						if (state_value.isBool())
							state_variant_map[state] = Variant(state_value.toBool());
						
						else if (state_value.isDouble())
							// TODO: Below implicitly converts double to int when constructing Variant!
							state_variant_map[state] = Variant(state_value.toDouble());

						else if (state_value.isString())
						{
							QString state_value_str = state_value.toString();

							if (state_value_str.startsWith("#"))
								state_variant_map[state] = Variant(QColor(state_value_str));
						}
						else if (state_value.isObject())
						{
							QJsonObject state_value_object = state_value.toObject();

							if (state_value_object.contains("gradient"))
							{
								QJsonObject gradient_object = state_value_object.value("gradient").toObject();

								QGradientStops gradient_stops;

								for (const QJsonValue& stop : gradient_object)
								{
									QJsonObject stop_object = stop.toObject();

									gradient_stops.append(
										QGradientStop(
											stop_object.value("point").toDouble(),
											stop_object.value("color").toString()
										)
									);
								}

								state_variant_map[state] = Variant(QVariant::fromValue(gradient_stops));
							}
						}
					}

					themeable_attributes[attr_key] =
						new Attribute(attr_name, state_variant_map, attr_disabled);
				}
				else if (attr_value_object.contains("gradient"))
				{
					QJsonObject gradient_object = attr_value_object.value("gradient").toObject();

					QGradientStops gradient_stops;

					for (const QJsonValue& stop : gradient_object)
					{
						QJsonObject stop_object = stop.toObject();

						gradient_stops.append(
							QGradientStop(
								stop_object.value("point").toDouble(),
								stop_object.value("color").toString()
							)
						);
					}

					themeable_attributes[attr_key] =
						new Attribute(attr_name,
							QVariant::fromValue(gradient_stops), attr_disabled);
				}
			}
			else if (attr_value.isBool())
				themeable_attributes[attr_key] =
					new Attribute(attr_name,
						QVariant::fromValue(attr_value.toBool()), attr_disabled);

			else if (attr_value.isDouble())
				themeable_attributes[attr_key] =
					new Attribute(attr_name,
						QVariant::fromValue(attr_value.toDouble()), attr_disabled);

			else if (attr_value.isString())
			{
				QString value_str = attr_value.toString();

				if (value_str.startsWith("#"))
					themeable_attributes[attr_key] =
						new Attribute(attr_name,
							QVariant::fromValue(QColor(value_str)), attr_disabled);
			}
		}

		m_data[themeable_tag] = themeable_attributes;
	}
}

void Theme::add_attributes(const QString& themeable_tag, QMap<QString, Attribute*> attributes)
{
	if (!m_data.contains(themeable_tag))
		m_data[themeable_tag] = attributes;
}

void Theme::clear()
{
	for (const QString& themeable_tag : m_data.keys())
	{
		for (Attribute* attr : m_data[themeable_tag])
		{
			delete attr;

			attr = nullptr;
		}
	}

	m_data.clear();
}

void Theme::consume(Theme&& theme)
{
	m_data.insert(theme.m_data);

	//for (const QString& themeable_tag : theme.m_data.keys())
	//{
	//	//if (!m_data.contains(themeable_tag))
	//	
	//	m_data[themeable_tag] = theme.m_data[themeable_tag];

	//	//AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	//	//for (Attribute* attr : theme.attribute_sets()[themeable_tag].attributes())
	//	//	if (!attribute_set.contains(attr->name()))
	//	//		attribute_set.add_attribute(attr);
	//}

	//for (const QString& themeable_tag : theme.attribute_sets().keys())
	//{
	//	if (!m_attribute_sets.contains(themeable_tag))
	//		m_attribute_sets[themeable_tag] = AttributeSet();

	//	AttributeSet& attribute_set = m_attribute_sets[themeable_tag];

	//	for (Attribute* attr : theme.attribute_sets()[themeable_tag].attributes())
	//		if (!attribute_set.contains(attr->name()))
	//			attribute_set.add_attribute(attr);
	//}
}

bool Theme::contains_attributes_for_tag(const QString& themeable_tag)
{
	return m_data.contains(themeable_tag);
}

void Theme::copy_from(Theme& theme)
{
	clear();

	for (const QString& themeable_tag : theme.m_data.keys())
	{
		QMap<QString, Attribute*>& themeable_data_in_theme =
			m_data[themeable_tag] = QMap<QString, Attribute*>();

		for (const QString& attr_key : theme.m_data[themeable_tag].keys())
		{
			themeable_data_in_theme[attr_key] = new Attribute(*theme.m_data[themeable_tag][attr_key]);
		}
	}
}

void Theme::copy_attribute_values_of(Themeable* themeable)
{
	if (m_data.contains(themeable->tag()))
	{
		QMap<QString, Attribute*>& themeable_data_in_theme = m_data[themeable->tag()];

		for (const QString& attr_key : themeable_data_in_theme.keys())
		{
			if (themeable->attributes().contains(attr_key))
			{
				themeable_data_in_theme[attr_key]->copy_value_from(
					*themeable->attributes()[attr_key]);
			}
		}
	}
	else
	{
		QMap<QString, Attribute*> new_attributes;

		for (const QString& attr_key : themeable->attributes().keys())
		{
			if (themeable->attributes()[attr_key]->owns_variant())
				new_attributes[attr_key] = new Attribute(*themeable->attributes()[attr_key]);
		}

		m_data[themeable->tag()] = new_attributes;
	}
}

bool Theme::is_custom()
{
	return m_is_custom;
}

QString& Theme::name()
{
	return m_name;
}

void Theme::set_name(const QString& new_name)
{
	m_name = new_name;
}

QList<QString> Theme::themeable_tags()
{
	return m_data.keys();
}

QJsonDocument Theme::to_json_document()
{
	QJsonDocument json_document;

	QJsonObject json_object;

	json_object.insert("name", m_name);

	QJsonObject data_json_object;

	for (const QString& themeable_tag : m_data.keys())
	{
		QMap<QString, Attribute*>& themeable_data_in_theme = m_data[themeable_tag];

		QJsonObject themeable_json_object;

		for (const QString& attr_key : themeable_data_in_theme.keys())
		{
			themeable_json_object.insert(attr_key, themeable_data_in_theme[attr_key]->to_json_object());
		}

		data_json_object.insert(themeable_tag, themeable_json_object);

		//json_object.insert(themeable_tag, QJsonValue());
	}

	json_object.insert("data", data_json_object);

	json_document.setObject(json_object);

	return json_document;
}

QMap<QString, Attribute*>& Theme::operator[](const QString& themeable_tag)
{
	return m_data[themeable_tag];
}
