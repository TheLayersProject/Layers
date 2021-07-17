#include "Layers.h"

using Layers::Widget;

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	init_attributes();

    installEventFilter(this);
    setFocusPolicy(Qt::ClickFocus);
}

void Widget::init_attributes()
{
    QGradientStops background_gradient_stops = { { 0.0, Qt::white },{ 1.0, Qt::black } };
    QGradientStops border_gradient_stops = { { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } };

    add_attribute("background_color", QColor(Qt::white));
    add_attribute("background_color_hover", QColor(Qt::white));
    add_attribute("background_color_hover_disabled", true);
    add_attribute("background_gradient_stops", QVariant::fromValue(background_gradient_stops));
    add_attribute("background_gradient_disabled", true);
    add_attribute("using_background_color_hover", false);
    add_attribute("background_disabled", false);
    add_attribute("border_gradient_stops", QVariant::fromValue(border_gradient_stops));
    add_attribute("border_gradient_disabled", true);
    add_attribute("border_color", QColor(Qt::black));
    add_attribute("border_thickness", 0);
    add_attribute("corner_radius_tl", 0);
    add_attribute("corner_radius_tr", 0);
    add_attribute("corner_radius_bl", 0);
    add_attribute("corner_radius_br", 0);
    add_attribute("margin_left", 0);
    add_attribute("margin_top", 0);
    add_attribute("margin_right", 0);
    add_attribute("margin_bottom", 0);
    add_attribute("corner_color_disabled", true);
    add_attribute("corner_color", QColor(Qt::black));
    add_attribute("outline_color_disabled", true);
    add_attribute("outline_color", QColor(Qt::black));
}

