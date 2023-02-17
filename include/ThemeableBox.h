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
		~ThemeableBox();

		BorderAttributes* border() const;

		CornerRadiiAttributes* corner_radii() const;

		MarginsAttributes* margins() const;

		Attribute* corner_color() const;

		Attribute* fill() const;

		Attribute* hover_fill() const;

		Attribute* outline_color() const;

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

		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		MarginsAttributes* m_margins{ new MarginsAttributes };

		Attribute* m_corner_color{ new Attribute(
			"corner_color",
			QColor(Qt::gray),
			true
			) };

		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute* m_hover_fill{ new Attribute(
			"hover_fill",
			QColor(Qt::lightGray),
			true
			) };

		Attribute* m_outline_color{ new Attribute(
			"outline_color",
			QColor(Qt::gray),
			true
			) };
	};
}

#endif // THEMEABLEBOX_H
