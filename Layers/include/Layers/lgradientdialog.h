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
class LAYERS_EXPORT LGradientDialog : public LDialog
{
	Q_OBJECT

public:
	LGradientDialog(QGradientStops gradient_stops, QWidget* parent = nullptr);

	QGradientStops gradient_stops() const;

private:
	void init_layout();

	LGradientEditor* m_gradient_editor;

	LButton* m_apply_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Apply") };
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTDIALOG_H
