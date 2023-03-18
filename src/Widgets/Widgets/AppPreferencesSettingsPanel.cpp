#include "AttributeWidgets.h"
#include "SettingsPanels.h"

using Layers::AppPreferencesSettingsPanel;

AppPreferencesSettingsPanel::AppPreferencesSettingsPanel(QWidget* parent) : Widget(parent)
{
	set_icon(new Graphic(":/svgs/panel_icon.svg", QSize(20, 20)));
	set_name("app_preferences_settings_panel");
	set_proper_name("App Preferences Panel");

	m_fill->set_disabled();
}
