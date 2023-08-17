#ifndef LGRADIENTCONTROL_H
#define LGRADIENTCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LGradientControl Example](gradient_control.png)
	
	An LGradientControl is an LWidget that displays a gradient to the user and
	generates an LGradientDialog when clicked, giving the user an interface for
	changing the gradient's value.
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

	~LGradientControl();

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTCONTROL_H
