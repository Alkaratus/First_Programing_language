#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("0");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::const_int && std::get<long long>(token.get_value()) == 0) {
		return 0;
	}
	return -1;
}