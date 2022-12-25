#ifndef DATA_H
#define DATA_H

#include <QJsonObject>

#include "Variant.h"

namespace Layers
{
	/*!
		Data type

		A Data object is a QObject that stores a pointer to either a single Variant
		or a QMap of QString-Variant pairs where the QString represents the state
		associated with the Variant.

		Data storing a pointer to a state-Variant map is stateful, whereas Data storing
		a pointer to a single Variant is not stateful. This can be referred to as the
		Data's statefulness.

		The term 'value' is sometimes used synonymously with Variant, although, technically
		the value is stored in a QVariant stored within the Variant. For example, the
		set_value() function takes a QVariant argument intended to represent the value being set.
	*/
	class Data : public QObject
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		Data(QVariant qvariant);
		Data(QMap<QString, Variant> state_variant_map);
		Data(const Data& d);
		~Data();

		/*!
			Returns the value stored in the single Variant converted to the template type T

			This function must only be used with Data objects that are not stateful.

			@returns Variant value converted to template type T
		*/
		template<typename T>
		T as() const;

		/*!
			Returns the value stored in the Variant associated with the supplied state,
			converted to the template type T.

			This function must only be used with Data objects that are stateful.

			@returns Value of Variant associated with state, converted to template type T
		*/
		template<typename T>
		T as(const QString& state) const;

		/*!
			Returns true if state exists in the state-variant map, otherwise, returns false.

			@param state - State to check whether it exists in the state-variant map
			@returns True if state exists in map, false otherwise
		*/
		bool contains_state(const QString& state) const;

		/*!
			Copies the supplied Data object.

			If the statefulness between the data objects is the same, then the values are
			simply copied over. If it is not the same, the statefulness of the caller Data
			is converted to the statefulness of the supplied Data before the values are copied.
		*/
		void copy(const Data& data);

		/*!
			Converts to stateful Data initialized with the supplied map.

			@param state_variant_map - Map to initialize the Data with
		*/
		void init_state_variant_map(const QMap<QString, Variant>& state_variant_map);

		/*!
			Returns true if stateful, otherwise, returns false.

			@returns True if stateful, false otherwise
		*/
		bool is_stateful() const;

		/*!
			Set the value of the stored Variant.

			This function will only work with Data objects that are not stateful.

			@param qvariant - QVariant containing the value being set
			@param retain_type - Whether to protect the value type from change, true by default
		*/
		void set_value(QVariant qvariant, bool retain_type = true);

		/*!
			Set the value of the stored Variant associated with state.

			This function will only work with Data objects that are stateful.

			@param state - State associated with value
			@param qvariant - QVariant containing the value being set
		*/
		void set_value(const QString& state, QVariant qvariant);

		/*!
			Returns a list of QStrings representing the available states.

			If the Data is not stateful, then an empty list will be returned.

			@returns QString list where QStrings represent the states
		*/
		QList<QString> states() const;

		/*!
			Returns Data converted to a QJsonObject.

			@returns QJsonObject pertaining to the Data
		*/
		QJsonObject to_json_object();

		/*!
			Returns the name of the type stored in the Data.

			If the Data is not stateful, the type name of the single Variant is returned.
			If it is stateful, then the type name of the Variant associated with the first
			key state of the state-Variant map is returned.

			@returns Name of type stored within the Data
		*/
		const char* typeName() const;

	private:
		QMap<QString, Variant>* m_state_variant_map{ nullptr };

		Variant* m_variant{ nullptr };
	};

	template<typename T>
	inline T Data::as() const
	{
		return m_variant->value<T>();
	}

	template<typename T>
	inline T Data::as(const QString& state) const
	{
		return (*m_state_variant_map)[state].value<T>();
	}
}

#endif // DATA_H