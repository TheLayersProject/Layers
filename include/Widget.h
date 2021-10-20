#ifndef WIDGET_H
#define WIDGET_H

#include <QPainter>
#include <QWidget>

#include "Themeable.h"

namespace Layers
{
	/*!
		The Widget class wraps a QWidget with a Themeable to give QWidgets compatibility with the Layers theme
		system. The Layers Widget class overrides the QWidget's paintEvent() and uses the attributes provided
		by the Themeable class to handle the widget's appearance.
	*/
	class Widget : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		Widget(QWidget* parent = nullptr);

		/*!
			Sets all margin attributes with one value.

			@param margin
		*/
		void set_margin(int margin);

		/*!
			Sets the margin attributes individually.

			@param left margin
			@param top margin
			@param right margin
			@param bottom margin
		*/
		void set_margin(int left, int top, int right, int bottom);

		/*!
			Updates anything that can't be changed with attributes.

			As a Widget, this function updates the border margins of the layout if the layout happens to be
			a Layers::Horizontal_Layout or Layers::VerticalLayout.
		*/
		void update_theme_dependencies();

	protected:
		/*!
			Overrides the QWidget::eventFilter() to handle widget hover coloring
		*/
		bool eventFilter(QObject* object, QEvent* event) override;

		/*!
			Initializes the widget's attributes.

			This function uses calls to set_attribute_value() to define attributes.

			Widget attributes include background color/gradient, corner radii, margins, outline color, and
			other varius numerical values, colors, and booleans.
		*/
		void init_attributes();

		void init_attribute_widgets();

		/*!
			Calls the QWidget's update() function
		*/
		void issue_update();

		/*!
			Paints the widget with values obtained from the widget's attributes.
		*/
		void paintEvent(QPaintEvent* event) override;

		QPainter painter;
	};
}

#endif // WIDGET_H  
