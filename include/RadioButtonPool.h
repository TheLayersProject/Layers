#ifndef RADIOBUTTONPOOL_H
#define RADIOBUTTONPOOL_H

#include <QList>
#include <QObject>

namespace Layers
{
	class RadioButton;

	class RadioButtonPool : public QObject
	{
		Q_OBJECT

	public:
		RadioButtonPool(QList<RadioButton*> radio_buttons);

	private:
		RadioButton* m_active_radio_button{ nullptr };

		QList<RadioButton*> m_radio_buttons;
	};
}

#endif // RADIOBUTTONPOOL_H
