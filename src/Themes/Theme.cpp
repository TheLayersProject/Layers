#include "../../../include/Theme.h"
#include "../../../include/Themeable.h"

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

void Theme::add_attributes(const QString& themeable_tag, QMap<QString, Attribute*> attributes)
{
	if (!m_data.contains(themeable_tag))
		m_data[themeable_tag] = attributes;
}

//void Theme::consume(Theme&& theme)
//{
//	for (const QString& themeable_tag : theme.attribute_sets().keys())
//	{
//		if (!m_attribute_sets.contains(themeable_tag))
//			m_attribute_sets[themeable_tag] = AttributeSet();
//
//		AttributeSet& attribute_set = m_attribute_sets[themeable_tag];
//
//		for (Attribute* attr : theme.attribute_sets()[themeable_tag].attributes())
//			if (!attribute_set.contains(attr->name()))
//				attribute_set.add_attribute(attr);
//	}
//}

bool Theme::contains_attributes_for_tag(const QString& themeable_tag)
{
	return m_data.contains(themeable_tag);
}

void Theme::copy_from(Theme& theme)
{
	m_data = theme.m_data;
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

QMap<QString, Attribute*>& Theme::operator[](const QString& themeable_tag)
{
	return m_data[themeable_tag];
}
