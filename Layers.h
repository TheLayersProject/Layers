#ifndef LAYERS_H
#define LAYERS_H

#include <QApplication>
#include <QColorDialog>
#include <QDebug>
#include <QDir>
#include <QFontMetrics>
#include <QGraphicsDropShadowEffect>
#include <QGridLayout>
#include <QHash>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QMenuBar>
#include <QMouseEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>
#include <QPainterPath>
#include <QSaveFile>
#include <QScrollArea>
#include <QScrollBar>
#include <QSettings>
#include <QSvgWidget>
#include <QTabBar>
#include <QTimer>
#include <QVersionNumber>
#include <QVBoxLayout>
#include <QWidget>

#include <Windows.h>
#include <windowsx.h>

namespace Layers
{
	class Application;
	class AttributeSharingCombo;
	class AttributeWidget;
	class ColorControl;
	class CustomizePanel;
	class Graphic;
	class Label;
	class StatelessAttribute;
	class Theme;
	class Themeable;
	class Titlebar;
	class Widget;
	class Window;
}

#define layersApp (static_cast<Layers::Application*>(qApp))

namespace Layers
{
	inline int round(double d)
	{
		return floor(d + 0.5);
	}

	inline bool is_even(int i)
	{
		if (i % 2) return false;

		return true;
	}

	inline int inner_radius(int outer_radius, int thickness)
	{
		double border_lower_bound = 3;
		double border_range = 27;
		double border_percent = (thickness - border_lower_bound) / border_range;

		double y_int_lower_bound = -2.2164;
		double y_int_range = 2.5446;

		double slope_lower_bound = 0.3435;
		double slope_range = 0.6205;

		double y_int = (border_percent * y_int_range) + y_int_lower_bound;

		double slope = ((1 - border_percent) * slope_range) + slope_lower_bound;

		int value = round(slope * double(outer_radius) + y_int);

		if (value < 0) value = 0;

		return value;
	}

	QString app_path(const QString& app_name);
	QString app_themes_path(const QString& app_name);
	QString deprecated_layers_path();
	QString deprecated_layers_themes_path();
	QString local_app_data_path();

	Theme build_layers_blue_theme();
	Theme build_layers_dark_theme();
	Theme build_layers_light_theme();

	class ImageSequence
	{
	public:
		ImageSequence(QDir dir);

		ImageSequence(QFile file);

		void save(QFile file);

		QList<QPixmap> to_pixmaps() const;

	private:
		QList<QImage> m_images{ QList<QImage>() };
	};

	class Version
	{
	public:
		Version(int major, int minor = 0, int patch = 0, QString phase = "");

		Version(QString version_string);

		Version();

		QString toString();

	private:
		const QList<QString> m_acceptable_phases{ QList<QString>({
			"alpha", "a", "beta", "b", "release-candidate", "rc" }) };

		int m_major{ 0 };
		int m_minor{ 0 };
		int m_patch{ 0 };

		QString m_phase{ "" };

		QString m_separator_charactor{ "" };
	};

	class GitHubRepo
	{
	public:
		GitHubRepo(const QString& repo_url);

		QString toString() const;

	private:
		QString m_repo_name{ "" };
		QString m_user_name{ "" };
	};

	/*!
		Pure abstract base class for Layers attributes.

		Implementers of the Attribute class will need to define the value() function since
		this class does not implement the representation of the attribute value(s).

		The functions name(), parent_themeable(), and set_parent_themeable() are defined by
		this class as they are not expected to be different between subclasses.
	*/
	class Attribute
	{
	public:
		/*!
			Constructor for the Attribute base class.

			Subclasses are to call this constructor passing along an attribute name string.
		*/
		Attribute(const QString& name);

		/*!
			Returns the name of the attribute.

			@returns Name of attribute
		*/
		QString& name();

		/*!
			Returns pointer to the parent themeable associated with the attribute.

			Attributes stored in themes will not have associated parent themeables so
			this function will return nullptr for those attributes.

			@returns Pointer to associated parent themeable, if one exists
		*/
		Themeable* parent_themeable() const;

		/*!
			Stores the provided parent themeable pointer.

			@param parent_themeable pointer to store
		*/
		void set_parent_themeable(Themeable* parent_themeable);

		/*!
			Pure virtual function intended to return the attribute value in the form of a QVariant reference.

			@returns Attribute value reference
		*/
		virtual QVariant& value() = 0;

	protected:
		QString m_name{ "" };

		Themeable* m_parent_themeable{ nullptr };
	};

	/*!
		Provides structure for storing attribute values.

		The Attribute class provides the data structure used by Themes and Themeables to store
		attribute values and attribute metadata, like the attribute's name.

		An attribute value can be of any type supported by the QVariant class.

		Attributes can either store a single value or multiple values associated with different
		states. Attributes that are not associated with states and only store a single value store
		that value as a QVariant. Stateful attributes store their values in a QMap associating 
		QStrings with QVariants, the states and values.

		Since the class representation uses two different mechanisms for storing values,
		users of the Attribute class will need to use two different sets of functions depending on
		whether or not the attribute is stateful.
	*/
	class StatelessAttribute : public Attribute
	{
	public:
		StatelessAttribute();
		StatelessAttribute(const QString& name, QVariant value);

		/*!
			Sets the value.

			@param value to set
		*/
		void set_value(QVariant value);

		/*!
			Returns the value of the attribute

			@returns Attribute's value
		*/
		QVariant& value();

		friend QDataStream& operator <<(QDataStream& stream, const StatelessAttribute& a)
		{
			stream << a.m_name;
			stream << a.m_value;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, StatelessAttribute& a)
		{
			stream >> a.m_name;
			stream >> a.m_value;
			return stream;
		}

	private:
		QVariant m_value{ QVariant() };
	};

	class StatefulAttribute : public Attribute
	{
	public:
		StatefulAttribute();
		StatefulAttribute(const QString& name, QMap<QString, QVariant> state_value_map);

		/*!
			Checks if the provided state already exists in the data structure.

			@param state to check
			@returns True if state exists, false if not
		*/
		bool contains_state(const QString& state) const;

		/*!
			Sets the current state of the attribute.

			@param state to mark as the current attribute state
		*/
		void set_state(const QString& state);

		/*!
			Sets the value of the provided state.

			This function only works if the provided state already exists in the data structure.

			@param state to update value of
			@param value pair with state
		*/
		void set_value(const QString& state, QVariant value);

		void set_values(const QMap<QString, QVariant>& values);

		/*!
			Returns the current state of the attribute.

			@returns Current state of attribute
		*/
		QString state() const;

		/*!
			Returns list of all the attribute's states.

			@returns List of attribute's states
		*/
		QList<QString> states() const;

		/*!
			Returns the value paired with the provided state.

			@returns Attribute value of the provided state
		*/
		QVariant* value(const QString& state);

