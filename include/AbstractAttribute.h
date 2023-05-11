#ifndef ABSTRACTATTRIBUTE_H
#define ABSTRACTATTRIBUTE_H

#include <QObject>

namespace Layers
{
	/*!
		An abstract QObject that represents an attribute or a group of
		attributes.
	*/
	class AbstractAttribute : public QObject
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when value changes occur.

			It is also emitted when the disabled status changes or when the
			active state is changed.
		*/
		void changed();

	public:
		/*!
			Constructs an abstract attribute with a name and disabled value.
		*/
		AbstractAttribute(const QString& name, bool disabled);

		/*!
			Returns a capitalized version of the name without underscores.
		*/
		QString capitalized_name();

		/*!
			Returns the disabled condition.
		*/
		bool disabled() const;

		/*!
			Returns true if multi-valued.
		*/
		virtual bool is_multi_valued() const = 0;

		/*!
			Returns the name of the attribute
		*/
		QString name();

		/*!
			Sets the disabled condition.
		*/
		virtual void set_disabled(bool disabled = true);

		/*!
			Sets the active state.
		*/
		virtual void set_state(const QString& state) = 0;

	protected:
		bool m_disabled;

		QString m_name;
	};
}

#endif // ABSTRACTATTRIBUTE_H