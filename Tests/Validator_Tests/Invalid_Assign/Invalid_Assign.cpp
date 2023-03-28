#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Variable_Call_Object.h"

int main() {
	Declarations_Object declarations(Position(), {
		Variable_Object(Position(), Variable_Essence(Data_Type::_int, "a",true), std::make_shared<Int_Object>(Position(), 0)),
		});
	Operation_Object operation(Position(), std::make_shared<Variable_Call_Object>(Position(), "a"), Operator_Type::assign, std::make_shared<Int_Object>(Position(), 1));
	Validator validator(true);
	try {
		declarations.accept(validator);
		operation.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Value cannot be assign to constans") {
			return 0;
		}
	}
	return -1;
}