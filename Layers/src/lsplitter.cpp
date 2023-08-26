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
	setObjectName("Splitter");
	setHandleWidth(20);
}
