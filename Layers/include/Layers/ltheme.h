#ifndef LTHEME_H
#define LTHEME_H

#include <QDataStream>
#include <QDir>
#include <QJsonDocument>
#include <QString>
#include <QUuid>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

struct LAYERS_EXPORT LThemeLineageData
{
	QString name;
	QString uuid;
	bool has_app_implementation_available = false;
};

/*!
	An LTheme stores data to change the appearance of LThemeable widgets within
	a *Layers* application.

	Themes store data using LThemeItem objects which handle the hierarchical
	structure of themes. The root item can be obtained using root_item().

	## Theme Identifier

	A theme has a name and a UUID. When the two are joined together, separated
	by an underscore, it is called the *theme identifier*, or theme-ID for
	short. The following is an example of how a theme-ID might look for a
	theme named *Sky Blue*:

		Sky Blue_bbc2fb0e-0b4e-4fcf-b651-dfeeacbffbaf

	The purpose of the UUID in the theme-ID is to allow the same name to be
	given to multiple themes.

	The theme-ID can be obtained using id().

	## Theme Files and Directories

	A theme stored on the system is made up of multiple JSON files, known
	as *theme files*, stored within a directory, known as a *theme directory*.

	A theme directory is labeled with the theme-ID.
	
	There is a special theme file that contains the theme's metadata, and then
	the rest of the theme files are *implementation files*.
	
	### Metadata File

	The theme's metadata is stored within a theme file labeled *meta.json*. It
	contains data regarding the theme's *name*, *UUID*, and *lineage*. This
	file should be present in every theme directory and is used as a way to
	partially load a theme without loading implementation files.

	### Implementation Files

	An implementation file is a theme file that contains theme data pertaining
	to a specific application. Implementation files are typically labeled with
	the *app ID* (see LApplication). The following is an example of how an
	implementation file for the *Layers Demo* application would be labeled:

		layers_demo_f97aae7f-2076-4918-93ce-19321584f675.json

	#### Layers Implementation File

	There is a special implementation file labeled *layers.json* which contains
	the theme data pertaining to the widgets that are included with *Layers*.
	These widgets are considered universal across different *Layers*
	applications.

	## Loading Themes

	System themes are partially loaded when the application is initialized.
	Only the theme's metadata is loaded while none of the implementation files
	get loaded until the theme becomes the active application theme. This
	partial-loading is performed to save system resources.

	When the theme becomes the active application theme, the application uses
	the load() function, passing the *app ID* as an argument to ensure that the
	theme loads the correct implementation file. During this function, the
	implementation file relevant to the application and the *Layers*
	implementation file get loaded. Other implementation files are left
	untouched.

	## Managing Attribute Links

	Once implementation files have been loaded, theme attributes with valid
	link paths have their links resolved. See LAttribute for more information
	on *attribute linking*.

	## Theme Lineage

	When a new theme is created, it starts as a copy of another theme, referred
	to as the parent theme. The ID of the parent theme is tracked as part of
	the new theme's *lineage*. The new theme also inherits the parent theme's
	lineage.

	Themes that make up the lineage are called *ancestor themes*.

	The main purpose for tracking theme lineage is to be able to acquire
	implementation files from ancestor themes when they don't already exist in
	a theme being loaded.
*/
class LAYERS_EXPORT LTheme
{
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
	LTheme(const QString& name, QUuid uuid, bool editable);

	~LTheme();

	/*!
		Adds *theme_id* to the lineage of this theme.
	*/
	void append_to_lineage(const QString& theme_id);

	/*!
		Clears out any loaded implementation data.

		The root item becomes nullptr after calling this function.
	*/
	void clear();

	/*!
		Returns the theme directory of this theme.
	*/
	QDir dir() const;

	/*!
		Returns a boolean value determining whether or not the theme is
		editable.
	*/
	bool editable();

	/*!
		Returns the child item identified by *name_list*.

		This function operates recursively down the theme's hierarchy, starting
		at the root item. If no item is found, then nullptr is returned.
	*/
	LThemeItem* find_item(const QStringList& name_list);

	/*!
		Returns the child item identified by *path*.

		This function operates recursively down the theme's hierarchy, starting
		at the root item. If no item is found, then nullptr is returned.
	*/
	LThemeItem* find_item(const QString& path);

	/*!
		Returns a boolean value determining whether or not the theme directory
		contains an implementation file for the given *app_id*.
	*/
	bool has_implementation(const QString& app_id) const;

	/*!
		Returns the theme-ID of this theme.

		The theme-ID is composed of the theme's name and UUID, separated by an
		underscore.
	*/
	QString id();

	/*!
		Returns a list containing the theme-IDs of the ancestor themes in the
		theme's lineage.
	*/
	QStringList lineage() const;

	/*!
		Loads the relevant implementation files of this theme.

		The relevant files are the *Layers* implementation file and the
		implementation file for the given *app_id*. Other implementation files
		are left untouched.
	*/
	void load(const QString& app_id);

	/*!
		Returns the name of the theme.
	*/
	QString name() const;

	/*!
		Returns a pointer to the theme's root item.
	*/
	LThemeItem* root_item() const;

	/*!
		Saves the theme.

		The currently loaded theme data is separated into corresponding 
		implementation files which are stored in the theme directory.
	*/
	void save();

	/*!
		Saves a the metadata file to the theme directory.

		The file is labeled *meta.json*.
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
		Returns the UUID of this theme.
	*/
	QUuid uuid() const;

private:
	void load_file(QFile& document_file);

	LThemeItem* init_item(const QString& name,
		QJsonObject item_object, const QString& file_name,
		LThemeItem* parent = nullptr);

	void resolve_links(LThemeItem* item);

	LThemeItem* m_root_item{ nullptr };

	QMap<QString, QList<LThemeItem*>> m_file_items;

	QDir m_dir;

	bool m_editable{ true };

	QStringList m_lineage;

	QString m_name;

	QUuid m_uuid;
};
LAYERS_NAMESPACE_END

#endif // LTHEME_H
