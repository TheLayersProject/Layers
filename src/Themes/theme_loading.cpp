#include "../../../include/theme_loading.h"

using Layers::Theme;

Theme* Layers::load_theme_1(const QString& file_name, const QString& app_identifier)
{
	Theme* loaded_theme = nullptr;

	if (file_name.endsWith(".json"))
	{
		QFile file = QFile(file_name);

		if (file.exists())
		{
			if (!file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme file";

			// Load Binary
			//QDataStream in(&file);
			//in.setVersion(QDataStream::Qt_6_1);
			//in >> loaded_theme;
			//QDataStream::Status status = in.status();

			// Load JSON
			loaded_theme = new Theme(QJsonDocument::fromJson(file.readAll()));

			file.close();
		}
	}
	else
	{
		QDir dir = QDir(file_name);

		QStringList file_name_parts = file_name.split('_', Qt::SkipEmptyParts);

		QString uuid_str = file_name_parts.last();

		QFile layers_theme_file(dir.filePath("layers.json"));

		if (layers_theme_file.exists())
		{
			if (!layers_theme_file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme file";

			// Load JSON
			loaded_theme = new Theme(QJsonDocument::fromJson(layers_theme_file.readAll()), new QUuid(uuid_str));

			layers_theme_file.close();
		}

		QFile app_theme_file(dir.filePath(app_identifier + ".json"));

		if (app_theme_file.exists())
		{
			if (!app_theme_file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme file";

			// Load JSON
			if (loaded_theme)
				loaded_theme->consume(Theme(QJsonDocument::fromJson(app_theme_file.readAll())));
			else
				loaded_theme = new Theme(QJsonDocument::fromJson(app_theme_file.readAll()), new QUuid(uuid_str));

			app_theme_file.close();
		}

		// Next, load the application's theme file


		// Probably don't need to loop since not loading all app theme files
		//for (const QString& file_name : dir.entryList(QDir::Files))
		//{
		//	if

		//	QFile file = QFile(file_name);

		//	if (file.exists())
		//	{
		//		if (!file.open(QIODevice::ReadOnly))
		//			qDebug() << "Could not read theme file";

		//		// Load Binary
		//		//QDataStream in(&file);
		//		//in.setVersion(QDataStream::Qt_6_1);
		//		//in >> loaded_theme;
		//		//QDataStream::Status status = in.status();

		//		// Load JSON
		//		loaded_theme = Theme(QJsonDocument::fromJson(file.readAll()));

		//		file.close();
		//	}
		//}
	}

	return loaded_theme;
}
