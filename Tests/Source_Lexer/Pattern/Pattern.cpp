#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

Token tokens[] = { 
	Token(Position(File("main.apl"),1,1),"void",Token::_void),
	Token(Position(File("main.apl"),1,6),"check",Token::name),
	Token(Position(File("main.apl"),1,11),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),1,12),"string",Token::_string),
	Token(Position(File("main.apl"),1,19),"value",Token::name),
	Token(Position(File("main.apl"),1,24),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),1,25),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),2,5),"inspect",Token::inspect),
	Token(Position(File("main.apl"),2,12),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),2,13),"value",Token::name),
	Token(Position(File("main.apl"),2,18),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),2,19),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),3,9),"i",Token::name),
	Token(Position(File("main.apl"),3,11),"as",Token::as),
	Token(Position(File("main.apl"),3,14),"int",Token::_int),
	Token(Position(File("main.apl"),3,18),'\0',Token::colon),
	Token(Position(File("main.apl"),3,19),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),4,13),"inspect",Token::inspect),
	Token(Position(File("main.apl"),4,20),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),4,21),"i",Token::name),
	Token(Position(File("main.apl"),4,22),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),4,23),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),5,17),"is",Token::is),
	Token(Position(File("main.apl"),5,20), 0, Token::const_int),
	Token(Position(File("main.apl"),5,21),'\0',Token::colon),
	Token(Position(File("main.apl"),5,23),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),5,25),"out",Token::name),
	Token(Position(File("main.apl"),5,28),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),5,29),"Default int/float value",Token::const_string),
	Token(Position(File("main.apl"),5,54),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),5,55),'\0',Token::semicolon),
	Token(Position(File("main.apl"),5,56),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),6,17),"is",Token::is),
	Token(Position(File("main.apl"),6,20), "_", Token::name),
	Token(Position(File("main.apl"),6,21),'\0',Token::colon),
	Token(Position(File("main.apl"),6,23),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),6,25),"out",Token::name),
	Token(Position(File("main.apl"),6,28),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),6,29),"Non-zero intiger",Token::const_string),
	Token(Position(File("main.apl"),6,47),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),6,48),'\0',Token::semicolon),
	Token(Position(File("main.apl"),6,49),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),7,13),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),8,9),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),9,9),"f",Token::name),
	Token(Position(File("main.apl"),9,11),"as",Token::as),
	Token(Position(File("main.apl"),9,14),"float",Token::_float),
	Token(Position(File("main.apl"),9,20),'\0',Token::colon),
	Token(Position(File("main.apl"),9,21),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),10,13),"inspect",Token::inspect),
	Token(Position(File("main.apl"),10,20),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),10,21),"f",Token::name),
	Token(Position(File("main.apl"),10,22),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),10,23),'\0',Token::colon),
	Token(Position(File("main.apl"),10,24),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),11,17),"is",Token::is),
	Token(Position(File("main.apl"),11,20),'\0',Token::grader_than),
	Token(Position(File("main.apl"),11,21), 0, Token::const_int),
	Token(Position(File("main.apl"),11,22),'\0',Token::colon),
	Token(Position(File("main.apl"),11,24),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),11,26),"out",Token::name),
	Token(Position(File("main.apl"),11,29),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),11,30),"Possitive float",Token::const_string),
	Token(Position(File("main.apl"),11,47),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),11,48),'\0',Token::semicolon),
	Token(Position(File("main.apl"),11,49),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),12,17),"is",Token::is),
	Token(Position(File("main.apl"),12,20), "_", Token::name),
	Token(Position(File("main.apl"),12,21),'\0',Token::colon),
	Token(Position(File("main.apl"),12,23),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),12,25),"out",Token::name),
	Token(Position(File("main.apl"),12,28),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),12,29),"Non-positive float",Token::const_string),
	Token(Position(File("main.apl"),12,49),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),12,50),'\0',Token::semicolon),
	Token(Position(File("main.apl"),12,51),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),13,13),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),14,9),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),15,9),"is",Token::is),
	Token(Position(File("main.apl"),15,12),"",Token::const_string),
	Token(Position(File("main.apl"),15,14),'\0',Token::colon),
	Token(Position(File("main.apl"),15,16),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),15,17),"out",Token::name),
	Token(Position(File("main.apl"),15,20),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),15,21),"Empty string",Token::const_string),
	Token(Position(File("main.apl"),15,35),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),15,36),'\0',Token::semicolon),
	Token(Position(File("main.apl"),15,37),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),16,9),"is",Token::is),
	Token(Position(File("main.apl"),16,12), "_", Token::name),
	Token(Position(File("main.apl"),16,13),'\0',Token::colon),
	Token(Position(File("main.apl"),16,15),'\0',Token::open_buckle),
	Token(Position(File("main.apl"),16,16),"out",Token::name),
	Token(Position(File("main.apl"),16,19),'\0',Token::open_bracket),
	Token(Position(File("main.apl"),16,20),"Unconvertable non-empty string",Token::const_string),
	Token(Position(File("main.apl"),16,52),'\0',Token::close_bracket),
	Token(Position(File("main.apl"),16,53),'\0',Token::semicolon),
	Token(Position(File("main.apl"),16,54),'\0',Token::close_buckle),
	Token(Position(File("main.apl"),17, 5), '\0', Token::close_buckle),
	Token(Position(File("main.apl"),18, 1), '\0', Token::close_buckle),
};

int main() {
	Source_String source(
R"(void check(string value){
	inspect(value){
		i as int :{
			inspect(i){
				is 0: { out("Default int/float value");}
				is _: { out("Non-zero intiger");}
			}
		}
		f as float :{
			inspect(f):{
				is >0: { out("Possitive float");}
				is _: { out("Non-positive float");}
			}
		}
		is "": {out("Empty string");}
		is _: {out("Unconvertable non-empty string");}
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