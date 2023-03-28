#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Variable_Object var_a(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<String_Object>(Position(), ""));
	Validator validator(true);
	try {
		var_a.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Variable and initializator have differend types") {
			return 0;
		}
	}
	return -1;
}