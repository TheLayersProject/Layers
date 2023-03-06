#ifndef THEMEABLE_H
#define THEMEABLE_H

#include "AttributeGroup.h"

namespace Layers
{
	class AttributeWidget;
	class Graphic;
	class Theme;

	/*!
		The Themeable class is designed to be inherited alongside QWidget
		classes to provide them functionality to apply Layers Themes.

		Before a theme can be applied to a themeable, some setup is required.

		# Populate the Entity Pointer Map

		Themeables need to store a map of pointers to all enities associated
		with them. Without this map, themeables would have no way of accessing
		the entities they are supposed to apply theme values to.

		Entities are typically declared as public member variables in classes
		that implement %Themeable. %Themeable subclass implementations will
		need to populate the map with pointers to these entity variables. The
		map is accessible through a protected member variable called
		*m_entities*.
		
		~~~~~~~~~~~~~{.c}
		// Example from ThemeableBox::init_attributes()

		m_entities.insert({
			{ "border", &border },
			{ "corner_color", &a_corner_color },
			{ "corner_radii", &corner_radii },
			{ "fill", &a_fill },
			{ "hover_fill", &a_hover_fill },
			{ "margins", &margins },
			{ "outline_color", &a_outline_color }
		});
		~~~~~~~~~~~~~

		# Themeable Tags

		![Themeable Tag Breakdown](themeable_tag_breakdown.png)

		A themeable tag is an identifier used to identify a particular
		themeable.

		## Setting a Name

		The primary component of the themeable tag is the themeable's name
		which is appended to the end of the tag. By default, themeables are
		nameless, so <b>it is important to remember to set themeable names
		since they are required for tag construction</b>. You can do this using
		set_name():

		~~~~~~~~~~~~~{.c}
		// Example from Titlebar::Titlebar()

		m_exit_button->set_name("exit_button");
		~~~~~~~~~~~~~

		## Prefix Assignment

		Tag prefixes consist of the names of the parent themeables in the
		widget hierarchy.

		Prefix assignment is handled by calling assign_tag_prefixes(). It also
		works recursively to assign prefixes to associated child themeables.
		assign_tag_prefixes() is called automatically at the end of the Window
		constructor after all of its children have presumably been initialized,
		so <b>as long as your themeable is part of the window's hierarchy, you
		will not need to call assign_tag_prefixes() manually</b>.

		### Layers Prefix

		Themeables that have been themed by Layers, not an application, have 
		the 'layers' prefix prepended to the front of the tag.

		## Constructing and Caching the Tag

		Once a name and any necessary tag prefixes have been assigned, a tag
		can be constructed. Tag construction is done automatically after the
		first call to tag() (typically during the first apply_theme() call).
		The tag is cached, so any subsequent calls to tag() will return the
		cached tag.

		# Applying Themes

		Once the conditions for tag construction are met, a theme can be
		applied. This is done by calling apply_theme() and passing the theme
		as an argument.

		Themes store values labeled under themeable tags. When a theme is
		applied, the themeable obtains its data from the theme
		by passing along its tag.

		apply_theme() works recursively to apply the theme to the caller and
		to the child themeables in the caller's hierarchy. <b>As long as your
		themeable is part of the window's hierarchy, you will not need to call
		apply_theme() manually</b>.

		# Copying Entity Values to Themes

		After a user makes changes to a custom theme, they will likely end up
		applying those changes once they are satisfied. They do this by
		clicking on the apply button in the CustomizeMenu. This causes
		copy_attribute_values_to() to be called on the menu's preview window,
		passing along the active theme.

		copy_attribute_values_to() copies entity values of the caller and of
		child themeables in the caller's hierarchy to the provided theme. It is
		effectively the reverse of applying a theme.

		# Themeable Entanglement

		A themeable can be *entangled* with another themeable. This is handled
		by Themeable::entangle_with() and works by entangling all of caller's
		entities with the entities of the argument themeable.

		It is important to note that Themeable::entangle_with() will only
		entangle entities whose pointers have been stored in *m_entities*.

		Example of %Themeable Entanglement:

		~~~~~~~~~~~~~{.c}
		Widget* widget_a = new Widget;
		Widget* widget_b = new Widget;

		widget_a->entangle_with(widget_b);

		widget_a->fill()->set_value(QColor(Qt::black));		// widget_b->a_fill is also black now
		widget_b->corner_radii()->top_left()->set_value(10.0);	// widget_a->corner_radii()->left is also 10.0 now
		~~~~~~~~~~~~~

		## Constrain Theme Application to One Entangled Themeable

		Once one themeable has been entangled with another, a theme can be
		applied to a single one of them but ultimately gets applied to both.
		You will want to constrain theme application to a single themeable in
		the entanglement relationship otherwise you may get unexpected results.

		If you want to apply different values to two different themeables, they
		shouldn't be entangled in the first place.
	*/
	class Themeable
	{
	public:
		~Themeable();

