#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,2),'\0',Token::assign),
		Token(Position(File("main.apl"),1,3),"value",Token::open_bracket),
		Token(Position(File("main.apl"),1,4),1,Token::const_int),
		Token(Position(File("main.apl"),1,5),'\0',Token::summation),
		Token(Position(File("main.apl"),1,6),2,Token::const_int),
		Token(Position(File("main.apl"),1,7),'\0',Token::shift_left),
		Token(Position(File("main.apl"),1,8),1,Token::const_int),
		Token(Position(File("main.apl"),1,9),"value",Token::close_bracket),
		Token(Position(File("main.apl"),1,10),'\0',Token::summation),
		Token(Position(File("main.apl"),1,11),3,Token::const_int),
		Token(Position(File("main.apl"),1,12),'\0',Token::multiplication),
		Token(Position(File("main.apl"),1,13),3,Token::const_int),
		Token(Position(File("main.apl"),1,14),'\0',Token::semicolon),
	});
	Parser parser(collection);
	auto object = parser.create_operation_object(std::make_shared<Variable_Call_Object>(Variable_Call_Object(Position(File("main.apl"),1, 1),"test")),true);
	auto code = object->generate_code();
	if (code=="( call_v test = ( ( (int 1 + 2 ) << 1 ) + (int 3 * 3 ) ) ) ") {
		return 0;
	}
	return -1;
}