#include "Layers.h"

using Layers::Attribute;
using Layers::Theme;
using Layers::Themeable;

void Theme::add_attribute(const QString& themeable_tag, const QString& attribute_name, QVariant value)
{
	if (!m_data.contains(themeable_tag)) m_data[themeable_tag] = QMap<QString, Attribute>();

	if (!m_data[themeable_tag].contains(attribute_name))
		m_data[themeable_tag][attribute_name] = Attribute(attribute_name, value);
}

void Theme::add_attribute(const QString& themeable_tag, const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (!m_data.contains(themeable_tag)) m_data[themeable_tag] = QMap<QString, Attribute>();

	if (!m_data[themeable_tag].contains(attribute_name))
	{
		m_data[themeable_tag][attribute_name] = Attribute(attribute_name, state_value_map);
	}
}

bool Theme::contains(const QString& key)
{
	return m_data.contains(key);
}

void Theme::replace_attributes(Themeable* themeable)
{
	for (Attribute& attribute : themeable->attributes())
	{
		if (m_data[themeable->theme_tag()].keys().contains(attribute.name()))
		{
			if (attribute.is_stateful())
			{
				for (const QString& state : attribute.states())
					m_data[themeable->theme_tag()][attribute.name()].set_value(state, attribute.value(state));
			}
			else m_data[themeable->theme_tag()][attribute.name()].set_value(attribute.value());
		}
	}
}

QMap<QString, Attribute> Theme::operator[](const QString& key)
{
	if (m_data.contains(key)) return m_data[key];

	qDebug() << "Themeable tag \"" + key + "\" was not found in Theme";

	return QMap<QString, Attribute>();
}

const QMap<QString, Attribute> Theme::operator[](const QString& key) const
{
	if (m_data.contains(key)) return m_data[key];

	qDebug() << "Themeable tag \"" + key + "\" was not found in Theme";

	return QMap<QString, Attribute>();
}

void Theme::set_attribute_value(const QString& themeable_tag, const QString& state, const QString& attribute_name, Attribute& attribute)
{
	if (m_data[themeable_tag].contains(attribute_name))
		m_data[themeable_tag][attribute_name] = attribute;
}
