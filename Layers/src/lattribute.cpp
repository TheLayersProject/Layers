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

#include <Layers/lattribute.h>

#include <Layers/lalgorithms.h>
#include <Layers/lthemeable.h>

using Layers::LAttribute;
using Layers::LAttributeList;
using Layers::LAttributeMap;
using Layers::LConnectionID;
using Layers::LJsonObject;
using Layers::LJsonValue;
using Layers::LVariant;

LAttribute::LAttribute(
	const std::string& name, LObject* parent) :
	LObject(parent)
{
	set_object_name(name);
}

LAttribute::LAttribute(const std::string& name, const char* value, LObject* parent) :
	m_value{ std::string(value) }, LObject(parent)
{
	set_object_name(name);
}

LAttribute::LAttribute(
	const std::string& name, LVariant value, LObject* parent) :
	m_value{ value }, LObject(parent)
{
	set_object_name(name);
}

LAttribute::LAttribute(
	const std::string& name, LJsonObject json_object, LObject* parent) :
	m_json_object{ json_object }, LObject(parent)
{
	set_object_name(name);

	if (json_object.find("linked_to") != json_object.end())
	{
		set_link_path(json_object["linked_to"].to_string());
	}
	else if (json_object.find("value") != json_object.end())
	{
		LJsonValue json_value = json_object["value"];

		if (json_value.is_bool())
			m_value = json_value.to_bool();

		else if (json_value.is_double())
			m_value = json_value.to_double();

		else if (json_value.is_string())
			m_value = json_value.to_string();

		else if (json_value.is_object())
		{
			LJsonObject object = json_value.to_object();

			if (object.find("gradient") != object.end())
			{
				std::vector<std::string> gradient_stops;

				for (const LJsonValue& value : object["gradient"].to_array())
					gradient_stops.push_back(value.to_string());

				m_value = gradient_stops;
			}
		}
	}
	
	if (json_object.find("overrides") != json_object.end())
	{
		LJsonObject overrides = json_object["overrides"].to_object();

		for (const auto& [key, override_val] : overrides)
		{
			LAttribute* override_attr =
				new LAttribute(key, override_val.to_object(), this);

			m_overrides[key] = override_attr;
		}
	}

	on_change(
		[this] {
			m_json_object = to_json_object();
		}
	);
}

LAttribute::LAttribute(const LAttribute& attribute) :
	m_link_path{ attribute.m_link_path },
	m_value{ attribute.m_value },
	LObject()
{
	set_object_name(attribute.object_name());

	if (!attribute.m_overrides.empty())
		for (const auto& [key, override_attr] : attribute.m_overrides)
		{
			LAttribute* copy_override_attr = new LAttribute(*override_attr);

			copy_override_attr->set_parent(this);

			m_overrides[override_attr->object_name()] =
				copy_override_attr;
		}
}

LAttribute::~LAttribute()
{
	if (m_theme_attr)
	{
		m_theme_attr->disconnect_change(m_theme_connection);
	}

	if (m_link_attr)
	{
		m_link_attr->disconnect_destroyed(m_link_destroyed_connection);

		for (auto dep_attr = m_link_attr->m_dependent_attrs.begin();
			dep_attr != m_link_attr->m_dependent_attrs.end(); dep_attr++)
		{
			if (*dep_attr == this)
			{
				dep_attr = m_link_attr->m_dependent_attrs.erase(dep_attr);
				m_link_attr->update_link_dependencies();
				break;
			}
		}

		m_link_attr = nullptr;
	}
}

void LAttribute::create_override(const std::string& name, const char* value)
{
	create_override(name, std::string(value));
}

void LAttribute::create_override(const std::string& name, LVariant value)
{
	LAttribute* override_attr = new LAttribute(name, value, this);

	m_overrides[name] = override_attr;
}

