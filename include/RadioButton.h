#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "Themeable.h"

#include <QWidget>

namespace Layers
{
	/*!
		A RadioButton is a QWidget and a Themeable that provides the user with
		a button that can be switched on or off. Typically, in a group of radio
		buttons, only one radio button can be active at a time.

		To enforce the idea that only one radio button is active at a time, it
		is recommended to use a RadioButtonPool.
	*/
	class RadioButton : public QWidget, public Themeable
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted whenever the button is pressed.
		*/
		void clicked();

	public:
		/*!
			Constructs a radio button.
		*/
		RadioButton(QWidget* parent = nullptr);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_attributes();

		Attribute* m_active_dot_fill{ new Attribute("active_dot_fill", QColor(Qt::black)) };

		BorderAttributes* m_border{ new BorderAttributes };

		Attribute* m_fill{ new Attribute("fill", {
			{ "Active", QColor(Qt::lightGray) },
			{ "Inactive", QColor(Qt::darkGray) }
			}) };

		Attribute* m_margin{ new Attribute("margin", Variant(10)) };
	};
}

#endif // RADIOBUTTON_H
