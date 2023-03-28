#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_if),
		Token(Position(File("main.apl"),1,2),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,3),"test",Token::name),
		Token(Position(File("main.apl"),1,4),'\0',Token::in),
		Token(Position(File("main.apl"),1,5),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,6),0,Token::const_int),
		Token(Position(File("main.apl"),1,7),'\0',Token::comma),
		Token(Position(File("main.apl"),1,8),1,Token::const_int),
		Token(Position(File("main.apl"),1,9),'\0',Token::close_buckle),
		Token(Position(File("main.apl"),1,10),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,11),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,12),"test",Token::name),
		Token(Position(File("main.apl"),1,13),'\0',Token::assign),
		Token(Position(File("main.apl"),1,14),2,Token::const_int),
		Token(Position(File("main.apl"),1,15),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,16),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_if_object();
	auto code = object.generate_code();
	if (code==
R"(IF (char In_Set ( call_v test colection { 0 1 } ) )
( call_v test = 2 ) 
IF_END
)"){
		return 0;
	}
	return -1;
}