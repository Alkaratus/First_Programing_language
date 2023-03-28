#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,1),'\0',Token::in),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),0,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::comma),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_is_conditional_object();
	auto code = object->generate_code();
	if (code==
R"(is (void in colection { 0 1 } ) )"){
		return 0;
	}
	return -1;
}