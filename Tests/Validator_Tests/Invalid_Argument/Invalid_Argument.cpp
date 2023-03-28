#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Variable_Object var(Position(), Variable_Essence(Data_Type::_int, "v", true), std::make_shared<Int_Object>(Position(), 2));
	Function_Call_Object call(Position(), "fun", {
		Function_Argument(false,std::make_shared<Variable_Call_Object>(Position(),"v"))
	});
	Validator validator(true);
	try {
		function.accept(validator);
		var.accept(validator);
		call.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Constans variable cannot be mutable argument") {
			return 0;
		}
	}
	return -1;
}