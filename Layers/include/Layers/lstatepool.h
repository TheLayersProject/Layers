#ifndef LSTATEPOOL_H
#define LSTATEPOOL_H

#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LStatePool : public QObject
{
	Q_OBJECT

signals:
	void changed();

public:
	LStatePool(const QString& name);

	LStatePool(const QString& name, QStringList states);

	void add_state(const QString& state);

	void set_state(const QString& state);

	QString state() const;

private:
	QString m_name;

	QString m_state;

	QStringList m_states;
};
LAYERS_NAMESPACE_END

#endif // LSTATEPOOL_H
