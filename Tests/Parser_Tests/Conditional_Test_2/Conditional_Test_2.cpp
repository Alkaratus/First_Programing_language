#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_if),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::equal),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,9),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,1),"test2",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::assign),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
		Token(Position(File("main.apl"),1,1),'\0',Token::_else),
		Token(Position(File("main.apl"),1,1),'\0',Token::_if),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::equal),
		Token(Position(File("main.apl"),1,9),2,Token::const_int),
		Token(Position(File("main.apl"),1,9),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,1),"test2",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::assign),
		Token(Position(File("main.apl"),1,9),2,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_conditional_object();
	auto code = object->generate_code();
	if (code==
R"(CONDITIONAL
IF ( ( call_v test == 1 ) )
( call_v test2 = 1 ) 
IF_END
IF ( ( call_v test == 2 ) )
( call_v test2 = 2 ) 
IF_END
CONDITIONAL_END
)") {
		return 0;
	}
	return -1;
}