#include "../../../include/Theme.h"
#include "../../../include/Themeable.h"

#include <QJsonObject>

using Layers::Attribute;
using Layers::Entity;
using Layers::Theme;
using Layers::Themeable;

Theme::Theme()
{
}

Theme::Theme(const QString& name, bool editable) :
	m_name{ name }, m_editable{ editable }, m_uuid{ new QUuid(QUuid::createUuid().toString()) }
{
}

Theme::Theme(const QString& name, QUuid* uuid, bool editable) :
	m_name{ name }, m_editable{ editable }, m_uuid{ uuid }
{
}

Theme::~Theme()
{
	for (const QString& themeable_tag : m_data.keys())
	{
		QMap<QString, Entity*>& themeable_data = m_data[themeable_tag];

		for (Entity* entity : themeable_data)
		{
			delete entity;
			entity = nullptr;
		}

		themeable_data.clear();
	}

	m_data.clear();

	if (m_uuid)
	{
		delete m_uuid;
		m_uuid = nullptr;
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
		for (Entity* entity : m_data[themeable_tag])
		{
			delete entity;

			entity = nullptr;
		}
	}

	m_data.clear();
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
		QMap<QString, Entity*>& themeable_data_in_theme =
			m_data[themeable_tag] = QMap<QString, Entity*>();

		for (const QString& entity_key : theme.m_data[themeable_tag].keys())
		{
			if (Attribute* theme_attr = dynamic_cast<Attribute*>(theme.m_data[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new Attribute(*theme_attr);
			else if (AttributeGroup* theme_attr_group = dynamic_cast<AttributeGroup*>(theme.m_data[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new AttributeGroup(*theme_attr_group);
		}
	}
}

void Theme::copy_attribute_values_of(Themeable* themeable)
{
	if (m_data.contains(themeable->tag()))
	{
		QMap<QString, Entity*>& themeable_data_in_theme = m_data[themeable->tag()];

		for (const QString& entity_key : themeable_data_in_theme.keys())
		{
			if (themeable->entities().contains(entity_key))
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(themeable->entities()[entity_key]))
					dynamic_cast<Attribute*>(themeable_data_in_theme[entity_key])->copy(*attr);
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable->entities()[entity_key]))
					dynamic_cast<AttributeGroup*>(themeable_data_in_theme[entity_key])->copy(*attr_group);
			}
		}
	}
	else
	{
		QMap<QString, Entity*> new_themeable_data_for_theme;

		for (const QString& entity_key : themeable->entities().keys())
		{
			if (Attribute* attr = dynamic_cast<Attribute*>(themeable->entities()[entity_key]))
			{
				if (!attr->is_entangled())
					new_themeable_data_for_theme[entity_key] = new Attribute(*attr);
			}
			else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable->entities()[entity_key]))
			{
				new_themeable_data_for_theme[entity_key] = new AttributeGroup(*attr_group);
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
	if (m_uuid)
		return m_name + "_" + m_uuid->toString(QUuid::WithoutBraces);
	else
		return m_name;
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

void Theme::load_document(const QJsonDocument& json_document)
{
	QJsonObject json_object = json_document.object();

	for (const QString& themeable_tag : json_object.keys())
	{
		QJsonObject themeable_object = json_object.value(themeable_tag).toObject();

		QMap<QString, Entity*> themeable_attributes;

		for (const QString& entity_key : themeable_object.keys())
		{
			QJsonObject entity_object = themeable_object.value(entity_key).toObject();

			QString entity_name = entity_key;
			bool entity_disabled = false;

			if (entity_object.contains("disabled"))
			{
				if (entity_object.value("disabled").toBool())
					entity_disabled = true;

				entity_object.remove("disabled");
			}

			// If entity_object contains key 'value', then it is an attribute, not a group
			if (entity_object.contains("value"))
			{
				themeable_attributes[entity_key] =
					init_attribute(
						entity_name, entity_disabled,
						entity_object.value("value"));
			}
			else // entity_object is a group...
			{
				QMap<QString, Attribute*> group_attributes;

				for (const QString& group_attr_key : entity_object.keys())
				{
					QJsonObject group_attr_object = entity_object.value(group_attr_key).toObject();

					group_attributes[group_attr_key] =
						init_attribute(
							group_attr_key, false,
							group_attr_object.value("value"));
				}

				AttributeGroup* attr_group = new AttributeGroup(entity_name, entity_disabled);

				attr_group->attributes() = group_attributes;

				themeable_attributes[entity_key] = attr_group;
			}
		}

		m_data[themeable_tag] = themeable_attributes;
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

		QMap<QString, Entity*>& themeable_data_in_theme = m_data[themeable_tag];

		QJsonObject themeable_json_object;

		for (const QString& entity_key : themeable_data_in_theme.keys())
		{
			if (Attribute* attr = dynamic_cast<Attribute*>(themeable_data_in_theme[entity_key]))
				themeable_json_object.insert(entity_key, attr->to_json_object());
			else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable_data_in_theme[entity_key]))
				themeable_json_object.insert(entity_key, attr_group->to_json_object());
		}

		data_json_object.insert(themeable_tag, themeable_json_object);
	}

	json_object.insert("data", data_json_object);

	json_document.setObject(json_object);

	return json_document;
}

QMap<QString, Entity*>& Theme::operator[](const QString& themeable_tag)
{
	return m_data[themeable_tag];
}
