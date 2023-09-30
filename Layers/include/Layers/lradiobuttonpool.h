#ifndef LRADIOBUTTONPOOL_H
#define LRADIOBUTTONPOOL_H

#include <QList>
#include <QObject>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LRadioButton;

class LAYERS_EXPORT LRadioButtonPool : public QObject
{
	Q_OBJECT

public:
	LRadioButtonPool(QList<LRadioButton*> radio_buttons);

	void set_active(LRadioButton* button);

private:
	LRadioButton* m_active_button{ nullptr };

	QList<LRadioButton*> m_radio_buttons;
};
LAYERS_NAMESPACE_END

#endif // LRADIOBUTTONPOOL_H
