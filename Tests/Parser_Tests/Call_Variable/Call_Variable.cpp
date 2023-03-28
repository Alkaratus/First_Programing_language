#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
	});
	Parser parser(collection);
	auto object = parser.create_variable_call_object(Token(Position(File("main.apl"),1, 1), "test", Token::name));
	auto code = object->generate_code();
	if (code == "call_v test ") {
		return 0;
	}
	return -1;
}