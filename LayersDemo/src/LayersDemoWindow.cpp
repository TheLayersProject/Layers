#include "LayersDemoWindow.h"

#include <Layers/lgraphic.h>

#include "LayersDemo.h"

using Layers::LGraphic;

LayersDemoWindow::LayersDemoWindow(QWidget* parent) :
	LMainWindow(parent)
{
	open_central_widget(new LayersDemo,
		LGraphic(":/images/layers.imgseq", QSize(35, 35)));

	setWindowIcon(QIcon(":/images/layers_2d.png"));
}
