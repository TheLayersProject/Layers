#ifndef DATA_H
#define DATA_H

#include <QJsonObject>

#include "Variant.h"

namespace Layers
{
	/*!
		A Data object is a QObject that implements a specialized Variant
		container.

		%Data can be either single-valued or multi-valued. This is referred to
		as the data's *plurality*.
		
		This is accomplished by storing a pointer to either a single variant or
		a variant map where QStrings represent variant states. States are
		required for multi-valued data in order to distinguish between the
		different values.

		~~~~~~~~~~~~~{.c}
		// Example of single-valued and multi-valued data

		Data thickness = Data(10);

		Data fill = Data({
			{ "Selected", QColor(Qt::lightGray) },
			{ "Unselected", QColor(Qt::darkGray) }
		});

		// thickness is single-valued data
		// fill is multi-valued data
		~~~~~~~~~~~~~

		%Data is synonymous with its value(s). Therefore, it is the
		responsibility of the *user* of data to label it, give it a purpose,
		and in the case of multi-valued data, define which state is active.
		%Data, by itself, does none of those things.

		# Value Change Detection

		A data object sets up connections that emit Data::changed() any time
		Variant::changed() is emitted from any of the associated variants. This
		works as a sort of signal repeater so that other objects associated
		with the data object can enable value change detection.

		~~~~~~~~~~~~~{.c}
		// Example of value change detection

		Data thickness = Data(10);

		connect(&thickness, &Data::changed, []
			{ qDebug() << "Thickness changed!"; });

		thickness.set_value(15);

		// The assignment above causes Data::changed() to emit and
		// 'Thickness changed!' is output to the console.
		~~~~~~~~~~~~~

		Value change detection is used to support critical Layers functionality
		like Attribute entanglement.
	*/
	class Data : public QObject
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		Data(Variant variant);
		Data(VariantMap variant_map);
		Data(const Data& d);
		~Data();

		/*!
			Returns data's value converted to the template type T.

			The state parameter is ignored if the caller is not multi-valued.

			@param state - State, if any, associated with value
			@returns Value, converted to template type T
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
			Copies the valuation of the supplied data object.

			If the caller's plurality does not match the plurality of the
			supplied data, then the caller is converted before copying takes
			place.
		*/
		void copy(const Data& data);

		/*!
			Converts to multi-valued data initialized with the supplied map.

			@param variant_map - Variant map to initialize the data with
		*/
		void init_variant_map(const VariantMap& variant_map);

		/*!
			Returns true if the data is multi-valued, otherwise, returns false.

			@returns True if multi-valued, false otherwise
		*/
		bool is_multi_valued() const;

		/*!
			Sets the data's value.

			For single-valued data, the *state* parameter is ignored.

			For multi-valued data, the *state* parameter is highly recommended.
			If the default argument is used with multi-valued data, then this
			function sets the value of the first variant in the map, which may
			be an undesirable result. It is likely in the interest of the
			caller to supply an explicit state argument when multi-valued data
			is involved.

			@param variant - Variant containing the value being set
			@param state - State associated with value, if any
		*/
		void set_value(Variant variant, const QString& state = "");

		/*!
			Returns a QStringList of the states associated with the data's
			values.

			If the data is single-valued, an empty list will be returned.

			@returns QStringList where QStrings represent the states
		*/
		QStringList states() const;

		/*!
			Returns data represented as a QJsonObject.

			@returns QJsonObject representation of the data
		*/
		QJsonObject to_json_object();

		/*!
			Returns the name of the type stored in the data.

			If the data is single-valued, then the type name of that value is
			returned.
			
			If the data is multi-valued, then the type name of the first
			variant in the map is returned.

			@returns Name of type stored within the data
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