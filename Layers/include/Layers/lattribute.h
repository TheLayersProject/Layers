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
	An LAttribute is an LAbstractAttribute that creates a specialized Data
	container.
	
	An attribute works by pointing to a data object, labeling it, and giving it
	a purpose.
	
	The relationship between attributes and data is analogous to the
	relationship between variables (i.e., value containers) and the values they
	store.
	
	## Data Ownership
	
	Initially, an attribute *owns* the data it points to. However, it can be
	*linked* with another attribute, after which it will no longer own the
	data it points to.
	
	## Entanglement
	
	A key feature of attributes is entanglement. *Entanglement* is the term
	used to describe the action of forcing one attribute to delete its data and
	point to the data of another attribute. This is done by calling
	link_to().
	
	~~~~~~~~~~~~~{.c}
	//  Example of attribute entanglement
	
	LAttribute slider_value = LAttribute("slider_value", 0);
	LAttribute thickness = LAttribute("thickness", 10);
	
	slider_value.link_to(thickness);
	
	//	After link_to() is called above, the slider_value attribute
	//	discards its data object containing the 0 value and points to the data
	//	object owned by the thickness attribute. The slider_value attribute is
	//	considered linked beyond this point.

	slider_value.set_value(15);

	//  The above call sets the value of the slider_value attribute to 15, but
	//  since it is linked with the thickness attribute, it actually updates
	//  the value of the data object owned by the thickness attribute. 
	~~~~~~~~~~~~~

	Combine this with value change detection and you get a recipe for attribute
	control widgets that update in real-time.

	~~~~~~~~~~~~~{.c}
	//  Example of attribute control widgets that update in real-time via
	//  attribute entanglement and value change detection.

	//  Keep in mind that Layers widgets have been setup already to call
	//  QWidget::update() when changes to their attributes are detected.

	LWidget* widget = new LWidget;
	LSlider* thickness_slider = new LSlider;

	thickness_slider->value()->link_to(*widget->border_thickness());

	//  That's it! Display both the widget and the thickness_slider to the
	//  user, and when they make changes to the slider, those changes will
	//  update the widget's border thickness in real-time.
	~~~~~~~~~~~~~
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
		Constructs an attribute with invalid data.
	*/
	LAttribute(const QString& name, QObject* parent = nullptr);

	/*!
		Constructs an attribute with single-valued data.
	*/
	LAttribute(const QString& name, QVariant value, QObject* parent = nullptr);

	/*!
		Constructs an attribute with data initialized with a QJsonObject.
	*/
	LAttribute(const QString& name, QJsonObject json_object, QObject* parent = nullptr);

	/*!
		Constructs a copy of *attribute*.
	*/
	LAttribute(const LAttribute& attribute);

	~LAttribute();

	void add_override(const QString& name, QVariant value);

	/*!
		Returns data value converted to the template type T.

		The *state* parameter is only necessary for multi-valued
		attributes. If the default value (an empty string) is used, and the
		attribute is multi-valued, then the value of the active state is
		returned.
	*/
	template<typename T>
	T as(const QStringList& states = QStringList()) const;

	void break_link();

	void clear_overrides();

	void clear_theme_attribute();

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies = false) const;

	/*!
		Returns true if this attribute's data is multi-valued. Otherwise,
		returns false.
	*/
	bool has_overrides() const;

	QJsonObject& json_object();

	LAttribute* link_attribute() const;

	QString link_path() const;

	/*!
		Returns the name of the attribute.
	*/
	QString name() const;

	LAttributeMap overrides() const;

	void set_theme_attribute(LAttribute* theme_attr);

	/*!
		Forces this attribute to point to the data of *attribute*.

		After this function executes, this attribute is considered *linked*
		with *attribute*.

		If this attribute was not previously linked, the data is deleted
		before the new pointer is assigned.

		Emits both linked() and changed().

		Another connection is established so that if *attribute* becomes
		linked, this function gets called again so this attribute can get a
		pointer to the new data.
	*/
	void set_link_attribute(LAttribute* link_attr);

	void set_link_path(const QString& link_path);

	/*!
		Sets the data's value.

		The *state* parameter is only necessary for multi-valued attributes. If
		the default value (an empty string) is used, and the attribute is
		multi-valued, then the value of the active state is set.
	*/
	void set_value(QVariant value);

	QString path() const;

	/*!
		Returns attribute represented as a QJsonObject.
	*/
	QJsonObject to_json_object();

	QJsonValue to_json_value();

	/*!
		Returns the name of type stored in the attribute's data.
	*/
	const char* typeName() const;

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
inline T LAttribute::as(const QStringList& states) const
{
	if (m_theme_attr)
		return m_theme_attr->as<T>(states);

	if (!m_overrides.isEmpty() && !states.isEmpty())
	{
		for (LAttribute* override_attr : m_overrides)
		{
			QStringList override_states = override_attr->name().split(":");

			bool return_override_attr = true;

			for (const QString& override_state : override_states)
				if (!states.contains(override_state))
					return_override_attr = false;

			if (return_override_attr)
				return override_attr->as<T>();
		}

		// TODO: Handle returning override with highest number of matching
		// states. If there is a conflict (two matching overrides), just
		// return the value of this
	}

	if (m_link_attr)
		return m_link_attr->as<T>();

	return m_value.value<T>();
}

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H
