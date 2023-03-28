#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"


int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"test",Token::open_bracket),
		Token(Position(File("main.apl"),1,1),"test",Token::close_bracket),
	});
	Parser parser(collection);
	auto object = parser.create_list_of_arguments();
	if (object.empty()) {
		return 0;
	}
	return -1;
}