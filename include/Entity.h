#ifndef ATTRIBUTETYPE_H
#define ATTRIBUTETYPE_H

#include <QObject>

namespace Layers
{
	/*!
		An Entity is an abstract QObject that represents a nameable,
		disableable, and stateable type.

		Nameable means that an entity can be named. Disableable means they can
		be switched on/off. Stateable means they can be in different states.
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
		virtual bool is_multi_valued() const = 0;

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

		void set_name(const QString& name);

		/*!
			Sets the Entity's active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) = 0;

	protected:
		bool m_disabled;

		QString m_name;
	};
}

#endif // ATTRIBUTETYPE_H