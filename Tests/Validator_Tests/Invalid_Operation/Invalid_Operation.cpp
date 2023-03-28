#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Operation_Object operation(Position(), std::make_shared<String_Object>(Position(), "ba"), Operator_Type::subtraction, std::make_shared<String_Object>(Position(), "a"));
	Validator validator(true);
	try {
		operation.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Opperation cannot be made for operatives of this type") {
			return 0;
		}
	}
	return -1;
}