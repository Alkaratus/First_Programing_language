#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Variable_Call_Object.h"

int main() {
	Declarations_Object declarations(Position(), {
		Variable_Object(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0)),
		});
	Variable_Call_Object call(Position(), "a");
	Validator validator(true);
	declarations.accept(validator);
	call.accept(validator);
	auto code=call.generate_code();
	if (code == "call_v a ") {
		return 0; 
	}
	return -1;
}