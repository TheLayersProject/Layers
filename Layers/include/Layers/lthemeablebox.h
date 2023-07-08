#ifndef LTHEMEABLEBOX_H
#define LTHEMEABLEBOX_H

#include <QPainter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LThemeableBox is a LThemeable that defines attributes and painting
	functionality for a box-shaped widget.
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

		LThemeableBox subclasses should call this function from paintEvent().
	*/
	void paint(QWidget* widget);

	LAttribute* m_border_fill{
		new LAttribute("Border.Fill", QColor(Qt::gray)) };

	LAttribute* m_border_thickness{
		new LAttribute("Border.Thickness", 0.0) };

	LAttribute* m_corner_radii_bottom_left{
		new LAttribute("Corner Radii.Bottom Left", 0.0) };

	LAttribute* m_corner_radii_bottom_right{
		new LAttribute("Corner Radii.Bottom Right", 0.0) };

	LAttribute* m_corner_radii_top_left{
		new LAttribute("Corner Radii.Top Left", 0.0) };

	LAttribute* m_corner_radii_top_right{
		new LAttribute("Corner Radii.Top Right", 0.0) };

	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white)) };

	LAttribute* m_margins_bottom{
		new LAttribute("Margins.Bottom", 0.0) };

	LAttribute* m_margins_left{
		new LAttribute("Margins.Left", 0.0) };

	LAttribute* m_margins_right{
		new LAttribute("Margins.Right", 0.0) };

	LAttribute* m_margins_top{
		new LAttribute("Margins.Top", 0.0) };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLEBOX_H
