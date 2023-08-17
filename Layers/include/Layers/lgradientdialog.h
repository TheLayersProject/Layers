#ifndef LGRADIENTDIALOG_H
#define LGRADIENTDIALOG_H

#include <QTimer>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lcolorcontrol.h"
#include "ldialog.h"
#include "lgradienteditor.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LGradientDialog Example](gradient_dialog.png)

	An LGradientDialog is an LDialog that provides an interface for changing a
	gradient value.

	The dialog contains an LGradientEditor which lets the user edit the
	gradient.

	Once the desired changes to the gradient have been made, there is an
	LButton labeled 'Apply' which wraps up execution of the dialog when
	clicked.
*/
class LAYERS_EXPORT LGradientDialog : public LDialog
{
	Q_OBJECT

public:
	/*!
		Constructs a gradient dialog initialized with *gradient_stops*.
	*/
	LGradientDialog(QGradientStops gradient_stops, QWidget* parent = nullptr);

	/*!
		Returns the stops of the gradient being edited.
	*/
	QGradientStops gradient_stops() const;

private:
	void init_layout();

	LGradientEditor* m_gradient_editor;

	LButton* m_apply_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Apply") };
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTDIALOG_H