		/*!
			Returns the value paired with the current state.

			@returns Attribute value of the current state
		*/
		QVariant& value();

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const StatefulAttribute& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, StatefulAttribute& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class AttributeSet
	{
	public:
		void add_attribute(StatelessAttribute attribute);

		void add_attribute(StatefulAttribute attribute);

		Attribute* attribute(const QString& attribute_name);

		QVariant* attribute_value(const QString& attribute_name);

		bool contains(const QString& attribute_name);

		bool contains_stateful_attribute(const QString& attribute_name);

		bool contains_stateless_attribute(const QString& attribute_name);

		void copy_values_from(AttributeSet& other_attribute_set);

		void remove_attribute(const QString& attribute_name);

		void set_state(const QString& state);

		StatefulAttribute* stateful_attribute(const QString& attribute_name);

		QMap<QString, StatefulAttribute>& stateful_attributes();

		StatelessAttribute* stateless_attribute(const QString& attribute_name);

		QMap<QString, StatelessAttribute>& stateless_attributes();

		QList<QString> states() const;

		friend QDataStream& operator <<(QDataStream& stream, const AttributeSet& as)
		{
			stream << as.m_stateful_attributes;
			stream << as.m_stateless_attributes;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, AttributeSet& as)
		{
			stream >> as.m_stateful_attributes;
			stream >> as.m_stateless_attributes;
			return stream;
		}

	private:
		QMap<QString, StatefulAttribute> m_stateful_attributes{ QMap<QString, StatefulAttribute>() };
		QMap<QString, StatelessAttribute> m_stateless_attributes{ QMap<QString, StatelessAttribute>() };
	};

	/*!
		Provides structure for Layers themes.

		Layers themes store sets of attributes associated with their themeable tags. When a theme is applied,
		themeables retrieve their attribute sets from the theme by passing along their tags.
	*/
	class Theme
	{
	public:
		Theme();
		Theme(const QString& name, bool is_custom = true);

		void add_attribute_set(const QString& themeable_tag, AttributeSet attribute_set);

		void add_stateful_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		/*!
			Add an attribute to the theme.

			This implementation of this function adds an attribute with a single value.

			@param themeable_tag of themeable associated with attribute
		*/
		void add_stateless_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QVariant value);

		// Recommend calling contains_attributes_for_tag() before calling this since this function
		// does not check if it contains an attribute set for the given themeable tag.
		AttributeSet& attribute_set(const QString& themeable_tag);

		QHash<QString, AttributeSet>& attribute_sets();

		void consume(Theme&& theme);

		bool contains_attributes_for_tag(const QString& themeable_tag);

		// Only needs one version since attribute names should not exist in both stateless and stateful lists
		bool contains_attribute(const QString& themeable_tag, const QString& attribute_name);

		void copy_attribute_sets_from(Theme& theme);

		void copy_attribute_values_of(Themeable* themeable);

		bool is_custom();

		QString& name();

		void set_name(const QString& new_name);

		StatefulAttribute* stateful_attribute(const QString& themeable_tag, const QString& attribute_name);

		StatelessAttribute* stateless_attribute(const QString& themeable_tag, const QString& attribute_name);

		friend QDataStream& operator <<(QDataStream& stream, const Theme& t)
		{
			stream << t.m_attribute_sets;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme& t)
		{
			stream >> t.m_attribute_sets;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		QHash<QString, AttributeSet> m_attribute_sets{ QHash<QString, AttributeSet>() };

		bool m_is_custom{ true };

		QString m_name{ "" };
	};

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

		void add_stateless_attribute(const QString& attribute_name, QVariant value);

		void add_stateful_attribute(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		/*!
			Adds a themeable to the child themeable references list.

			If the caller has already assigned tag prefixes, then the newly added themeable reference
			will have its prefixes assigned during this function. Otherwise, child themeables will
			have their prefixes assigned when the parent calls assign_tag_prefixes().

			@param child_themeable to be added to the reference list
		*/
		void add_child_themeable_reference(Themeable* child_themeable);

		/*!
			Adds a new state with a unique set of attributes.

			This function works recursively to add a new state and attribute set to all of the themeables
			in the caller's hierarchy. The new attribute set is created as a copy of the 'commmon' attribute set. (<-- CHANGE; NOT INTENT!)

			@param state to be added with unique attribute set
		*/
		//virtual void add_state(const QString& state);

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

		//void copy_all_attributes_to_theme(Theme& theme);

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

		//void make_attribute_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

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

		void set_ACW_primary(const QString& ACW_name, bool is_primary);

		void set_is_app_themeable(bool is_app_themeable);

		void set_functionality_disabled(bool disabled = true);

		void set_stateful_attribute_value(
			const QString& state,
			const QString& attribute_name,
			QVariant value,
			bool update = false); // IF-FAIL: Try setting to true?

		void set_stateless_attribute_value(
			const QString& attribute_name,
			QVariant value,
			bool update = false);

		/*!
			Sets a value for an attribute in an attribute set

			Attribute sets are a mapping of states to sets of attributes.  The particular
			attribute set that receives the new attribute value is defined by the state parameter.

			This function calls issue_update() to ensure the new attribute value is visually represented.

			@param attribute to set the value of
			@param value to set the attribute to
			@param state of the attribute set, 'default' by default
		*/
		//void set_attribute_value(const QString& attribute, QVariant value, const QString& state = "Default", bool update = true);

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

		/*!
			Shares all attributes with another themeable.

			This function only works if the themeable argument is the same type as the calling themeable.
		*/
		template<typename T>
		void share_all_attributes_with(T* themeable);

		/*!
			Establishes an attribute-value sharing relationship with another themeable.

			@param from_state The state of the attribute set of the from_attribute
			@param from_attribute The attribute to share with the to_themeable
			@param to_themeable The themeable to share the attribute with
			@param to_state The state of the attribute set of the to_attribute
			@param to_attribute The attribute of the to_themeable to store the incoming from_attribute value
			@param obtain_attribute Whether or not to obtain the value of the to_themeable, false by default
			@returns the address of the new attribute sharing combo
		*/
		//AttributeSharingCombo* share_attribute_with_themeable(
		//	const QString& from_state, const QString& from_attribute,
		//	Themeable* to_themeable, QString to_state = "", QString to_attribute = "",
		//	bool obtain_attribute = false
		//);

		AttributeSharingCombo* share_attribute_with_themeable(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatefulAttribute* to_stateful_attribute, QString to_state,
			bool obtain_attribute = false
		);

		AttributeSharingCombo* share_attribute_with_themeable(
			StatelessAttribute* from_stateless_attribute,
			StatelessAttribute* to_stateless_attribute,
			bool obtain_attribute = false
		);

		AttributeSharingCombo* share_attribute_with_themeable(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatelessAttribute* to_stateless_attribute,
			bool obtain_attribute = false
		);

		AttributeSharingCombo* share_attribute_with_themeable(
			StatelessAttribute* from_stateless_attribute,
			StatefulAttribute* to_stateful_attribute, QString to_state,
			bool obtain_attribute = false
		);

		/*!
			Shares attributes with themeables according to established sharing relationships.

			Attribute sharing relationships are established with share_attribute_with_themeable(). While the
			from-attribute value is copied over at that time, changes to the from-attribute will not update to
			the to-attribute until this function is called.
		*/
		void share_attributes();

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
			Removes and returns the address of the attribute sharing combo that is formed with the given parameters.

			The caller becomes responsible for the resource pointed to by the returned address!

			@param from_state
			@param from_attribute
			@param to_themeable
			@param to_state
			@param to_attribute
		*/
		AttributeSharingCombo* take_attribute_sharing_combo(
			const QString& from_state, const QString& from_attribute,
			Themeable* to_themeable, const QString& to_state, const QString& to_attribute
		);

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
			Break all sharing relationships with another themeable.

			This function only works if the themeable argument is the same type as the calling themeable.
		*/
		template<typename T>
		void unshare_all_attributes_with(T* themeable);

		/*!
			Break a sharing relationship with another themeable

			@param from_attribute - The attribute to unshare with the to_themeable
			@param to_themeable - The themeable to unshare the attribute with
			@param from_state - The state of the attribute set of the from_attribute
			@param to_state - The state of the attribute set of the to_attribute
		*/
		//void unshare_attribute_with_themeable(
		//	const QString& from_state, const QString& from_attribute,
		//	Themeable* to_themeable, QString to_state = "", QString to_attribute = ""
		//);

		//void unshare_attribute_with_themeable(
		//	StatelessAttribute& from_attribute, StatelessAttribute& to_attribute,
		//	QString from_state = "", QString to_state = "");

		void unshare_attribute_with_themeable(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatefulAttribute* to_stateful_attribute, QString to_state);

		void unshare_attribute_with_themeable(
			StatelessAttribute* from_stateless_attribute,
			StatelessAttribute* to_stateless_attribute);

		void unshare_attribute_with_themeable(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatelessAttribute* to_stateless_attribute);

		void unshare_attribute_with_themeable(
			StatelessAttribute* from_stateless_attribute,
			StatefulAttribute* to_stateful_attribute, QString to_state);

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

		QList<AttributeSharingCombo*> attribute_sharing_combos;

		Theme* m_current_theme{ nullptr };
	};

