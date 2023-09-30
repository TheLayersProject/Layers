#ifndef LFILLCONTROL_H
#define LFILLCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LFillDialog;

class LAYERS_EXPORT LFillControl : public LWidget
{
	Q_OBJECT

public:
	LFillControl(QWidget* parent = nullptr);

	~LFillControl();

	void set_attribute(LAttribute* attribute);

protected:
	bool eventFilter(QObject* object, QEvent* event);

private:
	void init_attributes();
};
LAYERS_NAMESPACE_END

#endif // LFILLCONTROL_H
