#include <stdexcept>
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"


int main() {
	Source_String source("&|");
	try {
		Source_Lexer lexer(source);
		auto token = lexer.get_token();
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 1 invalid operator") {
			return 0;
		}
	}
	return -1;
}