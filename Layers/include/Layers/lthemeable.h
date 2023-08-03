#ifndef LTHEMEABLE_H
#define LTHEMEABLE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lstatepool.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LGraphic;

/*!
	The LThemeable class is designed to be inherited alongside QWidget classes
	to provide them functionality to apply Layers themes.

	Before a theme can be applied to a themeable, some setup is required.

	## Populate the Attribute Map

	Themeables need to store a map of pointers to all attributes and attribute
	groups associated with them. Without this map, themeables would have no way
	of accessing the attributes they are supposed to apply theme values to.

	Attributes and attribute groups are typically declared as member variables
	in classes that implement %LThemeable. These subclasses will need to
	populate the map with pointers to these variables. The map is accessible
	through a protected member variable called *m_attrs*.
		
	~~~~~~~~~~~~~{.c}
	// Example from LThemeableBox::init_attributes()

	m_attrs.insert({
		{ "border", &m_border },
		{ "corner_radii", &m_corner_radii },
		{ "Fill", &m_fill },
		{ "margins", &m_margins }
	});
	~~~~~~~~~~~~~

	## LThemeable Tags

	![LThemeable Tag Example](themeable_tag_example.png)

	A themeable tag is an identifier used to identify a particular themeable.

	### Setting a Name

	The primary component of the themeable tag is the themeable's name which is
	appended to the end of the tag. By default, themeables are nameless, so
	<b>it is important to remember to set themeable names since they are
	required for tag construction</b>. You can do this using set_name():

	~~~~~~~~~~~~~{.c}
	// Example from LDialog::init_titlebar()

	m_exit_button->set_name("Exit Button");
	~~~~~~~~~~~~~

	### Prefix Assignment

	Tag prefixes consist of the names of the parent themeables in the widget
	hierarchy.

	Prefix assignment is handled by calling assign_tag_prefixes(). It works
	recursively to assign prefixes to associated child themeables. It should be
	called by top-level widgets, such as windows and dialogs.
		
	<b>You will NOT need to call assign_tag_prefixes() if your themeable is
	initialized as a child of a top-level widget that already calls it</b>.
	However, if your themeable is not a child of a top-level widget during its
	initialization, and instead, your themeable is initialized after the
	top-level widget at the top of its hierarchy, then you will need to
	manually call assign_tag_prefixes().

	### Constructing and Caching the Tag

	Once a name and any necessary tag prefixes have been assigned, a tag can be
	constructed. Tag construction is done automatically after the first call to
	tag() (typically during the first apply_theme() call). The tag is cached,
	so any subsequent calls to tag() will return the cached tag.

	## Applying Themes

	Once the attribute map has been populated and conditions for tag
	construction are met, a LTheme can be applied. This is done by calling
	apply_theme() and passing the theme as an argument.

	Themes store values labeled under themeable tags. When a theme is applied,
	the themeable obtains its data from the theme by passing along its tag.

	apply_theme() works recursively to apply the theme to the caller and to the
	child themeables in the caller's hierarchy. <b>As long as your themeable is
	part of the hierarchy of a top-level widget that is known by the
	LApplication, you will not need to call apply_theme() manually</b>.

	## Copying Attribute Values to Themes

	After a user makes changes to a custom theme, they will likely want to
	apply those changes. They do this by clicking on the apply button in the
	LThemeEditor. This causes copy_attribute_values_to() to be called on the
	theme editor's active preview widget, passing along the active theme.

	copy_attribute_values_to() copies attribute values of the caller and of
	child themeables in the caller's hierarchy to the provided theme. It is
	effectively the reverse of applying a theme.

	## LThemeable Entanglement

	A themeable can be *linked* with another themeable. This is handled by
	entangle_with() and works by entangling all of caller's attributes with the
	attributes of the argument themeable.

	It is important to note that entangle_with() will only entangle attributes
	whose pointers have been stored in *m_attrs*.

	This should only be done with themeables that are of the same type.

	Example of %LThemeable Entanglement:

	~~~~~~~~~~~~~{.c}
	LButton* control_button = new LButton("");
	LButton* button_1 = new LButton("Button 1");
	LButton* button_2 = new LButton("Button 2");
	LButton* button_3 = new LButton("Button 3");

	button_1->entangle_with(control_button);
	button_2->entangle_with(control_button);
	button_3->entangle_with(control_button);

	control_button->fill()->set_value(QColor(Qt::green));

	// After setting the fill of control_button to green, the other 3 buttons
	// will also have a green fill.
	~~~~~~~~~~~~~

	### Constrain Theme LApplication to One Entangled LThemeable

	Once one themeable has been linked with another, a theme can be applied
	to a single one of them to change both. You will want to constrain theme
	application to a single themeable in the entanglement relationship;
	otherwise, you may get unexpected results.

	If you want to apply different values to two different themeables, they
	shouldn't be linked in the first place.
*/
class LAYERS_EXPORT LThemeable
{
public:
	~LThemeable();

	void add_state_pool(LStatePool* state_pool, bool include_children = true);

	/*!
		Applies *theme* to this themeable and its children.

		A name must be set with set_name() before themes can be applied.

		The theme should contain a map of attributes pertaining to this
		themeable.

		This function works recursively to apply the theme to the children in
		the caller's hierarchy.
	*/
	virtual void apply_theme(LThemeItem* theme_item);

	QList<LAttribute*> child_attributes(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	/*!
		Returns a list of child themeables.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	void clear_theme();

	LThemeItem* current_theme_item() const;

	/*!
		Returns a pointer to the themeable's icon.
			
		Returns nullptr if no icon has been set.
	*/
	LGraphic* icon() const;

	/*!
		Returns a pointer to the name of this themeable.

		Returns nullptr if no name has been set.
	*/
	QString* name() const;

	QString path();

	LThemeable* parent_themeable();

	/*!
		Sets an icon for the themeable; replaces it if one already exists.
	*/
	void set_icon(const LGraphic& icon);

	/*!
		Sets the name of this themeable.
			
		If a name already exists, it is replaced.
	*/
	void set_name(const QString& name);

	void share_theme_item_with(LThemeable* themeable);

	QList<LStatePool*> state_pools() const;

	/*!
		Returns a QStringList containing the available states of this themeable.

		The themeable's available states are a sum of the available states of
		the themeable's attributes.
	*/
	QStringList states() const;

	virtual void update();

protected:
	LThemeItem* m_current_theme_item{ nullptr };

	LGraphic* m_icon{ nullptr };

	QString* m_name{ nullptr };

	QList<LThemeable*> m_sharing_with_themeables;

	QList<LStatePool*> m_state_pools;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLE_H
