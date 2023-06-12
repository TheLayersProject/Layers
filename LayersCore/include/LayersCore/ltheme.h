#ifndef LTHEME_H
#define LTHEME_H

#include <QDataStream>
#include <QDir>
#include <QHash>
#include <QJsonDocument>
#include <QString>
#include <QUuid>

#include "layers_global.h"
#include "layerscore_exports.h"

#include "lattributegroup.h"

#define LAttributeMap QMap<QString, Layers::LAbstractAttribute*>
#define LThemeData QHash<QString, LAttributeMap>

LAYERS_NAMESPACE_BEGIN

class Attribute;
class LThemeable;

struct LAYERS_CORE_EXPORT LThemeLineageData
{
	QString name;
	QString uuid;
	bool has_app_implementation_available = false;
};

enum class LAYERS_CORE_EXPORT LThemeDataType
{
	All, LApplication, Layers
};

/*!
	An LTheme is a QObject that stores data to change the appearance of
	LThemeable widgets.

	## Theme Directories/Files

	When a theme is stored on the system, the data is separated into
	different files within a single directory. These files are referred to
	as *theme files*, and the directory is referred to as a *theme directory*.

	Every theme directory should contain a *meta.json* file as well as
	an *layers.json* file. Other files present in the directory are called
	app-implementation files. There is an app-implementation file for every
	application that has been implemented in the theme.

	### meta.json

	The meta file contains metadata pertaining to the theme. This metadata
	includes the theme's name, UUID, and lineage.

	### layers.json

	The layers file is a special implementation file that implements the theme
	for widgets that exist universally across different Layers apps.

	## Theme Loading

	When loading themes from theme directories, only their metadata is loaded.
	This is done to prevent heavy memory usage.
		
	Relevant implementation files are only loaded for the active theme. This
	includes the *layers.json* file as well as the app-implementation file
	associated with the application performing the load.

	When a different theme gets applied, relevant implementation files of the
	previous theme are unloaded before loading the relevant implementation
	files of the next theme.
*/
class LAYERS_CORE_EXPORT LTheme : public QObject
{
	Q_OBJECT

public:
	/*!
		Constructs an empty, nameless theme.
	*/
	LTheme();

	/*!
		Constructs a theme from a directory.

		Metadata is loaded from the theme's *meta.json* file.
	*/
	LTheme(QDir dir);

	/*!
		Constructs a theme with the given *name* and *editable* status. A new
		UUID is generated.
	*/
	LTheme(const QString& name, bool editable = true);

	/*!
		Constructs a theme with the given *name*, *uuid*, and *editable*
		status.
	*/
	LTheme(const QString& name, QUuid* uuid, bool editable);

	~LTheme();

	/*!
		Adds *theme_id* to the lineage of this theme.
	*/
	void append_to_lineage(const QString& theme_id);

	/*!
		Unloads implementation data.
	*/
	void clear();

	/*!
		Removes data from this theme that pertains to the themeable identified
		by *themeable_tag*.
	*/
	void clear_data_for_themeable(const QString& themeable_tag);

	/*!
		Returns true if this theme contains any attributes identified
		by *themeable_tag*; otherwise, returns false.
	*/
	bool contains_attributes_for_tag(const QString& themeable_tag);

	/*!
		Copies the values of the attributes of *themeable* to this theme.
	*/
	void copy_attribute_values_of(LThemeable* themeable);

	/*!
		Returns the theme directory of this theme.
	*/
	QDir dir() const;

	/*!
		Returns true if this is a custom theme; otherwise, returns false.
	*/
	bool editable();

	/*!
		Returns true if this theme has an implementation file for the current
		application; otherwise, returns false.
	*/
	bool has_app_implementation(const QString& app_id) const;

	/*!
		Returns the ID of this theme.

		The ID is composed of the theme's name followed by the theme's UUID,
		separated by an underscore.
	*/
	QString id();

	/*!
		Returns a QStringList containing the IDs of the ancestor themes in this
		theme's lineage.
	*/
	QStringList lineage() const;

	/*!
		Loads the implementation files of this theme.

		This includes the *layers.json* file as well as the app-implementation
		file associated with the current application.
	*/
	void load(const QString& app_id);

	/*!
		Loads implementation data from *json_document*.

		The *data_type* parameter specifies whether the data being loaded is
		Layers data or application data.
	*/
	void load_document(
		const QJsonDocument& json_document,
		const LThemeDataType& data_type);

	/*!
		Returns the name of this theme.
	*/
	QString name() const;

	/*!
		Returns a reference to the attribute map in the theme that pertains
		to *themeable_tag*.

		This function **does not** check whether an attribute map pertaining
		to *themeable_tag* exists in the theme. For this reason, it is
		recommended to call contains_attributes_for_tag() first.
	*/
	LAttributeMap& operator[](const QString& themeable_tag);

	/*!
		Saves a *meta.json* file to the directory pertaining to this theme.
	*/
	void save_meta_file();

	/*!
		Sets the theme directory.
	*/
	void set_dir(QDir dir);

	/*!
		Sets the name of this theme.
	*/
	void set_name(const QString& new_name);

	/*!
		Returns a QStringList containing all of the themeable tags found in
		currently loaded data of this theme.
	*/
	QStringList themeable_tags();

	/*!
		Returns a QJsonDocument containing theme data.

		The *data_type* parameter specifies which data to include in the
		document.
	*/
	QJsonDocument to_json_document(
		LThemeDataType data_type = LThemeDataType::All);

	/*!
		Returns a pointer to the UUID of this theme.
	*/
	QUuid* uuid() const;

private:
	LThemeData m_data_for_app_themeables;
	LThemeData m_data_for_layers_themeables;

	QDir m_dir;

	bool m_editable{ true };

	QStringList m_lineage;

	QString m_name;

	QUuid* m_uuid{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LTHEME_H
