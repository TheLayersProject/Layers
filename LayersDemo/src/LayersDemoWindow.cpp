#include "LayersDemoWindow.h"

#include "LayersDemo.h"

using Layers::LThemeable;

LayersDemoWindow::LayersDemoWindow(QWidget* parent) :
	LMainWindow(parent)
{
	set_central_widget(new LayersDemo);
	setWindowIcon(QIcon(":/images/layers_2d.png"));
}
