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

		/*!
			Returns the name of the attribute.

			@returns Name of attribute
		*/
		QString& name();

		/*!
			Pure virtual function intended to return the attribute value in the form of a QVariant reference.

			@returns Attribute value reference
		*/
		virtual QVariant& value() = 0;

	protected:
		QString m_name{ "" };
	};

	/*!
		Provides structure for storing attribute values.

		The Attribute class provides the data structure used by Themes and Themeables to store
		attribute values and attribute metadata, like the attribute's name.

		An attribute value can be of any type supported by the QVariant class.

		Attributes can either store a single value or multiple values associated with different
		states. Attributes that are not associated with states and only store a single value store
		that value as a QVariant. Stateful attributes store their values in a QMap associating
		QStrings with QVariants, the states and values.

		Since the class representation uses two different mechanisms for storing values,
		users of the Attribute class will need to use two different sets of functions depending on
		whether or not the attribute is stateful.
	*/
	class StatelessAttribute : public Attribute
	{
		Q_OBJECT

	public:
		StatelessAttribute();
		StatelessAttribute(const QString& name, QVariant value);

		/*!
			Sets the value.

			@param value to set
		*/
		void set_value(QVariant value, bool block_emit = false);

		/*!
			Returns the value of the attribute

			@returns Attribute's value
		*/
		QVariant& value();

		friend QDataStream& operator <<(QDataStream& stream, const StatelessAttribute& a)
		{
			stream << a.m_name;
			stream << a.m_value;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, StatelessAttribute& a)
		{
			stream >> a.m_name;
			stream >> a.m_value;
			return stream;
		}

	private:
		QVariant m_value{ QVariant() };
	};

	class StatefulAttribute : public Attribute
	{
		Q_OBJECT

	public:
		StatefulAttribute();
		StatefulAttribute(const QString& name, QMap<QString, QVariant> state_value_map);

		/*!
			Checks if the provided state already exists in the data structure.

			@param state to check
			@returns True if state exists, false if not
		*/
		bool contains_state(const QString& state) const;

		/*!
			Sets the current state of the attribute.

			@param state to mark as the current attribute state
		*/
		void set_state(const QString& state);

		/*!
			Sets the value of the provided state.

			This function only works if the provided state already exists in the data structure.

			@param state to update value of
			@param value pair with state
		*/
		void set_value(const QString& state, QVariant value, bool block_emit = false);

		void set_values(const QMap<QString, QVariant>& values, bool block_emit = false);

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
			Returns the value paired with the provided state.

			@returns Attribute value of the provided state
		*/
		QVariant* value(const QString& state);

		/*!
			Returns the value paired with the current state.

			@returns Attribute value of the current state
		*/
		QVariant& value();

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const StatefulAttribute& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, StatefulAttribute& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};
}

#endif // ATTRIBUTES_H
