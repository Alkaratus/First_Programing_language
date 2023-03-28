#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,17),'\0',Token::open_bracket), 
		Token(Position(File("main.apl"),1,18),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,19),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,19),'\0',Token::close_buckle)
	});
	Parser parser(collection);
	auto object = parser.create_function_object(Token::_int, Token(Position(File("main.apl"),1, 9), "main", Token::name));
	auto code = object->generate_code();
	if (code == 
R"(FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}