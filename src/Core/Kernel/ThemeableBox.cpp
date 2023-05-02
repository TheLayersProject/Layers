#include "calculate.h"
#include "ThemeableBox.h"

#include <QEvent>
#include <QPainterPath>
#include <QWidget>

using Layers::Attribute;
using Layers::BorderAttributes;
using Layers::CornerRadiiAttributes;
using Layers::MarginsAttributes;
using Layers::ThemeableBox;

ThemeableBox::~ThemeableBox()
{
	delete m_border;
	delete m_corner_radii;
	delete m_fill;
	delete m_margins;

	m_border = nullptr;
	m_corner_radii = nullptr;
	m_fill = nullptr;
	m_margins = nullptr;
}

void ThemeableBox::init_attributes()
{
	m_attributes.insert({
		{ "border", m_border },
		{ "corner_radii", m_corner_radii },
		{ "fill", m_fill },
		{ "margins", m_margins }
	});

	for (AbstractAttribute* attribute : m_attributes)
		establish_update_connection(attribute);
}

void ThemeableBox::set_margin(double margin)
{
	set_margin(margin, margin, margin, margin);
}

void ThemeableBox::set_margin(double left, double top, double right, double bottom)
{
	m_margins->left()->set_value(left);
	m_margins->top()->set_value(top);
	m_margins->right()->set_value(right);
	m_margins->bottom()->set_value(bottom);
}

void ThemeableBox::paint(QWidget* widget)
{
	// CREATE VARIABLES:

	bool fill_disabled = m_fill->disabled();

	int border_thickness = (!m_border->disabled()) ?
		m_border->thickness()->as<double>() : 0;

	int margin_left = m_margins->left()->as<double>();
	int margin_top = m_margins->top()->as<double>();
	int margin_right = m_margins->right()->as<double>();
	int margin_bottom = m_margins->bottom()->as<double>();

	int widget_width = widget->width();
	int widget_height = widget->height();

	int draw_width = widget_width - margin_left - margin_right;
	int draw_height = widget_height - margin_top - margin_bottom;

	int corner_radius_tl = (!m_corner_radii->disabled()) ?
		m_corner_radii->top_left()->as<double>() : 0;
	int corner_radius_tr = (!m_corner_radii->disabled()) ?
		m_corner_radii->top_right()->as<double>() : 0;
	int corner_radius_bl = (!m_corner_radii->disabled()) ?
		m_corner_radii->bottom_left()->as<double>() : 0;
	int corner_radius_br = (!m_corner_radii->disabled()) ?
		m_corner_radii->bottom_right()->as<double>() : 0;

	if (widget->isMaximized())
	{
		border_thickness = 0;
		corner_radius_tl = 0;
		corner_radius_tr = 0;
		corner_radius_bl = 0;
		corner_radius_br = 0;
	}

	int tl_background_radius = border_thickness ? inner_radius(corner_radius_tl, border_thickness) : corner_radius_tl;
	int tr_background_radius = border_thickness ? inner_radius(corner_radius_tr, border_thickness) : corner_radius_tr;
	int bl_background_radius = border_thickness ? inner_radius(corner_radius_bl, border_thickness) : corner_radius_bl;
	int br_background_radius = border_thickness ? inner_radius(corner_radius_br, border_thickness) : corner_radius_br;

	// CREATE PATHS:

	// - Create Border Path
	QPainterPath border_path;
	border_path.moveTo(margin_left, margin_top + corner_radius_tl);
	border_path.arcTo(QRect(margin_left, margin_top, corner_radius_tl * 2, corner_radius_tl * 2), 180, -90);
	border_path.lineTo(margin_left + draw_width - corner_radius_tr, margin_top);
	border_path.arcTo(QRect(margin_left + draw_width - corner_radius_tr * 2, margin_top, corner_radius_tr * 2, corner_radius_tr * 2), 90, -90);
	border_path.lineTo(margin_left + draw_width, margin_top + draw_height - corner_radius_br);
	border_path.arcTo(QRect(margin_left + draw_width - corner_radius_br * 2, margin_top + draw_height - corner_radius_br * 2, corner_radius_br * 2, corner_radius_br * 2), 0, -90);
	border_path.lineTo(margin_left + corner_radius_bl, margin_top + draw_height);
	border_path.arcTo(QRect(margin_left, margin_top + draw_height - corner_radius_bl * 2, corner_radius_bl * 2, corner_radius_bl * 2), -90, -90);
	border_path.lineTo(margin_left, margin_top + corner_radius_tl);

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

	// - Create Corner Path
	QPainterPath corner_color_path;
	corner_color_path.addRect(0, 0, widget_width, widget_height);
	corner_color_path = corner_color_path - background_path;
	corner_color_path = corner_color_path - border_path;

	// - Create Outline Path
	QPainterPath outline_color_path;
	outline_color_path.addRect(0, 0, widget_width, widget_height);
	outline_color_path = outline_color_path - corner_color_path;

	// DRAW:

	QPainter painter(widget);
	painter.setRenderHint(QPainter::Antialiasing);

	// - Draw Border
	if (border_thickness)
	{
		if (QString(m_border->fill()->typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
			QLinearGradient border_fill_gradient;

			border_fill_gradient.setStart(0, 0);
			border_fill_gradient.setFinalStop(widget_width, 0);
			border_fill_gradient.setStops(m_border->fill()->as<QGradientStops>());

			painter.fillPath(border_path, border_fill_gradient);
		}
		else painter.fillPath(border_path, m_border->fill()->as<QColor>());
	}

	// - Draw Background
	if (!fill_disabled)
	{
		if (QString(m_fill->typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
			QLinearGradient fill_gradient;

			fill_gradient.setStart(0, 0);
			fill_gradient.setFinalStop(widget_width, 0);
			fill_gradient.setStops(m_fill->as<QGradientStops>());

			painter.fillPath(background_path, fill_gradient);
		}
		else
		{
			painter.fillPath(background_path, m_fill->as<QColor>());
		}
	}
}

BorderAttributes* ThemeableBox::border() const
{
	return m_border;
}

CornerRadiiAttributes* ThemeableBox::corner_radii() const
{
	return m_corner_radii;
}

MarginsAttributes* ThemeableBox::margins() const
{
	return m_margins;
}

Attribute* ThemeableBox::fill() const
{
	return m_fill;
}
