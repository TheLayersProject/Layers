#include "LayersDemoWindow.h"

#include <QIcon>
#include <QUuid>

#include <LayersCore/lgithubrepo.h>
#include <LayersCore/lversion.h>
#include <LayersWidgets/lapplication.h>

int main(int argc, char *argv[])
{
	Layers::LApplication app(argc, argv,
		"Layers Demo",
		QUuid("f97aae7f-2076-4918-93ce-19321584f675"),
		nullptr,
		new Layers::LVersion("0.16.0"),
		new Layers::LGitHubRepo("huntermalm/Layers"));

	if (app.update_available())
		if (app.update_on_request())
			return 0;

	LayersDemoWindow window;
	window.show();

	return app.exec();
}
