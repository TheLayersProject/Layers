#include <Layers/ltheme.h>

#include <QJsonArray>
#include <QJsonObject>

#include <Layers/lthemeable.h>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LTheme;
using Layers::LThemeable;
using Layers::LThemeLineageData;

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
	for (const QString& tag : m_hash.keys())
		m_hash[tag].clear();

	for (const QString& tag : m_hash_layers.keys())
		m_hash_layers[tag].clear();


	m_hash.clear();
	m_hash_layers.clear();
}

void LTheme::clear_tag(const QString& tag)
{
	LAttributeMapHash* relevant_hash = nullptr;

	if (m_hash.contains(tag))
		relevant_hash = &m_hash;
	else if (m_hash_layers.contains(tag))
		relevant_hash = &m_hash_layers;

	if (relevant_hash)
	{
		(*relevant_hash)[tag].clear();

		relevant_hash->remove(tag);
	}
}

bool LTheme::contains_attributes_for_tag(const QString& tag)
{
	return
		m_hash.contains(tag) ||
		m_hash_layers.contains(tag);
}

void LTheme::copy_attribute_values_of(LThemeable* themeable)
{
	clear_tag(themeable->tag());

	QList<LAttribute*> themeable_attrs = themeable->child_attributes();
	LAttributeMap theme_attrs;

	for (LAttribute* attr : themeable_attrs)
	{
		//if (!attr->link_established())
		theme_attrs[attr->name()] = new LAttribute(*attr);
	}

	if (themeable->is_app_themeable())
		m_hash[themeable->tag()] = theme_attrs;
	else
		m_hash_layers[themeable->tag()] = theme_attrs;
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

void LTheme::load_document(
	const QJsonDocument& json_document, const LThemeDataType& data_type)
{
	QJsonObject json_object = json_document.object();

	for (const QString& tag : json_object.keys())
	{
		QJsonObject themeable_object = json_object.value(tag).toObject();

		LAttributeMap m_attr_map;

		for (const QString& key : themeable_object.keys())
			m_attr_map[key] = new LAttribute(
				key, themeable_object.value(key).toObject());

		if (data_type == LThemeDataType::LApplication)
			m_hash[tag] = m_attr_map;
		else if (data_type == LThemeDataType::Layers)
			m_hash_layers[tag] = m_attr_map;
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
		m_hash.keys() +
		m_hash_layers.keys();
}

void LTheme::set_dir(QDir dir)
{
	m_dir = dir;
}

QJsonDocument LTheme::to_json_document(LThemeDataType data_type)
{
	QJsonDocument document;

	QJsonObject document_object;

	switch (data_type)
	{
	case (LThemeDataType::All):
	case (LThemeDataType::LApplication):
		for (const QString& tag : m_hash.keys())
		{
			LAttributeMap& tag_attrs = m_hash[tag];

			QJsonObject tag_object;

			for (const QString& key : tag_attrs.keys())
				tag_object.insert(key, tag_attrs[key]->to_json_object());

			document_object.insert(tag, tag_object);
		}

		if (data_type == LThemeDataType::LApplication)
			break;

		[[fallthrough]];

	case (LThemeDataType::Layers):
		for (const QString& tag : m_hash_layers.keys())
		{
			LAttributeMap& tag_attrs = m_hash_layers[tag];

			QJsonObject tag_object;

			for (const QString& key : tag_attrs.keys())
				tag_object.insert(key, tag_attrs[key]->to_json_object());

			document_object.insert(tag, tag_object);
		}
	}

	document.setObject(document_object);

	return document;
}

LAttributeMap& LTheme::operator[](const QString& tag)
{
	if (m_hash.contains(tag))
		return m_hash[tag];
	else if (m_hash_layers.contains(tag))
		return m_hash_layers[tag];
	
	return m_hash_layers[tag];
}

QUuid* LTheme::uuid() const
{
	return m_uuid;
}
