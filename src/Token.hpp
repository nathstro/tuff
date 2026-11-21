#pragma once
#include <any>
#include <string>

enum class TokenType {
	ENDLINE,							// emoji
	LEFT_PAREN, RIGHT_PAREN, 			// bruh idk
	LEFT_BRACE, RIGHT_BRACE,			// { } for blocks
	COMMA, COLON, DOT, ASSIGN,			// , : pls being
	EQ, NE, GREATER, GE, LESSER, LE,	// be aint highkey highkenuinely lowkey lowkenuinely
	PLUS, MINUS, STAR, SLASH, PERCENT, 	// gaining losing maxxing rotting aura

	IDENTIFIER, STRING, NUM, 			// literals

	AND, OR, NOT, NIL, TRUE, FALSE, LET,	// and or not chopped frfr cap larp
	IF, THEN, ELSE,	FOR, WHILE, DO,			// chat fr cooked yo let cook
	FUNC, RETURN_1, RETURN_2,				// yo let_him_cook fr bro its_giving
	CLASS, THIS, EXTENDS, SUPER,			// brainrot ts larping mommy
	PRINT, ENDSECTION,						// yap {period, ong, son, sybau}
	
	END
};

struct Token
{
	TokenType type;
	std::string lexeme;
	int line;
	std::any literal;

	Token(TokenType type, const std::string& lexeme, int line)
		: type(type), lexeme(lexeme), line(line)
		{}
	Token(TokenType type, const std::string& lexeme, int line, const std::any& literal)
		: type(type), lexeme(lexeme), line(line), literal(literal)
		{}
};