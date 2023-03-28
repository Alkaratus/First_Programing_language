#include <stdexcept>
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"

int main() {
	Source_String source("@");
	Source_Lexer lexer(source);
	try {
		auto token = lexer.get_token();
	}
	catch (std::invalid_argument& e) {
		std::string error =e.what();
		if(error== "Error in File: main.apl Line: 1 Column: 1 Unknown character")
		return 0;
	}
	return -1;
}