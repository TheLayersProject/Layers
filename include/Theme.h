#ifndef THEME_H
#define THEME_H

#include <QDataStream>
#include <QHash>
#include <QJsonDocument>
#include <QString>
#include <QUuid>

#include "Attribute.h"

namespace Layers
{
	class Attribute;
	class Themeable;

	// NOTE: Below has not been updated to support Entity
	//inline QDataStream& operator <<(QDataStream& stream, const QMap<QString, Attribute*>& attr_map)
	//{
	//	stream << attr_map.count();

	//	for (const QString& attr_tag : attr_map.keys())
	//	{
	//		stream << attr_tag;
	//		stream << *attr_map[attr_tag];
	//	}
	//	
	//	return stream;
	//}

	// NOTE: Below has not been updated to support Entity
	//inline QDataStream& operator >>(QDataStream& stream, QMap<QString, Attribute*>& attr_map)
	//{
	//	qsizetype attr_count;
	//	
	//	stream >> attr_count;
	//	
	//	for (int i = 0; i < attr_count; i++)
	//	{
	//		QString attr_tag = "";
	//		Attribute* attr = new Attribute("");
	//		
	//		stream >> attr_tag;
	//		stream >> *attr;
	//	
	//		attr_map[attr_tag] = attr;
	//	}
	//	
	//	return stream;
	//}

	enum class ThemeDataType
	{
		All, Application, Layers
	};

	/*!
		Provides structure for Layers themes.

		Layers themes store sets of attributes associated with their themeable tags. When a theme is applied,
		themeables retrieve their attribute sets from the theme by passing along their tags.
	*/
	class Theme
	{
	public:
		Theme();
		Theme(const QString& name, bool editable = true);
		Theme(const QJsonDocument& json_document, QUuid* uuid = nullptr);
		~Theme();

		/*!
			Adds a themeable tag paired with a set of attributes

			Does nothing if themeable tag already exists in the theme.

			@param themeable_tag of the themeable that the supplied attributes belong to
			@param attributes that belong to a themeable for this theme to store
		*/
		//void add_attributes(
		//	const QString& themeable_tag,
		//	QMap<QString, Attribute*> attributes);

		void clear();

		void consume(Theme&& theme);

		/*!
			Returns true if the theme contains any attributes for the given themeable tag; otherwise returns false.

			@param themeable_tag used to check whether the theme contains attributes for it
			@returns True if theme contains attributes for tag, false otherwise
		*/
		bool contains_attributes_for_tag(const QString& themeable_tag);

		/*!
			Copies the attribute sets of another theme.

			@param theme to copy attribute sets from
		*/
		void copy(Theme& theme);

		void copy_attribute_values_of(Themeable* themeable);

		/*!
			Returns true if the theme is a custom, user-created theme

			@returns true if theme is custom, false otherwise
		*/
		bool editable();

		QString identifier();

		Attribute* init_attribute(const QString& name, bool disabled, const QJsonValue& attr_value);

		/*!
			Returns a reference to the theme's name

			@returns Reference to theme's name
		*/
		QString& name();

		/*!
			Sets the theme's name

			@param new_name to set as the theme's name
		*/
		void set_name(const QString& new_name);

		/*!
			Returns a list of all of the themeable tags contained in the theme

			@returns list of themeable tags that exist in the theme
		*/
		QList<QString> themeable_tags();

		QJsonDocument to_json_document(ThemeDataType data_type = ThemeDataType::All);

		/*!
			Returns a reference to the attribute set of the themeable tag given in the subscript.

			This function does NOT check first whether the supplied themeable tag exists in the
			theme. For this reason, it is recommended to call contains_attributes_for_tag() first.

			@returns Reference to attribute set of themeable_tag
		*/
		QMap<QString, Entity*>& operator[](const QString& themeable_tag);

		//friend QDataStream& operator <<(QDataStream& stream, const Theme& t)
		//{
		//	stream << t.m_data;
		//	stream << t.m_editable;
		//	stream << t.m_name;
		//	return stream;
		//}

		//friend QDataStream& operator >>(QDataStream& stream, Theme& t)
		//{
		//	stream >> t.m_data;
		//	stream >> t.m_editable;
		//	stream >> t.m_name;
		//	return stream;
		//}

	private:
		QHash<QString, QMap<QString, Entity*>> m_data{ QHash<QString, QMap<QString, Entity*>>() };

		bool m_editable{ true };

		QString m_name{ "" };

		QUuid* m_uuid{ nullptr };
	};
}

#endif // THEME_H
