#ifndef DATA_H
#define DATA_H

#include <QJsonObject>

#include "Variant.h"

namespace Layers
{
	/*!
		Data type which represents either a single Variant or multiple Variants

		A Data object is a QObject that stores a pointer to either a single
		Variant or a QVariantMap where QString represents the state of the
		Variant.

		Data associated with multiple Variants is stateful, whereas Data
		associated with a single Variant is not stateful. This is referred to
		as the Data's statehood or statefulness.
	*/
	class Data : public QObject
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		Data(QVariant qvariant);
		Data(VariantMap variant_map);
		Data(const Data& d);
		~Data();

		/*!
			Returns value of the Variant associated with the supplied state,
			converted to the template type T.

			Ignore the state parameter when calling this with Data that is not
			stateful.

			@param state - State, if any, associated with Variant
			@returns Value of Variant associated with state, converted to
			template type T
		*/
		template<typename T>
		T as(const QString& state = "") const;

		/*!
			Returns true if state exists in variant map

			@param state - State that might exist in variant map
			@returns True if state exists in variant map, false otherwise
		*/
		bool contains_state(const QString& state) const;

		/*!
			Copies the supplied Data object.

			If the statehood of the data objects is different, then the caller
			is converted to match the statehood of the supplied Data before the
			values are copied.
		*/
		void copy(const Data& data);

		/*!
			Converts to stateful Data initialized with the supplied map.

			@param variant_map - Variant map to initialize the Data with
		*/
		void init_variant_map(const VariantMap& variant_map);

		/*!
			Returns true if the Data is stateful, otherwise, returns false.

			@returns True if stateful, false otherwise
		*/
		bool is_stateful() const;

		/*!
			Set the value of the stored Variant.

			<b>Only works with Data objects that are not stateful!</b>

			@param qvariant - QVariant containing the value being set
			@param retain_type - Whether to protect the value type from change,
			true by default
		*/
		//void set_value(QVariant qvariant);

		/*!
			Set the value of the stored Variant associated with the supplied
			state.

			<b>Only works with Data objects that are stateful!</b>

			@param state - State associated with value
			@param qvariant - QVariant containing the value being set
		*/
		void set_value(QVariant qvariant, const QString& state = "");

		/*!
			Returns a QStringList of the available states.

			If the Data is not stateful, an empty list will be returned.

			@returns QStringList where QStrings represent the states
		*/
		QStringList states() const;

		/*!
			Returns Data represented as a QJsonObject.

			@returns QJsonObject representing the Data
		*/
		QJsonObject to_json_object();

		/*!
			Returns the name of the type stored in the Data.

			If the Data is not stateful, the type name of the single Variant is
			returned.
			
			If it is stateful, then the type name of the Variant associated
			with the first key state of the Variant map is returned.

			@returns Name of type stored within the Data
		*/
		const char* typeName() const;

	private:
		Variant* m_variant{ nullptr };

		VariantMap* m_variant_map{ nullptr };
	};

	template<typename T>
	inline T Data::as(const QString& state) const
	{
		if (state == "")
			return m_variant->value<T>();
		else
			return (*m_variant_map)[state].value<T>();
	}
}

#endif // DATA_H