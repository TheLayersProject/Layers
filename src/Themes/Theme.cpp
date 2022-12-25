#include "../../../include/Theme.h"
#include "../../../include/Themeable.h"

#include <QJsonObject>

using Layers::Attribute;
using Layers::AttributeType;
using Layers::Theme;
using Layers::Themeable;

Theme::Theme()
{
}

Theme::Theme(const QString& name, bool editable) :
	m_name{ name }, m_editable{ editable }, m_uuid{ new QUuid(QUuid::createUuid().toString()) }
{
}

Theme::Theme(const QJsonDocument& json_document, QUuid* uuid) :
	m_uuid{ uuid }
{
	QJsonObject json_object = json_document.object();

	m_name = json_object.value("name").toString();

	if (json_object.contains("editable"))
		m_editable = json_object.value("editable").toBool();

	QJsonObject data_object = json_object.value("data").toObject();

	for (const QString& themeable_tag : data_object.keys())
	{
		QJsonObject themeable_object = data_object.value(themeable_tag).toObject();

		QMap<QString, AttributeType*> themeable_attributes;

		for (const QString& attr_type_key : themeable_object.keys())
		{
			QJsonObject attr_type_object = themeable_object.value(attr_type_key).toObject();

			QString attr_type_name = attr_type_key;
			bool attr_type_disabled = false;
			
			if (attr_type_object.contains("disabled"))
			{
				if (attr_type_object.value("disabled").toBool())
					attr_type_disabled = true;

				attr_type_object.remove("disabled");
			}

			// If attr_type_object contains key 'value', then it is an attribute, not a group
			if (attr_type_object.contains("value"))
			{
				themeable_attributes[attr_type_key] =
					init_attribute(
						attr_type_name, attr_type_disabled,
						attr_type_object.value("value"));
			}
			else // attr_type_object is a group...
			{
				QMap<QString, Attribute*> group_attributes;

				for (const QString& group_attr_key : attr_type_object.keys())
				{
					QJsonObject group_attr_object = attr_type_object.value(group_attr_key).toObject();

					group_attributes[group_attr_key] =
						init_attribute(
							group_attr_key, false,
							group_attr_object.value("value"));
				}

				themeable_attributes[attr_type_key] =
					new AttributeGroup(attr_type_name, group_attributes, attr_type_disabled);
			}
		}

		m_data[themeable_tag] = themeable_attributes;
	}
}

//void Theme::add_attributes(const QString& themeable_tag, QMap<QString, Attribute*> attributes)
//{
//	if (!m_data.contains(themeable_tag))
//		m_data[themeable_tag] = attributes;
//}

void Theme::clear()
{
	for (const QString& themeable_tag : m_data.keys())
	{
		for (AttributeType* attr_type : m_data[themeable_tag])
		{
			delete attr_type;

			attr_type = nullptr;
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

void Theme::copy(Theme& theme)
{
	clear();

	for (const QString& themeable_tag : theme.m_data.keys())
	{
		QMap<QString, AttributeType*>& themeable_data_in_theme =
			m_data[themeable_tag] = QMap<QString, AttributeType*>();

		for (const QString& attr_type_key : theme.m_data[themeable_tag].keys())
		{
			if (Attribute* theme_attr = dynamic_cast<Attribute*>(theme.m_data[themeable_tag][attr_type_key]))
				themeable_data_in_theme[attr_type_key] = new Attribute(*theme_attr);
			else if (AttributeGroup* theme_attr_group = dynamic_cast<AttributeGroup*>(theme.m_data[themeable_tag][attr_type_key]))
				themeable_data_in_theme[attr_type_key] = new AttributeGroup(*theme_attr_group);
		}
	}
}

void Theme::copy_attribute_values_of(Themeable* themeable)
{
	if (m_data.contains(themeable->tag()))
	{
		QMap<QString, AttributeType*>& themeable_data_in_theme = m_data[themeable->tag()];

		for (const QString& attr_type_key : themeable_data_in_theme.keys())
		{ // HERE
			if (themeable->attributes().contains(attr_type_key))
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(themeable->attributes()[attr_type_key]))
					dynamic_cast<Attribute*>(themeable_data_in_theme[attr_type_key])->copy(*attr);
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable->attributes()[attr_type_key]))
					dynamic_cast<AttributeGroup*>(themeable_data_in_theme[attr_type_key])->copy(*attr_group);
			}
		}
	}
	else
	{
		/* TODO: Temporarily disabling this code which copys themeable data to the theme
		   even if the theme doesn't already contain attributes for the themeable. This will
		   need to be re-enabled! */ 
		QMap<QString, AttributeType*> new_themeable_data_for_theme;

		for (const QString& attr_type_key : themeable->attributes().keys())
		{
			if (Attribute* attr = dynamic_cast<Attribute*>(themeable->attributes()[attr_type_key]))
			{
				if (attr->owns_data())
					new_themeable_data_for_theme[attr_type_key] = new Attribute(*attr);
			}
			else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable->attributes()[attr_type_key]))
			{
				new_themeable_data_for_theme[attr_type_key] = new AttributeGroup(*attr_group);
			}
		}

		m_data[themeable->tag()] = new_themeable_data_for_theme;
	}
}

bool Theme::editable()
{
	return m_editable;
}

QString Theme::identifier()
{
	return m_name + "_" + m_uuid->toString(QUuid::WithoutBraces);
}

Attribute* Theme::init_attribute(const QString& name, bool disabled, const QJsonValue& attr_value)
{
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

			return new Attribute(name, state_variant_map, disabled);
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

			return new Attribute(name, QVariant::fromValue(gradient_stops), disabled);
		}
	}
	else if (attr_value.isBool())
		return new Attribute(name, QVariant::fromValue(attr_value.toBool()), disabled);

	else if (attr_value.isDouble())
		return new Attribute(name, QVariant::fromValue(attr_value.toDouble()), disabled);

	else if (attr_value.isString())
	{
		QString value_str = attr_value.toString();

		if (value_str.startsWith("#"))
			return new Attribute(name, QVariant::fromValue(QColor(value_str)), disabled);
	}
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

QJsonDocument Theme::to_json_document(ThemeDataType data_type)
{
	QJsonDocument json_document;

	QJsonObject json_object;

	json_object.insert("name", m_name);

	QJsonObject data_json_object;

	for (const QString& themeable_tag : m_data.keys())
	{
		if (
			(data_type == ThemeDataType::Application && themeable_tag.startsWith("layers/")) ||
			(data_type == ThemeDataType::Layers && !themeable_tag.startsWith("layers/"))
			)
				continue;

		QMap<QString, AttributeType*>& themeable_data_in_theme = m_data[themeable_tag];

		QJsonObject themeable_json_object;

		for (const QString& attr_type_key : themeable_data_in_theme.keys())
		{
			if (Attribute* attr = dynamic_cast<Attribute*>(themeable_data_in_theme[attr_type_key]))
				themeable_json_object.insert(attr_type_key, attr->to_json_object());
			else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable_data_in_theme[attr_type_key]))
				themeable_json_object.insert(attr_type_key, attr_group->to_json_object());
		}

		data_json_object.insert(themeable_tag, themeable_json_object);

		//json_object.insert(themeable_tag, QJsonValue());
	}

	json_object.insert("data", data_json_object);

	json_document.setObject(json_object);

	return json_document;
}

QMap<QString, AttributeType*>& Theme::operator[](const QString& themeable_tag)
{
	return m_data[themeable_tag];
}
