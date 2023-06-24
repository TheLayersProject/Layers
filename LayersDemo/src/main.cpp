#include "LayersDemoWindow.h"

#include <QIcon>
#include <QUuid>

#include <Layers/lapplication.h>
#include <Layers/lgithubrepo.h>
#include <Layers/lversion.h>

using namespace Layers;

int main(int argc, char *argv[])
{
	LApplication app(argc, argv,
		"Layers Demo",
		QUuid("f97aae7f-2076-4918-93ce-19321584f675"),
		nullptr,
		new LVersion("0.16.0"),
		new LGitHubRepo("huntermalm/Layers"));

	if (app.update_available())
		if (app.update_on_request())
			return 0;

	LayersDemoWindow window;
	window.show();

	//qDebug() << "Testing START:";
	//
	//LAttribute* fill = app.attribute("Main Window/Settings Menu/Themes Widget.fill");
	//
	//if (fill)
	//{
	//	qDebug() << "fill FOUND!";
	//	fill->set_value(QColor(Qt::blue));
	//}
	//else
	//	qDebug() << "fill NOT FOUND!";
	//
	//qDebug() << "Testing END:";

	return app.exec();
}
