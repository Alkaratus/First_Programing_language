#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({
		Token(Position(File("main.apl"),6,29),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),6,30),0,Token::const_int),
		Token(Position(File("main.apl"),6,31),'\0',Token::comma),
		Token(Position(File("main.apl"),6,32),2,Token::const_int),
		Token(Position(File("main.apl"),6,39),'\0',Token::close_bracket),
		});
	Parser parser(collection);
	auto object=parser.create_zone_object();
	auto code = object->generate_code();
	if (code == "zone ( 0 2 ) ") {
		return 0;
	}
	return -1;
}