#include <Layers/lthemeitem.h>

using Layers::LAttributeMap;
using Layers::LThemeItem;

LThemeItem::LThemeItem(
	const QString& name,
	const LAttributeMap& attributes,
	bool is_overridable,
	const QString& file_name,
	LThemeItem* parent
) :
	m_name{ name },
	m_attributes{ attributes },
	m_is_overridable{ is_overridable },
	m_file_name{ file_name },
	m_parent{ parent },
	QObject(parent)
{
	for (LAttribute* attr : attributes)
		attr->setParent(this);
}

void LThemeItem::append_child(LThemeItem* child)
{
	m_child_items[child->name()] = child;
}

QStringList LThemeItem::attribute_group_names()
{
	QStringList attribute_group_names;

	for (LAttribute* attr : m_attributes)
		if (attr->name().contains("."))
		{
			QString group_name = attr->name().split(".").first();

			if (!attribute_group_names.contains(group_name))
				attribute_group_names.append(attr->name().split(".").first());
		}

	return attribute_group_names;
}

LAttributeMap& LThemeItem::attributes()
{
	return m_attributes;
}

LThemeItem* LThemeItem::child(int number)
{
	if (number < 0 || number >= m_child_items.size())
		return nullptr;
	return m_child_items[m_child_items.keys().at(number)];
}

int LThemeItem::child_count() const
{
	return m_child_items.count();
}

QMap<QString, LThemeItem*>& LThemeItem::child_items()
{
	return m_child_items;
}

QString LThemeItem::file_name() const
{
	return m_file_name;
}

LThemeItem* LThemeItem::find_item(QStringList name_list)
{
	if (!name_list.isEmpty())
	{
		QString name = name_list.takeFirst();

		for (LThemeItem* child_item : m_child_items)
		{
			if (child_item->name() == name)
			{
				if (name_list.isEmpty())
					return child_item;
				else
					return child_item->find_item(name_list);
			}
		}
	}

	return nullptr;
}

bool LThemeItem::is_overridable() const
{
	return m_is_overridable;
}

QString LThemeItem::name() const
{
	return m_name;
}

LThemeItem* LThemeItem::parent()
{
	return m_parent;
}

QString LThemeItem::path()
{
	QStringList path_names;

	path_names.append(m_name);

	LThemeItem* theme_item = parent();

	while (theme_item)
	{
		if (!theme_item->m_name.isEmpty())
			path_names.insert(0, theme_item->m_name);
		
		theme_item = theme_item->parent();
	}

	return path_names.join("/");
}

int LThemeItem::child_number() const
{
	if (m_parent)
	{
		QStringList keys = m_parent->m_child_items.keys();

		for (int i = 0; i < keys.size(); i++)
		{
			LThemeItem* parent_child_item =
				m_parent->m_child_items[keys.at(i)];

			if (parent_child_item == this)
				return i;
		}
	}

	return 0;
}

QJsonObject LThemeItem::to_json_object()
{
	QJsonObject item_object;
	QJsonObject attributes_object;
	QJsonObject children_object;

	for (const QString& key : m_attributes.keys())
		attributes_object.insert(key, m_attributes[key]->json_object());

	for (const QString& key : m_child_items.keys())
	{
		LThemeItem* child_item = m_child_items[key];

		if (child_item->file_name() == m_file_name)
			children_object.insert(
				child_item->name(),
				child_item->to_json_object());
	}

	if (!attributes_object.isEmpty())
		item_object.insert("attributes", attributes_object);

	if (!children_object.isEmpty())
		item_object.insert("children", children_object);

	if (m_is_overridable)
		item_object.insert("is_overridable", QJsonValue(m_is_overridable));

	return item_object;
}
