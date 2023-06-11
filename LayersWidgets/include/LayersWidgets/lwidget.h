#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>

#include "layerswidgetsexports.h"

#include <LayersCore/lthemeablebox.h>

namespace Layers
{
	/*!
		A LWidget is a QWidget and a LThemeableBox that serves as a base class
		for user interface objects.

		The widget is painted by the themeable-box class which contains
		attributes and painting functionality for a box shape.
	*/
	class LAYERS_WIDGETS_EXPORT LWidget : public QWidget, public LThemeableBox
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
}

#endif // LWIDGET_H  
