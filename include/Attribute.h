#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QColor>
#include <QGradient>
#include <QJsonObject>
#include <QVariant>

namespace Layers
{
	/*!
		Provides a variant type with signal/slot support

		The Variant class is designed by wrapping a QVariant and subclassing QObject to
		enable Qt signal/slot functionality.
		
		The purpose of having a variant type that can work with Qt's signal/slot system is
		to enable simple value change detection. Any time the value of a Variant's wrapped
		QVariant is modified, the changed() signal gets emitted.

		Variants are to be used by Layers Attributes. Attributes will store pointers to Variants.
		When
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

		friend QDataStream& operator <<(QDataStream& stream, const Variant& v)
		{
			stream << v.m_qvariant;

			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Variant& v)
		{
			stream >> v.m_qvariant;

			return stream;
		}

	private:
		QVariant m_qvariant;
	};

	struct AttributeLayoutItem : public QObject {};

	/*!
		Provides structure for attributes to be used by Themes and Themeables.

		Attributes store pointers to Variants which store values used for painting Themeables and
		supporting their appearance.

		A Themeable stores a set of Attribute pointers, and a Theme stores a collection of
		Attribute pointer sets for many Themeables.
		
		An Attribute can either point to a single Variant or point to a map of QString-Variant pairs
		where the QStrings are states.
	*/
	class Attribute : public AttributeLayoutItem
	{
		Q_OBJECT

	signals:
		void value_changed();
		void variant_changed();

	public:
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, QVariant qvariant, bool disabled = false);
		Attribute(const QString& name, QMap<QString, Variant> state_variant_map, bool disabled = false);
		~Attribute();

		/*!
			Returns the value stored in the Attribute's variant converted to the template type T.

			If the Attribute is stateful, then this function will return the value associated with the
			current state. If the value associated with a specific state is desired, use the version
			of as() that requires a state argument.

			@returns Variant value converted to template type T
		*/
		template<typename T>
		T as() const;

		/*!
			Returns the value of the variant associated with the supplied state, converted to the template type T.

			This function will only work if the Attribute is stateful and only if the state supplied exists
			in the state-variant map.

			@returns Value of variant associated with state, converted to template type T
		*/
		template<typename T>
		T as(const QString& state) const;

		void clear_variant_if_owner();

		/*!
			Returns true if the given state exists in the state-variant map; otherwise returns false.

			@param state to check whether it exists in the state-variant map
			@returns True if state exists in map, false otherwise
		*/
		bool contains_state(const QString& state) const;

		/*!
			Copies the variant condition from another Attribute.

			@param attr to copy 
		*/
		void copy_value_from(const Attribute& attr);

		bool disabled() const;

		void get_variant_from(Attribute& attribute);

		void init_state_variant_map(const QMap<QString, Variant>& state_variant_map);

		bool is_stateful() const;

		QString& name();

		void set_disabled(bool disabled = true);

		void set_state(const QString& state);

		void set_state_variant_map(QMap<QString, Variant>& state_variant_map);

		void set_value(QVariant variant);

		void set_value(const QString& state, QVariant variant);

		void set_variant(Variant& variant);

		QString state() const;

		QList<QString> states() const;

		const char* typeName() const;

		QJsonObject to_json_object();

		Variant* variant() const;

		friend QDataStream& operator <<(QDataStream& stream, const Attribute& a)
		{
			stream << a.m_disabled;
			stream << a.m_name;
			stream << a.m_state;

			if (a.m_variant)
			{
				stream << false;
				stream << *a.m_variant;
			}
			else if (a.m_state_variant_map)
			{
				stream << true;
				stream << *a.m_state_variant_map;
			}

			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute& a)
		{
			stream >> a.m_disabled;
			stream >> a.m_name;
			stream >> a.m_state;

			bool is_stateful = false;

			stream >> is_stateful;

			if (!is_stateful)
			{
				a.m_variant = new Variant;

				stream >> *a.m_variant;
			}
			else
			{
				a.m_state_variant_map = new QMap<QString, Variant>;

				stream >> *a.m_state_variant_map;
			}

			return stream;
		}

	private:
		bool m_disabled{ false };

		bool m_owns_variant{ true };

		QList<QMetaObject::Connection> variant_connections;

		QString m_name{ "" };

		QString m_state{ "" };

		QMap<QString, Variant>* m_state_variant_map{ nullptr };

		Variant* m_variant{ nullptr };
	};

	class AttributeGroup : public AttributeLayoutItem
	{
	public:
		AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes);

		QMap<QString, Attribute*>& attributes();

		bool is_stateful() const;

		QString name() const;

	private:
		QMap<QString, Attribute*> m_attributes;

		QString m_name;
	};

	template<typename T>
	inline T Attribute::as() const
	{
		if (m_variant) return m_variant->value<T>();
		else
		{
			return (*m_state_variant_map)[m_state].value<T>();
		}
	}

	template<typename T>
	inline T Attribute::as(const QString& state) const
	{
		if (m_state_variant_map)
		{
			if (m_state_variant_map->contains(state)) return (*m_state_variant_map)[state].value<T>();
			else
				qDebug() << "WARNING: Failed to obtain attribute value: State does not exist.";
		}
		else
			qDebug() << "WARNING: Failed to obtain attribute value: State provided but Attribute is not stateful.";
	}

	template<typename T>
	inline T Variant::value() const
	{
		return m_qvariant.value<T>();
	}
}

#endif // ATTRIBUTE_H