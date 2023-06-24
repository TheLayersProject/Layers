#ifndef LRADIOBUTTONPOOL_H
#define LRADIOBUTTONPOOL_H

#include <QList>
#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LRadioButton;

/*!
	An LRadioButtonPool is a QObject that ensures that within a group of
	LRadioButton widgets, only one is active at a time.
*/
class LAYERS_EXPORT LRadioButtonPool : public QObject
{
	Q_OBJECT

public:
	/*!
		Constructs a radio button pool object with a set of *radio_buttons*.
	*/
	LRadioButtonPool(QList<LRadioButton*> radio_buttons);

	/*!
		Sets *button* as the active radio button in the pool.
	*/
	void set_active(LRadioButton* button);

private:
	LRadioButton* m_active_button{ nullptr };

	QList<LRadioButton*> m_radio_buttons;
};
LAYERS_NAMESPACE_END

#endif // LRADIOBUTTONPOOL_H
