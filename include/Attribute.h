#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "AbstractAttribute.h"
#include "Data.h"

namespace Layers
{
	/*!
		An Attribute is an implementaion of AbstractAttribute that creates a
		specialized Data container.
	
		An attribute works by pointing to a data object, labeling it, and
		giving it a purpose.
	
		The relationship between attributes and data is analogous to the
		relationship between variables (i.e., value containers) and the values
		they store.
	
		## Data Ownership
	
		Initially, an attribute *owns* the data it points to. However, it can
		be *entangled* with another attribute, after which it will no longer
		own the data it points to.
	
		## Entanglement
	
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
	class Attribute : public AbstractAttribute
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted if the attribute becomes entangled.
		*/
		void entangled();

	public:
		/*!
			Constructs an attribute with invalid data.
		*/
		Attribute(const QString& name,
			bool disabled = false);

		/*!
			Constructs an attribute with single-valued data.
		*/
		Attribute(const QString& name, Variant variant,
			bool disabled = false);

		/*!
			Constructs an attribute with multi-valued data.
		*/
		Attribute(const QString& name, VariantMap variant_map,
			bool disabled = false);

		/*!
			Constructs an attribute with data initialized with a QJsonObject.
		*/
		Attribute(const QString& name, QJsonObject json_object,
			bool disabled = false);

		/*!
			Constructs a copy of *attribute*.
		*/
		Attribute(const Attribute& attribute);

		~Attribute();

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
		void copy(const Attribute& attribute);

		/*!
			Forces this attribute to point to the data of *attribute*.

			After this function executes, this attribute is considered
			*entangled* with *attribute*.

			If this attribute was not previously entangled, the data is
			deleted before the new pointer is assigned.

			Emits both entangled() and changed().

			Another connection is established so that if *attribute* becomes
			entangled, this function gets called again so this attribute can
			get a pointer to the new data.
		*/
		void entangle_with(Attribute& attribute);

		/*!
			Converts to multi-valued data initialized with *variant_map*.
		*/
		void init_variant_map(const VariantMap& variant_map);

		/*!
			Returns true if this attribute is entangled. Otherwise, returns
			false.
		*/
		bool is_entangled() const;

		/*!
			Returns true if this attribute's data is multi-valued. Otherwise,
			returns false.
		*/
		virtual bool is_multi_valued() const override;

		/*!
			Sets the active state of this attribute to *state*.
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Sets the data's value.

			The *state* parameter is only necessary for multi-valued
			attributes. If the default value (an empty string) is used, and the
			attribute is multi-valued, then the value of the active state is
			set.
		*/
		void set_value(Variant variant, const QString& state = "");

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

		void establish_reentanglement_connection(Attribute& attribute);

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