#ifndef THEME_H
#define THEME_H

#include <QDataStream>
#include <QDir>
#include <QHash>
#include <QJsonDocument>
#include <QString>
#include <QUuid>

#include "Attribute.h"

#define AttributeMap QMap<QString, Layers::AbstractAttribute*>

#define ThemeData QHash<QString, AttributeMap>

namespace Layers
{
	class Attribute;
	class Themeable;

	struct ThemeLineageData
	{
		QString name;
		QString uuid;
		bool has_app_implementation_available = false;
	};

	enum class ThemeDataType
	{
		All, Application, Layers
	};

	/*!
		Provides structure for Layers themes.

		Layers themes store sets of attributes associated with their themeable tags. When a theme is applied,
		themeables retrieve their attribute sets from the theme by passing along their tags.
	*/
	class Theme : public QObject
	{
		Q_OBJECT

	signals:
		void applied();

	public:
		Theme();
		Theme(QDir dir);
		Theme(const QString& name, bool editable = true);
		Theme(const QString& name, QUuid* uuid, bool editable);
		~Theme();

		void append_to_lineage(const QString& theme_id);

		void clear();

		void clear_data_for_themeable(const QString& themeable_tag);

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

		QDir dir() const;

		/*!
			Returns true if the theme is a custom, user-created theme

			@returns true if theme is custom, false otherwise
		*/
		bool editable();

		bool has_app_implementation() const;

		QString identifier();

		Attribute* init_attribute(const QString& name, bool disabled, const QJsonValue& attr_value);

		QStringList lineage() const;

		void load();

		void load_document(const QJsonDocument& json_document, const ThemeDataType& data_type);

		/*!
			Returns the theme's name

			@returns Theme's name
		*/
		QString name() const;

		void save_meta_file();

		void set_dir(QDir dir);

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

		QUuid* uuid() const;

		/*!
			Returns a reference to the attribute set of the themeable tag given in the subscript.

			This function does NOT check first whether the supplied themeable tag exists in the
			theme. For this reason, it is recommended to call contains_attributes_for_tag() first.

			@returns Reference to attribute set of themeable_tag
		*/
		AttributeMap& operator[](const QString& themeable_tag);

	private:
		ThemeData m_data_for_app_themeables{ ThemeData() };
		ThemeData m_data_for_layers_themeables{ ThemeData() };

		QDir m_dir;

		bool m_editable{ true };

		QStringList m_lineage{ QStringList() };

		QString m_name{ "" };

		QUuid* m_uuid{ nullptr };
	};
}

#endif // THEME_H
