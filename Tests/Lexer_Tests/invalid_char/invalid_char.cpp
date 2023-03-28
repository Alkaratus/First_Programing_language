#include <stdexcept>
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"


int main() {
	Source_String source("\'a ");
	try {
		Source_Lexer lexer(source);
		auto token = lexer.get_token();
	}
	catch (std::invalid_argument& e) {
		std::string error =e.what();
		if(error== "Error in File: main.apl Line: 1 Column: 3 unexpected sign, expected \'!")
		return 0;
	}
	return -1;
}