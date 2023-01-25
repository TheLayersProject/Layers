#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "AttributeType.h"
#include "Data.h"

namespace Layers
{
	/*!
		Attribute implementation used throughout Layers by AttributeGroup, Theme, and Themeable.

		An Attribute stores a pointer to a Data object which is used for drawing Themeables. At first,
		an Attribute inializes Data and *owns* it. However, through entangle_with(), an Attribute can
		be made to point to Data from another Attribute.
	*/
	class Attribute : public AttributeType
	{
		Q_OBJECT

	signals:
		void ownership_changed();

	public:
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, QVariant qvariant, bool disabled = false);
		Attribute(const QString& name, QMap<QString, Variant> state_variant_map, bool disabled = false);
		Attribute(const Attribute& a);
		~Attribute();

		/*!
			Returns Data value converted to the template type T.

			If the Attribute is stateful, the value associated with the current state is returned.
			If the value associated with a specific state is desired, use the version of as() that
			requires a state argument.

			@returns Data value converted to template type T
		*/
		template<typename T>
		T as() const;

		/*!
			Returns Data value associated with the supplied state, converted to the template type T.

			This function will work only if the Attribute is stateful and only if the state supplied exists
			in the state-variant map.

			@returns Data value associated with state, converted to template type T
		*/
		template<typename T>
		T as(const QString& state) const;

		/*!
			Deletes the Data if the Attribute is the owner.
		*/
		void clear_data_if_owner();

		/*!
			Returns true if state exists in the Data, otherwise, returns false.

			@param state - State to check whether it exists in the Data
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
			Makes this Attribute to point to the Data of another Attribute.

			If the caller Attribute owns its Data, the Data is deleted before the pointer is changed.

			Establishes a new data connection and emits both ownership_changed() and value_changed().

			Another connection is established so that if the attribute supplied changes its ownership,
			this function gets called again so the caller Attribute can get a pointer to the new Data.

			@param attribute - Attribute to obtain the Data pointer of
		*/
		void entangle_with(Attribute& attribute);

		/*!
			Converts to stateful Data initialized with the supplied map.

			This function simply calls Data::init_state_variant_map() and passes the state_variant_map.

			@param state_variant_map - Map to initialize the Data with
		*/
		void init_state_variant_map(const QMap<QString, Variant>& state_variant_map);

		/*!
			Returns true if stateful, otherwise, returns false.

			This function simply calls Data::is_stateful().

			@returns True if stateful, false otherwise
		*/
		virtual bool is_stateful() const override;

		/*!
			Returns true if Attribute owns the Data object being pointed to, otherwise, returns false.

			@returns True if Data object is owned by Attribute, false otherwise
		*/
		bool owns_data() const;

		/*!
			Sets the Attribute's active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Set the value of the Data.

			This function simply calls Data::set_value() and passes qvariant and retain_type. It only
			works with Attributes that are not stateful.

			@param qvariant - QVariant containing the value being set
			@param retain_type - Whether to protect the value type from change, true by default
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
			Returns a list of QStrings representing the available states.

			If the Attribute is not stateful, then an empty list will be returned.

			@returns QString list where QStrings represent the states
		*/
		QList<QString> states() const;

		/*!
			Returns Attribute converted to a QJsonObject.

			@returns QJsonObject pertaining to the Attribute
		*/
		QJsonObject to_json_object();

		/*!
			Returns the name of the value's type.

			This function simply calls Data::typeName().

			@returns Name of value's type
		*/
		const char* typeName() const;

	private:
		Data* m_data{ nullptr };

		QMetaObject::Connection m_data_connection;

		bool m_owns_data{ true };

		QString m_state{ "" };
	};

	template<typename T>
	inline T Attribute::as() const
	{
		if (m_data->is_stateful())
			return m_data->as<T>(m_state);

		return m_data->as<T>();
	}

	template<typename T>
	inline T Attribute::as(const QString& state) const
	{
		return m_data->as<T>(state);
	}
}

#endif // ATTRIBUTE_H