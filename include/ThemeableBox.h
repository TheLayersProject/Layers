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

		Attribute* fill() const;

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

		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		MarginsAttributes* m_margins{ new MarginsAttributes };

		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::white)
			) };
	};
}

#endif // THEMEABLEBOX_H
