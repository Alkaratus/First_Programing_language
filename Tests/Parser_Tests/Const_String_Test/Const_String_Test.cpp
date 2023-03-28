#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"text",Token::const_string),
	});
	Parser parser(collection);
	auto object=parser.create_string_object();
	auto code = object->generate_code();
	if (code == "\"text\" ") {
		return 0;
	}
	return -1;
}