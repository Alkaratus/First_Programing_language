#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,1),"_",Token::name),
	});
	Parser parser(collection);
	auto object = parser.create_is_conditional_object();
	auto code = object->generate_code();
	if (code==
R"(is _)"){
		return 0;
	}
	return -1;
}