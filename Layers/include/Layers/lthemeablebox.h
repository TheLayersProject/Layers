#ifndef LTHEMEABLEBOX_H
#define LTHEMEABLEBOX_H

#include <QPainter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lpaint.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LThemeableBox Example](themeable_box.png)
	
	An LThemeableBox is an LThemeable that defines attributes and painting
	functionality for a box-shaped widget.

	## Painting the Box

	Classes that inherit LThemeableBox (which should also be a type of QWidget)
	should override their paintEvent() functions to call paint(), passing along
	a pointer to themselves. The following is an example from LWidget:

	~~~~~~~~~~~~~{.c}
	void LWidget::paintEvent(QPaintEvent* event)
	{
		paint(this);
	}
	~~~~~~~~~~~~~

	This will draw the box across the width and height of the widget.

	## Box Attributes

	The themeable-box comes with a set of LAttribute objects that are used when
	drawing the	box to give it a certain appearance.

	### Border

	A border is drawn on the box if the *border thickness* attribute is greater
	than **0**. The *border fill* attribute determines what color or gradient
	should be used to fill the border with. These are
	considered *grouped attributes*.

	The border attributes are obtained through border_thickness() and
	border_fill().

	The corners of the border are affected by the box's *corner radii*
	attributes.

	### Corner Radii

	There is an attribute for every corner of the box. These are
	considered *grouped attributes*.

	The corner radii attributes are obtained through corner_radii_top_left(),
	corner_radii_top_right(), corner_radii_bottom_left(), and
	corner_radii_bottom_right().

	### Fill

	There is a *fill* attribute that determines what color or gradient should
	be used to fill the inside of the box with.

	### Margins

	There are four margin attributes, one for each side of the box. They
	can be changed to shorten the draw dimensions. These are
	considered *grouped attributes*.

	The margins attributes are obtained through margin_left(), margin_top(),
	margin_right(), and margin_bottom().

	See also: set_margin()
*/
class LAYERS_EXPORT LThemeableBox : public LThemeable
{
public:
	/*!
		Returns a pointer to the border fill attribute of this themeable.
	*/
	LAttribute* border_fill() const;

	/*!
		Returns a pointer to the border thickness attribute of this themeable.
	*/
	LAttribute* border_thickness() const;

	/*!
		Returns a box-shaped QPainterPath with the given *box_rect*
		and *corner_radii*.
	*/
	static QPainterPath box_path(
		const QRect& box_rect, const LCornerRadii& corner_radii);

	/*!
		Returns a pointer to the bottom-left corner radii attribute of this
		themeable.
	*/
	LAttribute* corner_radii_bottom_left() const;

	/*!
		Returns a pointer to the bottom-right corner radii attribute of this
		themeable.
	*/
	LAttribute* corner_radii_bottom_right() const;

	/*!
		Returns a pointer to the top-left corner radii attribute of this
		themeable.
	*/
	LAttribute* corner_radii_top_left() const;

	/*!
		Returns a pointer to the top-right corner radii attribute of this
		themeable.
	*/
	LAttribute* corner_radii_top_right() const;

	/*!
		Returns a pointer to the fill attribute of this themeable.
	*/
	LAttribute* fill() const;

	/*!
		Returns a pointer to the bottom margin attribute of this themeable.
	*/
	LAttribute* margins_bottom() const;

	/*!
		Returns a pointer to the left margin attribute of this themeable.
	*/
	LAttribute* margins_left() const;

	/*!
		Returns a pointer to the right margin attribute of this themeable.
	*/
	LAttribute* margins_right() const;

	/*!
		Returns a pointer to the top margin attribute of this themeable.
	*/
	LAttribute* margins_top() const;

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

		LThemeableBox subclasses need to call this function manually.
	*/
	void init_attributes();

	/*!
		Paints *widget* using the attributes of this LThemeableBox.

		LThemeableBox subclasses should call this function from overriden
		paintEvent() functions.
	*/
	void paint(QWidget* widget);

	LAttribute* m_border_fill
		{ new LAttribute("Border.Fill", QColor(Qt::gray)) };

	LAttribute* m_border_thickness
		{ new LAttribute("Border.Thickness", 0.0) };

	LAttribute* m_corner_radii_bottom_left
		{ new LAttribute("Corner Radii.Bottom Left", 0.0) };

	LAttribute* m_corner_radii_bottom_right
		{ new LAttribute("Corner Radii.Bottom Right", 0.0) };

	LAttribute* m_corner_radii_top_left
		{ new LAttribute("Corner Radii.Top Left", 0.0) };

	LAttribute* m_corner_radii_top_right
		{ new LAttribute("Corner Radii.Top Right", 0.0) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor(Qt::white)) };

	LAttribute* m_margins_bottom
		{ new LAttribute("Margins.Bottom", 0.0) };

	LAttribute* m_margins_left
		{ new LAttribute("Margins.Left", 0.0) };

	LAttribute* m_margins_right
		{ new LAttribute("Margins.Right", 0.0) };

	LAttribute* m_margins_top
		{ new LAttribute("Margins.Top", 0.0) };
};

LAYERS_NAMESPACE_END

#endif // LTHEMEABLEBOX_H
