#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({
		Token(Position(File("main.apl"),1,1),'\0',Token::_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::var),
		Token(Position(File("main.apl"),1,9),"value",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::assign),
		Token(Position(File("main.apl"),1,9),"test",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		});
	Parser parser(collection);
	auto object=parser.parse_in_scope();
	auto code = object->generate_code();
	if (code == "declare int var value call_v test \n") {
		return 0;
	}
	return -1;
}