#include "LayersDemoWindow.h"

#include <QIcon>
#include <QUuid>

#include <Layers/lapplication.h>
#include <Layers/lgithubrepo.h>
#include <Layers/lupdatedialog.h>

using namespace Layers;

int main(int argc, char *argv[])
{
	LApplication app(argc, argv,
		"Layers Demo",
		QUuid("f97aae7f-2076-4918-93ce-19321584f675"),
		new LGitHubRepo("huntermalm/Layers"));
	app.set_version("0.16.0");

	if (app.update_available())
	{
		LUpdateDialog update_dialog =
			LUpdateDialog(app.version(), app.latest_version());

		update_dialog.apply_theme(
			activeTheme()->find_item(update_dialog.path()));

		if (update_dialog.exec())
		{
			app.download_and_install_update();
			return 0;
		}
	}

	LayersDemoWindow window;
	window.apply_theme(activeTheme()->find_item(window.path()));
	window.show();

	return app.exec();
}
