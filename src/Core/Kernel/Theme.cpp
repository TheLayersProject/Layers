#include "Theme.h"

#include "Application.h"
#include "Themeable.h"

#include <QJsonArray>
#include <QJsonObject>

using Layers::AbstractAttribute;
using Layers::Attribute;
using Layers::AttributeGroup;
using Layers::Theme;
using Layers::Themeable;
using Layers::ThemeLineageData;
using Layers::Variant;

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

Theme::Theme(QDir dir) :
	m_dir{ dir }
{
	QFile meta_file(dir.filePath("meta.json"));

	if (meta_file.exists())
	{
		if (!meta_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme 'meta.json' file";

		QJsonDocument meta_doc = QJsonDocument::fromJson(meta_file.readAll());
		QJsonObject meta_obj = meta_doc.object();

		meta_file.close();

		m_name = meta_obj.value("name").toString();

		if (meta_obj.contains("uuid"))
			m_uuid = new QUuid(meta_obj.value("uuid").toString());

		if (meta_obj.contains("editable"))
			m_editable = meta_obj.value("editable").toBool();

		for (QJsonValue lineage_value : meta_obj.value("lineage").toArray())
			append_to_lineage(lineage_value.toString());
	}
}

Theme::~Theme()
{
	clear();

	if (m_uuid)
	{
		delete m_uuid;
		m_uuid = nullptr;
	}
}

void Theme::append_to_lineage(const QString& theme_id)
{
	m_lineage.append(theme_id);
}

void Theme::clear()
{
	for (const QString& themeable_tag : m_data_for_app_themeables.keys())
	{
		AttributeMap& themeable_data = m_data_for_app_themeables[themeable_tag];

		for (AbstractAttribute* entity : themeable_data)
		{
			delete entity;
			entity = nullptr;
		}

		themeable_data.clear();
	}

	for (const QString& themeable_tag : m_data_for_layers_themeables.keys())
	{
		AttributeMap& themeable_data = m_data_for_layers_themeables[themeable_tag];

		for (AbstractAttribute* entity : themeable_data)
		{
			delete entity;
			entity = nullptr;
		}

		themeable_data.clear();
	}


	m_data_for_app_themeables.clear();
	m_data_for_layers_themeables.clear();
}

void Theme::clear_data_for_themeable(const QString& themeable_tag)
{
	ThemeData* relevant_theme_data = nullptr;

	if (m_data_for_app_themeables.contains(themeable_tag))
		relevant_theme_data = &m_data_for_app_themeables;
	else if (m_data_for_layers_themeables.contains(themeable_tag))
		relevant_theme_data = &m_data_for_layers_themeables;

	if (relevant_theme_data)
	{
		AttributeMap& themeable_data = (*relevant_theme_data)[themeable_tag];

		for (AbstractAttribute* entity : themeable_data)
		{
			delete entity;
			entity = nullptr;
		}

		themeable_data.clear();

		relevant_theme_data->remove(themeable_tag);
	}
}

bool Theme::contains_attributes_for_tag(const QString& themeable_tag)
{
	return
		m_data_for_app_themeables.contains(themeable_tag) ||
		m_data_for_layers_themeables.contains(themeable_tag);
}

void Theme::copy(Theme& theme)
{
	/*  
		NOTE ABOUT Theme::copy():
		This function might be misleading since the copy only considers
		what the supplied theme currently has loaded. It **does not** consider
		the addional app theme files that did not get loaded in with the Theme.
	*/

	clear();

	for (const QString& themeable_tag : theme.m_data_for_app_themeables.keys())
	{
		AttributeMap& themeable_data_in_theme =
			m_data_for_app_themeables[themeable_tag] = AttributeMap();

		for (const QString& entity_key : theme.m_data_for_app_themeables[themeable_tag].keys())
		{
			if (Attribute* theme_attr = dynamic_cast<Attribute*>(theme.m_data_for_app_themeables[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new Attribute(*theme_attr);
			else if (AttributeGroup* theme_attr_group = dynamic_cast<AttributeGroup*>(theme.m_data_for_app_themeables[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new AttributeGroup(*theme_attr_group);
		}
	}

	for (const QString& themeable_tag : theme.m_data_for_layers_themeables.keys())
	{
		AttributeMap& themeable_data_in_theme =
			m_data_for_layers_themeables[themeable_tag] = AttributeMap();

		for (const QString& entity_key : theme.m_data_for_layers_themeables[themeable_tag].keys())
		{
			if (Attribute* theme_attr = dynamic_cast<Attribute*>(theme.m_data_for_layers_themeables[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new Attribute(*theme_attr);
			else if (AttributeGroup* theme_attr_group = dynamic_cast<AttributeGroup*>(theme.m_data_for_layers_themeables[themeable_tag][entity_key]))
				themeable_data_in_theme[entity_key] = new AttributeGroup(*theme_attr_group);
		}
	}

	for (const QString& theme_id : theme.lineage())
		append_to_lineage(theme_id);

	append_to_lineage(theme.id());
}

void Theme::copy_attribute_values_of(Themeable* themeable)
{
	clear_data_for_themeable(themeable->tag());

	AttributeMap new_themeable_data;

	for (const QString& entity_key : themeable->attributes().keys())
	{
		if (Attribute* attr = dynamic_cast<Attribute*>(themeable->attributes()[entity_key]))
		{
			if (!attr->is_entangled())
				new_themeable_data[entity_key] = new Attribute(*attr);
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable->attributes()[entity_key]))
		{
			new_themeable_data[entity_key] = new AttributeGroup(*attr_group);
		}
	}

	if (themeable->is_app_themeable())
		m_data_for_app_themeables[themeable->tag()] = new_themeable_data;
	else
		m_data_for_layers_themeables[themeable->tag()] = new_themeable_data;
}

QDir Theme::dir() const
{
	return m_dir;
}

bool Theme::editable()
{
	return m_editable;
}

bool Theme::has_app_implementation() const
{
	return QFile(
		m_dir.filePath(layersApp->app_identifier() + ".json")
	).exists();
}

QString Theme::id()
{
	if (m_uuid)
		return m_name + "_" + m_uuid->toString(QUuid::WithoutBraces);
	else
		return m_name;
}

QStringList Theme::lineage() const
{
	return m_lineage;
}

void Theme::load()
{
	if (m_dir.exists())
	{
		QFile layers_file(m_dir.filePath("layers.json"));
		QFile app_file(m_dir.filePath(layersApp->app_identifier() + ".json"));

		if (!layers_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme 'layers.json' file";

		load_document(QJsonDocument::fromJson(layers_file.readAll()), ThemeDataType::Layers);

		layers_file.close();

		if (app_file.exists())
		{
			if (!app_file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme app file";

			load_document(QJsonDocument::fromJson(app_file.readAll()), ThemeDataType::Application);

			app_file.close();
		}
	}
}

void Theme::load_document(const QJsonDocument& json_document, const ThemeDataType& data_type)
{
	QJsonObject json_object = json_document.object();

	for (const QString& tag : json_object.keys())
	{
		QJsonObject themeable_object = json_object.value(tag).toObject();

		AttributeMap themeable_attributes;

		for (const QString& attr_key : themeable_object.keys())
		{
			QJsonObject attr_object = themeable_object.value(attr_key).toObject();

			QString name = attr_key;
			bool disabled = false;

			if (attr_object.contains("disabled"))
			{
				if (attr_object.value("disabled").toBool())
					disabled = true;

				attr_object.remove("disabled");
			}

			// If entity_object contains key 'value', then it is an attribute, not a group
			if (attr_object.contains("value") || attr_object.contains("values"))
			{
				themeable_attributes[attr_key] =
					new Attribute(name, attr_object, disabled);
			}
			else // entity_object is a group...
			{
				QMap<QString, Attribute*> group_attributes;

				for (const QString& group_attr_key : attr_object.keys())
				{
					QJsonObject group_attr_object = attr_object.value(group_attr_key).toObject();

					group_attributes[group_attr_key] =
						new Attribute(group_attr_key, group_attr_object);
				}

				AttributeGroup* attr_group = new AttributeGroup(name, disabled);

				attr_group->attributes() = group_attributes;

				themeable_attributes[attr_key] = attr_group;
			}
		}

		if (data_type == ThemeDataType::Application)
			m_data_for_app_themeables[tag] = themeable_attributes;
		else if (data_type == ThemeDataType::Layers)
			m_data_for_layers_themeables[tag] = themeable_attributes;
	}
}

QString Theme::name() const
{
	return m_name;
}

void Theme::set_name(const QString& new_name)
{
	m_name = new_name;
}

void Theme::save_meta_file()
{
	QJsonDocument json_document;

	QJsonObject json_object;

	QJsonArray lineage_array;

	for (const QString& theme_id : m_lineage)
		lineage_array.append(theme_id);

	json_object.insert("lineage", lineage_array);
	json_object.insert("name", m_name);
	json_object.insert("uuid", m_uuid->toString(QUuid::WithoutBraces));

	json_document.setObject(json_object);

	QFile meta_file(m_dir.filePath("meta.json"));

	if (!meta_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create theme 'meta.json' file";
		return;
	}

	meta_file.write(json_document.toJson());
	meta_file.close();
}

QList<QString> Theme::themeable_tags()
{
	return
		m_data_for_app_themeables.keys() +
		m_data_for_layers_themeables.keys();
}

void Theme::set_dir(QDir dir)
{
	m_dir = dir;
}

QJsonDocument Theme::to_json_document(ThemeDataType data_type)
{
	QJsonDocument json_document;

	QJsonObject json_object;

	switch (data_type)
	{
	case (ThemeDataType::All):
	case (ThemeDataType::Application):
		for (const QString& themeable_tag : m_data_for_app_themeables.keys())
		{
			AttributeMap& themeable_data = m_data_for_app_themeables[themeable_tag];

			QJsonObject themeable_json_object;

			for (const QString& entity_key : themeable_data.keys())
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr->to_json_object());
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr_group->to_json_object());
			}

			json_object.insert(themeable_tag, themeable_json_object);
		}

		if (data_type == ThemeDataType::Application)
			break;

		[[fallthrough]];

	case (ThemeDataType::Layers):
		for (const QString& themeable_tag : m_data_for_layers_themeables.keys())
		{
			AttributeMap& themeable_data = m_data_for_layers_themeables[themeable_tag];

			QJsonObject themeable_json_object;

			for (const QString& entity_key : themeable_data.keys())
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr->to_json_object());
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr_group->to_json_object());
			}

			json_object.insert(themeable_tag, themeable_json_object);
		}
	}

	json_document.setObject(json_object);

	return json_document;
}

AttributeMap& Theme::operator[](const QString& themeable_tag)
{
	if (m_data_for_app_themeables.contains(themeable_tag))
		return m_data_for_app_themeables[themeable_tag];
	else if (m_data_for_layers_themeables.contains(themeable_tag))
		return m_data_for_layers_themeables[themeable_tag];
	else
		return m_data_for_layers_themeables[themeable_tag];
}

QUuid* Theme::uuid() const
{
	return m_uuid;
}
