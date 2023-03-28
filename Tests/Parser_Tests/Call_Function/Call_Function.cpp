#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
	Token(Position(File("main.apl"),20,25),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),20,26),2,Token::const_int),
	Token(Position(File("main.apl"),20,27),'\0',Token::comma),
	Token(Position(File("main.apl"),20,28),3,Token::const_int),
	Token(Position(File("main.apl"),20,29),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),20,30),'\0',Token::semicolon),
	});
	Parser parser(collection);
	auto object = parser.create_function_call_object(Token(Position(File("main.apl"),20, 20), "power", Token::name));
	auto code = object->generate_code();
	if (code == "call_f power ( 2 3 ) ") {
		return 0;
	}
	return -1;
}