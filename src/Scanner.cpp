#include "Scanner.hpp"
#include "Token.hpp"
#include "ErrorHandler.hpp"
#include <iostream>

std::vector<Token> Scanner::scanTokens()
{
	while (!atEnd())
	{
		start = current;
		scanToken();
	}

	tokens.emplace_back(TokenType::END, "", line);

	return tokens;
}

char Scanner::advance()
{
	return source.at(current++);
}

char Scanner::peek()
{
	if (atEnd()) return '\0';
	return source.at(current);
}

char Scanner::peekNext()
{
	if (current + 1 >= source.length()) return '\0';
	return source.at(current + 1);
}

bool Scanner::isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool Scanner::isAlpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool Scanner::isAlnum(char c)
{
	return isDigit(c) || isAlpha(c);
}

void Scanner::scanToken()
{
	char c = advance();
	switch (c)
	{
		case '#': comment(); break;
		case '{':
			addToken(TokenType::LEFT_BRACE);
			break;
		case '}':
			addToken(TokenType::RIGHT_BRACE);
			break;
		case ',': addToken(TokenType::COMMA); break;
		case ':': addToken(TokenType::COLON); break;

		case ' ': 
		case '\r':
		case '\t':
			break;

		case '\n': line++; break;

		case '*': string(); break;

		default:
			if (isDigit(c))
				number();
			else if (isAlpha(c))
				identifier();
			else if (static_cast<unsigned char>(c) >= 0x80)
				emoji();
			else
				ErrorHandler::error(line, "fym " + std::string(1, c) + " 😭");
			break; 
	}
}

void Scanner::string()
{
	while (peek() != '*' && !atEnd())
	{
		if (peek() == '\n') line++;
		advance();
	}

	if (atEnd())
	{
		ErrorHandler::error(line, "Unclosed string. ");
		return;
	}

	advance();

	std::string value = source.substr(start + 1, current - start - 2);
	addToken(TokenType::STRING, value);
}

void Scanner::number()
{
	while (isDigit(peek())) advance();

	if (peek() == '.' && isDigit(peekNext()))
	{
		advance();
		while (isDigit(peek())) advance();
	}
	
	double value = std::stod(source.substr(start, current - start));
	addToken(TokenType::NUM, value);
}

void Scanner::identifier()
{
	while (isAlnum(peek()))
		advance();

	std::string value = source.substr(start, current - start);
	if (keywords.count(value) > 0)
		addToken(keywords.at(value));
	else
		addToken(TokenType::IDENTIFIER, value);
}

void Scanner::comment()
{
	while (peek() != '\n' && !atEnd())
	{
		advance();
	}
}

bool Scanner::match(char expected)
{
	if (atEnd()) return false;
	if (source.at(current) != expected) return false;

	current++;
	return true;
}

void Scanner::addToken(TokenType type)
{
	std::string text = source.substr(start, current - start);
	tokens.emplace_back(type, text, line);
}

void Scanner::addToken(TokenType type, double numconst)
{
	std::string text = source.substr(start, current - start);
	tokens.emplace_back(type, text, line, numconst);
}

void Scanner::addToken(TokenType type, std::string strconst)
{
	std::string text = source.substr(start, current - start);
	tokens.emplace_back(type, text, line, strconst);
}

void Scanner::emoji()
{
	unsigned char first = static_cast<unsigned char>(source[current]);
	int length = utf8CharLength(first);

	if (length == 0) return;

	for (int i = 1; i < length; i++)
	{
		if (current + i >= source.length())
			return;

		unsigned char byte =
			static_cast<unsigned char>(source[current + i]);

		// Continuation bytes must be 10xxxxxx
		if ((byte & 0xC0) != 0x80)
			return;
	}

	current += length;

	addToken(TokenType::ENDLINE);
}

int Scanner::utf8CharLength(unsigned char c)
{
	if ((c & 0x80) == 0x00) return 1; // ASCII
	if ((c & 0xE0) == 0xC0) return 2;
	if ((c & 0xF0) == 0xE0) return 3;
	if ((c & 0xF8) == 0xF0) return 4;

	return 0; // invalid UTF-8
}
