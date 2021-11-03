#ifndef THEMEABLE_H
#define THEMEABLE_H

#include "AttributeSet.h"

namespace Layers
{
	class AttributeWidget;
	class CustomizePanel;
	class Graphic;
	class Theme;

	/*!
		Provides compatibility and structure for the Layers theme system.

		The Themeable class is designed to be wrapped with QWidget classes to allow them to be themed
		in a Layers application. A themeable builds a theme tag from details provided during
		initialization. The tag is used to retrieve attributes from themes.

		Before a theme can be applied to a themeable, the themeable must have a name.
		This is because a name is the minimum requirement to construct the theme tag.
		To set a themeable's name, use set_name().

		Themes are applied to themeables recursively through apply_theme(). To do this,
		references to child themeables need to be stored. These references are stored
		through add_child_themeable_reference().

		Before a themeable can be customized in a Layers application, two requirements
		must be fullfilled:
			1. A proper name must be defined with set_proper_name()
			2. Classes that implement Themeable need to define setup_customize_panel()
	*/
	class Themeable
	{
	public:
		~Themeable();

		void add_attribute(const QString& attribute_name, QVariant value);

		void add_attribute(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		/*!
			Adds a themeable to the child themeable references list.

			If the caller has already assigned tag prefixes, then the newly added themeable reference
			will have its prefixes assigned during this function. Otherwise, child themeables will
			have their prefixes assigned when the parent calls assign_tag_prefixes().

			@param child_themeable to be added to the reference list
		*/
		void add_child_themeable_reference(Themeable* child_themeable);

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
		void assign_tag_prefixes(QList<QString> parent_prefixes = QList<QString>(), const QString& parent_name = "");

		Attribute* attribute(const QString& attribute_name);

		/*!
			Get a reference to the attribute set of the given state.

			@param state of the attribute set to be returned, 'default' by default
			@returns Reference to attribute set of given state
		*/
		AttributeSet& attribute_set();

		QMap<QString, AttributeWidget*>& attribute_widgets();

		QList<Themeable*>& child_themeable_references();

		void convert_attribute_to_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		void copy_attribute_values_to(Theme* theme);

		/*!
			Gets the address of the currently applied theme. Returns nullptr if no theme has been applied.

			@returns Address of currently applied theme, or nullptr
		*/
		Theme* current_theme();

		/*!
			Get the address of the themeable's customize panel. Returns nullptr if the panel does not exist.

			@returns Address of customize panel, or nullptr
		*/
		CustomizePanel* customize_panel() const;

		/*!
			Adds the given attribute to an attribute filtration list.

			@param attribute to filter
		*/
		void filter_attribute(const QString& attribute);

		/*!
			Get the address of the themeable's icon. Returns nullptr if no icon exists.

			@returns Address of icon, or nullptr
		*/
		Graphic* icon() const;

		/*!
			Initializes customize panels and adds them to the provided list.

			This function works recursively to initialize all of the customize panels in the caller's
			hierarchy. As the panels are created, they are added to the list parameter.

			@param list to store initialized customize panels
		*/
		void initialize_and_acquire_panels(QList<CustomizePanel*>& list);

		bool is_stateful() const;

		/*!
			Calls the inheriting QWidget's update() function

			This is a pure virtual function that must be defined by other classes that inherit the
			Themeable class. This function should be used to call the inheriting QWidget's update().
		*/
		virtual void issue_update() = 0;

		/*!
			Get the address of the proper name. Returns nullptr if no proper name has been set.

			@returns Address of proper name, or nullptr
		*/
		QString* proper_name() const;

		/*!
			Reapplies the theme that is already applied to the caller.

			Does nothing if no theme has been applied yet.
		*/
		void reapply_theme();

		/*!
			Removes the given child themeable from the references list and unassigns tag prefixes.

			@param child_themeable to be removed from the reference list
		*/
		void remove_child_themeable_reference(Themeable* child_themeable);

		void replace_attribute_with_proxy(const QString& attribute_name, Attribute* proxy_attribute);

		//void set_ACW_primary(const QString& ACW_name, bool is_primary);

		void set_is_app_themeable(bool is_app_themeable);

		void set_functionality_disabled(bool disabled = true);

		void set_attribute_value(
			const QString& state,
			const QString& attribute_name,
			QVariant value);

		void set_attribute_value(
			const QString& attribute_name,
			QVariant value);

		/*!
			Sets an icon for the themeable; replaces it if one already exists.

			@param icon for the themeable
		*/
		void set_icon(Graphic* icon);

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

		template<typename T>
		void replace_all_attributes_with(T* themeable);

		QString state() const;

		/*!
			Get a reference to the attribute set of the given state.

			@param state of the attribute set to be returned, 'default' by default
			@returns Reference to attribute set of given state
		*/
		//QMap<QString, StatefulAttribute>& stateful_attributes();

		/*!
			Gets a list of the states that are used to identify the caller's attribute sets.

			@returns List of states that identify attribute sets
		*/
		QList<QString> states() const;

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
		QString& theme_tag();

		/*!
			Clears the tag prefix list

			This function works recursively to clear the tag prefixes of the caller and children in the
			caller's hierarchy.
		*/
		void unassign_prefixes();

		/*!
			Removes the given attribute from the attribute filtration list.

			@param attribute to stop filtering
		*/
		void unfilter_attribute(const QString& attribute);

		/*!
			Updates things that depend on the theme. Called by apply_theme().

			This function can be defined by implementers of the Themeable class to handle anything they want
			to change when a theme gets applied that can't be changed through attributes. However, it
			is not required to implement this function.
		*/
		virtual void update_theme_dependencies();

	protected:
		/*!
			Initializes the attributes.

			This is a pure virtual function that must be defined by other classes that inherit the
			Themeable class. This function should be used to define a themeable's attributes with
			calls to set_attribute_value().

			This function is called by init_themeable().
		*/
		virtual void init_attributes();

		virtual void init_attribute_widgets();

		/*!
			Initializes the customize panel.

			A themeable MUST have a proper name to initialize a customize panel. Set one using set_proper_name().

			This function is responsible for calling setup_customize_panel(), which is a pure virtual function
			that must be defined by other classes that inherit the Themeable class.

			@returns The initialized customize panel.
		*/
		CustomizePanel* init_customize_panel();

		/*!
			Initializes the reference list to child themeables.

			A list of child themeable references is necessary to allow the apply_theme() function
			to work recursively.

			Classes that inherit the Themeable class should define this function and use
			add_child_themeable_reference() to populate the reference list.

			This function is called by init_themeable().
		*/
		virtual void init_child_themeable_reference_list();

		bool m_functionality_disabled{ false };
		bool m_tag_prefixes_assigned{ false };
		bool m_shared_attributes{ false };
		bool m_is_app_themeable{ false };
		bool m_is_stateful{ false };

		CustomizePanel* m_customize_panel{ nullptr };

		Graphic* m_icon{ nullptr };

		QString* m_name{ nullptr };
		QString* m_proper_name{ nullptr };
		QString m_state{ "" };
		QString m_theme_tag{ "" };

		QMap<QString, bool> m_ACW_pre_init_primary_values{ QMap<QString, bool>() };
		QMap<QString, AttributeWidget*> m_attribute_widgets{ QMap<QString, AttributeWidget*>() };

		AttributeSet m_attribute_set{ AttributeSet() };

		QList<Themeable*> m_child_themeable_references;

		QList<QString> m_filtered_attributes;
		QList<QString> m_tag_prefixes;

		Theme* m_current_theme{ nullptr };
	};

	template<typename T>
	inline void Themeable::replace_all_attributes_with(T* themeable)
	{
		if (typeid(*this) == typeid(*themeable))
		{
			m_attribute_set.replace_all_with(themeable->attribute_set());

			for (Themeable* this_child_themeable : m_child_themeable_references)
				if (this_child_themeable->m_name)
					for (Themeable* child_themeable : themeable->m_child_themeable_references)
						if (*child_themeable->m_name == *this_child_themeable->m_name)
							this_child_themeable->replace_all_attributes_with(child_themeable);
		}
	}
}

#endif // THEMEABLE_H
