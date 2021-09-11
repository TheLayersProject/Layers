#include "Layers.h"

using Layers::Theme_2_0_0_a;
using Layers::Theme_2_1_0_a;
using Layers::Theme;

Theme_2_1_0_a Layers::update_theme_2_0_0_a_to_2_1_0_a(Theme_2_0_0_a& old_theme)
{
	Theme_2_1_0_a new_theme(old_theme.name, !old_theme.built_in);

	for (QString themeable_tag : old_theme.m_data.keys())
	{
		for (Attribute_2_0_0_a old_attribute : old_theme.m_data[themeable_tag])
		{
			if (old_attribute.m_values.count() == 1)
				new_theme.add_stateless_attribute(themeable_tag, old_attribute.m_name, old_attribute.m_values.first());
			else
				new_theme.add_stateful_attribute(themeable_tag, old_attribute.m_name, old_attribute.m_values);
		}
	}

	return new_theme;
}

Theme Layers::update_theme_2_1_0_a_to_2_2_0_a(Theme_2_1_0_a& old_theme)
{
	Theme new_theme(old_theme.name(), old_theme.is_custom());

	for (const QString& themeable_tag : old_theme.attribute_sets().keys())
	{
		for (Stateless_Attribute_2_1_0_a& stateless_attribute : old_theme.attribute_sets()[themeable_tag].stateless_attributes())
			new_theme.add_stateless_attribute(themeable_tag, stateless_attribute.name(), stateless_attribute.value());

		for (Stateful_Attribute_2_1_0_a& stateful_attribute : old_theme.attribute_sets()[themeable_tag].stateful_attributes())
			new_theme.add_stateful_attribute(themeable_tag, stateful_attribute.name(), stateful_attribute.values());
	}

	return new_theme;
}
