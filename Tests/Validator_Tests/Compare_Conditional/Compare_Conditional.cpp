#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Compare_Conditional_Object compare(Position(),std::make_shared<Int_Object>(Position(),1),Operator_Type::equal);
	Validator validator(true);
	compare.accept(validator);
	auto code= compare.generate_code();
	if (code == "(int == 1 ) ") {
		return 0; 
	}
	return -1;
}