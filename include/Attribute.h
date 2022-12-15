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

	class AttributeType : public QObject
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		AttributeType(const QString& name, bool disabled);

		QString capitalized_name();

		bool disabled() const;

		QString& name();

		virtual void set_disabled(bool disabled = true);

	protected:
		bool m_disabled{ false };

		QString m_name{ "" };
	};

	/*!
		Provides structure for attributes to be used by Themes and Themeables.

		Attributes store pointers to Variants which store values used for painting Themeables and
		supporting their appearance.

		A Themeable stores a set of Attribute pointers, and a Theme stores a collection of
		Attribute pointer sets for many Themeables.
		
		An Attribute can either point to a single Variant or point to a map of QString-Variant pairs
		where the QStrings are states.
	*/
	class Attribute : public AttributeType
	{
		Q_OBJECT

	signals:
		//void value_changed();
		void variant_changed();

	public:
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, QVariant qvariant, bool disabled = false);
		Attribute(const QString& name, QMap<QString, Variant> state_variant_map, bool disabled = false);
		Attribute(const Attribute& a);
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

		void get_variant_from(Attribute& attribute);

		void init_state_variant_map(const QMap<QString, Variant>& state_variant_map);

		bool is_stateful() const;

		bool owns_variant() const;

		//virtual void set_disabled(bool disabled = true) override;

		void set_state(const QString& state);

		void set_state_variant_map(QMap<QString, Variant>& state_variant_map);

		void set_value(QVariant variant, bool retain_type = true);

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
		bool m_owns_variant{ true };

		QList<QMetaObject::Connection> variant_connections;

		QString m_state{ "" };

		QMap<QString, Variant>* m_state_variant_map{ nullptr };

		Variant* m_variant{ nullptr };
	};

	class AttributeGroup : public AttributeType
	{
		Q_OBJECT

	public:
		AttributeGroup();
		AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes, bool disabled = false);
		AttributeGroup(const AttributeGroup& ag);

		QMap<QString, Attribute*>& attributes();

		void copy_from(const AttributeGroup& ag);

		void get_variant_from(AttributeGroup& attr_group);

		bool is_stateful() const;

		QString name() const;

		//virtual void set_disabled(bool disabled = true) override;

		void set_state(const QString& state);

		QJsonObject to_json_object();

	private:
		QMap<QString, Attribute*> m_attributes;
	};

	class BorderAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		BorderAttributes();

		Attribute fill{ Attribute(
			"fill",
			QColor(Qt::gray)
			) };

		Attribute thickness{ Attribute(
			"thickness",
			QVariant::fromValue(0.0)
			) };
	};

	class CornerRadiiAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		CornerRadiiAttributes();

		Attribute bottom_left{ Attribute(
			"bottom_left",
			QVariant::fromValue(0.0)
			) };

		Attribute bottom_right{ Attribute(
			"bottom_right",
			QVariant::fromValue(0.0)
			) };

		Attribute top_left{ Attribute(
			"top_left",
			QVariant::fromValue(0.0)
			) };

		Attribute top_right{ Attribute(
			"top_right",
			QVariant::fromValue(0.0)
			) };
	};

	class MarginsAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		MarginsAttributes();

		Attribute left{ Attribute(
			"left",
			QVariant::fromValue(0.0)
			) };

		Attribute top{ Attribute(
			"top",
			QVariant::fromValue(0.0)
			) };

		Attribute right{ Attribute(
			"right",
			QVariant::fromValue(0.0)
			) };

		Attribute bottom{ Attribute(
			"bottom",
			QVariant::fromValue(0.0)
			) };
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