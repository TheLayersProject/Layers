#ifndef LSTATEPOOL_H
#define LSTATEPOOL_H

#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LStatePool is a QObject that manages a set of states.

	States are just strings. States can be added to the pool using add_state()
	and the current pool state can be changed using set_state().
*/
class LAYERS_EXPORT LStatePool : public QObject
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the active state changes.
	*/
	void changed();

public:
	/*!
		Constructs a state pool with a given *name*.
	*/
	LStatePool(const QString& name, QObject* parent = nullptr);

	/*!
		Constructs a state pool with a given *name* and set of *states*.
	*/
	LStatePool(const QString& name, QStringList states,
		QObject* parent = nullptr);

	/*!
		Adds *state* to the pool.
	*/
	void add_state(const QString& state);

	/*!
		Sets *state* as the active pool state.

		The provided state must exist within the pool or the state will not be
		changed.
	*/
	void set_state(const QString& state);

	/*!
		Returns the active pool state.
	*/
	QString state() const;

private:
	QString m_name;

	QString m_state;

	QStringList m_states;
};
LAYERS_NAMESPACE_END

#endif // LSTATEPOOL_H
