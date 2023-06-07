#ifndef RADIOBUTTONPOOL_H
#define RADIOBUTTONPOOL_H

#include <QList>
#include <QObject>

namespace Layers
{
	class RadioButton;

	/*!
		A RadioButtonPool is a QObject that ensures that within a group of
		RadioButton widgets, only one is active at a time.
	*/
	class RadioButtonPool : public QObject
	{
		Q_OBJECT

	public:
		/*!
			Constructs a radio button pool object with a set of
			*radio_buttons*.
		*/
		RadioButtonPool(QList<RadioButton*> radio_buttons);

		/*!
			Sets *button* as the active radio button in the pool.
		*/
		void set_active(RadioButton* button);

	private:
		RadioButton* m_active_button{ nullptr };

		QList<RadioButton*> m_radio_buttons;
	};
}

#endif // RADIOBUTTONPOOL_H
