#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"


Token tokens[] = {
	Token(Position(File("main.apl"),1,1),"include",Token::include),
	Token(Position(File("main.apl"),1,9),"io.apl",Token::const_string),
	Token(Position(File("main.apl"),1,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),2,1),"include",Token::include),
	Token(Position(File("main.apl"),2,9),"math.apl",Token::const_string),
	Token(Position(File("main.apl"),2,19),'\0',Token::semicolon),
	Token(Position(File("main.apl"),4,1),"int",Token::_int),
	Token(Position(File("main.apl"),4,5),"main",Token::name),
	Token(Position(File("main.apl"),4,9),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),4,10),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),4,11),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),5,5),"int",Token::_int),
	Token(Position(File("main.apl"),5,9),"var",Token::var),
	Token(Position(File("main.apl"),5,13),"a",Token::name),
	Token(Position(File("main.apl"),5,14),'\0',Token::comma),
	Token(Position(File("main.apl"),5,16),"b",Token::name),
	Token(Position(File("main.apl"),5,17),'\0',Token::comma),
	Token(Position(File("main.apl"),5,19),"c",Token::name),
	Token(Position(File("main.apl"),5,20),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,5),"inp",Token::name),
	Token(Position(File("main.apl"),6,8),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,9),"a",Token::name),
	Token(Position(File("main.apl"),6,10),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,11),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,12),"inp",Token::name),
	Token(Position(File("main.apl"),6,15),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,16),"b",Token::name),
	Token(Position(File("main.apl"),6,17),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,18),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,19),"inp",Token::name),
	Token(Position(File("main.apl"),6,22),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,23),"c",Token::name),
	Token(Position(File("main.apl"),6,24),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,25),'\0',Token::semicolon),
	Token(Position(File("main.apl"),8,5),"auto",Token::_auto),
	Token(Position(File("main.apl"),8,10),"delta",Token::name),
	Token(Position(File("main.apl"),8,15),'\0',Token::assign),
	Token(Position(File("main.apl"),8,16),"b",Token::name),
	Token(Position(File("main.apl"),8,17),'\0',Token::multiplication),
	Token(Position(File("main.apl"),8,18),"b",Token::name),
	Token(Position(File("main.apl"),8,19),'\0',Token::subtraction),
	Token(Position(File("main.apl"),8,20),4,Token::const_int),
	Token(Position(File("main.apl"),8,21),'\0',Token::multiplication),
	Token(Position(File("main.apl"),8,22),"a",Token::name),
	Token(Position(File("main.apl"),8,23),'\0',Token::multiplication),
	Token(Position(File("main.apl"),8,24),"c",Token::name),
	Token(Position(File("main.apl"),8,25),'\0',Token::semicolon),
	Token(Position(File("main.apl"),9,5),"if",Token::_if),
	Token(Position(File("main.apl"),9,7),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),9,8),"delta",Token::name),
	Token(Position(File("main.apl"),9,13),'\0',Token::grader_than),
	Token(Position(File("main.apl"),9,14),0,Token::const_int),
	Token(Position(File("main.apl"),9,15),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),9,16),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),10,9),"out",Token::name),
	Token(Position(File("main.apl"),10,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,13),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,15),'\0',Token::subtraction),
	Token(Position(File("main.apl"),10,16),1,Token::const_int),
	Token(Position(File("main.apl"),10,17),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,18),'\0',Token::multiplication),
	Token(Position(File("main.apl"),10,19),"b",Token::name),
	Token(Position(File("main.apl"),10,20),'\0',Token::subtraction),
	Token(Position(File("main.apl"),10,21),"sqrt",Token::name),
	Token(Position(File("main.apl"),10,25),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,26),"delta",Token::name),
	Token(Position(File("main.apl"),10,31),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,32),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,33),'\0',Token::division),
	Token(Position(File("main.apl"),10,34),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,35),2,Token::const_int),
	Token(Position(File("main.apl"),10,36),'\0',Token::multiplication),
	Token(Position(File("main.apl"),10,37),"a",Token::name),
	Token(Position(File("main.apl"),10,38),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,39),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,40),'\0',Token::semicolon),
	Token(Position(File("main.apl"),11,9),"out",Token::name),
	Token(Position(File("main.apl"),11,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,13),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,15),'\0',Token::subtraction),
	Token(Position(File("main.apl"),11,16),1,Token::const_int),
	Token(Position(File("main.apl"),11,17),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,18),'\0',Token::multiplication),
	Token(Position(File("main.apl"),11,19),"b",Token::name),
	Token(Position(File("main.apl"),11,20),'\0',Token::summation),
	Token(Position(File("main.apl"),11,21),"sqrt",Token::name),
	Token(Position(File("main.apl"),11,25),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,26),"delta",Token::name),
	Token(Position(File("main.apl"),11,31),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,32),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,33),'\0',Token::division),
	Token(Position(File("main.apl"),11,34),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,35),2,Token::const_int),
	Token(Position(File("main.apl"),11,36),'\0',Token::multiplication),
	Token(Position(File("main.apl"),11,37),"a",Token::name),
	Token(Position(File("main.apl"),11,38),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,39),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,40),'\0',Token::semicolon),
	Token(Position(File("main.apl"),12,5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),13,5), "else", Token::_else),
	Token(Position(File("main.apl"),13,10), "if", Token::_if),
	Token(Position(File("main.apl"),13,12), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),13,13), "delta", Token::name),
	Token(Position(File("main.apl"),13,18), '\0', Token::equal),
	Token(Position(File("main.apl"),13,20), 0, Token::const_int),
	Token(Position(File("main.apl"),13,21), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),13,22), '\0', Token::open_buckle),
	Token(Position(File("main.apl"),14,9), "out", Token::name),
	Token(Position(File("main.apl"),14,12), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),14,13), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),14,14), '\0', Token::subtraction),
	Token(Position(File("main.apl"),14,15), 1, Token::const_int),
	Token(Position(File("main.apl"),14,16), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),14,17), '\0', Token::multiplication),
	Token(Position(File("main.apl"),14,18), "b", Token::name),
	Token(Position(File("main.apl"),14,19), '\0', Token::division),
	Token(Position(File("main.apl"),14,20), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),14,21), 2, Token::const_int),
	Token(Position(File("main.apl"),14,22), '\0', Token::multiplication),
	Token(Position(File("main.apl"),14,23), "a", Token::name),
	Token(Position(File("main.apl"),14,24), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),14,25), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),14,26), '\0', Token::semicolon),
	Token(Position(File("main.apl"),15,5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),16, 5), "else", Token::_else),
	Token(Position(File("main.apl"),16, 9), '\0', Token::open_buckle),
	Token(Position(File("main.apl"),18, 5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),19, 1), '\0', Token::close_buckle)
};

int main() {
	Source_String source(
R"(include "io.apl";
include "math.apl";

int main(){
	int var a, b, c;
	inp(a);inp(b);inp(c);
	
	auto delta=b*b-4*a*c;
	if(delta>0){
		out(((-1)*b-sqrt(delta))/(2*a));
		out(((-1)*b+sqrt(delta))/(2*a));
	}
	else if(delta==0){
		out((-1)*b/(2*a));
	}
	else{

	}
})");
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