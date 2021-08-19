#include "Layers.h"

using Layers::App_Preferences_Settings_Panel;

App_Preferences_Settings_Panel::App_Preferences_Settings_Panel(QWidget* parent) : Widget(parent)
{
	set_icon(new Graphic_Widget(":/svgs/panel_icon.svg", QSize(20, 20)));
	set_name("app_preferences_settings_panel");
	set_proper_name("App Preferences Panel");

	set_stateless_attribute_value("background_disabled", true);
}

void App_Preferences_Settings_Panel::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
}
