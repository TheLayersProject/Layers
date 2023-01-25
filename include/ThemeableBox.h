#ifndef THEMEABLEBOX_H
#define THEMEABLEBOX_H

#include <QPainter>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!

	*/
	class ThemeableBox : public Themeable
	{
	public:
		virtual void apply_theme_attributes(
			QMap<QString, AttributeType*>& theme_attrs) override;

		/*!
			Sets all margin attributes with one value.

			@param margin
		*/
		void set_margin(double margin);

		/*!
			Sets the margin attributes individually.

			@param left margin
			@param top margin
			@param right margin
			@param bottom margin
		*/
		void set_margin(double left, double top, double right, double bottom);

		BorderAttributes border;

		CornerRadiiAttributes corner_radii;

		MarginsAttributes margins;

		Attribute a_corner_color{ Attribute(
			"corner_color",
			QColor(Qt::gray),
			true
			) };

		Attribute a_fill{ Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute a_hover_fill{ Attribute(
			"hover_fill",
			QColor(Qt::lightGray),
			true
			) };

		Attribute a_outline_color{ Attribute(
			"outline_color",
			QColor(Qt::gray),
			true
			) };

	protected:
		/*!
			Overrides the QWidget::eventFilter() to handle widget hover coloring
		*/
		//bool eventFilter(QObject* object, QEvent* event);

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
		void paint(QWidget* widget);

		bool m_hovering{ false };
	};
}

#endif // THEMEABLEBOX_H