	/*!
		Stores the themeable addresses, states, and attributes needed to establish an attribute sharing connection.

		An AttributeSharingCombo is created and stored when Themeable::share_attribute_with_themeable() is called
	*/
	class AttributeSharingCombo
	{
	public:
		AttributeSharingCombo(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatefulAttribute* to_stateful_attribute, QString to_state);

		AttributeSharingCombo(
			StatelessAttribute* from_stateless_attribute,
			StatelessAttribute* to_stateless_attribute);

		AttributeSharingCombo(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatelessAttribute* to_stateless_attribute);

		AttributeSharingCombo(
			StatelessAttribute* from_stateless_attribute,
			StatefulAttribute* to_stateful_attribute, QString to_state);

		StatefulAttribute* from_stateful_attribute();

		StatelessAttribute* from_stateless_attribute();

		Themeable* from_themeable() const;

		QString& from_state();

		QString& from_attribute_name();

		/*!
			Obtains the value of the to_attribute

			If the from_attribute is a QString, and the to_attribute is an int, or vice-versa, then
			this function will convert the incoming to_attribute value into the type of the from_attribute.

			@param update_shares_and_dependencies controls whether attribute shares and theme dependencies gets updated or not, true by default
		*/
		void obtain_attribute(bool update_shares_and_dependencies = true);

		/*!
			Shares the value of the from_attribute

			If the from_attribute is a QString, and the to_attribute is an int, or vice-versa, then
			this function will convert the outgoing to_attribute value into the type of the from_attribute.
		*/
		void share_attribute();

		StatefulAttribute* to_stateful_attribute();

		StatelessAttribute* to_stateless_attribute();

		Themeable* to_themeable() const;

		QString& to_state();

		QString& to_attribute_name();

	private:
		StatefulAttribute* m_from_stateful_attribute{ nullptr };
		StatefulAttribute* m_to_stateful_attribute{ nullptr };

		StatelessAttribute* m_from_stateless_attribute{ nullptr };
		StatelessAttribute* m_to_stateless_attribute{ nullptr };

		QString m_from_state{ "" };
		QString m_to_state{ "" };
	};

	class HorizontalLayout : public QHBoxLayout
	{
	public:
		HorizontalLayout(QWidget* parent = nullptr);

		void set_border_margin(int border_margin);
		void setContentsMargins(int left, int top, int right, int bottom);

		void update_margins();

	protected:
		int m_margin_left{ 0 };
		int m_margin_top{ 0 };
		int m_margin_right{ 0 };
		int m_margin_bottom{ 0 };
		int m_border_margin{ 0 };
	};

	class VerticalLayout : public QVBoxLayout
	{
	public:
		VerticalLayout(QWidget* parent = nullptr);

		void set_border_margin(int border_margin);
		void setContentsMargins(int left, int top, int right, int bottom);

		void update_margins();

	protected:
		int m_margin_left{ 0 };
		int m_margin_top{ 0 };
		int m_margin_right{ 0 };
		int m_margin_bottom{ 0 };
		int m_border_margin{ 0 };
	};

	/*!
		The Widget class wraps a QWidget with a Themeable to give QWidgets compatibility with the Layers theme
		system. The Layers Widget class overrides the QWidget's paintEvent() and uses the attributes provided
		by the Themeable class to handle the widget's appearance.
	*/
	class Widget : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		Widget(QWidget* parent = nullptr);

		/*!
			Sets all margin attributes with one value.

			@param margin
		*/
		void set_margin(int margin);

		/*!
			Sets the margin attributes individually.

			@param left margin
			@param top margin
			@param right margin
			@param bottom margin
		*/
		void set_margin(int left, int top, int right, int bottom);

		/*!
			Updates anything that can't be changed with attributes.

			As a Widget, this function updates the border margins of the layout if the layout happens to be
			a Layers::Horizontal_Layout or Layers::VerticalLayout.
		*/
		void update_theme_dependencies();

	protected:
		/*!
			Overrides the QWidget::eventFilter() to handle widget hover coloring
		*/
		bool eventFilter(QObject* object, QEvent* event) override;

		/*!
			Initializes the widget's attributes.

			This function uses calls to set_attribute_value() to define attributes.

			Widget attributes include background color/gradient, corner radii, margins, outline color, and
			other varius numerical values, colors, and booleans.
		*/
		void init_attributes();

		void init_attribute_widgets();

		/*!
			Calls the QWidget's update() function
		*/
		void issue_update();

		/*!
			Paints the widget with values obtained from the widget's attributes.
		*/
		void paintEvent(QPaintEvent* event) override;

		QPainter painter;
	};

	class ScrollArea : public Widget
	{
		Q_OBJECT

	public:
		ScrollArea(QWidget* parent = nullptr);

		void issue_update();

		void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy);

		void setWidget(QWidget* widget);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		QScrollArea* m_scroll_area{ new QScrollArea(this) };

