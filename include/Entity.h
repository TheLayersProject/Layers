#ifndef ATTRIBUTETYPE_H
#define ATTRIBUTETYPE_H

#include <QObject>
#include <QWidget>

namespace Layers
{
	/*!
		An Entity is a QObject that is a named, disableable, and stateable.

		Named means that an Entity has a name.

		Disableable means that an Entity can be switched between on/off states.

		Stateable means that an Entity can be in different states.
	*/
	class Entity : public QObject
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		Entity(const QString& name, bool disabled);

		/*!
			Returns a capitalized version of the name without underscores.

			@returns Capitalized name without underscores
		*/
		QString capitalized_name();

		/*!
			Returns the disabled condition of the Entity.

			@returns True if disabled, false otherwise
		*/
		bool disabled() const;

		/*!
			Returns true if Entity is stateful.

			@returns True if stateful, false otherwise
		*/
		virtual bool is_stateful() const = 0;

		/*!
			Returns the name of the Entity

			@returns Name of Entity
		*/
		QString name();

		/*!
			Sets the Entity's disabled condition.

			@param disabled - New disabled condition, true by default
		*/
		virtual void set_disabled(bool disabled = true);

		/*!
			Sets the Entity's active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) = 0;

		/*!
			Establishes a connection that calls QWidget::update() when the
			Entity's value_changed() signal gets emitted.

			@param widget - The widget to establish the connection with
		*/
		//virtual void setup_widget_update_connection(QWidget* widget) = 0;

	protected:
		bool m_disabled{ false };

		QString m_name{ "" };
	};
}

#endif // ATTRIBUTETYPE_H