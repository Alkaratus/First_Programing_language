#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("\"Hello World\"");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	if (token.get_type() == Token::const_string && std::get<std::string>(token.get_value()) == "Hello World") {
		return 0;
	}
	return -1;
}