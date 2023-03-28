#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::var),
		Token(Position(File("main.apl"),1,9),"value",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
	});
	Parser parser(collection);
	auto object = parser.create_variable_begin_declarations_object(Token::_string);
	auto code = object->generate_code();
	if (code == R"(declare string var value "" 
)") {
		return 0;
	}
	return -1;
}