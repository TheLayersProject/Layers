#ifndef THEME_LOADING_H
#define THEME_LOADING_H

#include <QDataStream>
#include <QFile>

#include "old.h"
#include "Theme.h"

namespace Layers
{
	struct Theme_And_Load_Status_Combo_2_0_0_a
	{
		Theme_2_0_0_a theme;
		QDataStream::Status status;
	};

	struct Theme_And_Load_Status_Combo_2_1_0_a
	{
		Theme_2_1_0_a theme;
		QDataStream::Status status;
	};

	struct Theme_And_Load_Status_Combo_2_2_0_a
	{
		Theme_2_2_0_a theme;
		QDataStream::Status status;
	};

	struct Theme_And_Load_Status_Combo_2_3_0_a
	{
		Theme theme;
		QDataStream::Status status;
	};

	Theme_And_Load_Status_Combo_2_0_0_a load_theme_2_0_0_a(const QString& file_name);

	Theme_And_Load_Status_Combo_2_1_0_a load_theme_2_1_0_a(const QString& file_name);

	Theme_And_Load_Status_Combo_2_2_0_a load_theme_2_2_0_a(const QString& file_name);

	Theme_And_Load_Status_Combo_2_3_0_a load_theme_2_3_0_a(const QString& file_name);
}

#endif // THEME_LOADING_H
