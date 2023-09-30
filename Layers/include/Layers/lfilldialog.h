#ifndef LFILLDIALOG_H
#define LFILLDIALOG_H

#include <QGraphicsOpacityEffect>

#include "layers_global.h"
#include "layers_exports.h"

#include "lcolorcontrol.h"
#include "ldialog.h"
#include "lgradientcontrol.h"
#include "ltoggleswitch.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LFillDialog : public LDialog
{
	Q_OBJECT

public:
	LFillDialog(QWidget* parent = nullptr);

	void set_attribute(LAttribute* attribute);

private:
	void init_attributes();
	void init_layout();

	LToggleSwitch* m_fill_type_toggle{ new LToggleSwitch(true) };

	QGraphicsOpacityEffect* m_color_label_opacity
		{ new QGraphicsOpacityEffect };
	QGraphicsOpacityEffect* m_gradient_label_opacity
		{ new QGraphicsOpacityEffect };

	LLabel* m_color_label{ new LLabel("Color") };
	LLabel* m_gradient_label{ new LLabel("Gradient") };

	LColorControl* m_color_control{ new LColorControl };
	LGradientControl* m_gradient_control{ new LGradientControl };

	QColor m_previous_color{ "#f0f0f0" };
	QGradientStops m_previous_gradient
		{ { 0.0, "#f0f0f0" },{ 1.0, "#0f0f0f" } };
};
LAYERS_NAMESPACE_END

#endif // LFILLDIALOG_H
