#include "Layers.h"

using Layers::Graphic_Widget;
using Layers::Menu;

Menu::Menu(const QString& menu_name, Graphic_Widget* menu_icon, QWidget* parent) :
	name{ menu_name }, icon{ menu_icon }, Widget(parent)
{

}
