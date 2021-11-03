#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QVariant>

namespace Layers
{
	/*!
		Pure abstract base class for Layers attributes.

		Implementers of the Attribute class will need to define the value() function since
		this class does not implement the representation of the attribute value(s).

		The functions name(), parent_themeable(), and set_parent_themeable() are defined by
		this class as they are not expected to be different between subclasses.
	*/
	class Attribute : public QObject
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		/*!
			Constructor for the Attribute base class.

			Subclasses are to call this constructor passing along an attribute name string.
		*/
		Attribute(const QString& name, QObject* parent = 0);
		Attribute(const QString& name, QVariant value, QObject* parent = 0);
		Attribute(const QString& name, QMap<QString, QVariant> state_value_map, QObject* parent = 0);

		/*!
			Checks if the provided state already exists in the data structure.

			@param state to check
			@returns True if state exists, false if not
		*/
		bool contains_state(const QString& state) const;

		/*!
			Returns the name of the attribute.

			@returns Name of attribute
		*/
		QString& name();

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

		/*!
			Pure virtual function intended to return the attribute value in the form of a QVariant reference.

			@returns Attribute value reference
		*/
		QVariant& value();

		/*!
			Returns the value paired with the provided state.

			@returns Attribute value of the provided state
		*/
		QVariant* value(const QString& state);

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const Attribute& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_value;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_value;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_name{ "" };

		QString m_state{ "" };

		QVariant m_value{ QVariant() };

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};
}

#endif // ATTRIBUTES_H
