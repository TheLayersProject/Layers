#ifndef LATTRIBUTE_H
#define LATTRIBUTE_H

#include <QHash>
#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

#include "ldata.h"

LAYERS_NAMESPACE_BEGIN
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

	thickness_slider->value()->link_to(*widget->border()->thickness());

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
		This signal is emitted if the attribute becomes linked.
	*/
	void linked();

public:
	/*!
		Constructs an attribute with invalid data.
	*/
	LAttribute(const QString& name);

	/*!
		Constructs an attribute with single-valued data.
	*/
	LAttribute(const QString& name, LVariant variant);

	/*!
		Constructs an attribute with multi-valued data.
	*/
	LAttribute(const QString& name, LVariantMap variant_map);

	/*!
		Constructs an attribute with data initialized with a QJsonObject.
	*/
	LAttribute(const QString& name, QJsonObject json_object);

	/*!
		Constructs a copy of *attribute*.
	*/
	LAttribute(const LAttribute& attribute);

	~LAttribute();

	/*!
		Returns data value converted to the template type T.

		The *state* parameter is only necessary for multi-valued
		attributes. If the default value (an empty string) is used, and the
		attribute is multi-valued, then the value of the active state is
		returned.
	*/
	template<typename T>
	T as(const QString& state = "") const;

	/*!
		Returns true if state exists in the data. Otherwise, returns false.
	*/
	bool contains_state(const QString& state) const;

	/*!
		Copies the valuation of *attribute*.
	*/
	void copy(const LAttribute& attribute);

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
	void establish_link(LAttribute& attr);

	void set_link_new(const QString& link);

	/*!
		Converts to multi-valued data initialized with *variant_map*.
	*/
	void init_variant_map(const LVariantMap& variant_map);

	/*!
		Returns true if this attribute is linked. Otherwise, returns
		false.
	*/
	bool link_established() const;

	/*!
		Returns true if this attribute's data is multi-valued. Otherwise,
		returns false.
	*/
	bool is_multi_valued() const;

	/*!
		Returns the name of the attribute.
	*/
	QString name();

	/*!
		Sets the active state of this attribute to *state*.
	*/
	void set_state(const QString& state);

	/*!
		Sets the data's value.

		The *state* parameter is only necessary for multi-valued attributes. If
		the default value (an empty string) is used, and the attribute is
		multi-valued, then the value of the active state is set.
	*/
	void set_value(LVariant variant, const QString& state = "");

	/*!
		Returns the active state of the attribute.
	*/
	QString state() const;

	/*!
		Returns a QStringList of the states associated with the attribute's
		data.

		If the data is single-valued, an empty list will be returned.
	*/
	QStringList states() const;

	/*!
		Returns attribute represented as a QJsonObject.
	*/
	QJsonObject to_json_object();

	/*!
		Returns the name of type stored in the attribute's data.
	*/
	const char* typeName() const;

private:
	void establish_data_connection();

	void establish_reentanglement_connection(LAttribute& attribute);

	LData* m_data{ nullptr };

	QMetaObject::Connection m_data_connection;

	QMetaObject::Connection m_reentanglement_connection;

	bool m_link_established{ false };

	QString m_link;

	QString m_name;

	QString m_state;
};

template<typename T>
inline T LAttribute::as(const QString& state) const
{
	if (m_data->is_multi_valued())
	{
		if (state == "")
			return m_data->as<T>(m_state);
		else
			return m_data->as<T>(state);
	}
		
	return m_data->as<T>();
}

using LAttributeMap = QMap<QString, LAttribute*>;

LAYERS_NAMESPACE_END

#endif // LATTRIBUTE_H