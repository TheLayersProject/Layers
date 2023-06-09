#ifndef THEMEABLE_H
#define THEMEABLE_H

#include "AttributeGroup.h"

namespace Layers
{
	class Graphic;
	class Theme;

	/*!
		The Themeable class is designed to be inherited alongside QWidget
		classes to provide them functionality to apply Layers themes.

		Before a theme can be applied to a themeable, some setup is required.

		## Populate the Attribute Map

		Themeables need to store a map of pointers to all attributes and
		attribute groups associated with them. Without this map, themeables
		would have no way of accessing the attributes they are supposed to
		apply theme values to.

		Attributes and attribute groups are typically declared as member
		variables in classes that implement %Themeable. These subclasses will
		need to populate the map with pointers to these variables. The map is
		accessible through a protected member variable called *m_attributes*.
		
		~~~~~~~~~~~~~{.c}
		// Example from ThemeableBox::init_attributes()

		m_attributes.insert({
			{ "border", &m_border },
			{ "corner_radii", &m_corner_radii },
			{ "fill", &m_fill },
			{ "margins", &m_margins }
		});
		~~~~~~~~~~~~~

		## Themeable Tags

		![Themeable Tag Example](themeable_tag_example.png)

		A themeable tag is an identifier used to identify a particular
		themeable.

		### Setting a Name

		The primary component of the themeable tag is the themeable's name
		which is appended to the end of the tag. By default, themeables are
		nameless, so <b>it is important to remember to set themeable names
		since they are required for tag construction</b>. You can do this using
		set_name():

		~~~~~~~~~~~~~{.c}
		// Example from Dialog::init_titlebar()

		m_exit_button->set_name("Exit Button");
		~~~~~~~~~~~~~

		### Prefix Assignment

		Tag prefixes consist of the names of the parent themeables in the
		widget hierarchy.

		Prefix assignment is handled by calling assign_tag_prefixes(). It works
		recursively to assign prefixes to associated child themeables.
		It should be called by top-level widgets, such as windows and dialogs.
		
		<b>You will NOT need to call assign_tag_prefixes() if your themeable is
		initialized as a child of a top-level widget that already calls it</b>.
		However, if your themeable is not a child of a top-level widget during
		its initialization, and instead, your themeable is initialized after
		the top-level widget at the top of its hierarchy, then you will need to
		manually call assign_tag_prefixes().

		### Constructing and Caching the Tag

		Once a name and any necessary tag prefixes have been assigned, a tag
		can be constructed. Tag construction is done automatically after the
		first call to tag() (typically during the first apply_theme() call).
		The tag is cached, so any subsequent calls to tag() will return the
		cached tag.

		## Applying Themes

		Once the attribute map has been populated and conditions for tag
		construction are met, a Theme can be applied. This is done by calling
		apply_theme() and passing the theme as an argument.

		Themes store values labeled under themeable tags. When a theme is
		applied, the themeable obtains its data from the theme by passing
		along its tag.

		apply_theme() works recursively to apply the theme to the caller and
		to the child themeables in the caller's hierarchy. <b>As long as your
		themeable is part of the hierarchy of a top-level widget that is known
		by the Application, you will not need to call apply_theme()
		manually</b>.

		## Copying Attribute Values to Themes

		After a user makes changes to a custom theme, they will likely want to
		apply those changes. They do this by clicking on the apply button in
		the ThemeEditor. This causes copy_attribute_values_to() to be called on
		the theme editor's active preview widget, passing along the active theme.

		copy_attribute_values_to() copies attribute values of the caller and of
		child themeables in the caller's hierarchy to the provided theme. It is
		effectively the reverse of applying a theme.

		## Themeable Entanglement

		A themeable can be *entangled* with another themeable. This is handled
		by entangle_with() and works by entangling all of caller's attributes
		with the attributes of the argument themeable.

		It is important to note that entangle_with() will only entangle
		attributes whose pointers have been stored in *m_attributes*.

		This should only be done with themeables that are of the same type.

		Example of %Themeable Entanglement:

		~~~~~~~~~~~~~{.c}
		Button* control_button = new Button("");
		Button* button_1 = new Button("Button 1");
		Button* button_2 = new Button("Button 2");
		Button* button_3 = new Button("Button 3");

		button_1->entangle_with(control_button);
		button_2->entangle_with(control_button);
		button_3->entangle_with(control_button);

		control_button->fill()->set_value(QColor(Qt::green));

		// After setting the fill of control_button to green, the other 3
		// buttons will also have a green fill.
		~~~~~~~~~~~~~

		### Constrain Theme Application to One Entangled Themeable

		Once one themeable has been entangled with another, a theme can be
		applied to a single one of them to change both. You will want to
		constrain theme application to a single themeable in the entanglement
		relationship; otherwise, you may get unexpected results.

		If you want to apply different values to two different themeables, they
		shouldn't be entangled in the first place.
	*/
	class Themeable
	{
	public:
		~Themeable();

