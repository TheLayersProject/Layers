#include "../../../../include/AttributeWidgets.h"
#include "../../../../include/SettingsMenu.h"

using Layers::SettingsSidebar;

SettingsSidebar::SettingsSidebar(QWidget* parent) : Widget(parent)
{
	setFixedWidth(245);
	setMouseTracking(true);
	set_icon(new Graphic(":/svgs/sidebar_icon.svg", QSize(20, 20)));
	set_name("sidebar");
	set_proper_name("Sidebar");
	a_fill.set_value(QColor(Qt::lightGray));
}
