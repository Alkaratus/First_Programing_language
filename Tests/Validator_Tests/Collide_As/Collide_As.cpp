#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "foo", {
		Variable_Essence(Data_Type::_int,"arg1",false)
		});
	As_Conditional_Object as(Position(), "foo", Data_Type::_int);
	Validator validator(true);
	try {
		function.accept(validator);
		as.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Variable or Function with that name already exist") {
			return 0;
		}
	}
	return -1;
}