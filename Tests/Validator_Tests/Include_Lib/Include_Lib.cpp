#include "../../../Validator/Validator.h"


int main() {
	Include_Object include(Position(), "io.apl");
	Validator validator(true);
	include.accept(validator);
	auto tree = validator.get_current_tree();
	auto code = tree.generate_code();
	if (code == 
R"(FUNCTION void @out 
ARGUMENTS
declare string const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out1 
ARGUMENTS
declare int const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out2 
ARGUMENTS
declare char const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out3 
ARGUMENTS
declare float const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp 
ARGUMENTS
declare string var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp1 
ARGUMENTS
declare int var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp2 
ARGUMENTS
declare char var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp3 
ARGUMENTS
declare float var where 
ARGUMENTS_END
FUNCTION_END

)"){
		return 0; 
	}
	return -1;
}