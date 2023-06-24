#ifndef LRADIOBUTTON_H
#define LRADIOBUTTON_H

#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LRadioButton is a QWidget and a LThemeable that provides the user with a
	button that can be switched on or off. Typically, in a group of radio
	buttons, only one radio button can be active at a time.

	To enforce the idea that only one radio button is active at a time, it is
	recommended to use an LRadioButtonPool.
*/
class LAYERS_EXPORT LRadioButton : public QWidget, public LThemeable
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
	LRadioButton(QWidget* parent = nullptr);

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void paintEvent(QPaintEvent* event) override;

private:
	void init_attributes();

	LAttribute* m_active_dot_fill{ new LAttribute("active_dot_fill", QColor(Qt::black)) };

	LBorderAttributes* m_border{ new LBorderAttributes };

	LAttribute* m_fill{ new LAttribute("fill", {
		{ "Active", QColor(Qt::lightGray) },
		{ "Inactive", QColor(Qt::darkGray) }
		}) };

	LAttribute* m_margin{ new LAttribute("margin", LVariant(10)) };
};
LAYERS_NAMESPACE_END

#endif // LRADIOBUTTON_H
