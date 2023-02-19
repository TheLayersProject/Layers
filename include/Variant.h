#ifndef VARIANT_H
#define VARIANT_H

#include <QColor>
#include <QGradient>
#include <QVariant>

namespace Layers
{
	/*!
		A Variant is a QObject that wraps a QVariant to enable Qt signal/slot
		functionality.

		# Value Change Detection

		The purpose of having a variant type with signal/slot support is to
		enable value change detection. Any time the QVariant is modified, the
		changed() signal gets emitted.

		~~~~~~~~~~~~~{.c}
		// Example of value change detection

		Variant thickness = 10;

		connect(&thickness, &Variant::changed, []
			{ qDebug() << "Thickness changed!"; });

		thickness = 15;

		// The assignment above causes Variant::changed() to emit and
		// 'Thickness changed!' is output to the console.
		~~~~~~~~~~~~~

		%Variant value change detection is used to support critical Layers
		functionality like Attribute entanglement.
	*/
	class Variant : public QObject
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		Variant();
		Variant(double d);
		Variant(QColor color);
		Variant(QVariant qvariant);
		Variant(const Variant& variant);

		void operator=(const Variant& variant);
		bool operator!=(const Variant& variant);

		/*!
			Returns the name of the type stored in the variant.

			@returns Type name of value stored in the variant
		*/
		const char* typeName() const;

		/*!
			Returns the stored value converted to the template type T.

			@returns Value converted to the template type T
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