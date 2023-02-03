#include "../../../include/Menu.h"

using Layers::Graphic;
using Layers::Menu;

Menu::Menu(const QString& menu_name, Graphic* menu_icon, QWidget* parent) :
	name{ menu_name }, Widget(parent)
{
	m_icon = menu_icon;
}
