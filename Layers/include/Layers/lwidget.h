#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeablebox.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LWidget is a QWidget and a LThemeableBox that serves as a base class for user
	interface objects.

	The widget is painted by the themeable-box class which contains attributes and
	painting functionality for a box shape.
*/
class LAYERS_EXPORT LWidget : public QWidget, public LThemeableBox
{
	Q_OBJECT

public:
	/*!
		Constructs a widget.
	*/
	LWidget(QWidget* parent = nullptr);

protected:
	virtual void paintEvent(QPaintEvent* event) override;
};
LAYERS_NAMESPACE_END

#endif // LWIDGET_H  
