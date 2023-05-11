#ifndef VARIANT_H
#define VARIANT_H

#include <QColor>
#include <QGradient>
#include <QJsonValue>
#include <QVariant>

namespace Layers
{
	/*!
		A Variant is a QObject that wraps a QVariant to enable Qt signal/slot
		functionality.

		A variant represents a value. Therefore, the terms *variant* and
		*value* are often used synonymously.

		## Value Change Detection

		The purpose of having a variant type with signal/slot support is to
		enable value change detection. Any time the variant is modified, the
		changed() signal gets emitted. This signal can be connected to execute
		specific functionality whenever value changes occur.

		~~~~~~~~~~~~~{.c}
		// Example of value change detection

		Variant thickness = 10;

		connect(&thickness, &Variant::changed, []
			{ qDebug() << "Thickness changed!"; });

		thickness = 15;

		// The assignment above causes Variant::changed() to emit and
		// 'Thickness changed!' is output to the console.
		~~~~~~~~~~~~~

		Value change detection is used to support critical Layers functionality
		like Attribute entanglement.
	*/
	class Variant : public QObject
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the variant's value changes.
		*/
		void changed();

	public:
		/*!
			Constructs an invalid variant.
		*/
		Variant();

		/*!
			Constructs a variant with a floating point value.
		*/
		Variant(double value);

		/*!
			Constructs a variant with a color value.
		*/
		Variant(const QColor& value);

		/*!
			Constructs a variant with a color value.
		*/
		Variant(const QString& value);

		/*!
			Constructs a variant from a QVariant.
		*/
		Variant(QVariant qvariant);

		/*!
			Constructs a variant from a QJsonValue.

			The value of *json_value* must be one of the following:
			- Bool
			- Double
			- String containing a color name
			- QJsonObject containing a specially-formatted gradient value
		*/
		Variant(QJsonValue json_value);

		/*!
			Constructs a copy of *variant*.
		*/
		Variant(const Variant& variant);

		/*!
			Assigns the value of *variant* to this variant.
		*/
		void operator=(const Variant& variant);

		/*!
			Returns true if the value of this variant does not equal the value
			of *variant*, false otherwise.
		*/
		bool operator!=(const Variant& variant);

		/*!
			Returns a QJsonValue with the same value as this variant.
		*/
		QJsonValue to_json_value();

		/*!
			Returns the name of the type stored in the variant.
		*/
		const char* typeName() const;

		/*!
			Returns the value of this variant converted to the template type T.
		*/
		template<typename T>
		T value() const;

	private:
		QVariant m_qvariant;
	};

	template<typename T>
	inline T Variant::value() const
	{
		return m_qvariant.value<T>();
	}

	using VariantMap = QMap<QString, Variant>;

}

#endif // VARIANT_H