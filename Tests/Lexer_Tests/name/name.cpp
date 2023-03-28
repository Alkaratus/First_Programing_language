#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("test");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::name && std::get<std::string>(token.get_value()) == "test") {
		return 0;
	}
	return -1;
}