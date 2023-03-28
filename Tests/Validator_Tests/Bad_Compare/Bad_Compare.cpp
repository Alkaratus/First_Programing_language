#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Compare_Conditional_Object compare(Position(), std::make_shared<Int_Object>(Position(), 1), Operator_Type::summation);
	Validator validator(true);
	try {
		compare.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Used operator is not aceptable") {
			return 0;
		}
	}
	return -1;
}