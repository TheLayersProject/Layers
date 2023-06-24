#include "LayersDemo.h"

#include <Layers/lgraphic.h>

using Layers::LGraphic;

LayersDemo::LayersDemo(QWidget* parent) :
	LWidget(parent)
{
	set_icon(LGraphic(":/image_sequences/layers_logo.imgseq", QSize(35, 35)));
	set_name("Layers Demo");

	m_fill->set_link_new("Main Window.fill");
}
