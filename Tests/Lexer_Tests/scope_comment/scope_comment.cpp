#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("/* this is another comment */");
	Source_Lexer lexer(source);
	auto token = lexer.get_token();
	return 0;
}