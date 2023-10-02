/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

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
		new LGitHubRepo("TheLayersProject/Layers"));
	app.set_publisher("The Layers Project");
	app.set_version("0.16.0");
	app.init();

	if (app.update_available())
	{
		LUpdateDialog update_dialog =
			LUpdateDialog(app.version(), app.latest_version());

		update_dialog.apply_theme_item(
			activeTheme()->find_item(update_dialog.path()));

		if (update_dialog.exec())
		{
			app.download_and_install_update();
			return 0;
		}
	}

	LayersDemoWindow window;
	window.apply_theme_item(activeTheme()->find_item(window.path()));
	window.show();

	return app.exec();
}
