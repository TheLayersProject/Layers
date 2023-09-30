#ifndef LGRADIENTCONTROL_H
#define LGRADIENTCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGradientControl : public LWidget
{
	Q_OBJECT

signals:
	void gradient_changed();

public:
	LGradientControl(QWidget* parent = nullptr);

	~LGradientControl();

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTCONTROL_H
