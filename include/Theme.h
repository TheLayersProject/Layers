#ifndef THEME_H
#define THEME_H

#include <QDataStream>
#include <QHash>
#include <QString>

#include "Attribute.h"

namespace Layers
{
	class Attribute;
	class Themeable;

	inline QDataStream& operator <<(QDataStream& stream, const QMap<QString, Attribute*>& attr_map)
	{
		stream << attr_map.count();

		for (const QString& attr_tag : attr_map.keys())
		{
			stream << attr_tag;
			stream << *attr_map[attr_tag];
		}
		
		return stream;
	}

	inline QDataStream& operator >>(QDataStream& stream, QMap<QString, Attribute*>& attr_map)
	{
		qsizetype attr_count;
		
		stream >> attr_count;
		
		for (int i = 0; i < attr_count; i++)
		{
			QString attr_tag = "";
			Attribute* attr = new Attribute("");
			
			stream >> attr_tag;
			stream >> *attr;
		
			attr_map[attr_tag] = attr;
		}
		
		return stream;
	}

	/*!
		Provides structure for Layers themes.

		Layers themes store sets of attributes associated with their themeable tags. When a theme is applied,
		themeables retrieve their attribute sets from the theme by passing along their tags.
	*/
	class Theme
	{
	public:
		Theme();
		Theme(const QString& name, bool is_custom = true);

		void add_attributes(
			const QString& themeable_tag,
			QMap<QString, Attribute*> attributes);

		//void add_attribute(
		//	const QString& themeable_tag,
		//	const QString& attribute_name,
		//	QMap<QString, QVariant> state_value_map);

		//void add_attribute_set(const QString& themeable_tag, AttributeSet attribute_set);

		//Attribute* attribute(const QString& themeable_tag, const QString& attribute_name);

		// Recommend calling contains_attributes_for_tag() before calling this since this function
		// does not check if it contains an attribute set for the given themeable tag.
		//QList<Attribute*>* attribute_set(const QString& themeable_tag);

		//QHash<QString, QList<Attribute*>>& attribute_sets();

		//void consume(Theme&& theme);

		bool contains_attributes_for_tag(const QString& themeable_tag);

		// Only needs one version since attribute names should not exist in both stateless and stateful lists
		//bool contains_attribute(const QString& themeable_tag, const QString& attribute_name);

		void copy_from(Theme& theme);

		//void copy_attribute_values_of(Themeable* themeable);

		bool is_custom();

		QString& name();

		void set_name(const QString& new_name);

		QList<QString> themeable_tags();

		QMap<QString, Attribute*>& operator[](const QString& themeable_tag);

		friend QDataStream& operator <<(QDataStream& stream, const Theme& t)
		{
			stream << t.m_data;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme& t)
		{
			stream >> t.m_data;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		//QHash<QString, AttributeSet> m_attribute_sets{ QHash<QString, AttributeSet>() };

		QHash<QString, QMap<QString, Attribute*>> m_data{ QHash<QString, QMap<QString, Attribute*>>() };

		bool m_is_custom{ true };

		QString m_name{ "" };
	};
}

#endif // THEME_H
