#ifndef LTHEMEABLE_H
#define LTHEMEABLE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lstatepool.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LGraphic;

/*!
	LThemeable is intended to be inherited alongside QWidget classes to
	provide them with functionality to apply *Layers* themes (see LTheme and
	LThemeItem).

	The terms *themeable* and *widget* are often interchangeable
	throughout *Layers* since most *Layers* widgets inherit LThemeable. The
	term *themeable widget* is also used.

	Themeables recognize the QObject hierarchy. A parent-child relationship
	between two *widgets* is also a parent-child relationship between
	two *themeables*, as long as the widget-classes inherit LThemeable. They
	also recognize any child LAttribute objects owned by their widget
	counterparts. Attributes owned by themeable widgets are
	called *widget attributes*.

	Child themeables can be obtained through child_themeables(), and child
	attributes can be obtained through child_attributes().

	## Themeable Paths

	A themeable path is a string that contains the names of the widgets
	that make up the themeable's hierarchy, as well as the themeable's name,
	separated by a '/'. The following is an example of a themeable path:

		App/Main Window/Settings Menu

	Themeable paths are used to match themeables with the correct LThemeItem
	objects whose paths should be the same. So, the above example would also be
	the path of the theme-item containing data for the *Settings Menu* in an
	LTheme.

	## Applying Theme Items

	A theme item is applied to a themeable through apply_theme_item(). This
	sets the item's *theme attributes* to the themeable's widget attributes.
	
	In most cases, you will not have to manually call apply_theme_item() as
	long as the themeable is already a part of the application's QObject
	hierarchy when the application's theme changes.
	
	However, if a themeable is initialized *after* the application's theme has
	been set, you may need to manually call apply_theme_item(). In these cases,
	it is usually helpful to obtain the parent themeable's current theme item
	using the protected member variable m_current_theme_item, and then call
	LThemeItem::find_item() to obtain the desired theme item to apply. The
	following is an example:

	~~~~~~~~~~~~~{.c}
	// From LThemeEditorDialog:

	if (m_current_theme_item)
			attr_editor->apply_theme_item(
				m_current_theme_item->find_item("Attribute Editors"));
	~~~~~~~~~~~~~
	
	### Sharing Theme Items

	A themeable can share its theme item with other themeables. These other
	themeables are called *share themeables* and can be added using
	add_share_themeable(). When a theme item is applied to the original
	themeable, the item is also applied to the share themeables.

	This is useful for *recursive widgets* (widgets that have widgets of the
	same type as children).

	## State Pools

	A themeable can contain one or more LStatePool objects. A state pool
	contains a group of states, with one of them being considered
	the *active state* from that pool. To add a state pool to a themeable, use
	add_state_pool(). Themeables typically share their state pools with their
	children.

	### Overriding Attributes with State Combinations

	A list of all the active states make up the *state combination*, obtained
	through state_combo(). The combination is used when obtaining attribute
	values. If an attribute contains an override with a matching combination,
	the override's value is used instead. See LAttribute for more information
	on *attribute overriding*.
*/
class LAYERS_EXPORT LThemeable
{
public:
	/*!
		Adds *themeable* to the list of share themeables.
	*/
	void add_share_themeable(LThemeable* themeable);

	/*!
		Adds *state_pool* to the themeable.

		Also adds the state pool to child themeables if *include_children* is
		true, which is the default.
	*/
	void add_state_pool(LStatePool* state_pool, bool include_children = true);

	/*!
		Applies *theme* to this themeable and its children.

		A name must be set with set_name() before themes can be applied.

		This function works recursively to apply the theme to the children in
		the themeable's hierarchy.
	*/
	virtual void apply_theme_item(LThemeItem* theme_item);

	/*!
		Returns a list of child attributes.
	*/
	QList<LAttribute*> child_attributes(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	/*!
		Returns a list of child themeables.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	/*!
		Returns a pointer to the themeable's currently applied theme item.

		See also: apply_theme_item()
	*/
	LThemeItem* current_theme_item() const;

	/*!
		Returns a string representing the themeable's path.
	*/
	QString path();

	/*!
		Returns a list containing pointers to the state pools associated with
		the themeable.

		See also: LStatePool
	*/
	QList<LStatePool*> state_pools() const;

	/*!
		Returns a QStringList containing the available state_combo of this
		themeable.

		The themeable's available state_combo are a sum of the available
		state_combo of the themeable's attributes.
	*/
	QStringList state_combo() const;

	/*!
		Updates the themeable.
	*/
	virtual void update();

private:
	LThemeable* _parent_themeable();

	QString _name();

	LThemeItem* m_current_theme_item{ nullptr };

	QList<LThemeable*> m_share_themeables;

	QList<LStatePool*> m_state_pools;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLE_H
