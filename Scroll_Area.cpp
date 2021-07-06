#include "Layers.h"

using Layers::Scroll_Area;

Scroll_Area::Scroll_Area(QWidget* parent) : QScrollArea(parent)
{
	setWidgetResizable(true);
	setStyleSheet("background:transparent; border:none;");
}
