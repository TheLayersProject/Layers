#ifndef LATTRIBUTE_H
#define LATTRIBUTE_H

#include <QHash>
#include <QJsonObject>
#include <QObject>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

using LAttributeList = QList<LAttribute*>;
using LAttributeMap = QMap<QString, LAttribute*>;

/*!
	An LAttribute is a QObject that serves as a value container for Layers
	widgets and themes.

	Attributes store values as QVariant objects. This allows attributes to be
	capable of storing any type supported by QVariant.
	
	Attributes also maintain QJsonObject instances that are kept in sync with
	the values of the QVariant objects. The QJsonObject instances make saving
	themes much faster.

	Usage varies depending on the parent type. Typically, an LAttribute is
	owned by either a Layers widget (LThemeable subclass), an LThemeItem, or
	another LAttribute. These are referred to as widget attributes, theme
	attributes, and override attributes, respectively.

	<b>Widget attributes</b> change the appearance of their parent widgets.

	<b>Theme attributes</b> modify the value of widget attributes.

	<b>Override attributes</b> overtake the value of their parent attributes
	when the value is requested with a state-combination that matches the
	override attribute.

	## Applying Theme Attributes to Widget Attributes

	When a theme is applied to a Layers widget via LThemeable::apply_theme(),
	the theme attributes are applied to the widget's attributes using
	set_theme_attribute(). After this, when the value is requested from one of
	the widget attributes, the value of the theme attribute is returned
	instead.

	## Attribute Linking

	An attribute can be linked to another attribute whose value is used instead
	of the attribute's original value. For example:

	~~~~~~~~~~~~~{.c}
	LAttribute* slider_value = new LAttribute("Slider Value", 0);
	LAttribute* thickness = new LAttribute("Thickness", 10);

	slider_value->set_link_attribute(thickness);

	//  After set_link_attribute() is called above, slider_value is linked to
	//  thickness, so the thickness value represents both attributes.

	slider_value.set_value(15);

	//  The above call actually sets the value of thickness to 15.
	~~~~~~~~~~~~~

	In the example above, *slider_value* is linked to *thickness*. After the
	relationship is established, *slider_value* is considered a dependency
	of *thickness*. A list of dependent attributes can be obtained through
	calling dependent_attributes():

	~~~~~~~~~~~~~{.c}
	//  ... continued from above

	LAttributeList thickness_dependencies = thickness->dependent_attributes();

	//  thickness_dependencies should contain the slider_value attribute.
	~~~~~~~~~~~~~

	## Linking Theme Attributes (Soft Linking)

	Themes (and therefore, theme attributes) support linking. Most links are
	handled within themes so that they can be manipulated during theme editing.
	These links are referred to as **soft links** since they are **intended to
	be changeable**.

	A theme attribute links to another by storing a *link path* which is a
	string that identifies the theme attribute being linked to. Themes do not
	resolve these path-based links until the end of the loading process.

	These links between theme attributes can be established or broken by the
	user if the application provides access to the LThemeEditorDialog.

	## Linking Widget Attributes (Hard Linking)

	Links can also be established outside of themes between widget attributes
	directly. This is typical for control widgets where users interact with the
	widget to control a particular value. For example:

	~~~~~~~~~~~~~{.c}
	LWidget* widget = new LWidget;
	LSlider* thickness_slider = new LSlider;

	thickness_slider->value()->set_link_attribute(widget->border_thickness());

	//  After the above link is established, when the user interacts with
	//  thickness_slider, the widget's border thickness will change.
	~~~~~~~~~~~~~

	These links are referred to as **hard links** since they are established by
	the developer and **not intended to be changeable**.

	## Override Attributes

	Sometimes, you want one attribute to have multiple values. Consider a
	button whose fill value changes when the mouse hovers over it. This can be
	handled by adding an override attribute to the fill attribute:

	~~~~~~~~~~~~~{.c}
	LAttribute* button_fill = new LAttribute("Button Fill", QColor(Qt::green));
	button_fill->create_override("Selected", QColor(Qt::lightGreen));

	QColor color = button_fill->as<QColor>();
	QColor selected_color = button_fill->as<QColor>({ "Selected" });

	//  color should be the value of Qt::green.
	//  selected_color should be the value of Qt::lightGreen.
	~~~~~~~~~~~~~

	Override attributes can not have other override attributes.
*/
class LAYERS_EXPORT LAttribute : public QObject
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the attribute's value is changed.
	*/
	void changed();

	/*!
		This signal is emitted if the a new link is set or if the active one is
		broken.
	*/
	void link_changed();

