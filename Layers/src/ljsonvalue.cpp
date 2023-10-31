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

#include <Layers/ljsonvalue.h>

#include <sstream>

using Layers::LJsonArray;
using Layers::LJsonObject;
using Layers::LJsonValue;
using Layers::LString;

class LJsonValue::Impl {
public:
	Impl() {}

	Impl(bool v) :
		m_variant{ v } {}

	Impl(double v) :
		m_variant{ v } {}

	Impl(const LString& v) :
		m_variant{ v } {}

	Impl(const LJsonObject& v) :
		m_variant{ v } {}

	Impl(const LJsonArray& v) :
		m_variant{ v } {}

	bool is_bool() const
	{
		return std::get_if<bool>(&m_variant);
	}

	bool is_double() const
	{
		return std::get_if<double>(&m_variant);
	}

	bool is_object() const
	{
		return std::get_if<LJsonObject>(&m_variant);
	}

	bool is_string() const
	{
		return std::get_if<LString>(&m_variant);
	}

	LJsonArray to_array() const
	{
		return std::get<LJsonArray>(m_variant);
	}

	bool to_bool() const
	{
		return std::get<bool>(m_variant);
	}

	double to_double() const
	{
		return std::get<double>(m_variant);
	}

	LJsonObject to_object() const
	{
		return std::get<LJsonObject>(m_variant);
	}

	LString to_string() const
	{
		return std::get<LString>(m_variant);
	}

	LString to_output(
		int indent_space_count, int indent_level) const
	{
		std::ostringstream oss;
		std::string indent(indent_level * indent_space_count, ' ');

		if (auto string_val = std::get_if<LString>(&m_variant))
		{
			return "\"" + *string_val + "\"";
		}
		else if (auto object_val = std::get_if<LJsonObject>(&m_variant))
		{
			oss << "{\n";
			for (const auto& [key, value] : *object_val)
			{
				oss << indent << std::string(indent_space_count, ' ')
					<< "\"" << key << "\": "
					<< value.to_output(indent_space_count, indent_level + 1)
					<< ",\n";
			}
			if (!object_val->empty())
			{
				auto str = oss.str();
				// Remove trailing comma and newline
				str = str.substr(0, str.length() - 2);
				oss.str("");
				oss << str;
			}
			oss << "\n" << indent << "}";
			return oss.str().c_str();
		}
		else if (auto double_val = std::get_if<double>(&m_variant))
		{
			oss << *double_val;
			return oss.str().c_str();
		}
		else if (auto bool_val = std::get_if<bool>(&m_variant))
		{
			return *bool_val ? "true" : "false";
		}
		else if (auto array_val = std::get_if<LJsonArray>(&m_variant))
		{
			oss << "[\n";
			for (const auto& val : *array_val)
			{
				oss << indent << std::string(indent_space_count, ' ')
					<< val.to_output(indent_space_count, indent_level + 1)
					<< ",\n";
			}
			if (!array_val->empty())
			{
				auto str = oss.str();
				// Remove trailing comma and newline
				str = str.substr(0, str.length() - 2);
				oss.str("");
				oss << str;
			}
			oss << "\n" << indent << "]";
			return oss.str().c_str();
		}

		return "";
	}

	LJsonVariant m_variant;
};

LJsonValue::LJsonValue() :
	pimpl{ new Impl() } {}

LJsonValue::LJsonValue(bool v) :
	pimpl{ new Impl(v) } {}

LJsonValue::LJsonValue(double v) :
	pimpl{ new Impl(v) } {}

LJsonValue::LJsonValue(const char* v) :
	pimpl{ new Impl(LString(v)) } {}

LJsonValue::LJsonValue(const LString& v) :
	pimpl{ new Impl(v) } {}

LJsonValue::LJsonValue(const LJsonObject& v) :
	pimpl{ new Impl(v) } {}

LJsonValue::LJsonValue(const LJsonArray& v) :
	pimpl{ new Impl(v) } {}

LJsonValue::LJsonValue(const LJsonValue& other) :
	pimpl{ new Impl(*(other.pimpl)) } {}

LJsonValue::LJsonValue(LJsonValue&& other) noexcept :
	pimpl{ std::exchange(other.pimpl, nullptr) } {}

LJsonValue::~LJsonValue()
{
	delete pimpl;
}

bool LJsonValue::is_bool() const
{
	return pimpl->is_bool();
}

bool LJsonValue::is_double() const
{
	return pimpl->is_double();
}

bool LJsonValue::is_object() const
{
	return pimpl->is_object();
}

bool LJsonValue::is_string() const
{
	return pimpl->is_string();
}

LJsonArray LJsonValue::to_array() const
{
	return pimpl->to_array();
}

bool LJsonValue::to_bool() const
{
	return pimpl->to_bool();
}

double LJsonValue::to_double() const
{
	return pimpl->to_double();
}

LJsonObject LJsonValue::to_object() const
{
	return pimpl->to_object();
}

LString LJsonValue::to_string() const
{
	return pimpl->to_string();
}

LString LJsonValue::to_output(
	int indent_space_count, int indent_level) const
{
	return pimpl->to_output(indent_space_count, indent_level);
}

LJsonValue& LJsonValue::operator=(const LJsonValue& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete pimpl;
	pimpl = new Impl(*other.pimpl);
	return *this;
}

LJsonValue& LJsonValue::operator=(LJsonValue&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	delete pimpl;
	pimpl = std::exchange(other.pimpl, nullptr);
	return *this;
}
