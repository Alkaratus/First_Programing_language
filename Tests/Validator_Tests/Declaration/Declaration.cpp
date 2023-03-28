#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Variable_Call_Object.h"

int main() {
	Declarations_Object declarations(Position(), {
		Variable_Object(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0)),
		Variable_Object(Position(), Variable_Essence(Data_Type::_auto, "b", true), std::make_shared<Variable_Call_Object>(Position(), "a")),
		});
	Validator validator(true);
	declarations.accept(validator);
	auto code=declarations.generate_code();
	if (code == 
R"(declare int var a 0 
declare int const b call_v a 
)") {
		return 0; 
	}
	return -1;
}