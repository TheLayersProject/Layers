#ifndef THEMEABLEBOX_H
#define THEMEABLEBOX_H

#include <QPainter>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A ThemeableBox is a Themeable that defines attributes and painting
		functionality for a box-shaped widget.
	*/
	class ThemeableBox : public Themeable
	{
	public:
		~ThemeableBox();

		/*!
			Returns a pointer to the border attributes of this themeable.
		*/
		BorderAttributes* border() const;

		/*!
			Returns a pointer to the corner radii attributes of this themeable.
		*/
		CornerRadiiAttributes* corner_radii() const;

		/*!
			Returns a pointer to the margin attributes of this themeable.
		*/
		MarginsAttributes* margins() const;

		/*!
			Returns a pointer to the fill attribute of this themeable.
		*/
		Attribute* fill() const;

		/*!
			Sets all margin attributes with one value.
		*/
		void set_margin(double margin);

		/*!
			Sets the margin attributes individually.
		*/
		void set_margin(double left, double top, double right, double bottom);

	protected:
		/*!
			Initializes the attributes.

			ThemeableBox subclasses need to call this function manually.
		*/
		void init_attributes();

		/*!
			Paints *widget* using the attributes of this ThemeableBox.
		*/
		void paint(QWidget* widget);

		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		MarginsAttributes* m_margins{ new MarginsAttributes };

		Attribute* m_fill{ new Attribute("fill", QColor(Qt::white)) };
	};
}

#endif // THEMEABLEBOX_H
