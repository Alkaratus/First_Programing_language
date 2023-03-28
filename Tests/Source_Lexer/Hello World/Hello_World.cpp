#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

Token tokens[] = { 
	Token(Position(File("main.apl"),1,1),"include",Token::include),
	Token(Position(File("main.apl"),1,9),"io.apl",Token::const_string),
	Token(Position(File("main.apl"),1,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),3,1),"int",Token::_int),
	Token(Position(File("main.apl"),3,5),"main",Token::name),
	Token(Position(File("main.apl"),3,9),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),3,10),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),3,11),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),4,5),"out",Token::name),
	Token(Position(File("main.apl"),4,8),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),4,9),"Hello World",Token::const_string),
	Token(Position(File("main.apl"),4,22),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),4,23),'\0',Token::semicolon),
	Token(Position(File("main.apl"),5,1),'\0',Token::close_buckle),
};

int main() {
	Source_String source(
R"(include "io.apl";

int main(){
	out("Hello World");
})"
);
	int i = 0;
	Source_Lexer lexer(source);
	while (!source.is_end()) {
		auto token = lexer.get_token();
		if (token.get_position().to_string() != tokens[i].get_position().to_string() || token.get_type()!=tokens[i].get_type() || token.get_value() != tokens[i].get_value()) {
			return -1;
		}
		i++;
	}
	return 0;
}