#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"


int main() {
	Source_String source("\'\\a\'");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::const_char && std::get<char>(token.get_value()) == '\a') {
		return 0;
	}
	return -1;
}