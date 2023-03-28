#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),3,9),"i",Token::name),
		Token(Position(File("main.apl"),3,11),"as",Token::as),
		Token(Position(File("main.apl"),3,14),"int",Token::_int),
	});
	Parser parser(collection);
	auto object = parser.create_as_conditional_object(std::make_shared<Int_Object>(Int_Object(Position(File("main.apl"),1,1),0)));
	auto code = object->generate_code();
	if (code==
R"(i as int )"){
		return 0;
	}
	return -1;
}