		/*!
			Applies the given theme to the caller and its children.

			A name must be set with set_name() before themes can be applied.

			The theme should contain a map of entities that contain values for
			the themeable.

			This function works recursively to apply the theme to the children
			in the caller's hierarchy.

			@param theme - The Theme to apply
		*/
		virtual void apply_theme(Theme& theme);

		/*!
			Assigns tag prefixes to the themeable.

			This function works recursively to assign tag prefixes to the
			caller and child themeables in the caller's hierarchy. Each
			themeable's name gets added to the prefixes list as this function
			gets further down the hierarchy.

			If the default empty list is used, then assignment to the caller is
			skipped while its children continue to have prefixes assigned. The
			caller will still be marked as having its prefixes assigned.

			@param prefixes - QStringList containing the prefixes to assign
		*/
		void assign_tag_prefixes(QStringList prefixes = QStringList());

		/*!
			Returns a list of child themeables.

			Since the themeable should be inherited alongside a QWidget class,
			that should mean that the themeable *is* a QWidget. That means the
			themeable should be capable of being dynamically casted to a
			QWidget, which is the first thing this function does.

			QObject::findChildren() is called to obtain a QList of pointers to
			child QWidgets. Then, another QList is created by iterating the
			child QWidget pointer list, dynamically casting them to %Themeable
			pointers, and appending the ones that successfully cast.

			The QList containing the child themeable pointers is returned.

			@param options - FindChildOptions argument that gets forwarded to
			QObject::findChildren()
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

		virtual Themeable* clone();

		/*!
			Copies entity values of the caller and of child themeables in the
			caller's hierarchy to the provided theme.
			
			This is effectively the reverse of applying a theme.

			@param theme - Theme to copy values to
		*/
		void copy_attribute_values_to(Theme* theme);

		/*!
			Entangles the provided themeable by entangling all entities with
			the entities of the provided themeable.

			@param themeable - The themeable to entangle with
			@param entangle_children - Boolean value determining whether to
			entangle child themeables or not, true by default
		*/
		template<typename T>
		void entangle_with(T* themeable, bool entangle_children = true);

		/*!
			Returns a reference to the entity pointer map.

			@returns Reference to entity pointer map
		*/
		QMap<QString, Entity*>& entities();

		void establish_update_connection(Entity* entity);

		/*!
			Returns pointer to the themeable's icon.
			
			Returns nullptr if no icon has been set.

			@returns Pointer to icon, or nullptr
		*/
		Graphic* icon() const;

		bool is_app_themeable() const;

		/*!
			Returns true if the themeable is stateful, false otherwise.

			The themeable is considered stateful is any of its entities are
			stateful.

			@returns True if stateful, false otherwise
		*/
		bool is_multi_valued() const;

		/*!
			Returns pointer to the themeable's name.

			Returns nullptr if no name has been set.

			@returns Pointer to name, or nullptr
		*/
		QString* name() const;

