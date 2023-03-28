#include "../../../Executives/Executive_Code.h"
#include "../../../Runner/Runner.h"

int main() {
	Executive_Code code(
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
declare string const where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp1 
ARGUMENTS
declare int const where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp2 
ARGUMENTS
declare char const where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp3 
ARGUMENTS
declare float const where 
ARGUMENTS_END
FUNCTION_END

declare float const math_pi 3.141590 
FUNCTION int @sqrt 
ARGUMENTS
declare int const value 
ARGUMENTS_END
FUNCTION_END

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
declare float const angle 1.000000 

CONDITIONAL
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( 0.000000 call_v math_pi ) ) )
call_f @out ( "+" ) 
IF_END
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( call_v math_pi (float 2.000000 * call_v math_pi ) ) ) )
call_f @out ( "-" ) 
IF_END
ELSE
call_f @out1 ( 0 ) 
ELSE_END
CONDITIONAL_END

CONDITIONAL
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( (float 0.500000 * call_v math_pi ) (float 1.500000 * call_v math_pi ) ) ) )
call_f @out ( "-" ) 
IF_END
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) colection { (float 0.500000 * call_v math_pi ) (float 1.500000 * call_v math_pi ) } ) )
call_f @out1 ( 0 ) 
IF_END
ELSE
call_f @out ( "+" ) 
ELSE_END
CONDITIONAL_END

return 0 
FUNCTION_END

)");
	Runner runner(code);
	runner.run();
	return 0;
}