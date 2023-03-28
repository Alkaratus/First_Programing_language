#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Function_Object function2(Position(), Data_Type::_float, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Validator validator(true);
	try {
		function.accept(validator);
		function2.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Variable with that name or Function with that name and arguments already exist") {
			return 0;
		}
	}
	return -1;
}