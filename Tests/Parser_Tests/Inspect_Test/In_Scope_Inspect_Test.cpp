#pragma once
#include "../../../Lexer/Token_Collection.h"
#include "../../../Parser/Parser.h"

int main() {
	Token_Collection collection({ 
		Token(Position(File("main.apl"),1,1),'\0',Token::inspect),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_bracket),
		Token(Position(File("main.apl"),1,1),"test",Token::name),
		Token(Position(File("main.apl"),1,9),'\0',Token::close_bracket),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),

		Token(Position(File("main.apl"),1,1),"i",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::as),
		Token(Position(File("main.apl"),1,1),'\0',Token::_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),"i",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),

		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,1),'\0',Token::in),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),0,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::comma),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),4,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),

		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,9),2,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),3,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),

		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,1),'\0',Token::grader_or_equal),
		Token(Position(File("main.apl"),1,9),3,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),2,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),

		Token(Position(File("main.apl"),1,1),'\0',Token::is),
		Token(Position(File("main.apl"),1,1),"_",Token::name),
		Token(Position(File("main.apl"),1,1),'\0',Token::colon),
		Token(Position(File("main.apl"),1,9),'\0',Token::open_buckle),
		Token(Position(File("main.apl"),1,9),'\0',Token::_return),
		Token(Position(File("main.apl"),1,9),1,Token::const_int),
		Token(Position(File("main.apl"),1,1),'\0',Token::semicolon),
		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),

		Token(Position(File("main.apl"),1,1),'\0',Token::close_buckle),
	});
	Parser parser(collection);
	auto object = parser.create_inspect_object();
	auto code = object->generate_code();
	if (code==
R"(INSPECT ( call_v test )
OPTION i as int 
return  call_v i 
OPTION_END
OPTION is (void in colection { 0 1 } ) 
return int 4 
OPTION_END
OPTION is (int == 2 ) 
return int 3 
OPTION_END
OPTION is (int >= 3 ) 
return int 2 
OPTION_END
OPTION is _
return int 1 
OPTION_END
INSPECT_END
)"){
		return 0;
	}
	return -1;
}