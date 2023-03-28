#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),"i",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::as),
		Token(Position(File("main.apl"),1,1),'\0',Token::_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),"i",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_inspect_option_object(std::make_shared<Int_Object>(Int_Object(Position(File("main.apl"),1, 1), 0)));
	auto code = object->generate_code();
	if (code==
R"(OPTION i as int 
return  call_v i 
OPTION_END
)"){
		return 0;
	}
	return -1;
}