#pragma once
#include <stdexcept>
#include <string>
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"include",Token::include),
		Token(Position(File("main.apl"),1,8),'\0',Token::semicolon), 
	});
	Parser parser(collection);
	try {
		parser.create_include_object();
	}
	catch(std::invalid_argument& e){
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 8 Unexpected token, expected name") {
			return 0;
		}	
	}
	return -1;
}