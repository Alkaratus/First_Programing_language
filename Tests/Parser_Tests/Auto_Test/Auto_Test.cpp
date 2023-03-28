#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_auto),
		Token(Position(File("main.apl"),1,9),"value",Token::name),
		Token(Position(File("main.apl"),1,17),'\0',Token::assign), 
		Token(Position(File("main.apl"),1,18),3,Token::const_int),
		Token(Position(File("main.apl"),1,19),'\0',Token::semicolon)
	});
	Parser parser(collection);
	auto object=parser.create_auto_variable_object();
	auto code = object->generate_code();
	if (code == "declare int const value 3 ") {
		return 0;
	}
	return -1;
}