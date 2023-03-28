#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),1,Token::const_int),
	});
	Parser parser(collection);
	auto object=parser.create_int_object(true);
	auto code = object->generate_code();
	if (code == "-1 ") {
		return 0;
	}
	return -1;
}