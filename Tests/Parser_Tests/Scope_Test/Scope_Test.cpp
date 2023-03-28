#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"test",Token::open_buckle),
		Token(Position(File("main.apl"),1,1),"test",Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_scope();
	if (object.get_statements().empty()) {
		return 0;
	}
	return -1;
}