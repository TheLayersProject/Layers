#ifndef LGRADIENTCONTROL_H
#define LGRADIENTCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LGradientControl is a LWidget that gives the user a way to access the
	LGradientDialog. When the user clicks on the control, the application's
	LGradientDialog is displayed.
*/
class LAYERS_EXPORT LGradientControl : public LWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted if the associated gradient attribute changes.
	*/
	void gradient_changed();

public:
	/*!
		Constructs a gradient control.
	*/
	LGradientControl(QWidget* parent = nullptr);

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTCONTROL_H
