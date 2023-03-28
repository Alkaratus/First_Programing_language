#pragma once
#include <stdexcept>
#include <string>
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::_auto),
		Token(Position(File("main.apl"),1,9),"value",Token::name),
		Token(Position(File("main.apl"),1,19),'\0',Token::semicolon)
	});
	Parser parser(collection);
	try {
		auto object = parser.parse_in_scope();
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 19 Auto-type variable have to be initialized") {
			return 0;
		}
	}
	return -1;
}