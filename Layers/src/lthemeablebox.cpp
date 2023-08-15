#include <Layers/lthemeablebox.h>

#include <QEvent>
#include <QPainterPath>
#include <QWidget>

#include <Layers/lcalculate.h>

using Layers::LAttribute;
using Layers::LThemeableBox;

LAttribute* LThemeableBox::border_fill() const
{
	return m_border_fill;
}

LAttribute* LThemeableBox::border_thickness() const
{
	return m_border_thickness;
}

LAttribute* LThemeableBox::corner_radii_bottom_left() const
{
	return m_corner_radii_bottom_left;
}

LAttribute* LThemeableBox::corner_radii_bottom_right() const
{
	return m_corner_radii_bottom_right;
}

LAttribute* LThemeableBox::corner_radii_top_left() const
{
	return m_corner_radii_top_left;
}

LAttribute* LThemeableBox::corner_radii_top_right() const
{
	return m_corner_radii_top_right;
}

LAttribute* LThemeableBox::fill() const
{
	return m_fill;
}

LAttribute* LThemeableBox::margins_bottom() const
{
	return m_margins_bottom;
}

LAttribute* LThemeableBox::margins_left() const
{
	return m_margins_left;
}

LAttribute* LThemeableBox::margins_right() const
{
	return m_margins_right;
}

LAttribute* LThemeableBox::margins_top() const
{
	return m_margins_top;
}

void LThemeableBox::set_margin(double margin)
{
	set_margin(margin, margin, margin, margin);
}

void LThemeableBox::set_margin(
	double left, double top, double right, double bottom)
{
	m_margins_left->set_value(left);
	m_margins_top->set_value(top);
	m_margins_right->set_value(right);
	m_margins_bottom->set_value(bottom);
}

void LThemeableBox::init_attributes()
{
	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		m_border_fill->setParent(object);
		m_border_thickness->setParent(object);
		m_corner_radii_bottom_left->setParent(object);
		m_corner_radii_bottom_right->setParent(object);
		m_corner_radii_top_left->setParent(object);
		m_corner_radii_top_right->setParent(object);
		m_fill->setParent(object);
		m_margins_bottom->setParent(object);
		m_margins_left->setParent(object);
		m_margins_right->setParent(object);
		m_margins_top->setParent(object);
	}
}

void LThemeableBox::paint(QWidget* widget)
{
	// CREATE VARIABLES:

	// The active states of the themeable
	QStringList s = states();

	int border_thickness = m_border_thickness->as<double>(s);

	int margin_left = m_margins_left->as<double>(s);
	int margin_top = m_margins_top->as<double>(s);
	int margin_right = m_margins_right->as<double>(s);
	int margin_bottom = m_margins_bottom->as<double>(s);

	int widget_width = widget->width();
	int widget_height = widget->height();

	int draw_width = widget_width - margin_left - margin_right;
	int draw_height = widget_height - margin_top - margin_bottom;

	/*	NOTE:
		cr = corner radius
		tl = top-left
	*/

	int cr_tl = m_corner_radii_top_left->as<double>(s);
	int cr_tr = m_corner_radii_top_right->as<double>(s);
	int cr_bl = m_corner_radii_bottom_left->as<double>(s);
	int cr_br = m_corner_radii_bottom_right->as<double>(s);

	if (widget->isMaximized())
	{
		border_thickness = 0;
		cr_tl = 0;
		cr_tr = 0;
		cr_bl = 0;
		cr_br = 0;
	}

	int tl_background_radius = (border_thickness) ?
		inner_radius(cr_tl, border_thickness) : cr_tl;
	int tr_background_radius = (border_thickness) ?
		inner_radius(cr_tr, border_thickness) : cr_tr;
	int bl_background_radius = (border_thickness) ?
		inner_radius(cr_bl, border_thickness) : cr_bl;
	int br_background_radius = (border_thickness) ?
		inner_radius(cr_br, border_thickness) : cr_br;

	// CREATE PATHS:

	// - Create Border Path
	QPainterPath border_path;
	border_path.moveTo(margin_left, margin_top + cr_tl);
	border_path.arcTo(QRect(margin_left, margin_top, cr_tl * 2, cr_tl * 2), 180, -90);
	border_path.lineTo(margin_left + draw_width - cr_tr, margin_top);
	border_path.arcTo(QRect(margin_left + draw_width - cr_tr * 2, margin_top, cr_tr * 2, cr_tr * 2), 90, -90);
	border_path.lineTo(margin_left + draw_width, margin_top + draw_height - cr_br);
	border_path.arcTo(QRect(margin_left + draw_width - cr_br * 2, margin_top + draw_height - cr_br * 2, cr_br * 2, cr_br * 2), 0, -90);
	border_path.lineTo(margin_left + cr_bl, margin_top + draw_height);
	border_path.arcTo(QRect(margin_left, margin_top + draw_height - cr_bl * 2, cr_bl * 2, cr_bl * 2), -90, -90);
	border_path.lineTo(margin_left, margin_top + cr_tl);

	// - Create Background Path
	QPainterPath background_path;
	background_path.moveTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);
	background_path.arcTo(QRect(margin_left + border_thickness, margin_top + border_thickness, tl_background_radius * 2, tl_background_radius * 2), 180, -90);
	background_path.lineTo(margin_left + draw_width - tr_background_radius - border_thickness, margin_top + border_thickness);
	background_path.arcTo(QRect(margin_left + draw_width - tr_background_radius * 2 - border_thickness, margin_top + border_thickness, tr_background_radius * 2, tr_background_radius * 2), 90, -90);
	background_path.lineTo(margin_left + draw_width - border_thickness, margin_top + draw_height - br_background_radius - border_thickness);
	background_path.arcTo(QRect(margin_left + draw_width - br_background_radius * 2 - border_thickness, margin_top + draw_height - br_background_radius * 2 - border_thickness, br_background_radius * 2, br_background_radius * 2), 0, -90);
	background_path.lineTo(margin_left + border_thickness + bl_background_radius, margin_top + draw_height - border_thickness);
	background_path.arcTo(QRect(margin_left + border_thickness, margin_top + draw_height - bl_background_radius * 2 - border_thickness, bl_background_radius * 2, bl_background_radius * 2), -90, -90);
	background_path.lineTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);

	border_path = border_path - background_path;

	// DRAW:

	QPainter painter(widget);
	painter.setRenderHint(QPainter::Antialiasing);

	// - Draw Border
	if (border_thickness)
	{
		if (m_border_fill->typeName(s) == "QList<std::pair<double,QColor>>")
		{
			QLinearGradient border_fill_gradient;

			border_fill_gradient.setStart(0, 0);
			border_fill_gradient.setFinalStop(widget_width, 0);
			border_fill_gradient.setStops(m_border_fill->as<QGradientStops>(s));

			painter.fillPath(border_path, border_fill_gradient);
		}
		else painter.fillPath(border_path, m_border_fill->as<QColor>(s));
	}

	// - Draw Background
	if (m_fill->typeName(s) == "QList<std::pair<double,QColor>>")
	{
		QLinearGradient fill_gradient;

		fill_gradient.setStart(0, 0);
		fill_gradient.setFinalStop(widget_width, 0);
		fill_gradient.setStops(m_fill->as<QGradientStops>(s));

		painter.fillPath(background_path, fill_gradient);
	}
	else
	{
		painter.fillPath(background_path, m_fill->as<QColor>(s));
	}
}
