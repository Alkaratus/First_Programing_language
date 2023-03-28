#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("=");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::assign) {
		return 0;
	}
	return -1;
}