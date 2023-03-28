#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
	});
	Parser parser(collection);
	auto object = parser.create_constans_begin_declarations_object(Token::_float, Token(Position(File("main.apl"),1, 9), "value", Token::name));
	auto code = object->generate_code();
	if (code == "declare float const value 0.000000 \n") {
		return 0;
	}
	return -1;
}