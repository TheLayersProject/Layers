#ifndef ATTRIBUTETYPE_H
#define ATTRIBUTETYPE_H

#include <QObject>
#include <QWidget>

namespace Layers
{
	/*!
		AttributeType is an abstract type that should be implemented by attributes or
		attribute containers.
	*/
	class AttributeType : public QObject
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		AttributeType(const QString& name, bool disabled);

		/*!
			Returns a capitalized version of the name without underscores

			@returns Capitalized name without underscores
		*/
		QString capitalized_name();

		/*!
			Returns the disabled condition of the AttributeType

			@returns True if disabled, false otherwise
		*/
		bool disabled() const;

		/*!
			Returns true if AttributeType is stateful

			An AttributeType is stateful if its Data, or the Data of the attributes in a container,
			is also stateful. Because there is a difference between the implementations of attributes
			and their containers, this function is declared here as a pure virtual function. This means
			that **classes that implement AttributeType will also need to implement this function**.

			@returns True if stateful, false otherwise
		*/
		virtual bool is_stateful() const = 0;

		/*!
			Returns the name of the AttributeType

			@returns Name of AttributeType
		*/
		QString name();

		/*!
			Sets the AttributeType's disabled condition to the value supplied in the parameter

			@param disabled - Whether to set the AttributeType as disabled, true by default
		*/
		virtual void set_disabled(bool disabled = true);

		/*!
			Sets the state of the AttributeType

			If the AttributeType is a single attribute, then its state should be set. If it is an
			attribute container, then all of the attributes in the container should have their states
			set. Because there is a difference between the implementations of attributes
			and their containers, this function is declared here as a pure virtual function. This means
			that **classes that implement AttributeType will also need to implement this function**.

			@param state - QString representing state being set
		*/
		virtual void set_state(const QString& state) = 0;

		virtual void setup_widget_update_connection(QWidget* widget) = 0;

	protected:
		bool m_disabled{ false };

		QString m_name{ "" };
	};
}

#endif // ATTRIBUTETYPE_H