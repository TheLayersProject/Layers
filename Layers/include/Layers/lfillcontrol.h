#ifndef LFILLCONTROL_H
#define LFILLCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LFillDialog;

/*!
	An LFillControl is a LWidget that gives the user a way to access the
	LFillDialog. When the user clicks on the control, a LFillDialog is
	displayed.
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
		Sets the attribute to link with the control.
	*/
	void set_attribute(LAttribute* attribute);

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();

	LFillDialog* m_control_dialog;

	LFillDialog* m_dialog;
};
LAYERS_NAMESPACE_END

#endif // LFILLCONTROL_H
