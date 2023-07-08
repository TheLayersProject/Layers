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

	LStatePool* status_states() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void paintEvent(QPaintEvent* event) override;

private:
	void init_attributes();

	LAttribute* m_active_dot_fill{
		new LAttribute("active_dot_fill", QColor(Qt::black), this) };

	LAttribute* m_border_fill{
		new LAttribute("border.fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness{
		new LAttribute("border.thickness", 3.0, this) };

	LAttribute* m_fill{ new LAttribute("fill", QColor(Qt::darkGray), this) };

	LAttribute* m_margin{ new LAttribute("margin", QVariant(10.0), this) };

	//LStatePool* m_select_states{
	//	new LStatePool("Select", { "Selected", "Unselected" }) };

	LStatePool* m_status_states{
		new LStatePool("Status", { "Active", "Inactive" }) };
};
LAYERS_NAMESPACE_END

#endif // LRADIOBUTTON_H