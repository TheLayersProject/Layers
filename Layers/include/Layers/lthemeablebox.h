#ifndef LTHEMEABLEBOX_H
#define LTHEMEABLEBOX_H

#include <QPainter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"
#include "lpaint.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeableBox : public LThemeable
{
public:
	LAttribute* border_fill() const;

	LAttribute* border_thickness() const;

	static QPainterPath box_path(
		const QRect& box_rect, const LCornerRadii& corner_radii);

	LAttribute* corner_radii_bottom_left() const;

	LAttribute* corner_radii_bottom_right() const;

	LAttribute* corner_radii_top_left() const;

	LAttribute* corner_radii_top_right() const;

	LAttribute* fill() const;

	LAttribute* margins_bottom() const;

	LAttribute* margins_left() const;

	LAttribute* margins_right() const;

	LAttribute* margins_top() const;

	void set_margin(double margin);

	void set_margin(double left, double top, double right, double bottom);

protected:
	void init_attributes();

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
