#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'a',Token::const_char),
	});
	Parser parser(collection);
	auto object=parser.create_char_object();
	auto code = object->generate_code();
	if (code == "'97' ") {
		return 0;
	}
	return -1;
}