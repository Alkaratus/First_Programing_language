#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_void),
		Token(Position(File("main.apl"),1,9),"func",Token::name),
		Token(Position(File("main.apl"),1,17),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,17),'\0',Token::_float),
		Token(Position(File("main.apl"),1,9),"arg2",Token::name),
		Token(Position(File("main.apl"),1,9),'\0',Token::comma),
		Token(Position(File("main.apl"),1,17),'\0',Token::_int),
		Token(Position(File("main.apl"),1,17),'\0',Token::var),
		Token(Position(File("main.apl"),1,9),"arg",Token::name),
		Token(Position(File("main.apl"),1,18),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,19),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,19),'\0',Token::close_buckle)
	});
	Parser parser(collection);
	auto object = parser.create_void_function();
	auto code = object->generate_code();
	if (code==
R"(FUNCTION void func 
ARGUMENTS
declare float const arg2 
declare int var arg 
ARGUMENTS_END
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}