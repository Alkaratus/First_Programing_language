#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Real_Parser.h"

Token_Collection collection({
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
});

int main() {
	Real_Parser parser(collection);
	auto tree = parser.parse_all();
	auto code = tree.generate_code();
	if (code ==
R"(FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
call_f out ( "Hello World" ) 
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}