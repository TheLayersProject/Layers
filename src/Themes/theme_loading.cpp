#include "../../../include/theme_loading.h"

using Layers::Theme;

Theme Layers::load_theme_1(const QString& file_name)
{
	QFile file = QFile(file_name);

	Theme loaded_theme;

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
		loaded_theme = Theme(QJsonDocument::fromJson(file.readAll()));

		file.close();
	}

	return loaded_theme;
}
