#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	Variable_Object var_a(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0));
	Variable_Object var_b(Position(), Variable_Essence(Data_Type::_auto, "a", false), std::make_shared<Float_Object>(Position(), 0.0));
	Validator validator(true);
	try {
		var_a.accept(validator);
		var_b.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Variable of Function with that name already exist") {
			return 0;
		}
	}
	return -1;
}