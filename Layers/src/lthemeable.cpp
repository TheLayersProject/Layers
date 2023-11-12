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

#include <Layers/lthemeable.h>

using Layers::LAttribute;
using Layers::LThemeItem;
using Layers::LThemeable;

class LThemeable::Impl
{
public:
	Impl() = default;

	Impl(const Impl& other) {}

	void add_share_themeable(LThemeable* themeable)
	{
		if (themeable)
		{
			if (m_current_theme_item)
				themeable->apply_theme_item(m_current_theme_item);

			m_share_themeables.push_back(themeable);
		}
	}

	void apply_theme_item(LThemeable* t, LThemeItem* theme_item)
	{
		if (theme_item)
		{
			if (theme_item->object_name() == "Theme View")
			{
				int a = 0;
			}

			if (t->object_name() == theme_item->object_name())
			{
				m_current_theme_item = theme_item;

				const auto& attributes_map = theme_item->attributes();
				if (!attributes_map.empty())
				{
					for (LAttribute* attr : t->find_children<LAttribute>())
					{
						auto it = attributes_map.find(attr->object_name());
						if (it != attributes_map.end())
						{
							attr->set_theme_attribute(it->second);
						}
					}
				}

				const auto& children_map = theme_item->children();
				if (!children_map.empty())
				{
					for (LThemeable* child_t : t->child_themeables())
					{
						auto it = children_map.find(child_t->object_name());
						if (it != children_map.end())
						{
							child_t->apply_theme_item(it->second);
						}
					}
				}

				for (LThemeable* themeable : m_share_themeables)
				{
					themeable->apply_theme_item(m_current_theme_item);
				}
			}
		}
		else
		{
			m_current_theme_item = nullptr;

			for (LAttribute* attr : t->find_children<LAttribute>())
			{
				attr->clear_theme_attribute();
			}

			for (LThemeable* child_t : t->find_children<LThemeable>())
			{
				child_t->apply_theme_item(nullptr);
			}
		}
	}

	LThemeItem* current_theme_item() const
	{
		return m_current_theme_item;
	}

	LThemeItem* m_current_theme_item{ nullptr };

	std::vector<LThemeable*> m_share_themeables;
};

LThemeable::LThemeable() :
	pimpl{ new Impl() } {}

LThemeable::LThemeable(const LThemeable& other) :
	pimpl{ new Impl(*(other.pimpl)) } {}

LThemeable::~LThemeable()
{
	if (pimpl)
	{
		delete pimpl;
		pimpl = nullptr;
	}
}

void LThemeable::add_share_themeable(LThemeable* themeable)
{
	pimpl->add_share_themeable(themeable);
}

void LThemeable::apply_theme_item(LThemeItem* theme_item)
{
	pimpl->apply_theme_item(this, theme_item);
}

LThemeItem* LThemeable::current_theme_item() const
{
	return pimpl->current_theme_item();
}