		QScrollBar* m_horizontal_scrollbar{ new QScrollBar };
		QScrollBar* m_vertical_scrollbar{ new QScrollBar };
	};

	class ImageSequenceLabel : public QLabel
	{
		Q_OBJECT

	public:
		//ImageSequenceLabel(QDir dir, QSize size, QWidget* parent = nullptr);
		ImageSequenceLabel(ImageSequence image_sequence, QSize size, QWidget* parent = nullptr);
		ImageSequenceLabel(const ImageSequenceLabel& isl);
		//~ImageSequenceLabel();

	public slots:
		void time_out();

	private:
		int m_frame_number{ 0 };

		QTimer m_timer;

		QList<QPixmap> m_pixmaps{ QList<QPixmap>() };
	};

	/*!
		The SVG class provides representation for SVG files in Layers.

		An SVG loads an SVG file into a string. To make the SVG appear on the screen, the string is passed to
		QSvgWidget::load(). The load function can be called indefinitely. Therefore, changes can be made to the SVG string
		and loaded again, allowing for theme application.

		Manipulating the SVG string itself would be punishing. To make this easier, a list of SVG elements is built from
		the string with build_svg_elements_list().

		The SVG's constructors wait to call Themeable::init_themeable() until after the SVG elements list has been built.
		This is because the SVG::init_attributes() function, which is called virtually by Themeable::init_themeable(),
		depends on the elements list.

		When a theme is applied to the SVG, the attributes are updated to values provided in the applied theme, but
		the SVG string needs to be updated with the new attribute values and passed along to QSvgWidget::load() before the
		appearance of the SVG updates. This class implements update_theme_dependencies() to ensure that this all
		happens after theme application.
	*/
	class SVG : public QSvgWidget, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG from an SVG file.
		*/
		SVG(QString file_path, QWidget* parent = nullptr);

		/*!
			Copy constructs an SVG from another SVG.
		*/
		SVG(const SVG& svg_w);

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		void set_hovering(bool cond = true);

		/*!
			Updates things that depend on the theme.

			SVG elements are updated with the newly applied theme's attribute values. Then, the SVG string is rebuilt
			from those elements. And finally, the SVG string is passed to QSvgWidget::load() to update the SVG's
			appearance.
		*/
		void update_theme_dependencies();

	protected:
		/*!
			Initializes the attributes.

			This function is called by init_themeable().
		*/
		void init_attributes();

		void init_attribute_widgets();

		/*!
			Calls the QSvgWidget's update() function.
		*/
		void issue_update();

	private:
		void init_size();

		void build_svg_elements_list();

		QString element_id(const QString& element);

		bool m_hovering{ false };

		QString m_svg_str{  };

		QStringList m_svg_elements{  };
	};

	class Graphic : public Widget
	{
		Q_OBJECT

	public:
		Graphic(const ImageSequence& image_sequence, QSize size, QWidget* parent = nullptr);
		Graphic(const QString& filepath, QSize size, QWidget* parent = nullptr);
		Graphic(const QString& filepath, QWidget* parent = nullptr);
		Graphic(const QImage& image, QWidget* parent = 0);
		Graphic(const Graphic& gw);

		void convert_attribute_to_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		QSize image_size();

		void set_hovering(bool cond = true);
		void set_icon(Graphic* icon);
		void set_pixmap(const QPixmap& pixmap);
		void set_size(QSize size);

		SVG* svg() const;

		void update_theme_dependencies();

	protected:
		void init_attribute_widgets();

	private:
		QSize m_image_size{ QSize() };
		QLabel* m_bitmap_label{ nullptr };
		SVG* m_svg_widget{ nullptr };
		ImageSequenceLabel* m_image_sequence_label{ nullptr };
	};

	class Label : public QLabel, public Themeable
	{
		Q_OBJECT

	public:
		Label(QWidget* parent = nullptr);
		Label(const QString& text, QWidget* parent = 0);

		void init_attribute_widgets();

		void issue_update();

		void resize();

		void build_wrapped_lines();

		void setFont(const QFont& f);

		void setMaximumWidth(int maxw);

		void setWordWrap(bool on);

		void set_available_width(int available_width);
		void set_font_size(int size);
		void set_hovering(bool cond = true);
		void set_padding(int left, int top, int right, int bottom);
		void set_resize_disabled(bool disable = true);

		int width_unwrapped();

	public slots:
		void setText(const QString& text);

	protected:
		void init_attributes();
		void paintEvent(QPaintEvent* event);

		QList<QString> m_wrapped_lines;

		QPainter painter;

		bool m_hovering{ false };
		bool m_resize_disabled{ false };
		bool m_wrapping{ false };

		int m_available_width{ 16777215 };

		int m_padding_left{ 0 };
		int m_padding_top{ 0 };
		int m_padding_right{ 0 };
		int m_padding_bottom{ 0 };
	};

	class ToggleSwitch : public Widget
	{
		Q_OBJECT

	signals:
		void toggled_event();

	public:
		ToggleSwitch(QWidget* parent = nullptr);
		ToggleSwitch(const QString& first_label_text, const QString& second_label_text, QWidget* parent = nullptr);

		void set_toggled(bool toggled);

		void toggle();

		bool toggled() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Label* m_first_label{ nullptr };
		Label* m_second_label{ nullptr };

		QGraphicsOpacityEffect* m_first_label_opacity{ new QGraphicsOpacityEffect };
		QGraphicsOpacityEffect* m_second_label_opacity{ new QGraphicsOpacityEffect };

		Widget* m_spacer{ new Widget };
		Widget* m_square{ new Widget };
		Widget* m_switch{ new Widget };
	};

	class Button : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();

	public:
		Button(Graphic* graphic, const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic* graphic, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic* graphic_before, Graphic* graphic_after, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);

		void disable_graphic_hover_color(bool cond = true);
		void disable_text_hover_color(bool cond = true);

		bool disabled() const;

		Graphic* graphic() const;

		void resize();

		void set_attribute_value(const QString& attribute, QVariant value);
		void set_available_width(int available_width);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_padding(int padding);
		void set_padding(int left, int top, int right, int bottom);
		void set_text_padding(int left, int top, int right, int bottom);

		int left_padding() const;
		int top_padding() const;
		int right_padding() const;
		int bottom_padding() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init();
		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		void setup_layout();

	private:
		QHBoxLayout* main_layout{ new QHBoxLayout };

		QGraphicsOpacityEffect* m_button_opacity{ new QGraphicsOpacityEffect };

		bool m_auto_touch_target_compliance{ false };

		bool m_disabled{ false };

		bool m_use_graphic_hover_color{ true };
		bool m_use_text_hover_color{ true };

		int m_available_width{ 16777215 };

		Graphic* m_graphic{ nullptr };
		Graphic* m_graphic_after{ nullptr };

		Label* m_text_label{ nullptr };
	};

	class ComboboxItem : public Widget
	{
		Q_OBJECT

	public:
		ComboboxItem(const QString& item_text, QWidget* parent = nullptr);

		QString item_text();

		void replace_item_text(const QString& new_item_text);

		void set_font_size(int size);
		void setFixedSize(const QSize& s);
		void setFixedSize(int w, int h);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

	private:
		Label* m_item_label;

		QString m_item_text;
	};

	class Combobox : public Widget
	{
		Q_OBJECT

	signals:
		void current_item_changed(const QString& current_item);
		void item_replaced(const QString& old_item, const QString& new_item);

	public:
		Combobox(QWidget* parent = nullptr);

		void add_item(const QString& item);

		void alphabetize();

		void edit_current_item();

		void enable_alphabetization(bool cond = true);

		void set_current_item(const QString& item);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_item_renaming_disabled(bool disable = true);
		void set_padding(int left, int top, int right, int bottom);
		void setFixedSize(const QSize& s);
		void setFixedSize(int w, int h);

		QString current_item() const;

		QList<QString> items();

		void update_theme_dependencies();

	public slots:
		void line_edit_return_pressed();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		bool m_alphabetize{ false };
		bool m_disabled{ false };
		bool m_item_renaming_disabled{ true };

		ComboboxItem* m_control_combobox_item{ new ComboboxItem("") };
		ComboboxItem* m_current_combobox_item{ nullptr };

		Label* m_current_item_label{ new Label(this) };

		QLineEdit* m_line_edit{ new QLineEdit(this) };

		QList<ComboboxItem*> m_combobox_items;

		QVBoxLayout* m_drop_down_layout{ new QVBoxLayout };

		Widget* m_drop_down{ new Widget };
	};

	class LineEditor : public Widget
	{
		Q_OBJECT

	signals:
		void text_edited(const QString &text);

	public:
		LineEditor(QWidget* parent = nullptr);

		void init_attributes();

		void set_default_value(const QString& default_value);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_margin(int margin);
		void set_margin(int left, int top, int right, int bottom);
		void set_text(const QString& text);
		void set_validator(const QValidator* validator);

		void setFixedSize(int w, int h);

		void setFixedWidth(int w);

		QString text();

		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		QString* m_default_value{ nullptr };

		bool m_disabled{ false };

		QLineEdit* m_line_edit{ new QLineEdit(this) };
	};

	class Slider : public Widget
	{
		Q_OBJECT

	signals:
		void value_changed(int value);

	public:
		Slider(int limit, QWidget* parent = nullptr);

		void set_value(int value);

		void update_handle_pos();
		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_limit{ 99 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};

	class MiniSlider : public Widget
	{
		Q_OBJECT

	public:
		MiniSlider(int limit, QWidget* parent = nullptr);

		void update_handle_pos();
		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_limit{ 99 };
		int m_mouse_move_scale{ 5 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};

	class MenuBar : public QMenuBar, public Themeable
	{
		Q_OBJECT

	public:
		MenuBar(QWidget* parent = 0);

		// TODO: Make override other overloaded versions from the parent class
		QMenu* addMenu(const QString& title);

		void issue_update();

		void update_theme_dependencies();

	protected:
		QString build_stylesheet();

		void init_attributes();

		//void paintEvent(QPaintEvent* event);

	private:
		QList<QMenu*> m_menus{ QList<QMenu*>() };
	};

	class TabBar : public QTabBar, public Themeable
	{
		Q_OBJECT

	public:
		TabBar(QWidget* parent = 0);

		void SetCurrentTab(const QString& text);

		bool ContainsTab(const QString& text);

		void issue_update();

		//void removeTab(int index);
		void removeTab(const QString& text);

		void update_theme_dependencies();

	protected:
		QString build_stylesheet();

		void init_attributes();
	};

	class ColorControl : public Widget
	{
		Q_OBJECT

	signals:
		void color_changed();

	public:
		ColorControl(QWidget* parent = nullptr);

		void click();

		void disable_clicking(bool cond = true);

		void init_attributes();

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);

	private:
		bool clicking_disabled{ false };
		bool open_on_release{ false };
	};

	class GradientSelectionBox : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		GradientSelectionBox(QGradientStops gradient_stops, QWidget* parent = nullptr);

		void add_gradient_stop(double stop_val, QColor color);

		QGradientStops gradient_stops() const;

		void issue_update();

		void update_gradient();
		void update_theme_dependencies();

	public slots:
		void click_control();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_color_controls();
		void init_gradient_widget();
		void init_titlebar();

		void setup_layout();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_gradient_widget{ new Widget };
		Widget* m_titlebar{ new Widget };

		QGradientStops m_gradient_stops{ { 0.0, Qt::white },{ 1.0, Qt::black } };

		QList<ColorControl*> color_controls;

		Button* m_apply_button{ new Button("Apply") };

		ColorControl* m_selected_color_control{ nullptr };
		ColorControl* m_clicking_color_control{ nullptr };

		QPoint m_selection_start_point;

		int m_selected_control_start_x{ 0 };

		QTimer m_single_click_timer;

		bool m_moved{ false };

		QPainter painter;
	};

	class GradientControl : public Widget
	{
		Q_OBJECT

	signals:
		void gradient_changed();

	public:
		GradientControl(QWidget* parent = nullptr);

		void init_attributes();

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);
	};

	class AttributeWidget : public Widget
	{
		Q_OBJECT

	public:
		AttributeWidget(bool is_primary, QWidget* parent = nullptr);

		QList<QString>& customize_states();

		virtual void enable_secondary_background_color(bool cond = true);

		bool is_primary() const;

		void set_customize_states(const QList<QString>& customize_states);

		void set_primary(bool is_primary = true);

		StatefulAttribute* stateful_attribute() const;

		StatelessAttribute* stateless_attribute() const;

		virtual void update_customizing_state(const QString& customizing_state);

	protected:
		void init_attributes();

		void paintEvent(QPaintEvent* event) override;

		void store_attribute_pointer(Attribute* attribute);

		StatefulAttribute* m_stateful_attribute{ nullptr };
		StatelessAttribute* m_stateless_attribute{ nullptr };

		QList<QString> m_customize_states{ QList<QString>() };

	private:
		//bool m_attribute_is_stateful{ false };
		bool m_is_primary;
	};

	class AttributeWidgetContainer : public AttributeWidget
	{
		Q_OBJECT

	public:
		AttributeWidgetContainer(const QString& label_text, bool is_primary, QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void enable_secondary_background_color(bool cond = true);

		void set_customize_states(const QList<QString>& customize_states);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Button* m_collapse_button{ new Button(new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label;

		QList<AttributeWidget*> m_child_attribute_widgets{ QList<AttributeWidget*>() };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};

	class CornerRadiiAttributeWidget : public AttributeWidgetContainer
	{
		Q_OBJECT

	public:
		CornerRadiiAttributeWidget(Themeable* themeable, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		AttributeSharingCombo* m_tl_line_editor_asc{ nullptr };
		AttributeSharingCombo* m_tr_line_editor_asc{ nullptr };
		AttributeSharingCombo* m_bl_line_editor_asc{ nullptr };
		AttributeSharingCombo* m_br_line_editor_asc{ nullptr };

		AttributeWidget* m_attribute_widget;

		MiniSlider* m_tl_slider{ new MiniSlider(30) };
		MiniSlider* m_tr_slider{ new MiniSlider(30) };
		MiniSlider* m_bl_slider{ new MiniSlider(30) };
		MiniSlider* m_br_slider{ new MiniSlider(30) };

		LineEditor* m_tl_line_editor{ new LineEditor };
		LineEditor* m_tr_line_editor{ new LineEditor };
		LineEditor* m_bl_line_editor{ new LineEditor };
		LineEditor* m_br_line_editor{ new LineEditor };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_example_widget{ new Widget };
	};

	class ColorAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent = nullptr);
		ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, Attribute* disabling_attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void set_centered(bool centered = true);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_child_themeable_reference_list();

	private:
		Attribute* m_disabling_attribute{ nullptr };

		AttributeSharingCombo* m_color_control_asc{ nullptr };

		bool m_centered{ false };

		ColorControl* m_color_control{ new ColorControl };

		Label* m_attribute_label;

		ToggleSwitch* m_disabled_attribute_toggle{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class GradientAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		GradientAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void set_centered(bool centered = true);

	protected:
		void init_child_themeable_reference_list();

	private:
		AttributeSharingCombo* m_gradient_control_asc{ nullptr };

		bool m_centered{ false };

		GradientControl* m_gradient_control{ new GradientControl };

		Label* m_attribute_label;

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class NumberAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		NumberAttributeWidget(const QString& attribute_label_text, Attribute* attribute, QIntValidator* int_validator, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void enable_silder();

		void set_centered(bool centered = true);

		void set_unit_label_text(const QString& unit_string);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		AttributeSharingCombo* m_line_editor_asc{ nullptr };
		AttributeSharingCombo* m_line_editor_to_slider_asc{ nullptr };
		AttributeSharingCombo* m_slider_to_line_editor_asc{ nullptr };

		bool m_centered{ false };

		Label* m_attribute_label{ nullptr };
		Label* m_unit_label{ new Label };

		LineEditor* m_line_editor{ new LineEditor };

		QIntValidator* m_int_validator{ nullptr };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Slider* m_slider{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	// Control attribute currently not setup to work with stateful attributes; Not sure if needed
	class SwitchAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		SwitchAttributeWidget(
			const QString& first_label_text, AttributeWidget* first_attribute_widget,
			const QString& second_label_text, AttributeWidget* second_attribute_widget,
			StatelessAttribute* control_attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void enable_secondary_background_color(bool cond = true);

	private:
		StatelessAttribute* m_control_attribute;

		AttributeWidget* m_first_attribute_widget;
		AttributeWidget* m_second_attribute_widget;

		ToggleSwitch* m_labeled_toggle_switch;
	};

	class CustomizePanel : public Widget
	{
		Q_OBJECT

	public:
		CustomizePanel(Themeable* themeable, QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void add_element_button(Button* button, int index = -1);

		void setup_layout();

		void update_attribute_widget_background_colors();

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		bool m_layout_setup{ false };
		bool m_showing_primary{ true };

		QHBoxLayout* m_states_layout{ new QHBoxLayout };

		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_elements_layout{ new QVBoxLayout };
		QVBoxLayout* m_element_buttons_layout{ new QVBoxLayout };
		QVBoxLayout* m_stateful_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_stateless_attributes_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All", true) };
		Button* m_show_primary_button{ new Button("Show Primary", true) };

		Combobox* m_state_combobox{ new Combobox };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_elements_label{ new Label("Elements:") };
		Label* m_stateful_attributes_label{ new Label("Stateful Attributes:") };
		Label* m_stateless_attributes_label{ new Label("Stateless Attributes:") };
		Label* m_state_label{ new Label("State:") };

		QList<AttributeWidget*> m_stateless_attribute_widgets{ QList<AttributeWidget*>() };
		QList<AttributeWidget*> m_stateful_attribute_widgets{ QList<AttributeWidget*>() };
		QList<AttributeWidget*> m_attribute_widgets{ QList<AttributeWidget*>() };

		Themeable* m_themeable;
	};

	class Menu : public Widget
	{
		Q_OBJECT

	public:
		Menu(const QString& menu_name, Graphic* menu_icon, QWidget* parent = nullptr);

		Graphic* icon{ nullptr };

		QString name;
	};

	class MenuLabelLayer : public Widget
	{
		Q_OBJECT

	public:
		MenuLabelLayer(Menu* menu, QWidget* parent = nullptr);

		void shrink();
		void expand();

		Button* back_button() const;
		Button* icon_button() const;

		Label* text_label() const;

	protected:
		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_back_button{ new Button(new Graphic(":/svgs/back.svg", QSize(21, 18)), false) };
		Button* m_icon_button{ nullptr };

		Label* m_text_label{ nullptr };

		Widget* m_stretch_widget{ new Widget };
	};

	class AppPreferencesSettingsPanel : public Widget
	{
		Q_OBJECT

	public:
		AppPreferencesSettingsPanel(QWidget* parent = nullptr);

	protected:
		void init_attribute_widgets();
	};

	class CreateNewThemeDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		CreateNewThemeDialog(QWidget* parent = nullptr);

		void add_theme_name_to_combobox(const QString& theme_name);

		void clear();

		QString copy_theme_name();

		void issue_update();

		QString new_theme_name();

		void set_current_start_theme_name(const QString& theme_name);

		void update_theme_dependencies();

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_titlebar();

		void setup_layout();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_titlebar{ new Widget };

		Button* m_create_button{ new Button("Create") };

		Combobox* m_start_theme_combobox{ new Combobox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_edit{ new LineEditor };

		QPainter painter;
	};

	class UpdateDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		UpdateDialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent = nullptr);

		void issue_update();

		void update_theme_dependencies();

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_titlebar();

		void setup_layout();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_titlebar{ new Widget };

		Button* m_remind_me_later_button{ new Button("Remind Me Later") };
		Button* m_update_button{ new Button("Update") };

		Label* m_message_label;

		QPainter painter;
	};

	class ThemesSettingsPanel : public Widget
	{
		Q_OBJECT

	public:
		ThemesSettingsPanel(QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		Button* customize_theme_button() const;

		Button* new_theme_button() const;

		Combobox* theme_combobox() const;

		void show_custom_theme_buttons(bool cond = true);

	protected:
		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Label* m_theme_label{ new Label("Theme") };

		Combobox* m_theme_combobox{ new Combobox };

		Button* m_new_theme_button{ new Button(new Graphic(":/svgs/new_theme.svg", QSize(20, 20)), true) };
		Button* m_customize_theme_button{ new Button(new Graphic(":/svgs/customize_theme.svg", QSize(20, 20)), true) };
		Button* m_delete_theme_button{ new Button(new Graphic(":/svgs/delete_theme.svg", QSize(17, 20)), true) };
		Button* m_theme_info_button{ new Button(new Graphic(":/svgs/info_theme.svg", QSize(20, 20)), true) };

		Widget* m_control_separator{ new Widget };
		Widget* m_separator_1{ new Widget };
		Widget* m_separator_2{ new Widget };
		Widget* m_spacer_1{ new Widget };
		Widget* m_spacer_2{ new Widget };
	};

	class SettingsSidebar : public Widget
	{
		Q_OBJECT

	public:
		SettingsSidebar(QWidget* parent = nullptr);

	protected:
		void init_attribute_widgets();
	};

	class SettingsTab : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();
		void under_minimum_width();
		void over_minimum_width();

	public:
		SettingsTab(Graphic* icon, const QString& label_text, QWidget* parent = nullptr);

		void expand();
		void shrink();

		int recommended_minimum_width();

		void set_disabled(bool cond = true);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		void resizeEvent(QResizeEvent* event);

	private:
		void setup_layout();

		QHBoxLayout* main_layout{ new QHBoxLayout };

		bool m_disabled{ false };

		Label* m_text_label;

		Graphic* m_tab_icon;

		Widget* m_spacer{ new Widget };
		Widget* m_stretch_widget{ new Widget };
		Widget* m_stretch_widget2{ new Widget };
	};

	class SettingsMenu : public Menu
	{
		Q_OBJECT

	public:
		SettingsMenu(QWidget* parent = nullptr);

		void add_settings_tab(Graphic* icon, const QString& label_text);

		int largest_tab_index() const;

		int recommended_minimum_tab_width() const;

		ThemesSettingsPanel* themes_settings_panel() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_child_themeable_reference_list();

		void init_attribute_widgets();

	private slots:
		void shrink_tabs();
		void expand_tabs();

	private:
		void setup_layout();

		bool m_dragging_sidebar{ false };
		bool m_frozen{ false };
		bool m_hovering_over_divider{ false };
		bool m_shrunk{ false };

		VerticalLayout* m_sidebar_layout = new VerticalLayout;

		QList<SettingsTab*> m_settings_tabs;

		QPoint last_pos;

		SettingsSidebar* m_sidebar{ new SettingsSidebar };

		AppPreferencesSettingsPanel* m_app_preferences_settings_panel{ new AppPreferencesSettingsPanel };

		ThemesSettingsPanel* m_themes_settings_panel{ new ThemesSettingsPanel };
	};

	class CustomizeMenu : public Menu
	{
		Q_OBJECT

	public:
		CustomizeMenu(QWidget* parent = nullptr);

		Button* apply_button() const;

		QList<CustomizePanel*>& customize_panels();

		void init_preview_window();

		void open_customize_panel(CustomizePanel* customize_panel);

		void populate_panel_layout();

		Window* preview_window() const;

		int calculated_topbar_content_width();

		void set_preview_widget(QWidget* widget);

		int topbar_content_width(bool include_collapse_button);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attribute_widgets();
		void init_child_themeable_reference_list();

	private:
		void adjust_collapsed_widget();
		void collapse_text_buttons();
		void expand_text_buttons();
		void setup_layout();

		HorizontalLayout* m_main_layout = new HorizontalLayout;
		QVBoxLayout* m_collapsed_text_buttons_layout{ new QVBoxLayout };
		QVBoxLayout* m_sidebar_layout{ new QVBoxLayout };
		QHBoxLayout* m_topbar_layout{ new QHBoxLayout };
		QGridLayout* m_preview_layout{ new QGridLayout };

		Widget* m_sidebar{ new Widget };
		Widget* m_topbar{ new Widget };
		Widget* m_preview_widget = new Widget;

		ScrollArea* m_sidebar_scroll_area{ new ScrollArea };
		ScrollArea* m_preview_scroll_area{ new ScrollArea };

		Window* m_preview_window{ nullptr };

		QList<CustomizePanel*> m_customize_panels;
		QList<CustomizePanel*> m_panel_stack;
		QList<Button*> m_text_button_stack;
		QList<Button*> m_topbar_text_buttons;
		QList<Button*> m_collapsed_text_buttons;
		QList<Graphic*> m_arrow_graphics;

		QSize* m_previous_size{ nullptr };

		Button* m_apply_button{ new Button("Apply", true) };
		Button* m_collapsed_button{ new Button(new Graphic(":/svgs/ellipsis.svg", QSize(32, 8)), true) };

		Graphic* m_control_arrow_graphic{ new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)) };

		CustomizePanel* m_control_customize_panel{ nullptr };

		Button* m_control_text_button{ new Button("")};

		Widget* m_collapsed_widget{ new Widget };
	};

	class Titlebar : public Widget
	{
		Q_OBJECT

	signals:
		void window_icon_updated();

	public:
		Titlebar(QWidget* parent = nullptr);

		void add_mll(MenuLabelLayer* mll);
		void remove_mlls_past(int index);

		bool is(QWidget* widget);

		void set_window_icon(const Graphic& icon_graphic);

		void set_window_title(const QString& title);

		Button* window_icon() const;
		Button* settings_button() const;
		Button* minimize_button() const;
		Button* maximize_button() const;
		Button* exit_button() const;

	protected:
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		void resizeEvent(QResizeEvent* event);

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_window_icon{ new Button(new Graphic(QFile(":/image_sequences/layers_logo.imgseq"), QSize(35, 35)), true) };

		Label* m_window_title_label{ new Label("Window") };

		Button* m_settings_button{ new Button(new Graphic(":/svgs/settings.svg", QSize(20, 20)), true) };
		Button* m_minimize_button{ new Button(new Graphic(":/svgs/minimize.svg", QSize(20, 20)), true) };
		Button* m_maximize_button{ new Button(new Graphic(":/svgs/maximize.svg", QSize(20, 20)), true) };
		Button* m_exit_button{ new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true) };

		Widget* m_buttons_container{ new Widget(this) };

		QList<MenuLabelLayer*> mll_stack;

		MenuLabelLayer* m_base_mll{ nullptr };

		MenuLabelLayer* m_control_mll{ new MenuLabelLayer(new Menu("Control Menu", new Graphic(":/svgs/icon_icon.svg", QSize(20, 20)))) };

		Widget* m_stretch_widget{ new Widget };
	};

	class Window : public Widget
	{
		Q_OBJECT

	public:
		Window(bool preview = false, QWidget* parent = nullptr);

		void add_menu(Menu* menu);

		Menu* app_menu() const;

		void apply_theme(Theme& theme);

		void assign_tag_prefixes();

		//template<typename T>
		//void build_main_widget();

		void center_dialog(QDialog* dialog);

		CustomizeMenu* customize_menu() const;

		void finalize();

		void link_theme_name(const QString& name);

		void set_main_widget(Widget* main_widget);

		void set_window_icon(const Graphic& icon_graphic);

		void set_window_title(const QString& title);

		SettingsMenu* settings_menu() const;

		Titlebar* titlebar() const;

		void update_theme_dependencies();

	public slots:
		void customize_clicked();
		void exit_clicked();
		void maximize_clicked();
		void minimize_clicked();
		void new_theme_clicked();
		void open_menu(Menu* menu);
		void settings_clicked();

	protected:
		void init_attribute_widgets();

		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void setup_layout();

		bool m_maximized{ false };
		bool m_preview{ false };

		CreateNewThemeDialog* m_create_new_theme_dialog{ new CreateNewThemeDialog };

		QVBoxLayout* m_app_menu_layout{ new QVBoxLayout };
		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QList<Menu*> m_menus;
		QList<Menu*> m_menu_stack;

		Titlebar* m_titlebar{ new Titlebar };

		// TODO: Make Menu constructor that does not require an icon
		Menu* m_app_menu{ new Menu("App", new Graphic(":/svgs/settings_animated.svg", QSize(24, 24))) };

		SettingsMenu* m_settings_menu{ new SettingsMenu };

		CustomizeMenu* m_customize_menu{ new CustomizeMenu };

		Widget* m_main_widget{ nullptr };
	};

	class Downloader : public QObject
	{
		Q_OBJECT

	public:
		Downloader(QObject* parent = 0);

		QNetworkReply* download(const QUrl& file_url, const QDir& directory);

		QNetworkReply* download(const QUrl& file_url);

	private:
		QNetworkAccessManager m_network_manager;
	};

	class Application : public QApplication
	{
		Q_OBJECT

	public:
		Application(
			int& argc, char** argv,
			const QString& name,
			QFile* icon_file = nullptr,
			Version* version = nullptr,
			GitHubRepo* github_repo = nullptr);

		void add_child_themeable_reference(Themeable& themeable);

		void apply_theme(Theme& theme);

		void create_theme(const QString& new_theme_name, const QString& copy_theme_name);

		Theme* current_theme() const;

		QFile* icon_file();

		void issue_update();

		Theme load_theme(QFile& file);

		QString& name();

		void reapply_theme();

		void save_theme(Theme& theme);

		QSettings& settings();

		Theme* theme(const QString& theme_name);

		QMap<QString, Theme>& themes();

		bool update_available();

		bool update_on_request();

	public slots:
		void rename_theme(const QString& old_name, const QString& new_name);

	private:
		void copy_missing_attributes_to(Theme& theme_missing_attributes);

		void init_directories();
		void init_fonts();
		void init_themes();
		void init_latest_version_tag();

		QDir m_app_dir;

		QDir m_app_themes_dir;

		QList<Themeable*> m_child_themeable_references;

		Theme* m_current_theme{ nullptr };

		Downloader m_downloader{ this };

		QString m_github_api_repos_url_base{ "https://api.github.com/repos" };

		GitHubRepo* m_github_repo{ nullptr };

		QFile* m_icon_file{ nullptr };

		QString* m_latest_version{ nullptr };
		
		QString m_name;

		QSettings m_settings;

		QMap<QString, Theme> m_themes;

		Version* m_version{ nullptr };
	};

	template<typename T>
	inline void Themeable::share_all_attributes_with(T* themeable)
	{
		if (typeid(*this) == typeid(*themeable))
		{
			for (StatelessAttribute& stateless_attribute : m_attribute_set.stateless_attributes())
				share_attribute_with_themeable(
					&stateless_attribute,
					themeable->attribute_set().stateless_attribute(stateless_attribute.name()));

			for (StatefulAttribute& stateful_attribute : m_attribute_set.stateful_attributes())
				for (const QString& state : stateful_attribute.states())
					share_attribute_with_themeable(
						&stateful_attribute, state,
						themeable->attribute_set().stateful_attribute(stateful_attribute.name()), state);

			if (m_child_themeable_references.count() == themeable->m_child_themeable_references.count())
			{
				for (int i = 0; i < m_child_themeable_references.count(); i++)
				{
					m_child_themeable_references[i]->share_all_attributes_with(themeable->m_child_themeable_references[i]);
				}
			}
		}
	}

	template<typename T>
	inline void Themeable::unshare_all_attributes_with(T* themeable)
	{
		if (typeid(*this) == typeid(*themeable))
		{
			for (StatelessAttribute& stateless_attribute : m_attribute_set.stateless_attributes())
				unshare_attribute_with_themeable(
					&stateless_attribute,
					themeable->attribute_set().stateless_attribute(stateless_attribute.name()));

			for (StatefulAttribute& stateful_attribute : m_attribute_set.stateful_attributes())
				for (const QString& state : stateful_attribute.states())
					unshare_attribute_with_themeable(
						&stateful_attribute, state,
						themeable->attribute_set().stateful_attribute(stateful_attribute.name()), state);


			if (m_child_themeable_references.count() == themeable->m_child_themeable_references.count())
			{
				for (int i = 0; i < m_child_themeable_references.count(); i++)
				{
					m_child_themeable_references[i]->unshare_all_attributes_with(themeable->m_child_themeable_references[i]);
				}
			}
		}
	}
}

// 2.0.0a Classes
namespace Layers
{
	class Attribute_2_0_0_a
	{
	public:
		friend QDataStream& operator >>(QDataStream& stream, Attribute_2_0_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

		bool m_is_stateful{ false };

		QString m_name;
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class Theme_2_0_0_a
	{
	public:
		friend QDataStream& operator >>(QDataStream& stream, Theme_2_0_0_a& t)
		{
			stream >> t.name;
			stream >> t.built_in;
			stream >> t.m_data;
			return stream;
		}

		bool built_in{ false };

		QHash<QString, QMap<QString, Attribute_2_0_0_a>> m_data{ QHash<QString, QMap<QString, Attribute_2_0_0_a>>() };

		QString name;
	};
}

// 2.1.0a Classes
namespace Layers
{
	class Attribute_2_1_0_a
	{
	public:
		Attribute_2_1_0_a(const QString& name);

		QString& name();

	protected:
		QString m_name{ "" };

		Themeable* m_parent_themeable{ nullptr };
	};

	class Stateless_Attribute_2_1_0_a : public Attribute_2_1_0_a
	{
	public:
		Stateless_Attribute_2_1_0_a();
		Stateless_Attribute_2_1_0_a(const QString& name, QVariant value);

		QVariant& value();

		friend QDataStream& operator <<(QDataStream& stream, const Stateless_Attribute_2_1_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_value;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateless_Attribute_2_1_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_value;
			return stream;
		}

	private:
		QVariant m_value{ QVariant() };
	};

	class Stateful_Attribute_2_1_0_a : public Attribute_2_1_0_a
	{
	public:
		Stateful_Attribute_2_1_0_a();
		Stateful_Attribute_2_1_0_a(const QString& name, QMap<QString, QVariant> state_value_map);

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const Stateful_Attribute_2_1_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateful_Attribute_2_1_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class Attribute_Set_2_1_0_a
	{
	public:
		void add_attribute(Stateless_Attribute_2_1_0_a attribute);

		void add_attribute(Stateful_Attribute_2_1_0_a attribute);

		bool contains(const QString& attribute_name);

		QMap<QString, Stateful_Attribute_2_1_0_a>& stateful_attributes();

		QMap<QString, Stateless_Attribute_2_1_0_a>& stateless_attributes();

		friend QDataStream& operator <<(QDataStream& stream, const Attribute_Set_2_1_0_a& as)
		{
			stream << as.m_stateful_attributes;
			stream << as.m_stateless_attributes;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute_Set_2_1_0_a& as)
		{
			stream >> as.m_stateful_attributes;
			stream >> as.m_stateless_attributes;
			return stream;
		}

	private:
		QMap<QString, Stateful_Attribute_2_1_0_a> m_stateful_attributes{ QMap<QString, Stateful_Attribute_2_1_0_a>() };
		QMap<QString, Stateless_Attribute_2_1_0_a> m_stateless_attributes{ QMap<QString, Stateless_Attribute_2_1_0_a>() };
	};

	class Theme_2_1_0_a
	{
	public:
		Theme_2_1_0_a();
		Theme_2_1_0_a(const QString& name, bool is_custom = true);

		void add_stateful_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		void add_stateless_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QVariant value);

		QHash<QString, Attribute_Set_2_1_0_a>& attribute_sets();

		bool is_custom();

		QString& name();

		friend QDataStream& operator <<(QDataStream& stream, const Theme_2_1_0_a& t)
		{
			stream << t.m_attribute_sets;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme_2_1_0_a& t)
		{
			stream >> t.m_attribute_sets;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		bool m_is_custom{ true };

		QHash<QString, Attribute_Set_2_1_0_a> m_attribute_sets{ QHash<QString, Attribute_Set_2_1_0_a>() };

		QString m_name;
	};
}

// Theme Loading
namespace Layers
{
	struct Theme_And_Load_Status_Combo_2_0_0_a
	{
		Theme_2_0_0_a theme;
		QDataStream::Status status;
	};

	struct Theme_And_Load_Status_Combo_2_1_0_a
	{
		Theme_2_1_0_a theme;
		QDataStream::Status status;
	};

	struct Theme_And_Load_Status_Combo_2_2_0_a
	{
		Theme theme;
		QDataStream::Status status;
	};

	Theme_And_Load_Status_Combo_2_0_0_a load_theme_2_0_0_a(QFile& file);

	Theme_And_Load_Status_Combo_2_1_0_a load_theme_2_1_0_a(QFile& file);

	Theme_And_Load_Status_Combo_2_2_0_a load_theme_2_2_0_a(QFile& file);
}

// Theme Updating
namespace Layers
{
	// 2.0.0a -> 2.1.0a
	Theme_2_1_0_a update_theme_2_0_0_a_to_2_1_0_a(Theme_2_0_0_a& old_theme);

	// 2.1.0a -> 2.2.0a (Current)
	Theme update_theme_2_1_0_a_to_2_2_0_a(Theme_2_1_0_a& old_theme);
}

#endif // LAYERS_H
