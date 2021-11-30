#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QVariant>

namespace Layers
{
	struct AttributeLayoutItem : public QObject {};

	/*!
		Pure abstract base class for Layers attributes.

		Implementers of the Attribute class will need to define the value() function since
		this class does not implement the representation of the attribute value(s).

		The functions name(), parent_themeable(), and set_parent_themeable() are defined by
		this class as they are not expected to be different between subclasses.
	*/
	class Attribute : public AttributeLayoutItem
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		/*!
			Constructor for the Attribute base class.

			Subclasses are to call this constructor passing along an attribute name string.
		*/
		Attribute(const QString& name, bool disabled = false);
		Attribute(const QString& name, QVariant value, bool disabled = false);
		Attribute(const QString& name, QMap<QString, QVariant> state_value_map, bool disabled = false);
		~Attribute();

		/*!
			Checks if the provided state already exists in the data structure.

			@param state to check
			@returns True if state exists, false if not
		*/
		bool contains_state(const QString& state) const;

		void copy_values_from(const Attribute& attr);

		bool disabled() const;

		/*!
			Returns the name of the attribute.

			@returns Name of attribute
		*/
		QString& name();

		void get_values_from(Attribute& replacement_attr);

		void set_disabled(bool disabled = true);

		/*!
			Sets the current state of the attribute.

			@param state to mark as the current attribute state
		*/
		void set_state(const QString& state);

		/*!
			Sets the value.

			@param value to set
		*/
		void set_value(QVariant value);

		/*!
			Sets the value of the provided state.

			This function only works if the provided state already exists in the data structure.

			@param state to update value of
			@param value pair with state
		*/
		void set_value(const QString& state, QVariant value);

		void set_values(const QMap<QString, QVariant>& values);

		/*!
			Returns the current state of the attribute.

			@returns Current state of attribute
		*/
		QString state() const;

		/*!
			Returns list of all the attribute's states.

			@returns List of attribute's states
		*/
		QList<QString> states() const;

		const char* typeName() const;

		template<typename T>
		T value() const;

		template<typename T>
		T* value(const QString& state) const;

		QMap<QString, QVariant>* values();

		friend QDataStream& operator <<(QDataStream& stream, const Attribute& a)
		{
			stream << *a.m_disabled;
			stream << a.m_name;
			stream << a.m_state;

			if (a.m_value)
			{
				stream << false;
				stream << *a.m_value;
			}
			else if (a.m_values)
			{
				stream << true;
				stream << *a.m_values;
			}

			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute& a)
		{
			stream >> *a.m_disabled;
			stream >> a.m_name;
			stream >> a.m_state;

			bool is_stateful = false;

			stream >> is_stateful;

			if (!is_stateful)
			{
				a.m_value = new QVariant;

				stream >> *a.m_value;
			}
			else
			{
				a.m_values = new QMap<QString, QVariant>;

				stream >> *a.m_values;
			}

			return stream;
		}

	private:
		Attribute* m_overriding_attr{ nullptr };

		bool* m_disabled{ new bool(false) };

		QString m_name{ "" };

		QString m_state{ "" };

		QMetaObject::Connection m_override_update_connection;

		QVariant* m_value{ nullptr };

		QMap<QString, QVariant>* m_values{ nullptr };
	};

	template<typename T>
	inline T Attribute::value() const
	{
		if (m_value) return m_value->value<T>();
		else
		{
			return (*m_values)[m_state].value<T>();
		}
	}

	template<typename T>
	inline T* Attribute::value(const QString& state) const
	{
		if (m_values)
		{
			if (m_values->contains(state)) return &(*m_values)[state].value<T>();
			else
				qDebug() << "WARNING: Failed to obtain attribute value: State does not exist.";
		}
		else
			qDebug() << "WARNING: Failed to obtain attribute value: State provided but Attribute is not stateful.";

		return nullptr;
	}

	class AttributeGroup : public AttributeLayoutItem
	{
	public:
		AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes);

		QMap<QString, Attribute*>& attributes();

		QString name() const;

	private:
		QMap<QString, Attribute*> m_attributes;

		QString m_name;
	};
}

#endif // ATTRIBUTE_H
