#ifndef LFILLDIALOG_H
#define LFILLDIALOG_H

#include <QGraphicsOpacityEffect>

#include "layers_global.h"
#include "layers_exports.h"

#include "lcolorcontrol.h"
#include "lgradientcontrol.h"
#include "llabel.h"
#include "ltoggleswitch.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LFillDialog : public LWidget
{
	Q_OBJECT

public:
	LFillDialog(QWidget* parent = nullptr);

	void set_attribute(LAttribute* attribute);

protected:
	bool eventFilter(QObject* object, QEvent* event);

	void init_attributes();

private:
	void init_layout();

	LColorControl* m_color_control{ new LColorControl };

	LLabel* m_color_label{ new LLabel("Color") };

	QGraphicsOpacityEffect* m_color_label_opacity{ new QGraphicsOpacityEffect };

	LToggleSwitch* m_fill_type_toggle{ new LToggleSwitch(true) };

	LGradientControl* m_gradient_control{ new LGradientControl };

	LLabel* m_gradient_label{ new LLabel("Gradient") };

	QGraphicsOpacityEffect* m_gradient_label_opacity{ new QGraphicsOpacityEffect };
};
LAYERS_NAMESPACE_END

#endif // LFILLDIALOG_H
