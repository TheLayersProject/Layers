#ifndef LFILLCONTROL_H
#define LFILLCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LFillDialog;

/*!
	![LFillControl Example](fill_control.png)
	
	An LFillControl is an LWidget that displays a fill to the user and
	generates an LFillDialog when clicked, giving the user an interface for
	changing the fill's value. 

	A **fill** is an attribute type that represents either a *color* or
	a *gradient* value.
*/
class LAYERS_EXPORT LFillControl : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a fill control.
	*/
	LFillControl(QWidget* parent = nullptr);

	~LFillControl();

	/*!
		Links the control with *attribute*.
	*/
	void set_attribute(LAttribute* attribute);

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();
};
LAYERS_NAMESPACE_END

#endif // LFILLCONTROL_H