void Widget::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		Attribute_Widget_Container* border_awc = new Attribute_Widget_Container("Border", true);
		Attribute_Widget_Container* corner_radii_awc = new Attribute_Widget_Container("Corner Radii", true);
		Color_Attribute_Widget* background_caw = new Color_Attribute_Widget("Background", m_attributes["background_color"], m_attributes["background_disabled"], true);
		Color_Attribute_Widget* hover_background_caw = new Color_Attribute_Widget("Hover Background", m_attributes["background_color_hover"], m_attributes["background_color_hover_disabled"], true);
		Color_Attribute_Widget* outline_caw = new Color_Attribute_Widget("Outline", m_attributes["outline_color"], m_attributes["outline_color_disabled"], true);
		Color_Attribute_Widget* corner_color_caw = new Color_Attribute_Widget("Corner Color", m_attributes["corner_color"], m_attributes["corner_color_disabled"], true);
		Color_Attribute_Widget* border_caw = new Color_Attribute_Widget("Color", m_attributes["border_color"], true);
		Gradient_Attribute_Widget* border_gaw = new Gradient_Attribute_Widget("Gradient", m_attributes["border_gradient_stops"], true);
		Number_Attribute_Widget* border_thickness_naw = new Number_Attribute_Widget("Thickness", m_attributes["border_thickness"], new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_tl_naw = new Number_Attribute_Widget("Top-Left", m_attributes["corner_radius_tl"], new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_tr_naw = new Number_Attribute_Widget("Top-Right", m_attributes["corner_radius_tr"], new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_bl_naw = new Number_Attribute_Widget("Bottom-Left", m_attributes["corner_radius_bl"], new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_br_naw = new Number_Attribute_Widget("Bottom-Right", m_attributes["corner_radius_br"], new QIntValidator(0, 30), true);
		Switch_Attribute_Widget* border_color_saw = new Switch_Attribute_Widget(
			"Solid", border_caw,
			"Gradient", border_gaw,
			m_attributes["border_gradient_disabled"], true);

		border_caw->set_centered();
		border_gaw->set_centered();

		border_thickness_naw->set_centered();
		border_thickness_naw->set_unit_label_text("px");
		border_thickness_naw->enable_silder();

		border_awc->add_attribute_widget(border_color_saw);
		border_awc->add_attribute_widget(border_thickness_naw);

		corner_radius_tl_naw->set_centered();
		corner_radius_tl_naw->enable_silder();

		corner_radius_tr_naw->set_centered();
		corner_radius_tr_naw->enable_silder();

		corner_radius_bl_naw->set_centered();
		corner_radius_bl_naw->enable_silder();

		corner_radius_br_naw->set_centered();
		corner_radius_br_naw->enable_silder();

		corner_radii_awc->add_attribute_widget(corner_radius_tl_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_tr_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_bl_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_br_naw);

		m_customize_panel->add_attribute_widget(background_caw);
		m_customize_panel->add_attribute_widget(hover_background_caw);
		m_customize_panel->add_attribute_widget(outline_caw);
		m_customize_panel->add_attribute_widget(corner_color_caw);
		m_customize_panel->add_attribute_widget(border_awc);
		m_customize_panel->add_attribute_widget(corner_radii_awc);

		// Add attribute widget references

		m_attribute_widgets["border_awc"] = border_awc;
		m_attribute_widgets["corner_radii_awc"] = corner_radii_awc;
		m_attribute_widgets["background_caw"] = background_caw;
		m_attribute_widgets["hover_background_caw"] = hover_background_caw;
		m_attribute_widgets["outline_caw"] = outline_caw;
		m_attribute_widgets["corner_color_caw"] = corner_color_caw;
		m_attribute_widgets["border_caw"] = border_caw;
		m_attribute_widgets["border_gaw"] = border_gaw;
		m_attribute_widgets["border_thickness_naw"] = border_thickness_naw;
		m_attribute_widgets["corner_radius_tl_naw"] = corner_radius_tl_naw;
		m_attribute_widgets["corner_radius_tr_naw"] = corner_radius_tr_naw;
		m_attribute_widgets["corner_radius_bl_naw"] = corner_radius_bl_naw;
		m_attribute_widgets["corner_radius_br_naw"] = corner_radius_br_naw;
		m_attribute_widgets["border_color_saw"] = border_color_saw;

		for (const QString& ACW_name : m_attribute_widgets.keys())
			if (m_ACW_pre_init_primary_values.contains(ACW_name))
				m_attribute_widgets[ACW_name]->set_primary(m_ACW_pre_init_primary_values[ACW_name]);

		m_ACW_pre_init_primary_values.clear();

		// TODO: Consider an implicit way to get this done
		m_customize_panel->add_child_themeable_reference(border_color_saw);
		m_customize_panel->add_child_themeable_reference(border_caw);
		m_customize_panel->add_child_themeable_reference(border_gaw);
		m_customize_panel->add_child_themeable_reference(border_thickness_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_tl_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_tr_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_bl_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_br_naw);
	}
}

void Widget::issue_update()
{
    update();
}

void Widget::update_theme_dependencies()
{
    if (layout())
    {
		if (Vertical_Layout* vl = dynamic_cast<Vertical_Layout*>(layout()))
			vl->set_border_margin(m_attributes["border_thickness"].value().value<int>());
        else if (Horizontal_Layout* hl = dynamic_cast<Horizontal_Layout*>(layout()))
            hl->set_border_margin(m_attributes["border_thickness"].value().value<int>());
    }
}

void Widget::set_margin(int margin)
{
    set_margin(margin, margin, margin, margin);
}

void Widget::set_margin(int left, int top, int right, int bottom)
{
    set_attribute_value("margin_left", left);
    set_attribute_value("margin_top", top);
    set_attribute_value("margin_right", right);
    set_attribute_value("margin_bottom", bottom);
}

bool Widget::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::Enter)
    {
        if (!m_attributes["background_color_hover_disabled"].value().value<bool>())
            set_attribute_value(m_state, "using_background_color_hover", true, true);
    }
    else if (event->type() == QEvent::Leave)
    {
        if (!m_attributes["background_color_hover_disabled"].value().value<bool>())
			set_attribute_value(m_state, "using_background_color_hover", false, true);
    }

    return false;
}

void Widget::paintEvent(QPaintEvent* event)
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
				painter.fillPath(background_path, m_attributes["background_color"].value().value<QColor>());
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
