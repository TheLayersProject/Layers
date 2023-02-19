#include "../../../include/Menu.h"

using Layers::Graphic;
using Layers::Menu;

Menu::Menu(const QString& menu_name, Graphic* menu_icon, QWidget* parent) :
	m_menu_name{ menu_name }, Widget(parent)
{
	m_icon = menu_icon;
}

QString Menu::menu_name()
{
	return m_menu_name;
}
