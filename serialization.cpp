#include "Layers.h"

using Layers::Theme_2_0_0_a;
using Layers::Theme;

// 2.0.0a

Theme_2_0_0_a Layers::load_theme_2_0_0_a(QFile& theme_file)
{
	Theme_2_0_0_a loaded_theme;

	if (theme_file.exists())
	{
		if (!theme_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&theme_file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		theme_file.close();
	}

	return loaded_theme;
}

// 2.1.0a (Current)

Theme Layers::load_theme_2_1_0_a(QFile& theme_file)
{
	Theme loaded_theme;

	if (theme_file.exists())
	{
		if (!theme_file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read theme file";

		QDataStream in(&theme_file);
		in.setVersion(QDataStream::Qt_5_13);

		in >> loaded_theme;

		theme_file.close();
	}

	return loaded_theme;
}

// Theme update functions

Theme Layers::update_theme_2_0_0_a_to_2_1_0_a(Theme_2_0_0_a& old_theme)
{
	Theme new_theme;

	new_theme.built_in = old_theme.built_in;
	new_theme.name = old_theme.name;

	for (QString themeable_tag : old_theme.m_data.keys())
	{
		for (Attribute_2_0_0_a old_attribute : old_theme.m_data[themeable_tag])
		{
			if (old_attribute.m_values.count() == 1)
				new_theme.add_attribute(themeable_tag, old_attribute.m_name, old_attribute.m_values.first());
			else
				new_theme.add_attribute(themeable_tag, old_attribute.m_name, old_attribute.m_values);
		}
	}

	return new_theme;
}


