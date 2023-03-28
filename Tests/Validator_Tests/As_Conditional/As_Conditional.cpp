#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	As_Conditional_Object as(Position(), "i", Data_Type::_int);
	Validator validator(true);
	as.accept(validator);
	auto code= as.generate_code();
	if (code == "i as int ") {
		return 0; 
	}
	return -1;
}