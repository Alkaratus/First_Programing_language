#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	Variable_Object var_a(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0));
	Variable_Object var_b(Position(), Variable_Essence(Data_Type::_auto, "b", false), std::make_shared<Float_Object>(Position(), 0.0));
	Validator validator(true);
	var_a.accept(validator);
	var_b.accept(validator);
	auto code_1=var_a.generate_code();
	auto code_2=var_b.generate_code();
	if (code_1 == "declare int var a 0 " && code_2=="declare float var b 0.000000 ") {
		return 0; 
	}
	return -1;
}