#ifndef LTHEMEITEM_H
#define LTHEMEITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LThemeItem is a QObject that handles the hierarchical structure of
	LTheme objects. A theme item can store a set of LAttribute objects, which
	are referred to as *theme attributes*, as well as child LThemeItem objects.

	A theme item has a name which typically matches the name of the widget it
	represents.

	## Storing File Names
	
	When a theme's implementation files are loaded, their theme-item
	hierarchies are merged. To ensure that the data is separated back
	correctly, theme items store the name of the file their data originated
	from.

	The file name should be provided during initialization.

	## JSON Data Format

	The JSON data for a theme item is formatted as follows:

		{									 // Beginning of item's object
			"attributes": {					 // The item's attributes (if any)
				<attr_name>: <attr_object>,	 // First attribute
				...							 // Any other attributes follow (if any)
			},
			"children": {					 // The item's children (if any)
				<item_name>: <item_object>,	 // First child
				...							 // Any other children follow (if any)
			},
			"is_overridable": <bool>		 // True if attributes are overridable (optional)
		}

	If the *is_overridable* value is not present, it is assumed to be *false*.

	For information on how an attribute's JSON object is formatted, see LAttribute.

	In an *implementation file* (see LTheme), a top-level item-object is stored
	in the file's root object with the item's name as its key. The following is
	an example:

		{									   // Beginning of file's root object
			<top_level_item1>: <item_object>,  // First top-level item
			...								   // Any other top-level items follow (if any)
		}
*/
class LThemeItem : public QObject
{
	Q_OBJECT

public:
	/*!
		Constructs a theme item.
	*/
	LThemeItem(
		const QString& name,
		const LAttributeMap& attributes,
		bool is_overridable,
		const QString& file_name,
		LThemeItem* parent = nullptr);

	/*!
		Adds *child* to the list of child items.
	*/
	void append_child(LThemeItem* child);

	/*!
		Returns a list of group names determined from the item's child
		attributes.
	*/
	QStringList attribute_group_names();

	/*!
		Returns the item's child attributes.

		If a valid non-empty string is provided as the argument
		for *type_name*, then the returned map of attributes will only contain
		attributes whose values' types match the type-name.
	*/
	LAttributeMap attributes(const QString& type_name = "");

	/*!
		Returns a pointer to the theme item at the given *index*.

		If the argument provided for the index parameter does not exist, then
		nullptr is returned.
	*/
	LThemeItem* child(int index);

	/*!
		Returns the number of child items that this theme item has.
	*/
	int child_count() const;

	/*!
		Returns a reference to the map containing the child theme items.
	*/
	QMap<QString, LThemeItem*>& children();

	/*!
		Returns the child item identified by *name_list*.

		This function operates recursively down the item's hierarchy. If no
		item is found, then nullptr is returned.
	*/
	LThemeItem* find_item(QStringList name_list);

	/*!
		Returns the child item identified by *path*.

		This function operates recursively down the item's hierarchy. If no
		item is found, then nullptr is returned.
	*/
	LThemeItem* find_item(const QString& path);

	/*!
		Returns a boolean value indicating whether or not the item's attributes
		are overridable.
	*/
	bool is_overridable() const;

	/*!
		Returns the name of the theme item.
	*/
	QString name() const;

	/*!
		Returns a pointer to the item's parent theme-item.

		Returns nullptr if the item has no parent.
	*/
	LThemeItem* parent();

	/*!
		Returns the item's path.

		An item path is a string composed of the names in the item's hierarchy
		leading down to the item. The names are separated with '/' characters.
	*/
	QString path();

	/*!
		Returns the index of this item as it appears in the parent's list of
		child items.
	*/
	int index() const;

	/*!
		Returns a QJsonObject that contains a copy of the item's data.
	*/
	QJsonObject to_json_object();

private:
	LThemeItem* m_parent{ nullptr };
	QMap<QString, LThemeItem*> m_children;

	QString m_name;
	LAttributeMap m_attributes;
	QString m_file_name;
	bool m_is_overridable{ false };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEITEM_H
