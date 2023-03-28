#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	Function_Object function(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_int,"arg1",false)
	});
	Function_Object function2(Position(), Data_Type::_int, "fun", {
		Variable_Essence(Data_Type::_float,"arg1",false)
	});
	Validator validator(true);
	function.accept(validator);
	function2.accept(validator);
	auto code_1 = function.generate_code();
	auto code_2 = function2.generate_code();
	if (code_1 ==
R"(FUNCTION int fun 
ARGUMENTS
declare int var arg1 
ARGUMENTS_END
FUNCTION_END

)"
&& code_2 ==
R"(FUNCTION int fun1 
ARGUMENTS
declare float var arg1 
ARGUMENTS_END
FUNCTION_END

)") {
		return 0; 
	}
	return -1;
}