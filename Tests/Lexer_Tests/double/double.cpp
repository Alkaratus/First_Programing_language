#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"


int main() {
	Source_String source("0.75");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::const_float && std::get<double>(token.get_value()) == 0.75) {
		return 0;
	}
	return -1;
}