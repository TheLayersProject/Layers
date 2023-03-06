#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Entity.h"
#include "Data.h"

namespace Layers
{
	/*!
		An Attribute is an Entity that implements a specialized Data container.
	
		An attribute works by pointing to a data object and providing it with
		the characteristics of an entity. An attribute *labels* data and gives
		it purpose.
	
		The relationship between attributes and data is analogous to the
		relationship between variables (i.e., value containers) and the values
		they store.
	
		# Data Ownership
	
		Initially, an attribute will *own* the data it points to. However, it
		can be forced to *entangle* with another attribute, after which it will
		no longer own the data it points to.
	
		# Entanglement
	
		A key feature of attributes is entanglement. *Entanglement* is the term
		used to describe the action of forcing one attribute to delete its data
		and point to the data of another attribute. This is done by calling
		entangle_with().
	
		~~~~~~~~~~~~~{.c}
		//  Example of attribute entanglement
	
		Attribute slider_value = Attribute("slider_value", 0);
		Attribute thickness = Attribute("thickness", 10);
	
		slider_value.entangle_with(thickness);
	
		//	After entangle_with() is called above, the slider_value attribute
		//	discards its data object containing the 0 value and points to the
		//	data object owned by the thickness attribute. The slider_value
		//	attribute is considered entangled beyond this point.

		slider_value.set_value(15);

		//  The above call sets the value of the slider_value attribute to 15,
		//  but since it is entangled with the thickness attribute, it
		//  actually updates the value of the data object owned by the
		//  thickness attribute. 
		~~~~~~~~~~~~~

		Combine this with value change detection and you get a recipe for
		attribute control widgets that update in real-time.

		~~~~~~~~~~~~~{.c}
		//  Example of attribute control widgets that update in real-time
		//  via attribute entanglement and value change detection.

		//  Keep in mind that Layers widgets have been setup already to call
		//  QWidget::update() when changes to their attributes are detected.

		Widget* widget = new Widget;
		Slider* thickness_slider = new Slider;

		thickness_slider->value()->entangle_with(
			*widget->border()->thickness());

		//  Thats it! Display both the widget and the thickness_slider to the
		//  user, and when they make changes to the slider, those changes will
		//  update the widget's border thickness in real-time.
		~~~~~~~~~~~~~
	*/
	class Attribute : public Entity
	{
		Q_OBJECT

	signals:
		void entangled();

	public:
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, Variant variant, bool disabled = false);
		Attribute(const QString& name, VariantMap variant_map, bool disabled = false);
		Attribute(const Attribute& a);
		~Attribute();

		/*!
			Returns Data value converted to the template type T.

			The state parameter is only necessary for stateful Attributes.
			If the default value (an empty string) is used, and the Attribute
			is stateful, the value of the active state is returned.

			@param state - State associated with returned value
			@returns Data value converted to template type T
		*/
		template<typename T>
		T as(const QString& state = "") const;

		/*!
			Returns true if state exists in the Data, otherwise, returns false.

			@param state - State that might exist in the Data
			@returns True if state exists in Data, false otherwise
		*/
		bool contains_state(const QString& state) const;

		/*!
			Copies the supplied Attribute

			@param attr - Attribute to copy
		*/
		void copy(const Attribute& attr);

		/*!
			Connects the Data changed signal to emit value_changed().

			The previous connection is disconnected.
		*/
		void establish_data_connection();

		/*!
			Forces the Attribute to point to the Data of another Attribute.

			After this function, the caller Attribute is considered *entangled*
			with the other Attribute.

			If the caller Attribute was not previously entangled, the Data is
			deleted before the new pointer is assigned.

			Establishes a new data connection and emits both entangled() and
			value_changed().

			Another connection is established so that if the supplied attribute
			becomes entangled, this function gets called again so the caller
			Attribute can get a pointer to the new Data.

			@param attribute - Attribute to entangle with
		*/
		void entangle_with(Attribute& attribute);

		/*!
			Converts to stateful Data initialized with the supplied map.

			This function simply calls Data::init_variant_map() and passes the
			variant_map.

			@param variant_map - Variant map to initialize the Data with
		*/
		void init_variant_map(const VariantMap& variant_map);

		/*!
			Returns true if Attribute is entangled, otherwise, returns false.

			An entangled Attribute does not own the Data it points to.

			@returns True if entangled, false otherwise
		*/
		bool is_entangled() const;

		/*!
			Returns true if the Data this Attribute points to is stateful,
			otherwise, returns false.

			This function simply returns the result of Data::is_multi_valued().

			@returns True if stateful, false otherwise
		*/
		virtual bool is_multi_valued() const override;

		/*!
			Sets the Attribute's active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Set the Data value.

			The state parameter is only necessary for stateful Attributes.
			If the default value (an empty string) is used, and the Attribute
			is stateful, the value of the active state is set.

			@param qvariant - QVariant containing the value being set
			@param state - State associated with value
		*/
		void set_value(Variant variant, const QString& state = "");

		/*!
			Returns the active state of the Attribute.

			@returns Active state represented as a QString
		*/
		QString state() const;

		/*!
			Returns a QStringList of the available states.

			If the Attribute is not stateful, an empty list will be returned.

			@returns QString list where QStrings represent the states
		*/
		QStringList states() const;

		/*!
			Returns Attribute represented as a QJsonObject.

			@returns QJsonObject representing the Attribute
		*/
		QJsonObject to_json_object();

		/*!
			Returns the name of the Data value's type.

			This function simply calls Data::typeName().

			@returns Name of value's type
		*/
		const char* typeName() const;

	private:
		Data* m_data{ nullptr };

		QMetaObject::Connection m_data_connection;

		QMetaObject::Connection m_reentanglement_connection;

		bool m_is_entangled{ false };

		QString m_state{ "" };
	};

	template<typename T>
	inline T Attribute::as(const QString& state) const
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
}

#endif // ATTRIBUTE_H