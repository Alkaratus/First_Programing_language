#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Variable_Call_Object.h"

int main() {
	Declarations_Object declarations(Position(), {
		Variable_Object(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0)),
		});
	Variable_Call_Object call(Position(), "b");
	Validator validator(true);
	try {
		declarations.accept(validator);
		call.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Variable with that name not exist") {
			return 0;
		}
	}
	return -1;
}