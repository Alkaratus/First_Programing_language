#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

Token tokens[] = { 
	Token(Position(File("main.apl"),1,1),"include",Token::include),
	Token(Position(File("main.apl"),1,9),"io.apl",Token::const_string),
	Token(Position(File("main.apl"),1,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),2,1),"include",Token::include),
	Token(Position(File("main.apl"),2,9),"math.apl",Token::const_string),
	Token(Position(File("main.apl"),2,19),'\0',Token::semicolon),
	Token(Position(File("main.apl"),3,1),"int",Token::_int),
	Token(Position(File("main.apl"),3,5),"main",Token::name),
	Token(Position(File("main.apl"),3,9),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),3,10),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),3,11),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),4,5),"float",Token::_float),
	Token(Position(File("main.apl"),4,11),"angle",Token::name),
	Token(Position(File("main.apl"),4,16),'\0',Token::assign),
	Token(Position(File("main.apl"),4,17),1,Token::const_int),
	Token(Position(File("main.apl"),4,18),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,5),"if",Token::_if),
	Token(Position(File("main.apl"),6,7),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,8),"angle",Token::name),
	Token(Position(File("main.apl"),6,13),'\0',Token::modulation),
	Token(Position(File("main.apl"),6,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,15),2,Token::const_int),
	Token(Position(File("main.apl"),6,16),'\0',Token::multiplication),
	Token(Position(File("main.apl"),6,17),"math_pi",Token::name),
	Token(Position(File("main.apl"),6,24),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,26),"in",Token::in),
	Token(Position(File("main.apl"),6,29),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,30),0,Token::const_int),
	Token(Position(File("main.apl"),6,31),'\0',Token::comma),
	Token(Position(File("main.apl"),6,32),"math_pi",Token::name),
	Token(Position(File("main.apl"),6,39),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,40),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,41),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),7,9),"out",Token::name),
	Token(Position(File("main.apl"),7,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),7,13),"+",Token::const_string),
	Token(Position(File("main.apl"),7,16),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),7,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),8,5),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),9,5), "else", Token::_else),
	Token(Position(File("main.apl"),9,10), "if", Token::_if),
	Token(Position(File("main.apl"),9,13), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),9,14), "angle", Token::name),
	Token(Position(File("main.apl"),9,19),'\0',Token::modulation),
	Token(Position(File("main.apl"),9,20),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),9,21),2,Token::const_int),
	Token(Position(File("main.apl"),9,22),'\0',Token::multiplication),
	Token(Position(File("main.apl"),9,23),"math_pi",Token::name),
	Token(Position(File("main.apl"),9,30),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),9,32),"in",Token::in),
	Token(Position(File("main.apl"),9,35),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),9,36),"math_pi",Token::name),
	Token(Position(File("main.apl"),9,43),'\0',Token::comma),
	Token(Position(File("main.apl"),9,44),2,Token::const_int),
	Token(Position(File("main.apl"),9,45),'\0',Token::multiplication),
	Token(Position(File("main.apl"),9,46),"math_pi",Token::name),
	Token(Position(File("main.apl"),9,53),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),9,54),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),10,9),"out",Token::name),
	Token(Position(File("main.apl"),10,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,13),"-",Token::const_string),
	Token(Position(File("main.apl"),10,16),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),11,5),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),12,5), "else", Token::_else),
	Token(Position(File("main.apl"),12,9),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),13,9),"out",Token::name),
	Token(Position(File("main.apl"),13,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),13,13),0,Token::const_int),
	Token(Position(File("main.apl"),13,14),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),13,15),'\0',Token::semicolon),
	Token(Position(File("main.apl"),14,5),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),16,5),"if",Token::_if),
	Token(Position(File("main.apl"),16,7),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),16,8),"angle",Token::name),
	Token(Position(File("main.apl"),16,13),'\0',Token::modulation),
	Token(Position(File("main.apl"),16,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),16,15),2,Token::const_int),
	Token(Position(File("main.apl"),16,16),'\0',Token::multiplication),
	Token(Position(File("main.apl"),16,17),"math_pi",Token::name),
	Token(Position(File("main.apl"),16,24),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),16,26),"in",Token::in),
	Token(Position(File("main.apl"),16,29),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),16,30),0.5,Token::const_float),
	Token(Position(File("main.apl"),16,33),'\0',Token::multiplication),
	Token(Position(File("main.apl"),16,34),"math_pi",Token::name),
	Token(Position(File("main.apl"),16,41),'\0',Token::comma),
	Token(Position(File("main.apl"),16,42),1.5,Token::const_float),
	Token(Position(File("main.apl"),16,45),'\0',Token::multiplication),
	Token(Position(File("main.apl"),16,46),"math_pi",Token::name),
	Token(Position(File("main.apl"),16,53),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),16,54),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),16,55),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),17,9),"out",Token::name),
	Token(Position(File("main.apl"),17,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),17,13),"-",Token::const_string),
	Token(Position(File("main.apl"),17,16),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),17,17),'\0',Token::semicolon),
	Token(Position(File("main.apl"),18,5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),19, 5), "else", Token::_else),
	Token(Position(File("main.apl"),19, 10), "if", Token::_if),
	Token(Position(File("main.apl"),19, 12), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),19, 13), "angle", Token::name),
	Token(Position(File("main.apl"),19, 18), '\0', Token::modulation),
	Token(Position(File("main.apl"),19, 19), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),19, 20), 2, Token::const_int),
	Token(Position(File("main.apl"),19, 21), '\0', Token::multiplication),
	Token(Position(File("main.apl"),19, 22), "math_pi", Token::name),
	Token(Position(File("main.apl"),19, 29), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),19, 31), "in", Token::in),
	Token(Position(File("main.apl"),19, 34), '\0', Token::open_buckle),
	Token(Position(File("main.apl"),19, 35), 0.5, Token::const_float),
	Token(Position(File("main.apl"),19, 38), '\0', Token::multiplication),
	Token(Position(File("main.apl"),19, 39), "math_pi", Token::name),
	Token(Position(File("main.apl"),19, 46), '\0', Token::comma),
	Token(Position(File("main.apl"),19, 47), 1.5, Token::const_float),
	Token(Position(File("main.apl"),19, 50), '\0', Token::multiplication),
	Token(Position(File("main.apl"),19, 51), "math_pi", Token::name),
	Token(Position(File("main.apl"),19, 58), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),19, 59), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),19, 60), '\0', Token::open_buckle),
	Token(Position(File("main.apl"),20, 9), "out", Token::name),
	Token(Position(File("main.apl"),20, 12), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),20, 13), 0, Token::const_int),
	Token(Position(File("main.apl"),20, 14), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),20, 15), '\0', Token::semicolon),
	Token(Position(File("main.apl"),21, 5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),22, 5), "else", Token::_else),
	Token(Position(File("main.apl"),22, 9), '\0', Token::open_buckle),
	Token(Position(File("main.apl"),23, 9), "out", Token::name),
	Token(Position(File("main.apl"),23, 12), '\0', Token::open_bracket),
	Token(Position(File("main.apl"),23, 13), "+", Token::const_string),
	Token(Position(File("main.apl"),23, 16), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),23, 17), '\0', Token::semicolon),
	Token(Position(File("main.apl"),24, 5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),25, 5), "return", Token::_return),
	Token(Position(File("main.apl"),25, 12), 0, Token::const_int),
	Token(Position(File("main.apl"),25, 13), '\0', Token::semicolon),
	Token(Position(File("main.apl"),26, 1), '\0', Token::close_buckle)
};

int main() {
	Source_String source(
R"(include "io.apl";
include "math.apl";
int main(){
	float angle=1;
	//sinus
	if(angle%(2*math_pi) in (0,math_pi)){
		out("+");
	}
	else if (angle%(2*math_pi) in (math_pi,2*math_pi){
		out("-");
	}
	else{
		out(0);
	}
	/* cosinus */
	if(angle%(2*math_pi) in (0.5*math_pi,1.5*math_pi)){
		out("-");
	}
	else if(angle%(2*math_pi) in {0.5*math_pi,1.5*math_pi}){
		out(0);
	}
	else{
		out("+");
	}
	return 0;
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