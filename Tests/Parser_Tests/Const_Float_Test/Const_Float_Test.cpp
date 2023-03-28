#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),0.75,Token::const_float),
	});
	Parser parser(collection);
	auto object=parser.create_float_object(false);
	auto code = object->generate_code();
	if (code == "0.750000 ") {
		return 0;
	}
	return -1;
}