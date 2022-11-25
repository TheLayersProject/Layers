#include "../../../include/theme_loading.h"

using Layers::Theme_And_Load_Status_Combo_2_0_0_a;
using Layers::Theme_And_Load_Status_Combo_2_1_0_a;
using Layers::Theme_And_Load_Status_Combo_2_2_0_a;
using Layers::Theme_And_Load_Status_Combo_2_3_0_a;

// 2.0.0a
Theme_And_Load_Status_Combo_2_0_0_a Layers::load_theme_2_0_0_a(const QString& file_name)
{
	QFile file = QFile(file_name);

	Theme_2_0_0_a loaded_theme;

	QDataStream::Status status;

	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		status = in.status();

		file.close();
	}

	return Theme_And_Load_Status_Combo_2_0_0_a{ loaded_theme, status };
}

// 2.1.0a
Theme_And_Load_Status_Combo_2_1_0_a Layers::load_theme_2_1_0_a(const QString& file_name)
{
	QFile file = QFile(file_name);

	Theme_2_1_0_a loaded_theme;

	QDataStream::Status status;

	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		status = in.status();

		file.close();
	}

	return Theme_And_Load_Status_Combo_2_1_0_a{ loaded_theme, status };
}

// 2.2.0a
Theme_And_Load_Status_Combo_2_2_0_a Layers::load_theme_2_2_0_a(const QString& file_name)
{
	QFile file = QFile(file_name);

	Theme_2_2_0_a loaded_theme("");

	QDataStream::Status status;

	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_6_1);

		in >> loaded_theme;

		status = in.status();

		file.close();
	}

	return Theme_And_Load_Status_Combo_2_2_0_a{ loaded_theme, status };
}

// 2.3.0a (Current)
Theme_And_Load_Status_Combo_2_3_0_a Layers::load_theme_2_3_0_a(const QString& file_name)
{
	QFile file = QFile(file_name);

	Theme loaded_theme;

	QDataStream::Status status;

	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_6_1);

		// Load JSON
		loaded_theme = Theme(QJsonDocument::fromJson(file.readAll()));

		// Load Binary
		//in >> loaded_theme;

		status = in.status();

		file.close();
	}

	return Theme_And_Load_Status_Combo_2_3_0_a{ loaded_theme, status };
}
