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

#include <Layers/llink.h>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/ldefinition.h>

using Layers::LAttribute;
using Layers::LDefinition;
using Layers::LLink;
using Layers::LResolution;
using Layers::LString;

class LLink::Impl
{
public:
    LString absolute_path;
    LString relative_path;

    std::map<LDefinition*, LResolution> resolutions;

	LAttribute* attribute{ nullptr };

    Impl(const LString& absolute_path, const LString& relative_path) :
        absolute_path{ absolute_path }, relative_path{ relative_path } {}

    Impl(LAttribute* attribute) :
        attribute{ attribute } {}

    bool resolve(LDefinition* definition)
    {
        if (!relative_path.empty())
        {
            LStringList relative_path_parts =
                split<LStringList>(relative_path, '/');

            /*
                NOTE:
                The following assumes that dynamic links always begin with double-
                dot notation and that there is always only 1 of them. Other cases
                have not yet been considered.
            */
            if (relative_path_parts[0] == "..")
            {
                if (LObject* def_parent_as_obj = definition->parent())
                {
                    if (LDefinition* def_parent = dynamic_cast<LDefinition*>(def_parent_as_obj))
                    {
                        for (const auto& [key, attr] : def_parent->attributes())
                            if (attr->object_name() == relative_path_parts[1])
                            {
                                LResolution res;
                                res.target_definition = def_parent;
                                res.target_attribute = attr;

                                resolutions[definition] = res;
                                return true;
                                //return attr->as<T>(parent_parent_as_def);
                            }
                    }
                }
                else
                {
                    auto absolute_path_parts =
                        split<std::deque<LString>>(absolute_path, '/');
                    LString absolute_attr_name = absolute_path_parts.back();
                    absolute_path_parts.pop_back();

                    if (LDefinition* def = lController.find_definition(absolute_path_parts))
                        for (const auto& [attr_name, attr] : def->attributes())
                            if (attr_name == absolute_attr_name)
                            {
                                LResolution res;
                                res.target_definition = def;
                                res.target_attribute = attr;

                                resolutions[definition] = res;
                                return true;
                                //return attr->as<T>();
                            }
                }
            }
        }
        else if (!absolute_path.empty())
        {
            auto absolute_path_parts =
                        split<std::deque<LString>>(absolute_path, '/');
                    LString absolute_attr_name = absolute_path_parts.back();
                    absolute_path_parts.pop_back();

                    if (LDefinition* def = lController.find_definition(absolute_path_parts))
                        for (const auto& [attr_name, attr] : def->attributes())
                            if (attr_name == absolute_attr_name)
                            {
                                LResolution res;
                                res.target_definition = def;
                                res.target_attribute = attr;

                                resolutions[definition] = res;
                                return true;
                                //return attr->as<T>();
                            }
        }

        return false;
    }
};

LLink::LLink(const LString& absolute_path, const LString& relative_path) :
    pimpl{ new Impl(absolute_path, relative_path) } {}

LLink::LLink(LAttribute* attribute) :
	pimpl{ new Impl(attribute) } {}

 LAttribute* LLink::attribute() const
 {
     return pimpl->attribute;
 }

std::map<LDefinition*, LResolution> LLink::resolutions()
{
    return pimpl->resolutions;
}

bool LLink::resolve(LDefinition* definition)
{
    return pimpl->resolve(definition);
}
