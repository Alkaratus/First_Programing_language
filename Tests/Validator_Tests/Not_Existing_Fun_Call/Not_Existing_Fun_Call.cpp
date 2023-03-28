#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Function_Call_Object call(Position(), "foo", {
		Function_Argument(false,std::make_shared<Int_Object>(Position(),1))
	});
	Validator validator(true);
	try {
		function.accept(validator);
		call.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Function with that name and arguments not exist") {
			return 0;
		}
	}
	return -1;
}