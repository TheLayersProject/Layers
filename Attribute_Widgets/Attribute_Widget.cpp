#include "../Layers.h"

using Layers::Attribute;
using Layers::Attribute_Widget;
using Layers::Stateful_Attribute;
using Layers::Stateless_Attribute;

Attribute_Widget::Attribute_Widget(bool is_primary, QWidget* parent) :
	m_is_primary{ is_primary }, Widget(parent)
{
	init_attributes();

	set_name("attribute_widget");
	setFixedHeight(45);
	if (!m_is_primary) hide();
}

QList<QString>& Attribute_Widget::customize_states()
{
	return m_customize_states;
}

void Attribute_Widget::enable_secondary_background_color(bool cond)
{
	set_stateless_attribute_value("using_secondary_background_color", cond);
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

Stateful_Attribute* Attribute_Widget::stateful_attribute() const
{
	return m_stateful_attribute;
}

Stateless_Attribute* Attribute_Widget::stateless_attribute() const
{
	return m_stateless_attribute;
}

void Attribute_Widget::init_attributes()
{
	set_stateless_attribute_value("background_color", QColor("#b2b2b2"));
	set_stateless_attribute_value("corner_radius_tl", 10);
	set_stateless_attribute_value("corner_radius_tr", 10);
	set_stateless_attribute_value("corner_radius_bl", 10);
	set_stateless_attribute_value("corner_radius_br", 10);

	add_stateless_attribute("secondary_background_color", QColor("#b2b2b2"));
	add_stateless_attribute("using_secondary_background_color", false);
}

void Attribute_Widget::paintEvent(QPaintEvent * event)
{
	// CREATE VARIABLES:

	bool background_disabled = m_attribute_set.attribute_value("background_disabled")->value<bool>();

	int border_thickness = m_attribute_set.attribute_value("border_thickness")->value<int>();

	int margin_left = m_attribute_set.attribute_value("margin_left")->value<int>();
	int margin_top = m_attribute_set.attribute_value("margin_top")->value<int>();
	int margin_right = m_attribute_set.attribute_value("margin_right")->value<int>();
	int margin_bottom = m_attribute_set.attribute_value("margin_bottom")->value<int>();

	int draw_width = width() - margin_left - margin_right;
	int draw_height = height() - margin_top - margin_bottom;

	int corner_radius_tl = m_attribute_set.attribute_value("corner_radius_tl")->value<int>();
	int corner_radius_tr = m_attribute_set.attribute_value("corner_radius_tr")->value<int>();
	int corner_radius_bl = m_attribute_set.attribute_value("corner_radius_bl")->value<int>();
	int corner_radius_br = m_attribute_set.attribute_value("corner_radius_br")->value<int>();

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
	if (!m_attribute_set.attribute_value("corner_color_disabled")->value<bool>())
	{
		painter.fillPath(corner_color_path, m_attribute_set.attribute_value("corner_color")->value<QColor>());
	}

	// - Draw Border
	if (border_thickness)
	{
		if (!m_attribute_set.attribute_value("border_gradient_disabled")->value<bool>())
		{
			QLinearGradient gradient;

			gradient.setStart(0, 0);
			gradient.setFinalStop(width(), 0);
			gradient.setStops(m_attribute_set.attribute_value("border_gradient_stops")->value<QGradientStops>());

			painter.fillPath(border_path, gradient);
		}
		else painter.fillPath(border_path, m_attribute_set.attribute_value("border_color")->value<QColor>());
	}

	// - Draw Background
	if (!background_disabled)
	{
		if (m_attribute_set.attribute_value("background_gradient_disabled")->value<bool>())
		{
			if (!m_attribute_set.attribute_value("background_color_hover_disabled")->value<bool>() && m_attribute_set.attribute_value("using_background_color_hover")->value<bool>())
				painter.fillPath(background_path, m_attribute_set.attribute_value("background_color_hover")->value<QColor>());
			else
			{
				if (m_attribute_set.attribute_value("using_secondary_background_color")->value<bool>())
					painter.fillPath(background_path, m_attribute_set.attribute_value("secondary_background_color")->value<QColor>());
				else
					painter.fillPath(background_path, m_attribute_set.attribute_value("background_color")->value<QColor>());
			}
		}
		else
		{
			QLinearGradient bg_gradient;

			bg_gradient.setStart(0, 0);
			bg_gradient.setFinalStop(width(), 0);
			bg_gradient.setStops(m_attribute_set.attribute_value("background_gradient_stops")->value<QGradientStops>());

			painter.fillPath(background_path, bg_gradient);
		}
	}

	// - Draw Outline Color
	if (!m_attribute_set.attribute_value("outline_color_disabled")->value<bool>())
	{
		painter.strokePath(outline_color_path, QPen(m_attribute_set.attribute_value("outline_color")->value<QColor>()));
	}

	painter.end();
}

void Attribute_Widget::store_attribute_pointer(Attribute* attribute)
{
	m_stateful_attribute = dynamic_cast<Stateful_Attribute*>(attribute);
	m_stateless_attribute = dynamic_cast<Stateless_Attribute*>(attribute);
}

void Attribute_Widget::update_customizing_state(const QString& customizing_state)
{
}
