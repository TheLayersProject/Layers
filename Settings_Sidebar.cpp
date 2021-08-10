#include "Layers.h"

using Layers::Settings_Sidebar;

Settings_Sidebar::Settings_Sidebar(QWidget* parent) : Widget(parent)
{
	setFixedWidth(245);
	setMouseTracking(true);
	set_icon(new Graphic_Widget(":/svgs/sidebar_icon.svg", QSize(20, 20)));
	set_name("sidebar");
	set_proper_name("Sidebar");
	set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
}

void Settings_Sidebar::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_awc"]->set_primary(false);
}
