#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({
		Token(Position(File("main.apl"),1,1),'\0',Token::_return),
		Token(Position(File("main.apl"),1,1),0,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		});
	Parser parser(collection);
	auto object=parser.create_return_object();
	auto code = object->generate_code();
	if (code == "return int 0 ") {
		return 0;
	}
	return -1;
}