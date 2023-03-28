#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Function_Call_Object call(Position(), "fun", {
		Function_Argument(false,std::make_shared<Int_Object>(Position(),1))
	});
	Validator validator(true);
	function.accept(validator);
	call.accept(validator);
	auto code = call.generate_code();
	if (code == "call_f fun ( 1 ) ") {
		return 0; 
	}
	return -1;
}