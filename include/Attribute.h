#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Entity.h"
#include "Data.h"

namespace Layers
{
	/*!
		Attribute implementation used throughout Layers, especially by Themes
		and Themeables.

		An Attribute represents labeled Data, and if the Data it represents is
		stateful, the Attribute is also responsible for defining the active
		state.

		A key feature of Attributes is entanglement. 'Entanglement' is the term
		used to describe the action of forcing one Attribute to delete its Data
		and point to the Data of another Attribute. This is done by calling
		entangle_with().

		Attributes employ a concept of ownership over the Data they point to.
		Initially, an Attribute owns its Data, but if it becomes *entangled*
		with another Attribute, it will no longer own Data since the Data it
		points to after being entangled is owned by the other Attribute.
	*/
	class Attribute : public Entity
	{
		Q_OBJECT

	signals:
		void entangled();

	public:
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, QVariant qvariant, bool disabled = false);
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

			@param attribute - Attribute to obtain the Data pointer of
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

			This function simply returns the result of Data::is_stateful().

			@returns True if stateful, false otherwise
		*/
		virtual bool is_stateful() const override;

		/*!
			Sets the Attribute's active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Set the value of the Data.

			This function simply calls Data::set_value() and passes qvariant
			and retain_type. It only works with Attributes that are not
			stateful.

			@param qvariant - QVariant containing the value being set
			@param retain_type - Whether to protect the value type from change,
			true by default
		*/
		void set_value(QVariant qvariant, bool retain_type = true);

		/*!
			Set the Data value associated with state.

			This function simply calls Data::set_value() and passes state and qvariant. It only works
			with Attributes that are stateful.

			@param state - State associated with value
			@param qvariant - QVariant containing the value being set
		*/
		void set_value(const QString& state, QVariant qvariant);

		virtual void setup_widget_update_connection(QWidget* widget) override;

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

		bool m_is_entangled{ false };

		QString m_state{ "" };
	};

	template<typename T>
	inline T Attribute::as(const QString& state) const
	{
		if (m_data->is_stateful())
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