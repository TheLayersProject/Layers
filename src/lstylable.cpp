/*
 * Copyright (C) 2024 The Layers Project
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

#include <Layers/lstylable.h>

#include <Layers/lattribute.h>

using Layers::LAttribute;
using Layers::LStyle;
using Layers::LStylable;

//std::unordered_set<LStylable*> LStylable::dirty_stylables;

class LStylable::Impl
{
public:
	Impl() = default;

	Impl(const Impl& other) {}

	std::vector<std::unique_ptr<LAttribute>> attributes;

	LStyle* style{ nullptr };

	std::vector<LStylable*> share_stylables;
};

LStylable::LStylable() :
	pimpl{ new Impl() } {}

LStylable::LStylable(const LStylable& other) :
	pimpl{ new Impl(*(other.pimpl)) } {}

LStylable::~LStylable()
{
	delete pimpl;
}

void LStylable::add_attribute(std::unique_ptr<LAttribute> attr)
{
	if (!attr) return;

	attr->set_parent_stylable(this);

	attr->on_change([this](){ mark_dirty(); });

	pimpl->attributes.push_back(std::move(attr));

}

void LStylable::add_share_stylable(LStylable* stylable)
{
	if (stylable)
	{
		if (pimpl->style)
			stylable->apply_style(pimpl->style);

		pimpl->share_stylables.push_back(stylable);
	}
}

void LStylable::apply_style(LStyle* style, bool is_top_level)
{
	if (style)
	{
		if (name() == style->object_name())
		{
			pimpl->style = style;

			const auto& attributes_map = style->attributes();
			if (!attributes_map.empty())
			{
				for (const auto& attr : pimpl->attributes)
				{
					auto it = attributes_map.find(attr->object_name());
					if (it != attributes_map.end())
					{
						attr->set_style_attribute(it->second);
					}
				}
			}

			const auto& children_map = style->children();
			if (!children_map.empty())
			{
				for (LStylable* child : child_stylables())
				{
					auto it = children_map.find(child->name());
					if (it != children_map.end())
					{
						child->apply_style(it->second, false);
					}
				}
			}

			for (LStylable* themeable : pimpl->share_stylables)
			{
				themeable->apply_style(pimpl->style);
			}
		}
	}
	else
	{
		pimpl->style = nullptr;

		for (const auto& attr : pimpl->attributes)
		{
			attr->clear_style_attribute();
		}

		for (LStylable* child : child_stylables())
		{
			child->apply_style(nullptr, false);
		}
	}

	if (is_top_level)
	{
		LStylable::flush_updates();
	}
}

const std::vector<std::unique_ptr<LAttribute>>& LStylable::attributes() const
{
	return pimpl->attributes;
}

LStyle* LStylable::style() const
{
	return pimpl->style;
}

void LStylable::flush_updates()
{
	for (auto* d : dirty_stylables())
	{
		d->is_dirty = false;
		d->update();
	}
	dirty_stylables().clear();
}

void LStylable::mark_dirty()
{
	if (!is_dirty)
	{
		is_dirty = true;
		dirty_stylables().insert(this);
	}
}

std::unordered_set<LStylable*> &LStylable::dirty_stylables()
{
  static std::unordered_set<LStylable*> dirty_stylables;
    return dirty_stylables;
}
