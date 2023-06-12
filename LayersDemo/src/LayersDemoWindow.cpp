#include "LayersDemoWindow.h"

#include "LayersDemo.h"

using Layers::LThemeable;

LayersDemoWindow::LayersDemoWindow(bool preview, QWidget* parent) :
	LMainWindow(preview, parent)
{
	set_central_widget(new LayersDemo);
	setWindowIcon(QIcon("layers_2d_logo.png"));
}

LThemeable* LayersDemoWindow::clone()
{
	LayersDemoWindow* w = new LayersDemoWindow(true);

	w->setMinimumSize(500, 400);

	return w;
}
