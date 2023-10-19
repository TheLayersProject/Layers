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

#include <Layers/ljson.h>

#include <algorithm>
#include <iterator>
#include <stdexcept>

using Layers::LJsonArray;
using Layers::LJsonLexer;
using Layers::LJsonObject;
using Layers::LJsonParser;
using Layers::LJsonToken;
using Layers::LJsonValue;

LJsonLexer::LJsonLexer(const std::string& input) :
	m_input{ input }, m_pos{ 0 } {}

LJsonToken LJsonLexer::get_next_token()
{
	std::string token_value;

	LJsonToken token;

	do
	{
		if (m_pos == m_input.size())
		{
			token.type = LJsonTokenType::END;
			return token;
		}

		token_value += m_input[m_pos++];

		token = _build_token(token_value);
	}
	while (token.type == LJsonTokenType::INVALID);

	return token;
}

LJsonToken LJsonLexer::_build_token(std::string value)
{
	LJsonToken token;

	/* Determine Token Type */

	if (value == "{")
	{
		token.type = LJsonTokenType::LBRACE;
	}
	else if (value == "}")
	{
		token.type = LJsonTokenType::RBRACE;
	}
	else if (value == "[")
	{
		token.type = LJsonTokenType::LBRACKET;
	}
	else if (value == "]")
	{
		token.type = LJsonTokenType::RBRACKET;
	}
	else if (value == ":")
	{
		token.type = LJsonTokenType::COLON;
	}
	else if (value == ",")
	{
		token.type = LJsonTokenType::COMMA;
	}
	else if (
		std::count(value.begin(), value.end(), '"') == 2 &&
		value.front() == '"' && value.back() == '"')
	{
		token.type = LJsonTokenType::STRING;
	}
	else if (std::all_of(value.begin(), value.end(),
		[](char c) { return std::isdigit(c); }))
	{
		/*
			The above checks if all of the characters in 'value' are digits to
			decide if it contains a number. This check alone would cause every
			individual digit to be passed as 'NUMBER' tokens.
			
			An additional check is needed to determine if the next input
			character is also a digit. In that case, the token type should
			remain as 'INVALID' so that the next digit is included as part of
			the entire number.
		*/
		if (m_pos < m_input.size() &&
			!std::isdigit(m_input[m_pos]))
		{
			token.type = LJsonTokenType::NUMBER;
		}
	}
	else if (value == "true")
	{
		token.type = LJsonTokenType::TRUE;
	}
	else if (value == "false")
	{
		token.type = LJsonTokenType::FALSE;
	}
	else if (value == "null")
	{
		token.type = LJsonTokenType::NONE;
	}

	/* Set Token Value */

	if (token.type != LJsonTokenType::INVALID)
		token.value = value;

	return token;
}

LJsonParser::LJsonParser(const LJsonLexer& lexer) :
	m_lexer{ lexer }, m_current_token{ m_lexer.get_next_token() } {}

LJsonArray LJsonParser::parse_array()
{
	match(LJsonTokenType::LBRACKET);

	LJsonArray array = parse_value_list();

	match(LJsonTokenType::RBRACKET);

	return array;
}

LJsonObject LJsonParser::parse_object()
{
	match(LJsonTokenType::LBRACE);

	LJsonObject object = parse_pair_list();

	match(LJsonTokenType::RBRACE);

	return object;
}

LJsonObject LJsonParser::parse_pair_list()
{
	LJsonObject object;

	while (m_current_token.type != LJsonTokenType::RBRACE)
	{
		std::string key = m_current_token.value;

		match(LJsonTokenType::STRING);

		match(LJsonTokenType::COLON);

		object.insert({ key, parse_value() });

		if (m_current_token.type == LJsonTokenType::COMMA)
			next_token();
	}

	return object;
}

LJsonValue LJsonParser::parse_value()
{
	LJsonToken value_token = m_current_token;

	if (m_current_token.type == LJsonTokenType::STRING)
	{
		next_token();
		return LJsonValue(value_token.value);
	}
	else if (m_current_token.type == LJsonTokenType::NUMBER)
	{
		next_token();
		return LJsonValue(std::stoi(value_token.value));
	}
	else if (m_current_token.type == LJsonTokenType::LBRACE)
		return LJsonValue(parse_object());
	else if (m_current_token.type == LJsonTokenType::LBRACKET)
		return LJsonValue(parse_array());

	return LJsonValue();
}

LJsonArray LJsonParser::parse_value_list()
{
	LJsonArray array;

	while (m_current_token.type != LJsonTokenType::RBRACKET)
	{
		array.push_back(parse_value());

		if (m_current_token.type == LJsonTokenType::COMMA)
		{
			next_token();
			LJsonArray sub_value_list;
			std::copy(
				sub_value_list.begin(), sub_value_list.end(),
				std::back_inserter(array));
		}
	}

	return array;
}

void LJsonParser::match(LJsonTokenType expected_type)
{
	if (m_current_token.type == expected_type)
		next_token();
	else
		throw std::runtime_error("Parsing error!");
			//"Parsing error: Expected " + tokenTypeToString(expected_type) +
			//", but found " + tokenTypeToString(m_current_token.type));
}

void LJsonParser::next_token()
{
	m_current_token = m_lexer.get_next_token();
}

LJsonValue::LJsonValue() {}

LJsonValue::LJsonValue(std::string value) :
	m_variant{ value } {}

LJsonValue::LJsonValue(int value) :
	m_variant{ value } {}

LJsonValue::LJsonValue(LJsonObject value) :
	m_variant{ value } {}

LJsonValue::LJsonValue(LJsonArray value) :
	m_variant{ value } {}
