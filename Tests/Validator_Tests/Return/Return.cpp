#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Return_Object _return(Position(), std::make_shared<Int_Object>(Position(), 0));
	Validator validator(true);
	function.accept(validator);
	_return.accept(validator);
	auto code= _return.generate_code();
	if (code == "return int 0 ") {
		return 0; 
	}
	return -1;
}