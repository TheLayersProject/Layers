#ifndef VARIANT_H
#define VARIANT_H

#include <QColor>
#include <QGradient>
#include <QVariant>

namespace Layers
{
	/*!
		Variant type with signal/slot support

		The Variant class is a QObject that wraps a QVariant to enable Qt
		signal/slot functionality.

		The purpose of having a variant type with signal/slot support is to
		enable value change detection. Any time the QVariant is modified, the
		changed() signal gets emitted.
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
		void operator=(const QVariant& qvariant);
		bool operator!=(const QVariant& qvariant);

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