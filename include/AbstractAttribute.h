#ifndef ABSTRACTATTRIBUTE_H
#define ABSTRACTATTRIBUTE_H

#include <QObject>

namespace Layers
{
	/*!
		An AbstractAttribute is an abstract QObject that represents an
		attribute or a group of attributes.
	*/
	class AbstractAttribute : public QObject
	{
		Q_OBJECT

	signals:
		void value_changed();

	public:
		AbstractAttribute(const QString& name, bool disabled);

		/*!
			Returns a capitalized version of the name without underscores.

			@returns Capitalized name without underscores
		*/
		QString capitalized_name();

		/*!
			Returns the disabled condition.

			@returns True if disabled, false otherwise
		*/
		bool disabled() const;

		/*!
			Returns true if multi-valued.

			@returns True if multi-valued, false otherwise
		*/
		virtual bool is_multi_valued() const = 0;

		/*!
			Returns the name of the attribute

			@returns Name of attribute
		*/
		QString name();

		/*!
			Sets the disabled condition.

			@param disabled - New disabled condition, true by default
		*/
		virtual void set_disabled(bool disabled = true);

		void set_name(const QString& name);

		/*!
			Sets the active state.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) = 0;

	protected:
		bool m_disabled;

		QString m_name;
	};
}

#endif // ABSTRACTATTRIBUTE_H