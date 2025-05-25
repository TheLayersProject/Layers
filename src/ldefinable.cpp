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

#include <Layers/ldefinable.h>

#include <Layers/lattribute.h>

using Layers::LAttribute;
using Layers::LDefinition;
using Layers::LDefinable;

//std::unordered_set<LDefinable*> LDefinable::dirty_definables;

class LDefinable::Impl
{
public:
	Impl() = default;

	Impl(const Impl& other) {}

	std::vector<std::unique_ptr<LAttribute>> attributes;

	LDefinition* definition{ nullptr };

	std::vector<LDefinable*> share_definables;
};

LDefinable::LDefinable() :
	pimpl{ new Impl() } {}

LDefinable::LDefinable(const LDefinable& other) :
	pimpl{ new Impl(*(other.pimpl)) } {}

LDefinable::~LDefinable()
{
	delete pimpl;
}

void LDefinable::add_attribute(std::unique_ptr<LAttribute> attr)
{
	if (!attr) return;

	attr->set_parent_definable(this);

	attr->on_change([this](){ mark_dirty(); });

	pimpl->attributes.push_back(std::move(attr));

}

void LDefinable::add_share_definable(LDefinable* definable)
{
	if (definable)
	{
		if (pimpl->definition)
			definable->apply_definition(pimpl->definition);

		pimpl->share_definables.push_back(definable);
	}
}

void LDefinable::apply_definition(LDefinition* definition, bool is_top_level)
{
	if (definition)
	{
		if (name() == definition->object_name())
		{
			pimpl->definition = definition;

			const auto& attributes_map = definition->attributes();
			if (!attributes_map.empty())
			{
				for (const auto& attr : pimpl->attributes)
				{
					auto it = attributes_map.find(attr->object_name());
					if (it != attributes_map.end())
					{
						attr->set_definition_attribute(it->second);
					}
				}
			}

			const auto& children_map = definition->children();
			if (!children_map.empty())
			{
				for (LDefinable* child : child_definables())
				{
					auto it = children_map.find(child->name());
					if (it != children_map.end())
					{
						child->apply_definition(it->second, false);
					}
				}
			}

			for (LDefinable* themeable : pimpl->share_definables)
			{
				themeable->apply_definition(pimpl->definition);
			}
		}
	}
	else
	{
		pimpl->definition = nullptr;

		for (const auto& attr : pimpl->attributes)
		{
			attr->clear_definition_attribute();
		}

		for (LDefinable* child : child_definables())
		{
			child->apply_definition(nullptr, false);
		}
	}

	if (is_top_level)
	{
		LDefinable::flush_updates();
	}
}

const std::vector<std::unique_ptr<LAttribute>>& LDefinable::attributes() const
{
	return pimpl->attributes;
}

LDefinition* LDefinable::definition() const
{
	return pimpl->definition;
}

void LDefinable::flush_updates()
{
	for (auto* d : dirty_definables())
	{
		d->is_dirty = false;
		d->update();
	}
	dirty_definables().clear();
}

void LDefinable::mark_dirty()
{
	if (!is_dirty)
	{
		is_dirty = true;
		dirty_definables().insert(this);
	}
}

std::unordered_set<LDefinable *> &LDefinable::dirty_definables()
{
  static std::unordered_set<LDefinable*> dirty_definables;
    return dirty_definables;
}
