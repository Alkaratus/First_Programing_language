#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"test",Token::null),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,2),'\0',Token::assign),
		Token(Position(File("main.apl"),1,6),3,Token::const_int),
		Token(Position(File("main.apl"),1,2),'\0',Token::semicolon),
	});
	Parser parser(collection);
	auto object = parser.create_next_variable(Token::_int);
	auto code = object.generate_code();
	if (code == "declare int const test 3 ") {
		return 0;
	}
	return -1;
}