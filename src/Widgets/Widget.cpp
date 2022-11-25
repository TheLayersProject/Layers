#include "../../include/AttributeWidgets.h"
#include "../../include/CustomizePanel.h"
#include "../../include/Layouts.h"
#include "../../include/calculate.h"
#include "../../include/Theme.h"
#include "../../include/Widget.h"

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::Widget;

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	init_attributes();

    installEventFilter(this);
    setFocusPolicy(Qt::ClickFocus);

    connect(&a_border_thickness, &Attribute::value_changed, [this] {
        if (layout())
        {
            if (VerticalLayout* vl = dynamic_cast<VerticalLayout*>(layout()))
                vl->set_border_margin(a_border_thickness.as<double>());
            else if (HorizontalLayout* hl = dynamic_cast<HorizontalLayout*>(layout()))
                hl->set_border_margin(a_border_thickness.as<double>());
        }
        });
}

void Widget::init_attributes()
{
    m_attributes.insert({
        { "border_fill", &a_border_fill },
        { "border_thickness", &a_border_thickness },
        { "corner_color", &a_corner_color },
        { "corner_radius_tl", &a_corner_radius_tl },
        { "corner_radius_tr", &a_corner_radius_tr },
        { "corner_radius_bl", &a_corner_radius_bl },
        { "corner_radius_br", &a_corner_radius_br },
        { "fill", &a_fill },
        { "hover_fill", &a_hover_fill },
        { "margin_left", &a_margin_left },
        { "margin_top", &a_margin_top },
        { "margin_right", &a_margin_right },
        { "margin_bottom", &a_margin_bottom },
        { "outline_color", &a_outline_color },
    });

    m_attribute_layout.append(&a_fill);
    m_attribute_layout.append(&a_hover_fill);
    m_attribute_layout.append(&ag_border);
    m_attribute_layout.append(&ag_corner_radii);
    m_attribute_layout.append(&ag_margins);
    m_attribute_layout.append(&a_corner_color);
    m_attribute_layout.append(&a_outline_color);

    connect(&a_border_thickness, &Attribute::value_changed, [this] { update(); });
    connect(&a_corner_color, &Attribute::value_changed, [this] { update(); });
    connect(&a_corner_radius_tl, &Attribute::value_changed, [this] { update(); });
    connect(&a_corner_radius_tr, &Attribute::value_changed, [this] { update(); });
    connect(&a_corner_radius_bl, &Attribute::value_changed, [this] { update(); });
    connect(&a_corner_radius_br, &Attribute::value_changed, [this] { update(); });
    connect(&a_fill, &Attribute::value_changed, [this] { update(); });
    connect(&a_hover_fill, &Attribute::value_changed, [this] { update(); });
    connect(&a_margin_left, &Attribute::value_changed, [this] { update(); });
    connect(&a_margin_top, &Attribute::value_changed, [this] { update(); });
    connect(&a_margin_right, &Attribute::value_changed, [this] { update(); });
    connect(&a_margin_bottom, &Attribute::value_changed, [this] { update(); });
    connect(&a_outline_color, &Attribute::value_changed, [this] { update(); });
}

void Widget::apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs)
{
    a_border_fill.copy_value_from(*theme_attrs["border_fill"]);
    a_border_thickness.copy_value_from(*theme_attrs["border_thickness"]);
    a_corner_color.copy_value_from(*theme_attrs["corner_color"]);
    a_corner_radius_tl.copy_value_from(*theme_attrs["corner_radius_tl"]);
    a_corner_radius_tr.copy_value_from(*theme_attrs["corner_radius_tr"]);
    a_corner_radius_bl.copy_value_from(*theme_attrs["corner_radius_bl"]);
    a_corner_radius_br.copy_value_from(*theme_attrs["corner_radius_br"]);
    a_fill.copy_value_from(*theme_attrs["fill"]);
    a_hover_fill.copy_value_from(*theme_attrs["hover_fill"]);
    a_margin_left.copy_value_from(*theme_attrs["margin_left"]);
    a_margin_top.copy_value_from(*theme_attrs["margin_top"]);
    a_margin_right.copy_value_from(*theme_attrs["margin_right"]);
    a_margin_bottom.copy_value_from(*theme_attrs["margin_bottom"]);
    a_outline_color.copy_value_from(*theme_attrs["outline_color"]);
}

void Widget::set_margin(double margin)
{
    set_margin(margin, margin, margin, margin);
}

void Widget::set_margin(double left, double top, double right, double bottom)
{
    a_margin_left.set_value(left);
    a_margin_top.set_value(top);
    a_margin_right.set_value(right);
    a_margin_bottom.set_value(bottom);
}

bool Widget::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::Enter)
    {
        m_hovering = true;
        update();
    }
    else if (event->type() == QEvent::Leave)
    {
        m_hovering = false;
        update();
    }

    return false;
}

void Widget::paintEvent(QPaintEvent* event)
{
    // CREATE VARIABLES:

    bool fill_disabled = a_fill.disabled();
    
    int border_thickness = a_border_thickness.as<double>();
    
    int margin_left = a_margin_left.as<double>();
    int margin_top = a_margin_top.as<double>();
    int margin_right = a_margin_right.as<double>();
    int margin_bottom = a_margin_bottom.as<double>();
    
    int draw_width = width() - margin_left - margin_right;
    int draw_height = height() - margin_top - margin_bottom;
    
    int corner_radius_tl = a_corner_radius_tl.as<double>();
    int corner_radius_tr = a_corner_radius_tr.as<double>();
    int corner_radius_bl = a_corner_radius_bl.as<double>();
    int corner_radius_br = a_corner_radius_br.as<double>();
    
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
	if (!a_corner_color.disabled())
	{
		painter.fillPath(corner_color_path, a_corner_color.as<QColor>());
	}

    // - Draw Border
    if (border_thickness)
    {
        if (QString(a_border_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
        {
            QLinearGradient border_fill_gradient;

            border_fill_gradient.setStart(0, 0);
            border_fill_gradient.setFinalStop(width(), 0);
            border_fill_gradient.setStops(a_border_fill.as<QGradientStops>());

            painter.fillPath(border_path, border_fill_gradient);
        }
        else painter.fillPath(border_path, a_border_fill.as<QColor>());
    }

    // - Draw Background
    if (!fill_disabled)
    {
		if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
            QLinearGradient fill_gradient;

            fill_gradient.setStart(0, 0);
            fill_gradient.setFinalStop(width(), 0);
            fill_gradient.setStops(a_fill.as<QGradientStops>());

            painter.fillPath(background_path, fill_gradient);
		}
		else
		{
            if (m_hovering && !a_hover_fill.disabled())
                painter.fillPath(background_path, a_hover_fill.as<QColor>());
            else
                painter.fillPath(background_path, a_fill.as<QColor>());
		}
    }

	// - Draw Outline Color
	if (!a_outline_color.disabled())
	{
		painter.strokePath(outline_color_path, QPen(a_outline_color.as<QColor>()));
	}

    painter.end();
}
