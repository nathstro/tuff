#pragma once
#include <unordered_map>
#include <string>
#include <vector>

#include "Token.hpp"

class Scanner 
{
	private:
		std::string source;
		std::vector<Token> tokens;
		std::unordered_map<std::string, TokenType> keywords;
		bool ignoreNewlines;

		int start = 0;
		int current = 0;
		int line = 1;

		bool atEnd() { return current >= source.length(); };
		char advance();
		bool match(char expected);
		char peek();
		char peekNext();
		bool isDigit(char c);
		bool isAlpha(char c);
		bool isAlnum(char c);

		void string();
		void number();
		void identifier();
		void comment();
		void emoji();
		int utf8CharLength(unsigned char c);

		void scanToken();
		void addToken(TokenType type);
		void addToken(TokenType type, double numconst);
		void addToken(TokenType type, std::string strconst);

	public:
		Scanner(std::string source) : source(source), ignoreNewlines(false)
		{
			keywords.emplace("and", TokenType::AND);
			keywords.emplace("or", TokenType::OR);
			keywords.emplace("not", TokenType::NOT);
			keywords.emplace("chopped", TokenType::NIL);
			keywords.emplace("frfr", TokenType::TRUE);
			keywords.emplace("cap", TokenType::FALSE);
			keywords.emplace("larp", TokenType::LET);
			keywords.emplace("chat", TokenType::IF);
			keywords.emplace("fr", TokenType::THEN);
			keywords.emplace("cooked", TokenType::ELSE);
			keywords.emplace("yo", TokenType::FOR);
			keywords.emplace("let", TokenType::WHILE);
			keywords.emplace("cook", TokenType::DO);
			keywords.emplace("bro", TokenType::FUNC);
			keywords.emplace("its", TokenType::RETURN_1);
			keywords.emplace("giving", TokenType::RETURN_2);
			keywords.emplace("brainrot", TokenType::CLASS);
			keywords.emplace("period", TokenType::ENDSECTION);
			keywords.emplace("ong", TokenType::ENDSECTION);
			keywords.emplace("sybau", TokenType::ENDSECTION);
			keywords.emplace("son", TokenType::ENDSECTION);
			keywords.emplace("ts", TokenType::THIS);
			keywords.emplace("mommy", TokenType::SUPER);
			keywords.emplace("larping", TokenType::EXTENDS);
			keywords.emplace("yap", TokenType::PRINT);
			keywords.emplace("bruh", TokenType::LEFT_PAREN);
			keywords.emplace("idk", TokenType::RIGHT_PAREN);
			keywords.emplace("pls", TokenType::DOT);
			keywords.emplace("being", TokenType::ASSIGN);
			keywords.emplace("lowkey", TokenType::LESSER);
			keywords.emplace("lowkenuinely", TokenType::LE);
			keywords.emplace("highkey", TokenType::GREATER);
			keywords.emplace("highkenuinely", TokenType::GE);
			keywords.emplace("be", TokenType::EQ);
			keywords.emplace("aint", TokenType::NE);
			keywords.emplace("gaining", TokenType::PLUS);
			keywords.emplace("losing", TokenType::MINUS);
			keywords.emplace("maxxing", TokenType::STAR);
			keywords.emplace("rotting", TokenType::SLASH);
			keywords.emplace("aura", TokenType::PERCENT);
		};
		std::vector<Token> scanTokens();
};