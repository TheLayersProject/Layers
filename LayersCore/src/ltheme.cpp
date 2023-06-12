#include <LayersCore/ltheme.h>

#include <QJsonArray>
#include <QJsonObject>

#include <LayersCore/lthemeable.h>

using Layers::LAbstractAttribute;
using Layers::LAttribute;
using Layers::LAttributeGroup;
using Layers::LTheme;
using Layers::LThemeable;
using Layers::LThemeLineageData;
using Layers::LVariant;

LTheme::LTheme()
{
}

LTheme::LTheme(QDir dir) :
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

LTheme::LTheme(const QString& name, bool editable) :
	m_name{ name },
	m_editable{ editable },
	m_uuid{ new QUuid(QUuid::createUuid().toString()) }
{
}

LTheme::LTheme(const QString& name, QUuid* uuid, bool editable) :
	m_name{ name },
	m_editable{ editable },
	m_uuid{ uuid }
{
}

LTheme::~LTheme()
{
	clear();

	if (m_uuid)
		delete m_uuid;
}

void LTheme::append_to_lineage(const QString& theme_id)
{
	m_lineage.append(theme_id);
}

void LTheme::clear()
{
	for (const QString& themeable_tag : m_data_for_app_themeables.keys())
	{
		LAttributeMap& themeable_data = m_data_for_app_themeables[themeable_tag];

		for (LAbstractAttribute* entity : themeable_data)
			delete entity;

		themeable_data.clear();
	}

	for (const QString& themeable_tag : m_data_for_layers_themeables.keys())
	{
		LAttributeMap& themeable_data = m_data_for_layers_themeables[themeable_tag];

		for (LAbstractAttribute* entity : themeable_data)
			delete entity;

		themeable_data.clear();
	}


	m_data_for_app_themeables.clear();
	m_data_for_layers_themeables.clear();
}

void LTheme::clear_data_for_themeable(const QString& themeable_tag)
{
	LThemeData* relevant_theme_data = nullptr;

	if (m_data_for_app_themeables.contains(themeable_tag))
		relevant_theme_data = &m_data_for_app_themeables;
	else if (m_data_for_layers_themeables.contains(themeable_tag))
		relevant_theme_data = &m_data_for_layers_themeables;

	if (relevant_theme_data)
	{
		LAttributeMap& themeable_data = (*relevant_theme_data)[themeable_tag];

		for (LAbstractAttribute* entity : themeable_data)
			delete entity;

		themeable_data.clear();

		relevant_theme_data->remove(themeable_tag);
	}
}

bool LTheme::contains_attributes_for_tag(const QString& themeable_tag)
{
	return
		m_data_for_app_themeables.contains(themeable_tag) ||
		m_data_for_layers_themeables.contains(themeable_tag);
}

void LTheme::copy_attribute_values_of(LThemeable* themeable)
{
	clear_data_for_themeable(themeable->tag());

	LAttributeMap new_themeable_data;

	for (const QString& entity_key : themeable->attributes().keys())
	{
		if (LAttribute* attr = dynamic_cast<LAttribute*>(themeable->attributes()[entity_key]))
		{
			if (!attr->is_entangled())
				new_themeable_data[entity_key] = new LAttribute(*attr);
		}
		else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(themeable->attributes()[entity_key]))
		{
			new_themeable_data[entity_key] = new LAttributeGroup(*attr_group);
		}
	}

	if (themeable->is_app_themeable())
		m_data_for_app_themeables[themeable->tag()] = new_themeable_data;
	else
		m_data_for_layers_themeables[themeable->tag()] = new_themeable_data;
}

QDir LTheme::dir() const
{
	return m_dir;
}

bool LTheme::editable()
{
	return m_editable;
}

bool LTheme::has_app_implementation(const QString& app_id) const
{
	return
		QFile(
			m_dir.filePath(app_id + ".json")
		).exists();
}

QString LTheme::id()
{
	if (m_uuid)
		return m_name + "_" + m_uuid->toString(QUuid::WithoutBraces);
	else
		return m_name;
}

QStringList LTheme::lineage() const
{
	return m_lineage;
}

