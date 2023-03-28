#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),11,17),"is",Token::is),
		Token(Position(File("main.apl"),11,20),'\0',Token::grader_than),
		Token(Position(File("main.apl"),11,21), 0, Token::const_int),
	});
	Parser parser(collection);
	auto object = parser.create_is_conditional_object();
	auto code = object->generate_code();
	if (code==
R"(is (int > 0 ) )"){
		return 0;
	}
	return -1;
}