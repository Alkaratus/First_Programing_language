#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({
		Token(Position(File("main.apl"),1, 1), '\0', Token::open_bracket),
		Token(Position(File("main.apl"),1, 1), "test", Token::name),
		Token(Position(File("main.apl"),1, 1), '\0', Token::close_bracket)
	});
	Parser parser(collection);
	auto object = parser.check_bracket_and_create_operative();
	auto code = object->generate_code();
	if (code == "call_v test ") {
		return 0;
	}
	return -1;
}