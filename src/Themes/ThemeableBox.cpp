//#include "../../include/AttributeWidgets.h"
//#include "../../include/CustomizePanel.h"
//#include "../../include/Layouts.h"
#include "../../include/calculate.h"
//#include "../../include/Theme.h"
#include "../../include/ThemeableBox.h"

#include <QEvent>
#include <QPainterPath>

using Layers::ThemeableBox;

void ThemeableBox::init_attributes()
{
    m_attributes.insert({
        { "border", &border },
        { "corner_color", &a_corner_color },
        { "corner_radii", &corner_radii },
        { "fill", &a_fill },
        { "hover_fill", &a_hover_fill },
        { "margins", &margins },
        { "outline_color", &a_outline_color },
        });

    m_attribute_layout.append(&a_fill);
    m_attribute_layout.append(&a_hover_fill);
    m_attribute_layout.append(&border);
    m_attribute_layout.append(&corner_radii);
    m_attribute_layout.append(&margins);
    m_attribute_layout.append(&a_corner_color);
    m_attribute_layout.append(&a_outline_color);

    //for (AttributeType* attr_type : m_attributes)
    //    attr_type->setup_widget_update_connection(this);
}

void ThemeableBox::apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs)
{
    border.copy(*dynamic_cast<AttributeGroup*>(theme_attrs["border"]));
    a_corner_color.copy(*dynamic_cast<Attribute*>(theme_attrs["corner_color"]));
    corner_radii.copy(*dynamic_cast<AttributeGroup*>(theme_attrs["corner_radii"]));
    a_fill.copy(*dynamic_cast<Attribute*>(theme_attrs["fill"]));
    a_hover_fill.copy(*dynamic_cast<Attribute*>(theme_attrs["hover_fill"]));
    margins.copy(*dynamic_cast<AttributeGroup*>(theme_attrs["margins"]));
    a_outline_color.copy(*dynamic_cast<Attribute*>(theme_attrs["outline_color"]));
}

void ThemeableBox::set_margin(double margin)
{
    set_margin(margin, margin, margin, margin);
}

void ThemeableBox::set_margin(double left, double top, double right, double bottom)
{
    margins.left.set_value(left);
    margins.top.set_value(top);
    margins.right.set_value(right);
    margins.bottom.set_value(bottom);
}

//bool ThemeableBox::eventFilter(QObject* object, QEvent* event)
//{
//    // TODO: Could make an Attribute for hovering which would also handle updating
//    if (event->type() == QEvent::Enter)
//    {
//        m_hovering = true;
//        //update();
//    }
//    else if (event->type() == QEvent::Leave)
//    {
//        m_hovering = false;
//       //update();
//    }
//
//    return false;
//}

void ThemeableBox::paint(QWidget* widget)
{
    // CREATE VARIABLES:

    bool fill_disabled = a_fill.disabled();

    int border_thickness = (!border.disabled()) ?
        border.thickness.as<double>() : 0;

    int margin_left = margins.left.as<double>();
    int margin_top = margins.top.as<double>();
    int margin_right = margins.right.as<double>();
    int margin_bottom = margins.bottom.as<double>();

    int widget_width = widget->width();
    int widget_height = widget->height();

    int draw_width = widget_width - margin_left - margin_right;
    int draw_height = widget_height - margin_top - margin_bottom;

    int corner_radius_tl = (!corner_radii.disabled()) ?
        corner_radii.top_left.as<double>() : 0;
    int corner_radius_tr = (!corner_radii.disabled()) ?
        corner_radii.top_right.as<double>() : 0;
    int corner_radius_bl = (!corner_radii.disabled()) ?
        corner_radii.bottom_left.as<double>() : 0;
    int corner_radius_br = (!corner_radii.disabled()) ?
        corner_radii.bottom_right.as<double>() : 0;

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

    // - Draw Corner Color
    if (!a_corner_color.disabled())
    {
        painter.fillPath(corner_color_path, a_corner_color.as<QColor>());
    }

    // - Draw Border
    if (border_thickness)
    {
        if (QString(border.fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
        {
            QLinearGradient border_fill_gradient;

            border_fill_gradient.setStart(0, 0);
            border_fill_gradient.setFinalStop(widget_width, 0);
            border_fill_gradient.setStops(border.fill.as<QGradientStops>());

            painter.fillPath(border_path, border_fill_gradient);
        }
        else painter.fillPath(border_path, border.fill.as<QColor>());
    }

    // - Draw Background
    if (!fill_disabled)
    {
        if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
        {
            QLinearGradient fill_gradient;

            fill_gradient.setStart(0, 0);
            fill_gradient.setFinalStop(widget_width, 0);
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
}
