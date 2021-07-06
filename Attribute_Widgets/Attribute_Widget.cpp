#include "../Layers.h"

using Layers::Attribute;
using Layers::Attribute_Widget;

Attribute_Widget::Attribute_Widget(bool is_primary, QWidget* parent) :
	m_is_primary{ is_primary }, Widget(parent)
{
	init_attributes();

	set_name("attribute_widget");
	setFixedHeight(45);
	if (!m_is_primary) hide();
}
Attribute* Attribute_Widget::attribute() const
{
	return m_attribute;
}
QList<QString>& Attribute_Widget::customize_states()
{
	return m_customize_states;
}

void Attribute_Widget::enable_secondary_background_color(bool cond)
{
	set_attribute_value("Default", "using_secondary_background_color", cond);
}

bool Attribute_Widget::is_primary() const
{
	return m_is_primary;
}

void Attribute_Widget::set_customize_states(const QList<QString>& customize_states)
{
	m_customize_states = customize_states;
}

void Attribute_Widget::set_primary(bool is_primary)
{
	if (m_is_primary != is_primary)
	{
		m_is_primary = is_primary;

		if (!m_is_primary) hide();
	}
}

void Attribute_Widget::init_attributes()
{
	set_attribute_value("Default", "background_color", QColor("#b2b2b2"));
	set_attribute_value("Default", "corner_radius_tl", 10);
	set_attribute_value("Default", "corner_radius_tr", 10);
	set_attribute_value("Default", "corner_radius_bl", 10);
	set_attribute_value("Default", "corner_radius_br", 10);

	add_attribute("Default", "secondary_background_color", QColor("#b2b2b2"));
	add_attribute("Default", "using_secondary_background_color", false);
}

void Attribute_Widget::paintEvent(QPaintEvent * event)
{
	// CREATE VARIABLES:

	bool background_disabled = m_attributes["background_disabled"].value().value<bool>();

	int border_thickness = m_attributes["border_thickness"].value().value<int>();

	int margin_left = m_attributes["margin_left"].value().value<int>();
	int margin_top = m_attributes["margin_top"].value().value<int>();
	int margin_right = m_attributes["margin_right"].value().value<int>();
	int margin_bottom = m_attributes["margin_bottom"].value().value<int>();

	int draw_width = width() - margin_left - margin_right;
	int draw_height = height() - margin_top - margin_bottom;

	int corner_radius_tl = m_attributes["corner_radius_tl"].value().value<int>();
	int corner_radius_tr = m_attributes["corner_radius_tr"].value().value<int>();
	int corner_radius_bl = m_attributes["corner_radius_bl"].value().value<int>();
	int corner_radius_br = m_attributes["corner_radius_br"].value().value<int>();

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
	corner_color_path.addRect(0, 0, width(), height());
	corner_color_path = corner_color_path - background_path;
	corner_color_path = corner_color_path - border_path;

	// - Create Outline Path
	QPainterPath outline_color_path;
	outline_color_path.addRect(0, 0, width(), height());
	outline_color_path = outline_color_path - corner_color_path;

	// DRAW:

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// - Draw Corner Color
	if (!m_attributes["corner_color_disabled"].value().value<bool>())
	{
		painter.fillPath(corner_color_path, m_attributes["corner_color"].value().value<QColor>());
	}

	// - Draw Border
	if (border_thickness)
	{
		if (!m_attributes["border_gradient_disabled"].value().value<bool>())
		{
			QLinearGradient gradient;

			gradient.setStart(0, 0);
			gradient.setFinalStop(width(), 0);
			gradient.setStops(m_attributes["border_gradient_stops"].value().value<QGradientStops>());

			painter.fillPath(border_path, gradient);
		}
		else painter.fillPath(border_path, m_attributes["border_color"].value().value<QColor>());
	}

	// - Draw Background
	if (!background_disabled)
	{
		if (m_attributes["background_gradient_disabled"].value().value<bool>())
		{
			if (!m_attributes["background_color_hover_disabled"].value().value<bool>() && m_attributes["using_background_color_hover"].value().value<bool>())
				painter.fillPath(background_path, m_attributes["background_color_hover"].value().value<QColor>());
			else
			{
				if (m_attributes["using_secondary_background_color"].value().value<bool>())
					painter.fillPath(background_path, m_attributes["secondary_background_color"].value().value<QColor>());
				else
					painter.fillPath(background_path, m_attributes["background_color"].value().value<QColor>());
			}
		}
		else
		{
			QLinearGradient bg_gradient;

			bg_gradient.setStart(0, 0);
			bg_gradient.setFinalStop(width(), 0);
			bg_gradient.setStops(m_attributes["background_gradient_stops"].value().value<QGradientStops>());

			painter.fillPath(background_path, bg_gradient);
		}
	}

	// - Draw Outline Color
	if (!m_attributes["outline_color_disabled"].value().value<bool>())
	{
		painter.strokePath(outline_color_path, QPen(m_attributes["outline_color"].value().value<QColor>()));
	}

	painter.end();
}

void Attribute_Widget::update_customizing_state(const QString& customizing_state)
{
}