void LTheme::load(const QString& app_id)
{
	if (m_dir.exists())
	{
		QFile layers_file(m_dir.filePath("layers.json"));
		QFile app_file(m_dir.filePath(app_id + ".json"));

		if (!layers_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme 'layers.json' file";

		load_document(QJsonDocument::fromJson(layers_file.readAll()), LThemeDataType::Layers);

		layers_file.close();

		if (app_file.exists())
		{
			if (!app_file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme app file";

			load_document(QJsonDocument::fromJson(app_file.readAll()), LThemeDataType::LApplication);

			app_file.close();
		}
	}
}

void LTheme::load_document(const QJsonDocument& json_document, const LThemeDataType& data_type)
{
	QJsonObject json_object = json_document.object();

	for (const QString& tag : json_object.keys())
	{
		QJsonObject themeable_object = json_object.value(tag).toObject();

		LAttributeMap themeable_attributes;

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
					new LAttribute(name, attr_object, disabled);
			}
			else // entity_object is a group...
			{
				QMap<QString, LAttribute*> group_attributes;

				for (const QString& group_attr_key : attr_object.keys())
				{
					QJsonObject group_attr_object = attr_object.value(group_attr_key).toObject();

					group_attributes[group_attr_key] =
						new LAttribute(group_attr_key, group_attr_object);
				}

				LAttributeGroup* attr_group = new LAttributeGroup(name, disabled);

				attr_group->attributes() = group_attributes;

				themeable_attributes[attr_key] = attr_group;
			}
		}

		if (data_type == LThemeDataType::LApplication)
			m_data_for_app_themeables[tag] = themeable_attributes;
		else if (data_type == LThemeDataType::Layers)
			m_data_for_layers_themeables[tag] = themeable_attributes;
	}
}

QString LTheme::name() const
{
	return m_name;
}

void LTheme::set_name(const QString& new_name)
{
	m_name = new_name;
}

void LTheme::save_meta_file()
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

QStringList LTheme::themeable_tags()
{
	return
		m_data_for_app_themeables.keys() +
		m_data_for_layers_themeables.keys();
}

void LTheme::set_dir(QDir dir)
{
	m_dir = dir;
}

QJsonDocument LTheme::to_json_document(LThemeDataType data_type)
{
	QJsonDocument json_document;

	QJsonObject json_object;

	switch (data_type)
	{
	case (LThemeDataType::All):
	case (LThemeDataType::LApplication):
		for (const QString& themeable_tag : m_data_for_app_themeables.keys())
		{
			LAttributeMap& themeable_data = m_data_for_app_themeables[themeable_tag];

			QJsonObject themeable_json_object;

			for (const QString& entity_key : themeable_data.keys())
			{
				if (LAttribute* attr = dynamic_cast<LAttribute*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr->to_json_object());
				else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr_group->to_json_object());
			}

			json_object.insert(themeable_tag, themeable_json_object);
		}

		if (data_type == LThemeDataType::LApplication)
			break;

		[[fallthrough]];

	case (LThemeDataType::Layers):
		for (const QString& themeable_tag : m_data_for_layers_themeables.keys())
		{
			LAttributeMap& themeable_data = m_data_for_layers_themeables[themeable_tag];

			QJsonObject themeable_json_object;

			for (const QString& entity_key : themeable_data.keys())
			{
				if (LAttribute* attr = dynamic_cast<LAttribute*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr->to_json_object());
				else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(themeable_data[entity_key]))
					themeable_json_object.insert(entity_key, attr_group->to_json_object());
			}

			json_object.insert(themeable_tag, themeable_json_object);
		}
	}

	json_document.setObject(json_object);

	return json_document;
}

LAttributeMap& LTheme::operator[](const QString& themeable_tag)
{
	if (m_data_for_app_themeables.contains(themeable_tag))
		return m_data_for_app_themeables[themeable_tag];
	else if (m_data_for_layers_themeables.contains(themeable_tag))
		return m_data_for_layers_themeables[themeable_tag];
	else
		return m_data_for_layers_themeables[themeable_tag];
}

QUuid* LTheme::uuid() const
{
	return m_uuid;
}