void LAttribute::break_link()
{
	if (m_link_attr)
	{
		m_value = m_link_attr->value();

		m_link_attr->disconnect_destroyed(m_link_destroyed_connection);

		for (auto dep_attr = m_link_attr->m_dependent_attrs.begin();
			dep_attr != m_link_attr->m_dependent_attrs.end(); dep_attr++)
		{
			if (*dep_attr == this)
			{
				dep_attr = m_link_attr->m_dependent_attrs.erase(dep_attr);
				m_link_attr->update_link_dependencies();
				break;
			}
		}

		m_link_attr = nullptr;
		m_link_path = "";
	}

	update_link_dependencies();
	update_dependencies();
}

void LAttribute::clear_overrides()
{
	if (!m_overrides.empty())
	{
		for (const auto& [key, override_attr] : m_overrides)
		{
			remove_child(override_attr);
			delete override_attr;
		}

		m_overrides.clear();
	}
}

void LAttribute::clear_theme_attribute()
{
	if (m_theme_attr)
	{
		m_theme_attr->disconnect_change(m_theme_connection);
		m_theme_attr = nullptr;
	}
}

LAttributeList LAttribute::dependent_attributes(
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

void LAttribute::disconnect_change(LConnectionID connection)
{
	m_change_connections.erase(connection);
}

void LAttribute::disconnect_link_change(LConnectionID connection)
{
	m_link_change_connections.erase(connection);
}

bool LAttribute::has_overrides() const
{
	return !m_overrides.empty();
}

LJsonObject& LAttribute::json_object()
{
	return m_json_object;
}

LAttribute* LAttribute::link_attribute() const
{
	return m_link_attr;
}

std::string LAttribute::link_path() const
{
	return m_link_path;
}

LConnectionID LAttribute::on_change(std::function<void()> callback)
{
	m_change_connections[m_change_connections_next_id++] = callback;
	return std::prev(m_change_connections.end())->first;
}

LConnectionID LAttribute::on_link_change(std::function<void()> callback)
{
	m_link_change_connections[m_link_change_connections_next_id++] = callback;
	return std::prev(m_link_change_connections.end())->first;
}

LAttribute* LAttribute::override_attribute(
	const std::vector<std::string>& state_combo)
{
	for (const auto& [key, override_attr] : m_overrides)
	{
		std::vector<std::string> override_states =
			split<std::vector<std::string>>(override_attr->object_name(), ':');

		bool qualifies = true;

		for (const auto& override_state : override_states)
		{
			if (std::find(state_combo.begin(), state_combo.end(),
				override_state) == state_combo.end())
			{
				qualifies = false;
			}
		}

		if (qualifies)
			return override_attr;
	}

	// TODO: Handle returning override with highest number of matching
	// states. If there is a conflict (two matching overrides), just
	// return the value of this

	return nullptr;
}

LAttributeMap LAttribute::overrides() const
{
	return m_overrides;
}

std::string LAttribute::path() const
{
	if (parent())
	{
		if (LAttribute* parent_attr = dynamic_cast<LAttribute*>(parent()))
			return parent_attr->path() + "." + object_name();
		else if (LThemeable* parent_themeable = dynamic_cast<LThemeable*>(parent()))
			return parent_themeable->path().toStdString() + "/" + object_name();
		else if (LThemeItem* parent_theme_item = dynamic_cast<LThemeItem*>(parent()))
			return parent_theme_item->path() + "/" + object_name();
	}

	return object_name();
}

void LAttribute::set_link_attribute(LAttribute* link_attr)
{
	m_value = LVariant();

	if (m_link_attr)
	{
		m_link_attr->disconnect_destroyed(m_link_destroyed_connection);

		for (auto dep_attr = m_link_attr->m_dependent_attrs.begin();
			dep_attr != m_link_attr->m_dependent_attrs.end(); dep_attr++)
		{
			if (*dep_attr == this)
			{
				dep_attr = m_link_attr->m_dependent_attrs.erase(dep_attr);
				break;
			}
		}

		m_link_attr = nullptr;
	}

	m_link_attr = link_attr;

	m_link_attr->m_dependent_attrs.push_back(this);
	m_link_attr->update_link_dependencies();

	m_link_destroyed_connection = m_link_attr->on_destroyed(
		[this] {
			m_link_attr = nullptr;
		}
	);

	update_link_dependencies();
	update_dependencies();
}

void LAttribute::set_link_path(const std::string& link_path)
{
	m_link_path = link_path;

	m_value = LVariant();
}

void LAttribute::set_theme_attribute(LAttribute* theme_attr)
{
	m_theme_attr = theme_attr;

	m_theme_connection = m_theme_attr->on_change(
		[this] {
			update_dependencies();
		}
	);

	update_dependencies();
}

void LAttribute::set_value(const char* value)
{
	set_value(std::string(value));
}

void LAttribute::set_value(LVariant value)
{
	if (m_link_attr)
	{
		m_link_attr->set_value(value);
		update_dependencies();
	}
	else if (m_value.index() == value.index())
	{
		bool same_value = false;

		switch (m_value.index())
		{
		case 0:
			same_value = true;
			break;
		case 1:
			if (std::get<double>(m_value) == std::get<double>(value))
				same_value = true;
			break;
		case 2:
			if (std::get<bool>(m_value) == std::get<bool>(value))
				same_value = true;
			break;
		case 3:
			if (std::get<std::string>(m_value) == std::get<std::string>(value))
				same_value = true;
			break;
		case 4:
			if (std::get<std::vector<std::string>>(m_value) == std::get<std::vector<std::string>>(value))
				same_value = true;
			break;
		}

		if (same_value)
			return;
	}

	m_value = value;
	update_dependencies();
}

LJsonObject LAttribute::to_json_object()
{
	LJsonObject json_object;

	if (!m_link_path.empty())
	{
		json_object["linked_to"] = m_link_path;
	}
	else if (m_value.index() > 0)
	{
		json_object["value"] = to_json_value();
	}

	if (has_overrides())
	{
		LJsonObject overrides_json_object;

		for (const auto& [key, override_attr] : m_overrides)
			overrides_json_object[override_attr->object_name()] =
				override_attr->to_json_object();

		json_object["overrides"] = overrides_json_object;
	}

	return json_object;
}

LJsonValue LAttribute::to_json_value()
{
	LJsonValue json_value;

	if (bool* bool_val = std::get_if<bool>(&m_value))
		json_value = *bool_val;

	else if (double* double_val = std::get_if<double>(&m_value))
		json_value = *double_val;

	else if (std::string* string_val = std::get_if<std::string>(&m_value))
		json_value = *string_val;

	else if (std::vector<std::string>* gradient_stops_val =
		std::get_if<std::vector<std::string>>(&m_value))
	{
		LJsonArray gradient;

		for (const std::string& stop : *gradient_stops_val)
			gradient.push_back(stop);

		json_value = LJsonObject({ {"gradient", gradient } });
	}

	return json_value;
}

int LAttribute::type_index() const
{
	return m_value.index();
}

LVariant LAttribute::value()
{
	if (m_link_attr)
		return m_link_attr->value();

	return m_value;
}

void LAttribute::update_dependencies()
{
	for (auto& change_function : m_change_connections)
	{
		change_function.second();
	}

	if (this->parent())
	{
		if (LThemeable* t = dynamic_cast<LThemeable*>(this->parent()))
		{
			t->update();
		}
		else if (LAttribute* a = dynamic_cast<LAttribute*>(this->parent()))
		{
			a->update_dependencies();
		}
	}

	if (!m_dependent_attrs.empty())
	{
		for (const auto& dependent_attr : m_dependent_attrs)
		{
			dependent_attr->update_dependencies();
		}
	}
}

void LAttribute::update_link_dependencies()
{
	for (auto& link_change_function : m_link_change_connections)
	{
		link_change_function.second();
	}

	for (LAttribute* dependent_attr : dependent_attributes(true))
	{
		dependent_attr->update_link_dependencies();
	}
}

void LAttribute::update_json_object()
{
	if (!m_link_path.empty())
	{
		m_json_object["linked_to"] = m_link_path;
	}
	else if (m_value.index() > 0)
	{
		m_json_object["value"] = to_json_value();
	}

}
