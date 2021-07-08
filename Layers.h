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
#include <QPainter>
#include <QScrollArea>
#include <QSvgWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include <Windows.h>
#include <windowsx.h>

namespace Layers
{
	class Attribute;
	class Attribute_Sharing_Combo;
	class Attribute_Widget;
	class Color_Control;
	class Customize_Panel;
	class Graphic_Widget;
	class Label;
	class Theme;
	class Themeable;
	class Titlebar;
	class Widget;
	class Window;
}

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

	QString app_data_dir();
	QString layers_dir();
	QString layers_themes_dir();

	Theme build_dark_theme();
	Theme build_light_theme();
	Theme build_blue_theme();

	/*!
		Provides structure for storing attribute values and handles attribute states.

		The Attribute class is a data structure used by Themes and Themeables to store
		values, their associated states, and the current state of the attribute.

		Attributes can store different values mapped from different states. However,
		attributes are not required to be stateful. In fact, most attributes do not
		need states and only need to store a single value.
	*/
	class Attribute
	{
	public:
		Attribute();
		Attribute(const QString& name, QVariant value);
		Attribute(const QString& name, const QString& state, QVariant value);
		Attribute(const QString& name, QMap<QString, QVariant> state_value_map);

		void add_state_and_value(const QString& state, QVariant value);

		void apply_theme_attribute(Attribute& theme_attribute);

		bool contains(const QString& key) const;

		bool is_stateful() const;

		void make_stateful(QMap<QString, QVariant> state_value_map);

		QString& name();

		Themeable* parent_themeable() const;

		void set_common(QVariant value);

		void set_parent_themeable(Themeable* parent_themeable);

		void set_state(const QString& state);

		void set_value(const QString& state, QVariant value);

		QString state() const;

		QList<QString> states() const;

		QVariant& value();
		QVariant& value(const QString& state);

		bool m_is_stateful{ false };

		QString m_name;
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };

		Themeable* m_parent_themeable{ nullptr };
	};

	inline QDataStream& operator <<(QDataStream& stream, const Attribute& a)
	{
		stream << a.m_name;
		stream << a.m_state;
		stream << a.m_values;
		return stream;
	}

	inline QDataStream& operator >>(QDataStream& stream, Attribute& a)
	{
		stream >> a.m_name;
		stream >> a.m_state;
		stream >> a.m_values;
		return stream;
	}

	class Theme
	{
	public:
		void add_attribute(
			const QString& themeable_tag,
			const QString& state,
			const QString& attribute,
			QVariant value);

		void add_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		bool contains(const QString& key);

		void replace_attributes(Themeable* themeable);

		QMap<QString, Attribute> operator[](const QString& key);
		const QMap<QString, Attribute> operator[](const QString& key) const;

		void set_attribute_value(
			const QString& themeable_tag,
			const QString& state,
			const QString& attribute_name,
			Attribute& attribute);

		bool built_in{ false };

		// Data
		QHash<QString, QMap<QString, Attribute>> m_data{ QHash<QString, QMap<QString, Attribute>>() };

		QString name;
	};

	inline QDataStream& operator <<(QDataStream& stream, const Theme& t)
	{
		stream << t.name;
		stream << t.built_in;
		stream << t.m_data;
		return stream;
	}

	inline QDataStream& operator >>(QDataStream& stream, Theme& t)
	{
		stream >> t.name;
		stream >> t.built_in;
		stream >> t.m_data;
		return stream;
	}

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

		void add_attribute(const QString& state, const QString& attribute, QVariant value);

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
		QMap<QString, Attribute>& attributes();

		QMap<QString, Attribute_Widget*>& attribute_widgets();

		QList<Themeable*>& child_themeable_references();

		void replace_all_attributes_in_theme(Theme* theme);

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
		Customize_Panel* customize_panel() const;

		/*!
			Adds the given attribute to an attribute filtration list.

			@param attribute to filter
		*/
		void filter_attribute(const QString& attribute);

		/*!
			Get the address of the themeable's icon. Returns nullptr if no icon exists.

			@returns Address of icon, or nullptr
		*/
		Graphic_Widget* icon() const;

		/*!
			Initializes customize panels and adds them to the provided list.

			This function works recursively to initialize all of the customize panels in the caller's
			hierarchy. As the panels are created, they are added to the list parameter.

			@param list to store initialized customize panels
		*/
		void initialize_and_acquire_panels(QList<Customize_Panel*>& list);

		bool is_stateful() const;

		/*!
			Calls the inheriting QWidget's update() function

			This is a pure virtual function that must be defined by other classes that inherit the
			Themeable class. This function should be used to call the inheriting QWidget's update().
		*/
		virtual void issue_update() = 0;

		//void make_attribute_common(const QString& attribute, QVariant value);

		void make_attributes_common();

		void make_attribute_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

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

		void set_attribute_value(
			const QString& state,
			const QString& attribute,
			QVariant value,
			bool update = false); // IF-FAIL: Try setting to true?

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
		void set_icon(Graphic_Widget* icon);

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
			Establishes a sharing relationship with another themeable.

			@param from_state The state of the attribute set of the from_attribute
			@param from_attribute The attribute to share with the to_themeable
			@param to_themeable The themeable to share the attribute with
			@param to_state The state of the attribute set of the to_attribute
			@param to_attribute The attribute of the to_themeable to store the incoming from_attribute value
			@param obtain_attribute Whether or not to obtain the value of the to_themeable, false by default
			@returns the address of the new attribute sharing combo
		*/
		Attribute_Sharing_Combo* share_attribute_with_themeable(
			const QString& from_state, const QString& from_attribute,
			Themeable* to_themeable, QString to_state = "", QString to_attribute = "",
			bool obtain_attribute = false
		);

		Attribute_Sharing_Combo* share_attribute_with_themeable(
			const QString& from_state, Attribute& from_attribute,
			QString to_state, Attribute& to_attribute,
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
		Attribute_Sharing_Combo* take_attribute_sharing_combo(
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
		void unshare_attribute_with_themeable(
			const QString& from_state, const QString& from_attribute,
			Themeable* to_themeable, QString to_state = "", QString to_attribute = ""
		);

		void unshare_attribute_with_themeable(
			const QString& from_state, Attribute& from_attribute,
			const QString& to_state, Attribute& to_attribute
		);

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
		Customize_Panel* init_customize_panel();

		/*!
			Initializes the reference list to child themeables.

			A list of child themeable references is necessary to allow the apply_theme() function
			to work recursively.

			Classes that inherit the Themeable class should define this function and use
			add_child_themeable_reference() to populate the reference list.

			This function is called by init_themeable().
		*/
		virtual void init_child_themeable_reference_list();

		bool m_tag_prefixes_assigned{ false };
		bool m_shared_attributes{ false };
		bool m_is_stateful{ false };

		Customize_Panel* m_customize_panel{ nullptr };

		Graphic_Widget* m_icon{ nullptr };

		QString* m_app_name{ nullptr };
		QString* m_name{ nullptr };
		QString* m_proper_name{ nullptr };
		QString m_state{ "Default" };
		QString m_theme_tag{ "" };

		QMap<QString, bool> m_ACW_pre_init_primary_values{ QMap<QString, bool>() };
		QMap<QString, Attribute> m_attributes{ QMap<QString, Attribute>() };
		QMap<QString, Attribute_Widget*> m_attribute_widgets{ QMap<QString, Attribute_Widget*>() };

		QList<Themeable*> m_child_themeable_references;

		QList<QString> m_filtered_attributes;
		QList<QString> m_tag_prefixes;

		QList<Attribute_Sharing_Combo*> attribute_sharing_combos;

		Theme* m_current_theme{ nullptr };
	};

	/*!
		Stores the themeable addresses, states, and attributes needed to establish an attribute sharing connection.

		An Attribute_Sharing_Combo is created and stored when Themeable::share_attribute_with_themeable() is called
	*/
	class Attribute_Sharing_Combo
	{
	public:
		Attribute_Sharing_Combo(
			QString from_state,
			Attribute& from_attribute,
			QString to_state,
			Attribute& to_attribute);

		Attribute& from_attribute();
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

		Attribute& to_attribute();
		Themeable* to_themeable() const;
		QString& to_state();
		QString& to_attribute_name();

	private:
		Attribute& m_from_attribute;
		Attribute& m_to_attribute;

		QString m_from_state;
		QString m_to_state;
	};

	class Scroll_Area : public QScrollArea
	{
		Q_OBJECT

	public:
		Scroll_Area(QWidget* parent = nullptr);
	};

	class Horizontal_Layout : public QHBoxLayout
	{
	public:
		Horizontal_Layout(QWidget* parent = nullptr);

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

	class Vertical_Layout : public QVBoxLayout
	{
	public:
		Vertical_Layout(QWidget* parent = nullptr);

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
			a Layers::Horizontal_Layout or Layers::Vertical_Layout.
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

	class Image_Sequence_Label : public QLabel
	{
		Q_OBJECT

	public:
		Image_Sequence_Label(QDir dir, QSize size, QWidget* parent = nullptr);
		Image_Sequence_Label(const Image_Sequence_Label& isl);
		~Image_Sequence_Label();

	public slots:
		void time_out();

	private:
		int m_frame_number{ 0 };

		QTimer m_timer;

		QList<QPixmap*> m_image_seq{ QList<QPixmap*>() };
	};

	/*!
		The SVG_Widget class provides representation for SVG files in Layers.

		An SVG_Widget loads an SVG file into a string. To make the SVG appear on the screen, the string is passed to
		QSvgWidget::load(). The load function can be called indefinitely. Therefore, changes can be made to the SVG string
		and loaded again, allowing for theme application.

		Manipulating the SVG string itself would be punishing. To make this easier, a list of SVG elements is built from
		the string with build_svg_elements_list().

		The SVG_Widget's constructors wait to call Themeable::init_themeable() until after the SVG elements list has been built.
		This is because the SVG_Widget::init_attributes() function, which is called virtually by Themeable::init_themeable(),
		depends on the elements list.

		When a theme is applied to the SVG_Widget, the attributes are updated to values provided in the applied theme, but
		the SVG string needs to be updated with the new attribute values and passed along to QSvgWidget::load() before the
		appearance of the SVG_Widget updates. This class implements update_theme_dependencies() to ensure that this all
		happens after theme application.
	*/
	class SVG_Widget : public QSvgWidget, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG_Widget from an SVG file.
		*/
		SVG_Widget(QString file_path, QWidget* parent = nullptr);

		/*!
			Copy constructs an SVG_Widget from another SVG_Widget.
		*/
		SVG_Widget(const SVG_Widget& svg_w);

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		void set_hovering(bool cond = true);

		/*!
			Updates things that depend on the theme.

			SVG elements are updated with the newly applied theme's attribute values. Then, the SVG string is rebuilt
			from those elements. And finally, the SVG string is passed to QSvgWidget::load() to update the SVG_Widget's
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
		void build_svg_elements_list();

		QString element_id(const QString& element);

		bool m_hovering{ false };

		QString m_svg_str{  };

		QList<QString> m_svg_elements{  };
	};

	class Graphic_Widget : public Widget
	{
		Q_OBJECT

	public:
		Graphic_Widget(const QDir& img_seq_dir, QSize size, QWidget* parent = nullptr);
		Graphic_Widget(const QString& filepath, QSize size, QWidget* parent = nullptr);
		Graphic_Widget(const QImage& image, QWidget* parent = 0);
		Graphic_Widget(const Graphic_Widget& gw);

		void make_attribute_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		void set_hovering(bool cond = true);
		void set_icon(Graphic_Widget* icon);
		void set_size(QSize size);

	protected:
		void init_attribute_widgets();

	private:
		QLabel* m_bitmap_label{ nullptr };
		SVG_Widget* m_svg_widget{ nullptr };
		Image_Sequence_Label* m_image_sequence_label{ nullptr };
	};

	class Label : public QLabel, public Themeable
	{
		Q_OBJECT

	public:
		Label(QWidget* parent = nullptr);
		Label(const QString& text, QWidget* parent = 0);

		void init_attributes();

		void init_attribute_widgets();

		void issue_update();

		void resize();

		void set_font_size(int size);
		void set_hovering(bool cond = true);
		void set_padding(int left, int top, int right, int bottom);

	public slots:
		void setText(const QString& text);

	protected:
		void paintEvent(QPaintEvent* event);

		QPainter painter;

		bool m_hovering{ false };

		int m_padding_left{ 0 };
		int m_padding_top{ 0 };
		int m_padding_right{ 0 };
		int m_padding_bottom{ 0 };
	};

	class Toggle_Switch : public Widget
	{
		Q_OBJECT

	signals:
		void toggled_event();

	public:
		Toggle_Switch(QWidget* parent = nullptr);
		Toggle_Switch(const QString& first_label_text, const QString& second_label_text, QWidget* parent = nullptr);

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
		Button(Graphic_Widget* graphic, const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic_Widget* graphic, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic_Widget* graphic_before, Graphic_Widget* graphic_after, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);

		void disable_graphic_hover_color(bool cond = true);
		void disable_text_hover_color(bool cond = true);

		bool disabled() const;

		void resize();

		void set_attribute_value(const QString& state, const QString& attribute, QVariant value);
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

		Graphic_Widget* m_graphic{ nullptr };
		Graphic_Widget* m_graphic_after{ nullptr };

		Label* m_text_label{ nullptr };
	};

	class Combobox_Item : public Widget
	{
		Q_OBJECT

	public:
		Combobox_Item(const QString& item_text, QWidget* parent = nullptr);

		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		QString item_text();

		void replace_item_text(const QString& new_item_text);

		void set_font_size(int size);
		void setFixedSize(const QSize& s);
		void setFixedSize(int w, int h);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

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

		void init_attributes();
		void init_child_themeable_reference_list();

		void set_current_item(const QString& item);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void setFixedSize(const QSize& s);
		void setFixedSize(int w, int h);

		QString current_item() const;

		QList<QString> items();

		void update_theme_dependencies();

	public slots:
		void line_edit_return_pressed();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attribute_widgets();

	private:
		void setup_layout();

		bool m_alphabetize{ false };

		bool m_disabled{ false };

		Combobox_Item* m_control_combobox_item{ new Combobox_Item("") };
		Combobox_Item* m_current_combobox_item{ nullptr };

		Label* m_current_item_label{ new Label(this) };

		QLineEdit* m_line_edit{ new QLineEdit(this) };

		QList<Combobox_Item*> m_combobox_items;

		QVBoxLayout* m_drop_down_layout{ new QVBoxLayout };

		Widget* m_drop_down{ new Widget };
	};

	class Line_Editor : public Widget
	{
		Q_OBJECT

	signals:
		void text_edited(const QString &text);

	public:
		Line_Editor(QWidget* parent = nullptr);

		void init_attributes();

		void set_default_value(const QString& default_value);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_margin(int margin);
		void set_margin(int left, int top, int right, int bottom);
		void set_text(const QString& text);
		void set_validator(const QValidator* validator);

		void setFixedSize(int w, int h);

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

	public:
		Slider(int range_start, int range_end, QWidget* parent = nullptr);

		void init_attributes();
		void init_child_themeable_reference_list();

		int range_difference();

		void update_handle_pos();
		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void setup_layout();

		Widget* m_bar{ new Widget };
		Widget* m_handle{ new Widget(this) };

		int m_range_start{ 0 };
		int m_range_end{ 99 };
		int m_value_on_click{ 0 };

		bool m_dragging_handle{ false };

		QPoint m_mouse_click_position{ QPoint() };
	};

	class Color_Control : public Widget
	{
		Q_OBJECT

	signals:
		void color_changed();

	public:
		Color_Control(QWidget* parent = nullptr);

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

	class Gradient_Selection_Box : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		Gradient_Selection_Box(QGradientStops gradient_stops, QWidget* parent = nullptr);

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

		bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;

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

		QList<Color_Control*> color_controls;

		Button* m_apply_button{ new Button("Apply") };

		Color_Control* m_selected_color_control{ nullptr };
		Color_Control* m_clicking_color_control{ nullptr };

		QPoint m_selection_start_point;

		int m_selected_control_start_x{ 0 };

		QTimer m_single_click_timer;

		bool m_moved{ false };

		QPainter painter;
	};

	class Gradient_Control : public Widget
	{
		Q_OBJECT

	signals:
		void gradient_changed();

	public:
		Gradient_Control(QWidget* parent = nullptr);

		void init_attributes();

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);
	};

	class Attribute_Widget : public Widget
	{
		Q_OBJECT

	public:
		Attribute_Widget(bool is_primary, QWidget* parent = nullptr);

		Attribute* attribute() const;

		QList<QString>& customize_states();

		virtual void enable_secondary_background_color(bool cond = true);

		bool is_primary() const;

		void set_customize_states(const QList<QString>& customize_states);

		void set_primary(bool is_primary = true);

		virtual void update_customizing_state(const QString& customizing_state);

	protected:
		void init_attributes();

		void paintEvent(QPaintEvent* event) override;

		Attribute* m_attribute{ nullptr };

		QList<QString> m_customize_states{ QList<QString>() };

	private:
		bool m_is_primary;
	};

	class Attribute_Widget_Container : public Attribute_Widget
	{
		Q_OBJECT

	public:
		Attribute_Widget_Container(const QString& label_text, bool is_primary, QWidget* parent = nullptr);

		void add_attribute_widget(Attribute_Widget* attribute_widget);

		void enable_secondary_background_color(bool cond = true);

		void init_attributes();
		void init_child_themeable_reference_list();

		void set_customize_states(const QList<QString>& customize_states);

		void update_customizing_state(const QString& customizing_state);

	private:
		void setup_layout();

		Button* m_collapse_button{ new Button(new Graphic_Widget(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic_Widget(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label;

		QList<Attribute_Widget*> m_child_attribute_widgets{ QList<Attribute_Widget*>() };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};

	class Color_Attribute_Widget : public Attribute_Widget
	{
		Q_OBJECT

	public:
		Color_Attribute_Widget(const QString& attribute_label_text, Attribute& attribute, bool is_primary, QWidget* parent = nullptr);
		Color_Attribute_Widget(const QString& attribute_label_text, Attribute& attribute, Attribute& disabling_attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void set_centered(bool centered = true);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_child_themeable_reference_list();

	private:
		Attribute* m_disabling_attribute{ nullptr };

		Attribute_Sharing_Combo* m_color_control_asc{ nullptr };

		bool m_centered{ false };

		Color_Control* m_color_control{ new Color_Control };

		Label* m_attribute_label;

		Toggle_Switch* m_disabled_attribute_toggle{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class Gradient_Attribute_Widget : public Attribute_Widget
	{
		Q_OBJECT

	public:
		Gradient_Attribute_Widget(const QString& attribute_label_text, Attribute& attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void set_centered(bool centered = true);

	protected:
		void init_child_themeable_reference_list();

	private:
		Attribute_Sharing_Combo* m_gradient_control_asc{ nullptr };

		bool m_centered{ false };

		Gradient_Control* m_gradient_control{ new Gradient_Control };

		Label* m_attribute_label;

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class Number_Attribute_Widget : public Attribute_Widget
	{
		Q_OBJECT

	public:
		Number_Attribute_Widget(const QString& attribute_label_text, Attribute& attribute, QIntValidator* int_validator, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void enable_silder();

		void set_centered(bool centered = true);

		void set_unit_label_text(const QString& unit_string);

		void update_customizing_state(const QString& customizing_state);

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Attribute_Sharing_Combo* m_line_editor_asc{ nullptr };
		Attribute_Sharing_Combo* m_line_editor_to_slider_asc{ nullptr };
		Attribute_Sharing_Combo* m_slider_to_line_editor_asc{ nullptr };

		bool m_centered{ false };

		Label* m_attribute_label{ nullptr };
		Label* m_unit_label{ new Label };

		Line_Editor* m_line_editor{ new Line_Editor };

		QIntValidator* m_int_validator{ nullptr };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Slider* m_slider{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class Switch_Attribute_Widget : public Attribute_Widget
	{
		Q_OBJECT

	public:
		Switch_Attribute_Widget(
			const QString& first_label_text, Attribute_Widget* first_attribute_widget,
			const QString& second_label_text, Attribute_Widget* second_attribute_widget,
			Attribute& control_attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void enable_secondary_background_color(bool cond = true);

	private:
		Attribute* m_control_attribute;

		Attribute_Widget* m_first_attribute_widget;
		Attribute_Widget* m_second_attribute_widget;

		Toggle_Switch* m_labeled_toggle_switch;
	};

	class Customize_Panel : public Widget
	{
		Q_OBJECT

	public:
		Customize_Panel(Themeable* themeable, QWidget* parent = nullptr);

		void add_attribute_widget(Attribute_Widget* attribute_widget);

		void add_element_button(Button* button);

		void update_attribute_widget_background_colors();

	private:
		void init_attributes();
		void init_child_themeable_reference_list();
		void setup_layout();

		bool m_showing_primary{ true };

		QHBoxLayout* m_states_layout{ new QHBoxLayout };

		QVBoxLayout* m_attributes_layout{ new QVBoxLayout };
		QVBoxLayout* m_elements_layout{ new QVBoxLayout };
		QVBoxLayout* m_element_buttons_layout{ new QVBoxLayout };

		Button* m_show_all_button{ new Button("Show All", true) };
		Button* m_show_primary_button{ new Button("Show Primary", true) };

		Combobox* m_state_combobox{ new Combobox };

		Label* m_attributes_label{ new Label("Attributes:") };
		Label* m_elements_label{ new Label("Elements:") };
		Label* m_states_label{ new Label("State:") };

		QList<Attribute_Widget*> m_child_attribute_widgets{ QList<Attribute_Widget*>() };

		Themeable* m_themeable;
	};

	class Menu : public Widget
	{
		Q_OBJECT

	public:
		Menu(const QString& menu_name, Graphic_Widget* menu_icon, QWidget* parent = nullptr);

		Graphic_Widget* icon{ nullptr };

		QString name;
	};

	class Menu_Label_Layer : public Widget
	{
		Q_OBJECT

	public:
		Menu_Label_Layer(Menu* menu, QWidget* parent = nullptr);

		void init_attributes();

		void init_child_themeable_reference_list();

		void shrink();
		void expand();

		Button* back_button() const;
		Button* icon_button() const;

		Label* text_label() const;

	protected:
		void init_attribute_widgets();

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_back_button{ new Button(new Graphic_Widget(":/svgs/back.svg", QSize(21, 18)), false) };
		Button* m_icon_button{ nullptr };

		Label* m_text_label{ nullptr };

		Widget* m_stretch_widget{ new Widget };
	};

	class App_Preferences_Settings_Panel : public Widget
	{
		Q_OBJECT

	public:
		App_Preferences_Settings_Panel(QWidget* parent = nullptr);

	protected:
		void init_attribute_widgets();
	};

	class Create_New_Theme_Dialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		Create_New_Theme_Dialog(QWidget* parent = nullptr);


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

		bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;

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

		Line_Editor* m_theme_name_line_edit{ new Line_Editor };

		QPainter painter;
	};

	class Themes_Settings_Panel : public Widget
	{
		Q_OBJECT

	public:
		Themes_Settings_Panel(QWidget* parent = nullptr);

		void init_attributes();
		void init_child_themeable_reference_list();

		Button* customize_theme_button() const;

		Button* new_theme_button() const;

		Combobox* theme_combobox() const;

		void show_custom_theme_buttons(bool cond = true);

	protected:
		void init_attribute_widgets();

	private:
		void setup_layout();

		Label* m_theme_label{ new Label("Theme") };

		Combobox* m_theme_combobox{ new Combobox };

		Button* m_new_theme_button{ new Button(new Graphic_Widget(":/svgs/new_theme.svg", QSize(20, 20)), true) };
		Button* m_customize_theme_button{ new Button(new Graphic_Widget(":/svgs/customize_theme.svg", QSize(20, 20)), true) };
		Button* m_delete_theme_button{ new Button(new Graphic_Widget(":/svgs/delete_theme.svg", QSize(17, 20)), true) };
		Button* m_theme_info_button{ new Button(new Graphic_Widget(":/svgs/info_theme.svg", QSize(20, 20)), true) };

		Widget* m_control_separator{ new Widget };
		Widget* m_separator_1{ new Widget };
		Widget* m_separator_2{ new Widget };
		Widget* m_spacer_1{ new Widget };
		Widget* m_spacer_2{ new Widget };
	};

	class Settings_Sidebar : public Widget
	{
		Q_OBJECT

	public:
		Settings_Sidebar(QWidget* parent = nullptr);

	protected:
		void init_attribute_widgets();
	};

	class Settings_Tab : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();
		void under_minimum_width();
		void over_minimum_width();

	public:
		Settings_Tab(Graphic_Widget* icon, const QString& label_text, QWidget* parent = nullptr);

		void expand();
		void shrink();

		void init_attributes();
		void init_attribute_widgets();
		void init_child_themeable_reference_list();

		int recommended_minimum_width();

		void set_disabled(bool cond = true);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void resizeEvent(QResizeEvent* event);

	private:
		void setup_layout();

		QHBoxLayout* main_layout{ new QHBoxLayout };

		bool m_disabled{ false };

		Label* m_text_label;

		Graphic_Widget* m_tab_icon;

		Widget* m_spacer{ new Widget };
		Widget* m_stretch_widget{ new Widget };
		Widget* m_stretch_widget2{ new Widget };
	};

	class Settings_Menu : public Menu
	{
		Q_OBJECT

	public:
		Settings_Menu(QWidget* parent = nullptr);

		void add_settings_tab(Graphic_Widget* icon, const QString& label_text);

		void init_child_themeable_reference_list();

		int largest_tab_index() const;

		int recommended_minimum_tab_width() const;

		Themes_Settings_Panel* themes_settings_panel() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

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

		Vertical_Layout* m_sidebar_layout = new Vertical_Layout;

		QList<Settings_Tab*> m_settings_tabs;

		QPoint last_pos;

		Settings_Sidebar* m_sidebar{ new Settings_Sidebar };

		App_Preferences_Settings_Panel* m_app_preferences_settings_panel{ new App_Preferences_Settings_Panel };

		Themes_Settings_Panel* m_themes_settings_panel{ new Themes_Settings_Panel };
	};

	class Customize_Menu : public Menu
	{
		Q_OBJECT

	public:
		Customize_Menu(QWidget* parent = nullptr);

		Button* apply_button() const;

		void init_preview_window();
		void init_child_themeable_reference_list();

		void open_customize_panel(Customize_Panel* customize_panel);

		Window* preview_window() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attribute_widgets();

	private:
		void setup_layout();

		Horizontal_Layout* m_main_layout = new Horizontal_Layout;
		QVBoxLayout* m_sidebar_layout{ new QVBoxLayout };
		QHBoxLayout* m_topbar_layout{ new QHBoxLayout };
		QGridLayout* m_preview_layout{ new QGridLayout };

		Widget* m_sidebar{ new Widget };
		Widget* m_topbar{ new Widget };
		Widget* m_preview_widget = new Widget;

		Scroll_Area* m_sidebar_scroll_area{ new Scroll_Area };
		Scroll_Area* m_preview_scroll_area{ new Scroll_Area };

		Window* m_preview_window{ nullptr };

		QList<Customize_Panel*> m_customize_panels;
		QList<Customize_Panel*> m_panel_stack;
		QList<Button*> m_label_button_stack;
		QList<Graphic_Widget*> m_arrow_graphic_stack;

		Button* m_apply_button{ new Button("Apply", true) };
	};

	class Titlebar : public Widget
	{
		Q_OBJECT

	public:
		Titlebar(QWidget* parent = nullptr);

		void add_mll(Menu_Label_Layer* mll);
		void remove_mlls_past(int index);

		void init_child_themeable_reference_list();

		bool is(QWidget* widget);

		void set_window_title(const QString& title);

		Button* window_icon() const;
		Button* settings_button() const;
		Button* minimize_button() const;
		Button* maximize_button() const;
		Button* exit_button() const;

	protected:
		void init_attribute_widgets();

		void resizeEvent(QResizeEvent* event);

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_window_icon{ new Button(new Graphic_Widget(QDir("./data/logo_animate"), QSize(35, 35)), true) };

		Label* m_window_title_label{ new Label("Layers - Demo") };

		Button* m_settings_button{ new Button(new Graphic_Widget(":/svgs/settings.svg", QSize(20, 20)), true) };
		Button* m_minimize_button{ new Button(new Graphic_Widget(":/svgs/minimize.svg", QSize(20, 20)), true) };
		Button* m_maximize_button{ new Button(new Graphic_Widget(":/svgs/maximize.svg", QSize(20, 20)), true) };
		Button* m_exit_button{ new Button(new Graphic_Widget(":/svgs/exit.svg", QSize(20, 20)), true) };

		Widget* m_buttons_container{ new Widget(this) };

		QList<Menu_Label_Layer*> mll_stack;

		Menu_Label_Layer* m_base_mll{ nullptr };

		Menu_Label_Layer* m_control_mll{ new Menu_Label_Layer(new Menu("Control Menu", new Graphic_Widget(":/svgs/icon_icon.svg", QSize(20, 20)))) };

		Widget* m_stretch_widget{ new Widget };
	};

	class Window : public Widget
	{
		Q_OBJECT

	public:
		Window(bool is_preview_window = false, QWidget* parent = nullptr);

		void add_menu(Menu* menu);
		void add_theme(const QString& name, const Theme& theme);

		void apply_theme(Theme& theme);

		void assign_tag_prefixes();

		void center_dialog(QDialog* dialog);

		Customize_Menu* customize_menu() const;

		void finalize();

		void init_child_themeable_reference_list();

		void update_theme_dependencies();

		void set_window_title(const QString& title);

		Settings_Menu* settings_menu() const;

		Titlebar* titlebar() const;

	public slots:
		void apply_theme_changes();
		void change_current_theme_name(const QString& old_name, const QString& new_name);
		void create_theme(const QString& new_theme_name, const QString& copy_theme_name);
		void customize_clicked();
		void exit_clicked();
		void maximize_clicked();
		void minimize_clicked();
		void new_theme_clicked();
		void open_menu(Menu* menu);
		void settings_clicked();

	protected:
		void init_attribute_widgets();

		Theme load_theme(const QString& file_path);

		bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;

		void paintEvent(QPaintEvent* event) override;

		void save_theme(const Theme& theme);

	private:
		void setup_layout();

		bool m_maximized{ false };

		Create_New_Theme_Dialog* m_create_new_theme_dialog{ new Create_New_Theme_Dialog };

		QMap<QString, Theme> m_themes;

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QList<Menu*> m_menus;
		QList<Menu*> m_menu_stack;

		Titlebar* m_titlebar{ new Titlebar };

		// TODO: Make Menu constructor that does not require an icon
		Menu* m_app_menu{ new Menu("App", new Graphic_Widget(":/svgs/settings_animated.svg", QSize(24, 24))) };

		Settings_Menu* m_settings_menu{ new Settings_Menu };

		Customize_Menu* m_customize_menu{ new Customize_Menu };
	};

	template<typename T>
	inline void Themeable::share_all_attributes_with(T* themeable)
	{
		if (typeid(*this) == typeid(*themeable))
		{
			for (Attribute& attribute : m_attributes)
				for (const QString& state : attribute.states())
					share_attribute_with_themeable(state, attribute, state, themeable->attributes()[attribute.name()]);


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
			for (Attribute& attribute : m_attributes)
				for (const QString& state : attribute.states())
					unshare_attribute_with_themeable(state, attribute, state, themeable->attributes()[attribute.name()]);

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

#endif // LAYERS_H
