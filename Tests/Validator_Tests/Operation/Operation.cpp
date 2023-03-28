#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Variable_Call_Object.h"

int main() {
	Declarations_Object declarations(Position(), {
		Variable_Object(Position(), Variable_Essence(Data_Type::_int, "a",false), std::make_shared<Int_Object>(Position(), 0)),
		});
	Operation_Object operation(Position(), std::make_shared<Variable_Call_Object>(Position(), "a"), Operator_Type::assign, std::make_shared<Int_Object>(Position(), 1));
	Validator validator(true);
	declarations.accept(validator);
	operation.accept(validator);
	auto code=operation.generate_code();
	if (code == "(int call_v a = 1 ) ") {
		return 0; 
	}
	return -1;
}