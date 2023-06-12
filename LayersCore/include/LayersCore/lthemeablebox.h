#ifndef LTHEMEABLEBOX_H
#define LTHEMEABLEBOX_H

#include <QPainter>

#include "layers_global.h"
#include "layerscore_exports.h"

#include "lattribute.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LThemeableBox is a LThemeable that defines attributes and painting
	functionality for a box-shaped widget.
*/
class LAYERS_CORE_EXPORT LThemeableBox : public LThemeable
{
public:
	~LThemeableBox();

	/*!
		Returns a pointer to the border attributes of this themeable.
	*/
	LBorderAttributes* border() const;

	/*!
		Returns a pointer to the corner radii attributes of this themeable.
	*/
	LCornerRadiiAttributes* corner_radii() const;

	/*!
		Returns a pointer to the margin attributes of this themeable.
	*/
	LMarginsAttributes* margins() const;

	/*!
		Returns a pointer to the fill attribute of this themeable.
	*/
	LAttribute* fill() const;

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
	*/
	void paint(QWidget* widget);

	LBorderAttributes* m_border{ new LBorderAttributes };

	LCornerRadiiAttributes* m_corner_radii{ new LCornerRadiiAttributes };

	LMarginsAttributes* m_margins{ new LMarginsAttributes };

	LAttribute* m_fill{ new LAttribute("fill", QColor(Qt::white)) };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLEBOX_H
