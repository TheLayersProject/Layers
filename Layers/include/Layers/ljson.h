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

#ifndef LJSON_H
#define LJSON_H

#include <map>
#include <string>

#include "layers_global.h"

#include "ljsonvalue.h"
#include "lstring.h"

LAYERS_NAMESPACE_BEGIN

enum class LJsonTokenType
{
	INVALID,
	LBRACE, RBRACE,
	LBRACKET, RBRACKET,
	COLON, COMMA,
	STRING, NUMBER,
	T, F,
	NONE, END
};

class LJsonToken
{
public:
	LJsonTokenType type{ LJsonTokenType::INVALID };
	std::string value;
};

class LJsonLexer
{
public:
	LJsonLexer(const std::string& input);

	LJsonToken get_next_token();

private:
	LJsonToken _build_token(std::string value);

	std::string m_input;
	size_t m_pos;
};

class LJsonParser {
public:
	LJsonParser(const LJsonLexer& lexer);

	LJsonArray parse_array();
	LJsonObject parse_object();
	LJsonObject parse_pair_list();
	LJsonValue parse_value();
	LJsonArray parse_value_list();

private:
	void match(LJsonTokenType expected_type);

	void next_token();

	LJsonLexer m_lexer;
	LJsonToken m_current_token;
};

LAYERS_NAMESPACE_END

#endif // LJSON_H