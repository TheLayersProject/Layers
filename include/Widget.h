#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ThemeableBox.h"

namespace Layers
{
	/*!
		A Widget is a QWidget and a ThemeableBox that serves as a base class
		for user interface objects.

		The widget is painted by the themeable-box class which contains
		attributes and painting functionality for a box shape.
	*/
	class Widget : public QWidget, public ThemeableBox
	{
		Q_OBJECT

	public:
		/*!
			Constructs a widget.
		*/
		Widget(QWidget* parent = nullptr);

	protected:
		virtual void paintEvent(QPaintEvent* event) override;
	};
}

#endif // WIDGET_H  
