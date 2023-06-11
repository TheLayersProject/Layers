#ifndef LRADIOBUTTONPOOL_H
#define LRADIOBUTTONPOOL_H

#include <QList>
#include <QObject>

#include "layerswidgetsexports.h"

namespace Layers
{
	class LRadioButton;

	/*!
		A LRadioButtonPool is a QObject that ensures that within a group of
		LRadioButton widgets, only one is active at a time.
	*/
	class LAYERS_WIDGETS_EXPORT LRadioButtonPool : public QObject
	{
		Q_OBJECT

	public:
		/*!
			Constructs a radio button pool object with a set of
			*radio_buttons*.
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
}

#endif // LRADIOBUTTONPOOL_H
