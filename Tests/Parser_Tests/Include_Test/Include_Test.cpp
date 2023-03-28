#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(),"include",Token::include),
		Token(Position(),"io.apl",Token::const_string),
		Token(Position(),'\0',Token::semicolon), 
	});
	Parser parser(collection);
	auto parsed_object=parser.create_include_object();
	if (parsed_object->get_name() == "io.apl") {
		return 0;
	}
	return -1;
}