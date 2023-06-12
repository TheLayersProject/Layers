#include "LayersDemo.h"

#include <LayersCore/lgraphic.h>

using Layers::LGraphic;

LayersDemo::LayersDemo(QWidget* parent) :
	LWidget(parent)
{
	set_icon(LGraphic(":/image_sequences/layers_logo.imgseq", QSize(35, 35)));
	set_name("Layers Demo");

	m_fill->set_disabled();
}
