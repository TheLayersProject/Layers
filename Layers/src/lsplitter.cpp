#include <Layers/lsplitter.h>

using Layers::LSplitter;

LSplitter::LSplitter(QWidget* parent) :
	QSplitter(parent)
{
	init();
}

LSplitter::LSplitter(Qt::Orientation orientation, QWidget* parent) :
	QSplitter(orientation, parent)
{
	init();
}

void LSplitter::init()
{
	set_name("Splitter");
	setHandleWidth(20);
}
