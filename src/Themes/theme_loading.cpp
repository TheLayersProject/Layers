#include "../../../include/theme_loading.h"

#include "../../../include/Application.h"

#include <QJsonArray>

using Layers::Theme;

Theme* Layers::load_theme_1(const QString& file_name, const QString& app_identifier)
{
	Theme* loaded_theme = nullptr;

	QDir dir = QDir(file_name);

	QFile meta_file(dir.filePath("meta.json"));
	QFile layers_file(dir.filePath("layers.json"));
	QFile app_file(dir.filePath(layersApp->app_identifier() + ".json"));

	if (meta_file.exists() && layers_file.exists())
	{
		if (!meta_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme 'meta.json' file";

		QJsonDocument meta_doc = QJsonDocument::fromJson(meta_file.readAll());
		QJsonObject meta_obj = meta_doc.object();

		meta_file.close();

		QString name = meta_obj.value("name").toString();

		QUuid* uuid = new QUuid(meta_obj.value("uuid").toString());

		bool editable = true;
		if (meta_obj.contains("editable"))
			editable = meta_obj.value("editable").toBool();

		loaded_theme = new Theme(name, uuid, editable);

		QStringList lineage = QStringList();
		for (QJsonValue lineage_value : meta_obj.value("lineage").toArray())
			lineage.append(lineage_value.toString());
		loaded_theme->append_to_lineage(lineage);

		if (!layers_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme 'layers.json' file";

		loaded_theme->load_document(QJsonDocument::fromJson(layers_file.readAll()), ThemeDataType::Layers);

		layers_file.close();

		if (app_file.exists())
		{
			if (!app_file.open(QIODevice::ReadOnly))
				qDebug() << "Could not read theme app file";

			loaded_theme->load_document(QJsonDocument::fromJson(app_file.readAll()), ThemeDataType::Application);

			app_file.close();
		}
	}

	return loaded_theme;
}