		/*!
			Applies *theme* to this themeable and its children.

			A name must be set with set_name() before themes can be applied.

			The theme should contain a map of attributes pertaining to this
			themeable.

			This function works recursively to apply the theme to the children
			in the caller's hierarchy.
		*/
		virtual void apply_theme(Theme& theme);

		/*!
			Assigns tag prefixes to the themeable.

			This function works recursively to assign tag prefixes to the
			caller and child themeables in the caller's hierarchy. Each
			themeable's name gets added to *prefixes* as this function gets
			further down the hierarchy.
		*/
		void assign_tag_prefixes(QStringList prefixes = QStringList());

		/*!
			Returns a reference to the attribute map.
		*/
		QMap<QString, AbstractAttribute*>& attributes();

		/*!
			Returns a list of child themeables.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

		/*!
			Returns a pointer to a new object of the same type as the caller.

			This function should be overridden by top-level widgets.
		*/
		virtual Themeable* clone();

		/*!
			Copies attribute values of the caller and of child themeables in
			the caller's hierarchy to *theme*.
		*/
		void copy_attribute_values_to(Theme* theme);

		/*!
			Entangles this themeable with *themeable* by entangling all
			attributes with the attributes of *themeable*.
		*/
		template<typename T>
		void entangle_with(T* themeable, bool entangle_children = true);

		/*!
			Creates a connection to call QWidget::update() when the
			AbstractAttribute::changed() signal is emitted by
			*abstract_attribute*.
		*/
		void establish_update_connection(
			AbstractAttribute* abstract_attribute);

		/*!
			Returns a pointer to the themeable's icon.
			
			Returns nullptr if no icon has been set.
		*/
		Graphic* icon() const;

		/*!
			Returns true if the themeable was created by an application as
			opposed to Layers; otherwise, returns false.
		*/
		bool is_app_themeable() const;

		/*!
			Returns true if any of this themeable's attributes are
			multi-valued; otherwise, returns false.
		*/
		bool is_multi_valued() const;

		/*!
			Returns a pointer to the name of this themeable.

			Returns nullptr if no name has been set.
		*/
		QString* name() const;

		/*!
			Sets the functionality of this themeable and its children to
			*disabled*.

			This is used primarily to disable certain functionality of the
			active preview widget of the ThemeEditor.
		*/
		void set_functionality_disabled(bool disabled = true);

		/*!
			Sets an icon for the themeable; replaces it if one already exists.
		*/
		void set_icon(const Graphic& icon);

		/*!
			Marks the caller and its children as application themeables.
		*/
		void set_is_app_themeable(bool is_app_themeable);

		/*!
			Marks the caller and its children as themeables that are blocked
			from being copied to a theme.
		*/
		void set_is_blocked_from_theme(bool is_blocked_from_theme);

		/*!
			Marks the caller and its children as preview themeables.
		*/
		void set_is_preview_themeable(bool is_preview_themeable);

		/*!
			Sets the name of this themeable.
			
			If a name already exists, it is replaced.
		*/
		void set_name(const QString& name);

		/*!
			Sets the active state of this themeable.
		*/
		virtual void set_state(const QString& state);

		/*!
			Returns the active state of this themeable.
		*/
		QString state() const;

		/*!
			Returns a QStringList containing the available states of this
			themeable.

			The themeable's available states are a sum of the available states
			of the themeable's attributes.
		*/
		QStringList states() const;

		/*!
			Get the tag for this themeable.

			If the tag has not been constructed yet, it will be constructed
			after the first call to this function and then stored to be
			returned in subsequent calls.
		*/
		QString& tag();

		/*!
			Returns a QStringList containing the tag prefixes of this
			themeable.
		*/
		QStringList tag_prefixes() const;

	protected:
		QMap<QString, AbstractAttribute*> m_attributes;

		bool m_functionality_disabled{ false };

		Graphic* m_icon{ nullptr };
		
		bool m_is_app_themeable{ false };

		bool m_is_blocked_from_theme{ false };

		bool m_is_preview_themeable{ false };

		QString* m_name{ nullptr };

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
			for (const QString& entity_key : m_attributes.keys())
			{
				if (Attribute* attr = dynamic_cast<Attribute*>(m_attributes[entity_key]))
					attr->entangle_with(*dynamic_cast<Attribute*>(themeable->m_attributes[entity_key]));
				else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(m_attributes[entity_key]))
					attr_group->entangle_with(*dynamic_cast<AttributeGroup*>(themeable->m_attributes[entity_key]));
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
