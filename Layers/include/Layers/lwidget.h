#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeablebox.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LWidget : public QWidget, public LThemeableBox
{
	Q_OBJECT

public:
	LWidget(QWidget* parent = nullptr);

protected:
	virtual void paintEvent(QPaintEvent* event) override;
};
LAYERS_NAMESPACE_END

#endif // LWIDGET_H  
