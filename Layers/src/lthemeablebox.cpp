#include <Layers/lthemeablebox.h>

#include <QEvent>
#include <QPainterPath>
#include <QWidget>

#include <Layers/lcalculate.h>

using Layers::LAttribute;
using Layers::LBorderAttributes;
using Layers::LCornerRadiiAttributes;
using Layers::LMarginsAttributes;
using Layers::LThemeableBox;

LThemeableBox::~LThemeableBox()
{
	delete m_border;
	delete m_corner_radii;
	delete m_fill;
	delete m_margins;
}

void LThemeableBox::init_attributes()
{
	// Handle groups
	m_attr_data.attr_groups.insert({
		{ "border", m_border },
		{ "corner_radii", m_corner_radii },
		{ "margins", m_margins }
	});

	for (LAttributeGroup* attr_group : m_attr_data.attr_groups)
		for (LAttribute* group_attr : (*attr_group))
			establish_update_connection(group_attr);

	// Handle ungrouped
	m_attr_data.ungrouped_attrs.insert({
		{ "fill", m_fill }
	});

	for (LAttribute* attr : m_attr_data.ungrouped_attrs)
		establish_update_connection(attr);
}

void LThemeableBox::set_margin(double margin)
{
	set_margin(margin, margin, margin, margin);
}

void LThemeableBox::set_margin(
	double left, double top, double right, double bottom)
{
	m_margins->left()->set_value(left);
	m_margins->top()->set_value(top);
	m_margins->right()->set_value(right);
	m_margins->bottom()->set_value(bottom);
}

void LThemeableBox::paint(QWidget* widget)
{
	// CREATE VARIABLES:

	// The active states of the themeable
	QStringList s = states();

	int border_thickness = m_border->thickness()->as<double>(s);

	int margin_left = m_margins->left()->as<double>(s);
	int margin_top = m_margins->top()->as<double>(s);
	int margin_right = m_margins->right()->as<double>(s);
	int margin_bottom = m_margins->bottom()->as<double>(s);

	int widget_width = widget->width();
	int widget_height = widget->height();

	int draw_width = widget_width - margin_left - margin_right;
	int draw_height = widget_height - margin_top - margin_bottom;

	/*	NOTE:
		cr = corner radius
		tl = top-left
	*/

	int cr_tl = m_corner_radii->top_left()->as<double>(s);
	int cr_tr = m_corner_radii->top_right()->as<double>(s);
	int cr_bl = m_corner_radii->bottom_left()->as<double>(s);
	int cr_br = m_corner_radii->bottom_right()->as<double>(s);

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
		if (QString(m_border->fill()->typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
			QLinearGradient border_fill_gradient;

			border_fill_gradient.setStart(0, 0);
			border_fill_gradient.setFinalStop(widget_width, 0);
			border_fill_gradient.setStops(m_border->fill()->as<QGradientStops>(s));

			painter.fillPath(border_path, border_fill_gradient);
		}
		else painter.fillPath(border_path, m_border->fill()->as<QColor>(s));
	}

	// - Draw Background
	if (QString(m_fill->typeName()) == QString("QList<std::pair<double,QColor>>"))
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

LBorderAttributes* LThemeableBox::border() const
{
	return m_border;
}

LCornerRadiiAttributes* LThemeableBox::corner_radii() const
{
	return m_corner_radii;
}

LMarginsAttributes* LThemeableBox::margins() const
{
	return m_margins;
}

LAttribute* LThemeableBox::fill() const
{
	return m_fill;
}
