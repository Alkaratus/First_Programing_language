#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Operation_Object operation(Position(), std::make_shared<String_Object>(Position(), "ba"), Operator_Type::summation, std::make_shared<Int_Object>(Position(), 1));
	Validator validator(true);
	try {
		operation.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Operatives data_types not match, use converters to make it") {
			return 0;
		}
	}
	return -1;
}