/*
 * Copyright (C) 2025 Huntr Software LLC
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

#include <Layers/lattribute.h>

#include <Layers/lalgorithms.h>
#include <Layers/lstyle.h>
#include <Layers/lconnector.h>

using Layers::LAttribute;
using Layers::LAttributeList;
using Layers::LAttributeMap;
using Layers::LConnectionID;
using Layers::LLink;
using Layers::LObject;
using Layers::LString;
using Layers::LStringList;
using Layers::LVariant;

// Might be able to delete these
template double LAttribute::as<double>(const LStringList&, LStyle*);
template bool LAttribute::as<bool>(const LStringList&, LStyle*);
template LString LAttribute::as<LString>(const LStringList&, LStyle*);
template LStringList LAttribute::as<LStringList>(const LStringList&, LStyle*);

class LAttribute::Impl
{
public:
	LAttribute* owner{ nullptr };

	LConnectionID m_link_destroyed_connection;
	LConnectionID def_connection;

	LAttributeList m_dependent_attrs;

	LAttribute* def_attr{ nullptr };

	std::unique_ptr<LLink> link;

	LVariant _value;

	LConnector<> connector_change;
	LConnector<> connector_link_change;

	Impl(LAttribute* owner) :
		owner{ owner } {}

	Impl(LAttribute* owner, double value) :
		owner{ owner }, _value{ value } {}

	Impl(LAttribute* owner, const char* value) :
		owner{ owner }, _value{ LString(value) } {}

	Impl(LAttribute* owner, const LVariant& value) :
		owner{ owner }, _value{ value } {}

	Impl(LAttribute* owner, const json& j) :
		owner{ owner }
	{
		if (j.is_object())
        {
            // Handle Links
            LString absolute_link_path = "";
            LString relative_link_path = "";

            if (j.contains("link"))
				absolute_link_path =
					remove_substring(j["link"].get<std::string>(), "L:");

            if (j.contains("link_relative"))
                relative_link_path = 
					remove_substring(j["link_relative"].get<std::string>(), "L:");

            if (!absolute_link_path.empty() || !relative_link_path.empty())
                link = std::make_unique<LLink>(absolute_link_path, relative_link_path);

            // Handle Value
            if (j.contains("value"))
                init_value(j["value"]);
        }
        else
        {
            init_value(j);
        }
	}

	void init_value(const json& j)
    {
        if (j.is_number())
        {
            _value = j.get<double>();
        }
        else if (j.is_boolean())
        {
            // Your LVariant needs to support bool, or cast to double/string
             _value = j.get<bool>(); 
        }
        else if (j.is_string())
        {
            LString str_val = j.get<std::string>();

            if (starts_with(str_val, "L:"))
			{
				link = std::make_unique<LLink>(
					remove_substring(str_val, "L:"));
			}
            else
                _value = str_val;
        }
        else if (j.is_array())
        {
            // Check if it is a string array (gradient)
            if (!j.empty() && j[0].is_string())
            {
                std::vector<LString> gradient_stops;
                // nlohmann allows direct conversion to std::vector
                for (const auto& val : j)
                {
                    gradient_stops.push_back(val.get<std::string>());
                }
                _value = gradient_stops;
            }
        }
    }

	void break_link(bool update)
	{
		if (!link || !link->attribute()) return;

		_value = link->attribute()->value();

		link->attribute()->disconnect_destroyed(m_link_destroyed_connection);

		auto& deps = link->attribute()->pimpl->m_dependent_attrs;
		deps.erase(std::remove(deps.begin(), deps.end(), owner), deps.end());

		link.reset();

		connector_link_change.execute();
		if (update)
		{
			connector_change.execute();
		}
	}

	void clear_style_attribute()
	{
		if (def_attr)
		{
			def_attr->disconnect_change(def_connection);
			def_attr = nullptr;
		}

		connector_change.execute();
	}

	void create_link(LAttribute* link_attr)
	{
		_value = LVariant();

		break_link(false);

		link = std::make_unique<LLink>(link_attr);

		update_link_dependencies();
		connector_change.execute();

		link_attr->pimpl->m_dependent_attrs.push_back(owner);
		link_attr->update_link_dependencies();
	}

	void create_link(LLink* new_link)
	{
		if (new_link)
		{
			_value = LVariant();

			break_link(false);

			link = std::make_unique<LLink>(*new_link);

			if (LAttribute* link_attr = link->attribute())
			{
				link_attr->pimpl->m_dependent_attrs.push_back(owner);
				link_attr->update_link_dependencies();
			}

			update_link_dependencies();
			connector_change.execute();
		}
	}

	LAttributeList dependent_attributes(
		bool include_indirect_dependencies) const
	{
		LAttributeList dependent_attributes = m_dependent_attrs;

		if (include_indirect_dependencies)
			for (LAttribute* dependent_attr : m_dependent_attrs)
			{
				LAttributeList attrs =
					dependent_attr->dependent_attributes(
		 				include_indirect_dependencies);

				std::copy(attrs.begin(), attrs.end(),
					std::back_inserter(dependent_attributes));
			}

		return dependent_attributes;
	}

	void disconnect_change(
		const LConnectionID& connection)
	{
		connector_change.disconnect(connection);
	}

	void disconnect_link_change(
		const LConnectionID& connection)
	{
		connector_link_change.disconnect(connection);
	}

	bool is_link(const LString& str) const
	{
		if (starts_with(str, "L:"))
			return true;
		
		return false;
	}

	LConnectionID on_change(std::function<void()> callback)
	{
		return connector_change.connect(callback);
	}

	LConnectionID on_link_change(std::function<void()> callback)
	{
		return connector_link_change.connect(callback);
	}

	void resolve_links()
	{
		if (link)
		{
			link->resolve(owner);
			//if (!link->resolve(owner));
			// TODO: Handle link resolution failure

			if (const auto& link_attr = link->attribute())
			{
				bool link_attr_already_has_this_dependency = false;

				for (const auto& dep_attr : link_attr->pimpl->m_dependent_attrs)
				{
					if (dep_attr == owner)
						link_attr_already_has_this_dependency = true;
				}

				if (!link_attr_already_has_this_dependency)
					link_attr->pimpl->m_dependent_attrs.push_back(owner);
			}
		}

		for (const auto& [key, state] : owner->states(false))
			state->resolve_links();

		connector_change.execute();
	}

	void set_style_attribute(LAttribute* new_def_attr)
	{
		if (def_attr)
		{
			def_attr->disconnect_change(def_connection);
			def_attr = nullptr;
		}

		if (new_def_attr)
		{
			def_attr = new_def_attr;

			def_connection = def_attr->on_change(
				[this] { connector_change.execute(); });
		}

		connector_change.execute();
	}

	void set_value(const LVariant& new_value)
	{
		if (link && link->attribute())
		{
			link->attribute()->set_value(new_value);
		}

		if (!link && _value == new_value)
			return;

		_value = new_value;
		connector_change.execute();
	}

	json to_json_object() const
    {
        json j;

        if (link)
        {
            if (!link->path().empty())
                j["link"] = link->path(); // implicit conversion to std::string
            else if (!link->relative_path().empty())
                j["link_relative"] = link->relative_path();
        }
        else if (_value.index() > 0)
        {
            j["value"] = to_json_value();
        }

        LAttributeMap s = owner->states();

        if (!s.empty())
        {
            json overrides_json_object;

            for (const auto& [key, override_attr] : s)
                overrides_json_object[key] = override_attr->to_json_object();

            j["states"] = overrides_json_object;
        }

        return j;
    }

    json to_json_value() const
    {
        // Use std::visit to handle the LVariant (std::variant)
        return std::visit([](const auto& arg) -> json {
            using T = std::decay_t<decltype(arg)>;
            
            // Handle std::vector<LString> specifically
            if constexpr (std::is_same_v<T, std::vector<LString>>) {
                json j_array = json::array();
                for (const auto& s : arg) j_array.push_back(s);
                return j_array;
            }
            // Handle LString -> std::string conversion
            else if constexpr (std::is_same_v<T, LString>) {
                return std::string(arg); 
            }
            // Handle empty variant (monostate) or basic types (double, bool)
            else {
                return json(); 
            }
        }, _value);
    }

	size_t type_index() const
	{
		if (def_attr)
			return def_attr->type_index();

		//if (link && link->attribute())
		//	return link->attribute()->type_index();

		//if (!states.empty())
		//	return (*states.begin()).second->type_index();

		return _value.index();
	}

	void update_link_dependencies()
	{
		connector_link_change.execute();

		for (LAttribute* dep_attr : dependent_attributes(true))
		{
			dep_attr->update_link_dependencies();
		}
	}

	const LVariant& value()
	{
		if (link && link->attribute())
			return link->attribute()->value();

		return _value;
	}
};

LAttribute::LAttribute(const LString& name) :
	pimpl{ new Impl(this) }, LObject()
{
	set_object_name(name);
}

LAttribute::LAttribute(const LString& name, double value) :
	pimpl{ new Impl(this, value) }, LObject()
{
	set_object_name(name);
}

LAttribute::LAttribute(const LString& name, const char* value) :
	pimpl{ new Impl(this, value) }, LObject()
{
	set_object_name(name);
}

LAttribute::LAttribute(const LString& name, const LVariant& value) :
	pimpl{ new Impl(this, value) }, LObject()
{
	set_object_name(name);
}

LAttribute::LAttribute(const LString& name, const json& value) :
    pimpl{ new Impl(this, value) }, LObject()
{
    set_object_name(name);

    if (value.is_object())
    {
        if (value.contains("states"))
        {
            for (const auto& [key, state_val] : value["states"].items())
            {
                lMake<LAttribute>(this, key, state_val);
            }
        }
    }
}

LAttribute::~LAttribute()
{
	// 1) break *all* links from attributes that depend on me
	auto deps = pimpl->m_dependent_attrs;   // copy the list
	for (LAttribute* dep : deps)
	{
		dep->break_link(false);
	}

	// 2) tear down any style-attribute subscription
	if (pimpl->def_attr)
		pimpl->def_attr->disconnect_change(pimpl->def_connection);

	// 3) break *my* own link (to some other attribute), but don't emit update
	break_link(false);

	delete pimpl;
}

void LAttribute::create_link(LAttribute* link_attr)
{
	pimpl->create_link(link_attr);
}

void LAttribute::create_link(LLink* link)
{
	pimpl->create_link(link);
}

void LAttribute::break_link(bool update)
{
	pimpl->break_link(update);
}

void LAttribute::clear_style_attribute()
{
	pimpl->clear_style_attribute();
}

LAttributeList LAttribute::dependent_attributes(
	bool include_indirect_dependencies) const
{
	return pimpl->dependent_attributes(include_indirect_dependencies);
}

void LAttribute::disconnect_change(const LConnectionID& connection)
{
	pimpl->disconnect_change(connection);
}

void LAttribute::disconnect_link_change(const LConnectionID& connection)
{
	pimpl->disconnect_link_change(connection);
}

bool LAttribute::has_states() const
{
	return !states().empty();
}

LConnectionID LAttribute::on_change(std::function<void()> callback)
{
	return pimpl->on_change(callback);
}

LConnectionID LAttribute::on_link_change(std::function<void()> callback)
{
	return pimpl->on_link_change(callback);
}

LString LAttribute::path() const
{
	if (parent())
	{
		if (LAttribute* parent_attr = dynamic_cast<LAttribute*>(parent()))
			return parent_attr->path() + "." + object_name();
		else if (LStyle* parent_theme_item = dynamic_cast<LStyle*>(parent()))
			return parent_theme_item->path() + "/" + object_name();
	}

	return object_name();
}

void LAttribute::resolve_links()
{
	pimpl->resolve_links();
}

void LAttribute::set_style_attribute(LAttribute* new_def_attr)
{
	pimpl->set_style_attribute(new_def_attr);
}

void LAttribute::set_value(const char* new_value)
{
	set_value(LString(new_value));
}

void LAttribute::set_value(const LVariant& new_value)
{
	pimpl->set_value(new_value);
}

LAttribute* LAttribute::state(const LStringList& state_combo)
{
	for (const auto& [key, state_attr] : states())
	{
		auto state_names =
			split<LStringList>(state_attr->object_name(), ':');

		bool qualifies = true;

		for (const auto& state_name : state_names)
		{
			if (std::find(state_combo.begin(), state_combo.end(),
				state_name) == state_combo.end())
			{
				qualifies = false;
			}
		}

		if (qualifies)
			return state_attr;
	}

	// TODO: Handle returning override with highest number of matching
	// states. If there is a conflict (two matching overrides), just
	// return the value of this

	return nullptr;

	//return pimpl->state(state_combo);
}

LAttributeMap LAttribute::states(bool include_parent_states) const
{
	LAttributeMap states;

	std::vector<LAttribute*> attr_list = find_children<LAttribute>();

	for (const auto& attr : attr_list)
	{
		states[attr->object_name()] = attr;
	}

	if (include_parent_states && parent())
	{
		if (LStyle* parent_as_def = dynamic_cast<LStyle*>(parent()))
		{
			if (parent_as_def->base())
			{
				if (LAttribute* base_attr = parent_as_def->base()->find_attribute(object_name()))
				{
					LAttributeMap base_states = base_attr->states();

					states.insert(base_states.begin(), base_states.end());
				}
			}
		}
	}

	return states;
}

LLink* LAttribute::link() const
{
	return pimpl->link.get();
}

LAttribute* LAttribute::style_attribute() const
{
	return pimpl->def_attr;
}

json LAttribute::to_json_object() const
{
	return pimpl->to_json_object();
}

json LAttribute::to_json_value() const
{
	return pimpl->to_json_value();
}

size_t LAttribute::type_index() const
{
	return pimpl->type_index();
}

const LVariant& LAttribute::value()
{
	return pimpl->value();
}

void LAttribute::update_link_dependencies()
{
	pimpl->update_link_dependencies();
}
