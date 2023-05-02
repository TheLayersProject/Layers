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
			Paints the widget with values obtained from the widget's attributes.
		*/
		virtual void paintEvent(QPaintEvent* event) override;
	};
}

#endif // WIDGET_H  
