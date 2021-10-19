#include "../../Layers.h"

using Layers::Theme_And_Load_Status_Combo_2_0_0_a;
using Layers::Theme_And_Load_Status_Combo_2_1_0_a;
using Layers::Theme_And_Load_Status_Combo_2_2_0_a;

// 2.0.0a
Theme_And_Load_Status_Combo_2_0_0_a Layers::load_theme_2_0_0_a(QFile& theme_file)
{
	Theme_2_0_0_a loaded_theme;

	QDataStream::Status status;

	if (theme_file.exists())
	{
		if (!theme_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&theme_file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		status = in.status();

		theme_file.close();
	}

	return Theme_And_Load_Status_Combo_2_0_0_a{ loaded_theme, status };
}

// 2.1.0a
Theme_And_Load_Status_Combo_2_1_0_a Layers::load_theme_2_1_0_a(QFile& theme_file)
{
	Theme_2_1_0_a loaded_theme;

	QDataStream::Status status;

	if (theme_file.exists())
	{
		if (!theme_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&theme_file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		status = in.status();

		theme_file.close();
	}

	return Theme_And_Load_Status_Combo_2_1_0_a{ loaded_theme, status };
}

// 2.2.0a (Current)
Theme_And_Load_Status_Combo_2_2_0_a Layers::load_theme_2_2_0_a(QFile& theme_file)
{
	Theme loaded_theme("");

	QDataStream::Status status;

	if (theme_file.exists())
	{
		if (!theme_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&theme_file);
		in.setVersion(QDataStream::Qt_6_1);

		in >> loaded_theme;

		status = in.status();

		theme_file.close();
	}

	return Theme_And_Load_Status_Combo_2_2_0_a{ loaded_theme, status };
}
