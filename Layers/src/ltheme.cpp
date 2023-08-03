#include <Layers/ltheme.h>

#include <QJsonArray>
#include <QJsonObject>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LTheme;
using Layers::LThemeItem;

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
	delete m_root_item;

	if (m_uuid)
		delete m_uuid;
}

void LTheme::append_to_lineage(const QString& theme_id)
{
	m_lineage.append(theme_id);
}

void LTheme::clear()
{
	if (m_root_item)
	{
		delete m_root_item;
		m_root_item = nullptr;
	}

	m_file_items.clear();
}

QDir LTheme::dir() const
{
	return m_dir;
}

bool LTheme::editable()
{
	return m_editable;
}

LThemeItem* LTheme::find_item(const QStringList& name_list)
{
	return m_root_item->find_item(name_list);
}

LThemeItem* LTheme::find_item(const QString& path)
{
	return find_item(path.split("/"));
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
		clear();
		m_root_item = new LThemeItem("", {}, false, "");

		QFile layers_file = QFile(m_dir.filePath("layers.json"));
		load_file(layers_file);

		QFile app_file = QFile(m_dir.filePath(app_id + ".json"));
		if (app_file.exists())
			load_file(app_file);

		resolve_links(m_root_item);
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

void LTheme::set_dir(QDir dir)
{
	m_dir = dir;
}

void LTheme::resolve_links(LThemeItem* item)
{
	auto resolve = [this](LAttribute* attr)
	{
		if (!attr->link_path().isEmpty())
		{
			QStringList name_list = attr->link_path().split("/");
			QString attr_name = name_list.takeLast();

			if (LThemeItem* item = m_root_item->find_item(name_list))
			{
				for (LAttribute* item_attr : item->attributes())
				{
					if (item_attr->name() == attr_name)
					{
						attr->set_link_attribute(item_attr);
						return;
					}
					else
					{
						for (LAttribute* override_attr : item_attr->overrides())
							if (item_attr->name() + "." + override_attr->name() == attr_name)
							{
								attr->set_link_attribute(override_attr);
								return;
							}
					}
				}
			}
		}
	};

	for (LAttribute* attr : item->attributes())
	{
		resolve(attr);

		for (LAttribute* override_attr : attr->overrides())
			resolve(override_attr);
	}

	for (LThemeItem* child_item : item->child_items())
		resolve_links(child_item);
}

LThemeItem* LTheme::root_item() const
{
	return m_root_item;
}

void LTheme::save()
{
	for (const QString& file_name : m_file_items.keys())
	{
		QJsonObject object = QJsonObject();

		for (LThemeItem* theme_item : m_file_items[file_name])
			object.insert(theme_item->path(), theme_item->to_json_object());

		QJsonDocument document = QJsonDocument();

		document.setObject(object);

		QFile theme_file(file_name);

		if (!theme_file.open(QIODevice::WriteOnly))
		{
			qDebug() << "Could not write theme file: " << file_name;
			return;
		}

		theme_file.write(document.toJson(QJsonDocument::Indented));
		theme_file.close();
	}
}

QUuid* LTheme::uuid() const
{
	return m_uuid;
}

void LTheme::load_file(QFile& file)
{
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << __FUNCTION__ << ":"
			<< " Could not read file:" << file.fileName();
		return;
	}

	QJsonDocument document = QJsonDocument::fromJson(file.readAll());
	file.close();

	QJsonObject object = document.object();

	for (const QString& name : object.keys())
	{
		if (name.contains("/"))
		{
			QStringList name_list = name.split("/");
			QString new_name = name_list.takeLast();

			if (LThemeItem* parent_item = m_root_item->find_item(name_list))
			{
				LThemeItem* new_item = init_item(
					new_name, object.value(name).toObject(), file.fileName(),
					parent_item);

				m_file_items[file.fileName()].append(new_item);

				parent_item->append_child(new_item);
			}
		}
		else
		{
			LThemeItem* new_item = init_item(
				name, object.value(name).toObject(), file.fileName(),
				m_root_item);

			m_file_items[file.fileName()].append(new_item);

			m_root_item->append_child(new_item);
		}
	}
}

LThemeItem* LTheme::init_item(const QString& name,
	QJsonObject item_object, const QString& file_name, LThemeItem* parent)
{
	LAttributeMap attributes;

	if (item_object.contains("attributes"))
	{
		QJsonObject attrs_object = item_object.value("attributes").toObject();
		
		for (const QString& key : attrs_object.keys())
			attributes[key] = new LAttribute(
				key, attrs_object.value(key).toObject());
	}

	bool is_overridable = false;

	if (item_object.contains("is_overridable") &&
		item_object.value("is_overridable").toBool())
		is_overridable = true;

	LThemeItem* item =
		new LThemeItem(name, attributes, is_overridable, file_name, parent);

	if (item_object.contains("children"))
	{
		QJsonObject children_object = item_object.value("children").toObject();

		for (const QString& key : children_object.keys())
			item->append_child(
				init_item(key,
					children_object.value(key).toObject(), file_name, item));
	}

	return item;
}
