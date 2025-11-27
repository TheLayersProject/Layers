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

#include <Layers/ltheme.h>

#include <fstream>

#include <Layers/lalgorithms.h>
#include <Layers/lattribute.h>
#include <Layers/lgenerate.h>
#include <Layers/lcontroller.h>

using Layers::LAttribute;
using Layers::LAttributeMap;
using Layers::LString;
using Layers::LTheme;
using Layers::LController;
using Layers::LStyle;

class LTheme::Impl
{
public:
	Impl() {}

	Impl(const LString& name, bool editable = true) :
		m_uuid{ generate_uuid() },
		m_editable{ editable } {}

	Impl(const LString& name, const LString& uuid, bool editable) :
		m_uuid{ uuid },
		m_editable{ editable } {}

	void append_to_lineage(const LString& theme_id)
	{
		m_lineage.push_back(theme_id);
	}

	std::filesystem::path directory() const
	{
		return m_path;
	}

	bool editable() const
	{
		return m_editable;
	}

	bool has_implementation(const LString& app_display_id) const
	{
		std::filesystem::path dir_path = m_path / app_display_id;
		return std::filesystem::exists(dir_path);
	}

	std::vector<LString> lineage() const
	{
		return m_lineage;
	}

	void save_meta_file()
	{
		json json_object;
        json lineage_array = json::array();

		for (const auto& theme_id : m_lineage)
		{
			lineage_array.push_back(theme_id);
		}

		json_object["lineage"] = lineage_array;
		json_object["uuid"] = m_uuid;

		if (!publisher.empty())
		{
			json_object["publisher"] = publisher;
		}

		//LJsonValue json_value(json_object);

		std::ofstream meta_file(m_path / "meta.json");

		if (!meta_file.is_open())
		{
			std::cerr << "Could not create theme 'meta.json' file" << std::endl;
			return;
		}

		//meta_file << json_value.to_output();
		meta_file << json_object.dump(4);
		meta_file.close();
	}

	void set_dir(const std::filesystem::path& directory)
	{
		m_path = directory;
	}

	void set_edit_mode_enabled(bool enabled)
	{
		m_edit_mode_enabled = enabled;
	}

	LString uuid() const
	{
		return m_uuid;
	}

	std::filesystem::path m_path;

	bool m_editable{ true };
	bool m_edit_mode_enabled{ false };

	std::vector<LString> m_lineage;

	LString publisher;
	LString m_uuid;
};

LTheme::LTheme() :
	pimpl{ new Impl() }, LStyle()
{
	Layers::lMake<LAttribute>(this, "Foreground", "#000000");
	Layers::lMake<LAttribute>(this, "Gradient", LVariant(std::vector<LString>({ "0:#ffffff", "1:#ffffff" })));
	Layers::lMake<LAttribute>(this, "Primary", "#ffffff");
	Layers::lMake<LAttribute>(this, "Secondary", "#ffffff");
	Layers::lMake<LAttribute>(this, "Tertiary", "#ffffff");
}

LTheme::LTheme(const LString& name, const LString& publisher) :
	LTheme()
{
	set_object_name(name);
	set_publisher(publisher);
	pimpl->m_uuid = generate_uuid();
}

LTheme::LTheme(
	const LString& name,
	const json& value,
	const std::filesystem::path& file_path) :
	pimpl{ new Impl() },
	LStyle(name, value, file_path)
{
	pimpl->m_path = file_path.parent_path();

	if (value.is_object())
	{
		//LJsonObject object = value.to_object();

		if (value.contains("_meta"))
		{
			const auto& meta_object = value["_meta"];

			if (meta_object.contains("publisher"))
                set_publisher(meta_object["publisher"].get<std::string>());
            
            if (meta_object.contains("uuid"))
                pimpl->m_uuid = meta_object["uuid"].get<std::string>();
		}
	}
}

LTheme::~LTheme()
{
	delete pimpl;
}

void LTheme::append_to_lineage(const LString& theme_id)
{
	pimpl->append_to_lineage(theme_id);
}

std::filesystem::path LTheme::directory() const
{
	return pimpl->directory();
}

LString LTheme::display_id() const
{
	if (!pimpl->publisher.empty())
	{
		return object_name() + " (" + pimpl->publisher + ")";
	}
	else if (!pimpl->m_uuid.empty())
	{
		return object_name() + " (" + pimpl->m_uuid + ")";
	}

	return object_name();
}

bool LTheme::editable() const
{
	return pimpl->editable();
}

bool LTheme::has_implementation(const LString& app_display_id) const
{
	return pimpl->has_implementation(app_display_id);
}

std::vector<LString> LTheme::lineage() const
{
	return pimpl->lineage();
}

LString LTheme::publisher() const
{
	return pimpl->publisher;
}

void LTheme::set_publisher(const LString& publisher)
{
	pimpl->publisher = publisher;
}

void LTheme::save()
{
	if (!std::filesystem::exists(directory()))
	{
		std::filesystem::create_directory(directory());
	}

	std::ofstream theme_file(directory() / "theme.json");
	if (!theme_file.is_open())
	{
		std::cerr << "Could not write theme file: " << file_name() << std::endl;
		return;
	}

	theme_file << to_json_object().dump(4);
	theme_file.close();
}

void LTheme::save_meta_file()
{
	pimpl->save_meta_file();
}

void LTheme::set_dir(const std::filesystem::path& directory)
{
	pimpl->set_dir(directory);
}

void LTheme::set_edit_mode_enabled(bool enabled)
{
	pimpl->set_edit_mode_enabled(enabled);
}

LString LTheme::uuid() const
{
	return pimpl->uuid();
}

json LTheme::to_json_object() const
{
    json meta_object;
    meta_object["publisher"] = pimpl->publisher;
    meta_object["uuid"] = pimpl->m_uuid;

    // Call base class LStyle to get the style definition JSON
    json theme_object = LStyle::to_json_object();
    theme_object["_meta"] = meta_object;

    // Wrap in the theme name key
    json object;
    object[object_name()] = theme_object;

    return object;
}
