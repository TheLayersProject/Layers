#ifndef THEMEABLE_H
#define THEMEABLE_H

#include "AttributeGroup.h"

namespace Layers
{
	class AttributeWidget;
	class Graphic;
	class Theme;

	/*!
		The Themeable class is designed to be wrapped with QWidget classes to
		provide them functionality to apply Layers Themes.

		Before a theme can be applied to a themeable, some setup is required.

		## Populate the Entity Pointer Map

		Themeables need to store a map of pointers to all enities associated
		with them. Without this map, themeables would have no way of accessing
		the entities they are supposed to apply theme values to.

		Entities are typically declared as public member variables in classes
		that implement Themeable. Themeable subclass implementations will need
		to populate the Themeable's entity pointer map with pointers to these
		entity variables. The map is accessible through a protected member
		variable called *m_entities*.

		## Themeable Tags

		A themeable tag is an identifier used to identify a particular
		themeable.

		The primary component of the themeable tag is the themeable's name. By
		default, themeables are nameless, 

		Once a name and any necessary tag prefixes have been assigned, a tag
		can be constructed. Tag construction is done automatically after the
		first call to tag() (typically during the first apply_theme() call).
		The tag is cached, so any subsequent calls to tag() will return the
		cached tag.

		Themes store values labeled under these themeable tags. A themeable
		obtains its data from a theme by passing its tag to the theme.
	*/
	class Themeable
	{
	public:
		~Themeable();

		/*!
			Applies the given theme to the caller and its children.

			This function works recursively to apply the given theme to the caller and children in the
			caller's hierarchy.

			A name must be set with set_name() before themes can be applied. This is because a name
			is the minimum requirement to construct the theme tag.

			@param theme to be applied
		*/
		virtual void apply_theme(Theme& theme);

		/*!
			Assigns tag prefixes from the parent and the parent's name.

			This function works recursively to assign tag prefixes to the caller and children in the
			caller's hierarchy. Each themeable's name gets added to the tag prefix list as this function
			gets called down the hierarchy.

			If no arguments are given, then assignment to the caller is skipped and the children have their
			prefixes assigned. However, the caller will still be marked as having its prefixes assigned.
		*/
		void assign_tag_prefixes(QStringList parent_prefixes = QStringList(), const QString& parent_name = "");

		QList<Themeable*> child_themeables(Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

		void copy_attribute_values_to(Theme* theme);

		template<typename T>
		void entangle_with(T* themeable, bool entangle_children = true);

		/*!
			Get a reference to the attribute set of the given state.

			@param state of the attribute set to be returned, 'default' by default
			@returns Reference to attribute set of given state
		*/
		QMap<QString, Entity*>& entities();

		/*!
			Get the address of the themeable's icon. Returns nullptr if no icon exists.

			@returns Address of icon, or nullptr
		*/
		Graphic* icon() const;

		bool is_stateful() const;

		QString* name() const;

		/*!
			Get the address of the proper name. Returns nullptr if no proper name has been set.

			@returns Address of proper name, or nullptr
		*/
		QString* proper_name() const;

		void set_functionality_disabled(bool disabled = true);

		/*!
			Sets an icon for the themeable; replaces it if one already exists.

			@param icon for the themeable
		*/
		void set_icon(Graphic* icon);

		void set_is_app_themeable(bool is_app_themeable);

		/*!
			Sets the name of the themeable; replaces it if one already exists.

			A themeable name is the minimum requirement to construct the themeable's theme tag
			needed to apply a theme.

			@param name of the themeable
		*/
		void set_name(const QString& name);

		/*!
			Sets a proper name for the themeable; replaces it if one already exists.

			A themeable's proper name is used to represent the themeable to the user. It is recommended
			to use capitalization when setting a proper name.

			@param proper_name for the themeable
		*/
		void set_proper_name(const QString& proper_name);

		/*!
			Sets the current state of the themeable.

			This function calls issue_update() to ensure the state change is visually represented.

			@param state to set the themeable to
		*/
		virtual void set_state(const QString& state);

		QString state() const;

		/*!
			Gets a list of the states that are used to identify the caller's attribute sets.

			@returns List of states that identify attribute sets
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

		/*!
			Clears the tag prefix list

			This function works recursively to clear the tag prefixes of the caller and children in the
			caller's hierarchy.
		*/
		void unassign_prefixes();

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