public:
	/*!
		Constructs an invalid attribute.
	*/
	LAttribute(const QString& name,
		QObject* parent = nullptr);

	/*!
		Constructs an attribute with a *value*.
	*/
	LAttribute(const QString& name, QVariant value,
		QObject* parent = nullptr);

	/*!
		Constructs an attribute from a QJsonObject.
	*/
	LAttribute(const QString& name, QJsonObject json_object,
		QObject* parent = nullptr);

	/*!
		Constructs a copy of *attribute*.
	*/
	LAttribute(const LAttribute& attribute);

	~LAttribute();

	/*!
		Returns the attribute's value converted to the template type T.

		If a theme attribute has been set, its value is returned.

		If the attribute contains an override attribute that matches the list
		of *states*, then its value is returned.

		If a link attribute has been set, its value is returned.

		If none of the other conditions are true, then the attribute's stored
		value is returned.
	*/
	template<typename T>
	T as(const QStringList& states = QStringList());

	/*!
		Breaks the link relationship if a link attribute has been set.

		Resets the link path to empty.

		Removes the caller attribute as a dependent attribute of the
		previously linked attribute.
	*/
	void break_link();

	/*!
		Deletes all override attributes.
	*/
	void clear_overrides();

	/*!
		Resets theme attribute pointer to nullptr and clears connection to it.
	*/
	void clear_theme_attribute();

	/*!
		Creates a new override with *name* and *value*.

		The *name* parameter should consist of the state-combination that the
		override pertains to. Multiple states should be separated by colons
		(e.g. "Inactive:Hovered").
	*/
	void create_override(const QString& name, QVariant value);

	/*!
		Returns list containing the attributes that link to this one.

		If include_indirect_dependencies is true, then the function will work
		recursively to return the dependent attributes of dependent attributes.
	*/
	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	/*!
		Returns true if the attribute contains any override attributes.
	*/
	bool has_overrides() const;

	/*!
		Returns a reference to the attribute's QJsonObject instance.
	*/
	QJsonObject& json_object();

	/*!
		Returns a pointer to the link attribute if one has been set. Otherwise,
		returns nullptr.
	*/
	LAttribute* link_attribute() const;

	/*!
		Returns the link path if one has been set. Otherwise, returns an empty
		QString.
	*/
	QString link_path() const;

	/*!
		Returns the name of the attribute.
	*/
	QString name() const;

	LAttribute* override_attribute(const QStringList& states);

	/*!
		Returns a map containing the override attributes.
	*/
	LAttributeMap overrides() const;

	/*!
		Sets the theme attribute to *theme_attr*.

		This function is called by LThemeable::apply_theme() to apply theme
		attributes to widget attributes. Library users are unlikely to ever
		need to call this function manually.
	*/
	void set_theme_attribute(LAttribute* theme_attr);

	/*!
		Sets the link attribute to *link_attr*.

		Sets the caller attribute as a dependent attribute of *link_attr*.

		As long as the link remains established, the value of *link_attr* will
		be returned when the caller's value is requested.
	*/
	void set_link_attribute(LAttribute* link_attr);

	/*!
		Sets the attribute's link path.
	*/
	void set_link_path(const QString& link_path);

	/*!
		Sets the attribute's *value*.

		If a link attribute has been set, its value is set instead.
	*/
	void set_value(QVariant value);

	/*!
		Returns the path of the attribute.

		An attribute path consists of the attribute's name appended at the end
		of the parent's path. If no parent exists, then just the name is
		returned.
	*/
	QString path() const;

	/*!
		Returns attribute represented as a QJsonObject.
	*/
	QJsonObject to_json_object();

	/*!
		Returns the attribute's value as a QJsonValue.
	*/
	QJsonValue to_json_value();

	/*!
		Returns the name of type stored in the attribute's value.
	*/
	QString typeName(const QStringList& states = QStringList());

	/*!
		Returns the attribute's value.

		If a link attribute has been set, its value is returned instead.
	*/
	QVariant value();

private slots:
	void update_json_object();

private:
	void establish_link_connections();
	void establish_theme_connection();

	void emit_link_changed();

	QMetaObject::Connection m_link_connection;
	QMetaObject::Connection m_link_destroyed_connection;
	QMetaObject::Connection m_theme_connection;

	LAttributeList m_dependent_attrs;

	LAttribute* m_theme_attr{ nullptr };

	LAttribute* m_link_attr{ nullptr };

	QString m_link_path;

	QString m_name;

	LAttributeMap m_overrides;

	QVariant m_value;

	QJsonObject m_json_object;
};

template<typename T>
inline T LAttribute::as(const QStringList& states)
{
	if (m_theme_attr)
		return m_theme_attr->as<T>(states);

	if (!m_overrides.isEmpty() && !states.isEmpty())
		if (LAttribute* override_attr = override_attribute(states))
			return override_attr->as<T>();

	if (m_link_attr)
		return m_link_attr->as<T>();

	return m_value.value<T>();
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