		/*!
			Returns pointer to the themeable's proper name.
			
			Returns nullptr if no proper name has been set.

			@returns Pointer to proper name, or nullptr
		*/
		QString* proper_name() const;

		/*!
			Marks the themeable as functional or disfunctional.

			This is used primarily to disable certain functionality of the
			preview window owned by the CustomizeMenu.

			@param disabled - Boolean value determining whether to disable the
			themeable's functionality, true by default
		*/
		void set_functionality_disabled(bool disabled = true);

		/*!
			Sets an icon for the themeable; replaces it if one already exists.

			@param icon for the themeable
		*/
		void set_icon(Graphic* icon);

		/*!
			Marks the caller and its children as app themeables.

			This prevents the 'layers' prefix from being prepended to the
			themeable tag.

			@param is_app_themeable - Boolean value determining whether to set
			the themeable as an app themeable or not
		*/
		void set_is_app_themeable(bool is_app_themeable);

		/*!
			Sets the name of the themeable.
			
			If a name already exists, it is replaced.

			@param name - Name to assign to the themeable
		*/
		void set_name(const QString& name);

		/*!
			Sets the proper name of the themeable.

			If a proper name already exists, it is replaced.

			A themeable's proper name is used to represent the themeable to the
			user.

			@param proper_name - Proper name to assign to the themeable
		*/
		void set_proper_name(const QString& proper_name);

		/*!
			Sets the active state of the themeable.

			@param state - New active state to assign to the themeable
		*/
		virtual void set_state(const QString& state);

		/*!
			Returns the active state of the themeable.

			@returns The themeable's active state
		*/
		QString state() const;

		/*!
			Returns a QStringList containing the themeable's available states.

			The themeable's available states are a sum of the available states
			of the themeable's entities.

			@returns QStringList containing available states
		*/
		QStringList states() const;

		/*!
			Get the theme tag.

			The theme tag is created structurally upon calling this function.  The first part of the tag
			is the primary prefix which determines the owning application of the themeable. It is constructed
			as 'app/\a application \a name/'. If the themeable is built-in with Layers, and not application specific,
			then the primary prefix is constructed as 'layers/'.

			The tag is then followed by the tag prefixes. The prefixes are made up of parent themeable names
			going all the way up the hierarchy from the calling themeable. They are separated by slashes in
			the tag.

			The last part of the tag is the themeable's name.

			@returns Theme tag
		*/
		QString& tag();

	protected:
		QMap<QString, Entity*> m_entities{ QMap<QString, Entity*>() };

		bool m_functionality_disabled{ false };

		Graphic* m_icon{ nullptr };
		
		bool m_is_app_themeable{ false };

		QString* m_name{ nullptr };

		QString* m_proper_name{ nullptr };

		QString m_state{ "" };
		
		QString m_tag{ "" };

		QStringList m_tag_prefixes;

		bool m_tag_prefixes_assigned{ false };

		QList<QMetaObject::Connection> m_update_widget_connections{ QList<QMetaObject::Connection>() };
	};

	template<typename T>
	inline void Themeable::entangle_with(T* themeable, bool entangle_children)
	{
		if (typeid(*this) == typeid(*themeable))
		{
			for (const QString& entity_key : m_entities.keys())
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(m_entities[entity_key]))
					attr->entangle_with(*dynamic_cast<Attribute*>(themeable->m_entities[entity_key]));
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(m_entities[entity_key]))
					attr_group->entangle_with(*dynamic_cast<AttributeGroup*>(themeable->m_entities[entity_key]));
			}

			if (entangle_children)
				for (Themeable* this_child_themeable : child_themeables())
					if (this_child_themeable->m_name)
						for (Themeable* child_themeable : themeable->child_themeables())
							if (child_themeable->m_name)
								if (*child_themeable->m_name == *this_child_themeable->m_name)
									this_child_themeable->entangle_with(child_themeable);
		}
	}
}

#endif // THEMEABLE_H
