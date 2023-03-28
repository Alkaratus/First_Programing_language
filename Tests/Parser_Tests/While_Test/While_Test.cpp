#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_while),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::grader_than),
		Token(Position(File("main.apl"),1,9),0,Token::const_int),
		Token(Position(File("main.apl"),1,9),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::assign),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,9),'\0',Token::subtraction),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_while_object();
	auto code = object->generate_code();
	if (code==
R"(WHILE ( ( call_v test > 0 ) )
( call_v test = ( call_v test - 1 ) ) 
WHILE_END
)"){
		return 0;
	}
	return -1;
}