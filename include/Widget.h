#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ThemeableBox.h"

namespace Layers
{
	/*!
		The Widget class wraps a QWidget with a Themeable to give QWidgets compatibility with the Layers theme
		system. The Layers Widget class overrides the QWidget's paintEvent() and uses the attributes provided
		by the Themeable class to handle the widget's appearance.
	*/
	class Widget : public QWidget, public ThemeableBox
	{
		Q_OBJECT

	public:
		Widget(QWidget* parent = nullptr);

	protected:
		/*!
			Initializes the widget's attributes.

			This function uses calls to set_attribute_value() to define attributes.

			Widget attributes include background color/gradient, corner radii, margins, outline color, and
			other varius numerical values, colors, and booleans.
		*/
		void init_attributes();

		/*!
			Paints the widget with values obtained from the widget's attributes.
		*/
		void paintEvent(QPaintEvent* event) override;
	};
}

#endif // WIDGET_H  
