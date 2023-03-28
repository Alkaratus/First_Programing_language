#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

Token tokens[] = { 
	Token(Position(File("main.apl"),1,1),"float",Token::_float),
	Token(Position(File("main.apl"),1,7),"power",Token::name),
	Token(Position(File("main.apl"),1,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),1,13),"float",Token::_float),
	Token(Position(File("main.apl"),1,19),"base",Token::name),
	Token(Position(File("main.apl"),1,23),'\0',Token::comma),
	Token(Position(File("main.apl"),1,25),"int",Token::_int),
	Token(Position(File("main.apl"),1,29),"var",Token::var),
	Token(Position(File("main.apl"),1,33),"exp",Token::name),
	Token(Position(File("main.apl"),1,36),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),1,37),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),2,5),"auto",Token::_auto),
	Token(Position(File("main.apl"),2,10),"var",Token::var),
	Token(Position(File("main.apl"),2,14),"result",Token::name),
	Token(Position(File("main.apl"),2,21),'\0',Token::assign),
	Token(Position(File("main.apl"),2,23),1,Token::const_int),
	Token(Position(File("main.apl"),2,24),'\0',Token::semicolon),
	Token(Position(File("main.apl"),3,5),"while",Token::_while),
	Token(Position(File("main.apl"),3,10),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),3,11),"exp",Token::name),
	Token(Position(File("main.apl"),3,14),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),3,15),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),4,9),"result",Token::name),
	Token(Position(File("main.apl"),4,16),'\0',Token::assign),
	Token(Position(File("main.apl"),4,18),"result",Token::name),
	Token(Position(File("main.apl"),4,25),'\0',Token::multiplication),
	Token(Position(File("main.apl"),4,27),"base",Token::name),
	Token(Position(File("main.apl"),4,31),'\0',Token::semicolon),
	Token(Position(File("main.apl"),5,9),"exp",Token::name),
	Token(Position(File("main.apl"),5,13),'\0',Token::assign),
	Token(Position(File("main.apl"),5,15),"exp",Token::name),
	Token(Position(File("main.apl"),5,19),'\0',Token::subtraction),
	Token(Position(File("main.apl"),5,21),1,Token::const_int),
	Token(Position(File("main.apl"),5,22),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),7,5),"return",Token::_return),
	Token(Position(File("main.apl"),7,12),"result",Token::name),
	Token(Position(File("main.apl"),7,18),'\0',Token::semicolon),
	Token(Position(File("main.apl"),8,1), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),10,1),"int",Token::_int),
	Token(Position(File("main.apl"),10,5),"factorial",Token::name),
	Token(Position(File("main.apl"),10,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,15),"int",Token::_int),
	Token(Position(File("main.apl"),10,19),"var",Token::var),
	Token(Position(File("main.apl"),10,23),"number",Token::name),
	Token(Position(File("main.apl"),10,29),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,30),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),11,5),"auto",Token::_auto),
	Token(Position(File("main.apl"),11,10),"var",Token::var),
	Token(Position(File("main.apl"),11,14),"result",Token::name),
	Token(Position(File("main.apl"),11,21),'\0',Token::assign),
	Token(Position(File("main.apl"),11,23),1,Token::const_int),
	Token(Position(File("main.apl"),11,24),'\0',Token::semicolon),
	Token(Position(File("main.apl"),12,5),"while",Token::_while),
	Token(Position(File("main.apl"),12,11),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),12,12),"number",Token::name),
	Token(Position(File("main.apl"),12,18),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),12,19),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),13,9),"result",Token::name),
	Token(Position(File("main.apl"),13,16),'\0',Token::assign),
	Token(Position(File("main.apl"),13,18),"result",Token::name),
	Token(Position(File("main.apl"),13,25),'\0',Token::multiplication),
	Token(Position(File("main.apl"),13,27),"number",Token::name),
	Token(Position(File("main.apl"),13,33),'\0',Token::semicolon),
	Token(Position(File("main.apl"),14,9),"number",Token::name),
	Token(Position(File("main.apl"),14,16),'\0',Token::assign),
	Token(Position(File("main.apl"),14,18),"number",Token::name),
	Token(Position(File("main.apl"),14,25),'\0',Token::subtraction),
	Token(Position(File("main.apl"),14,27),1,Token::const_int),
	Token(Position(File("main.apl"),14,28),'\0',Token::semicolon),
	Token(Position(File("main.apl"),15,5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),16,5),"return",Token::_return),
	Token(Position(File("main.apl"),16,12),"result",Token::name),
	Token(Position(File("main.apl"),16,18),'\0',Token::semicolon),
	Token(Position(File("main.apl"),17,1), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),19,1),"int",Token::_int),
	Token(Position(File("main.apl"),19,5),"main",Token::name),
	Token(Position(File("main.apl"),19,9),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),19,10),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),19,11),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),20,5),"auto",Token::_auto),
	Token(Position(File("main.apl"),20,10),"pow_res",Token::name),
	Token(Position(File("main.apl"),20,18),'\0',Token::assign),
	Token(Position(File("main.apl"),20,20),"power",Token::name),
	Token(Position(File("main.apl"),20,25),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),20,26),2,Token::const_int),
	Token(Position(File("main.apl"),20,27),'\0',Token::comma),
	Token(Position(File("main.apl"),20,28),3,Token::const_int),
	Token(Position(File("main.apl"),20,29),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),20,30),'\0',Token::semicolon),
	Token(Position(File("main.apl"),21,5),"auto",Token::_auto),
	Token(Position(File("main.apl"),21,10),"var",Token::var),
	Token(Position(File("main.apl"),21,14),"number",Token::name),
	Token(Position(File("main.apl"),21,20),'\0',Token::assign),
	Token(Position(File("main.apl"),21,22),6,Token::const_int),
	Token(Position(File("main.apl"),21,23),'\0',Token::semicolon),
	Token(Position(File("main.apl"),22,5),"factorial",Token::name),
	Token(Position(File("main.apl"),22,14),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),22,15), '\0', Token::hash),
	Token(Position(File("main.apl"),22,16), "number", Token::name),
	Token(Position(File("main.apl"),22,22), '\0', Token::close_bracket),
	Token(Position(File("main.apl"),22,23), '\0', Token::semicolon),
	Token(Position(File("main.apl"),23, 5), "return", Token::_return),
	Token(Position(File("main.apl"),23, 12), 0, Token::const_int),
	Token(Position(File("main.apl"),23, 13), '\0', Token::semicolon),
	Token(Position(File("main.apl"),24, 1), '\0', Token::close_buckle)
};

int main() {
	Source_String source(
R"(float power(float base, int var exp){
	auto var result = 1;
	while(exp){
		result = result * base;
		exp = exp - 1;
	}
	return result;
}

int factorial(int var number){
	auto var result = 1;
	while (number){
		result = result * number;
		number = number - 1;
	}
	return result;
}

int main(){
	auto pow_res = power(2,3);
	auto var number= 6;
	factorial(#number);
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