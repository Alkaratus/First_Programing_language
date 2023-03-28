#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({
		Token(Position(File("main.apl"),19, 34), '\0', Token::open_buckle),
		Token(Position(File("main.apl"),19, 35), 0.5, Token::const_float),
		Token(Position(File("main.apl"),19, 35), '\0', Token::comma),
		Token(Position(File("main.apl"),19, 47), 1.5, Token::const_float),
		Token(Position(File("main.apl"),19, 58), '\0', Token::close_buckle),
		});
	Parser parser(collection);
	auto object=parser.create_colection_object();
	auto code = object->generate_code();
	if (code == "colection { 0.500000 1.500000 } ") {
		return 0;
	}
	return -1;
}