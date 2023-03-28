#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
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
declare int var a 1 
declare int var b 5 
declare int var c 6 

declare int const delta (int (int call_v b * call_v b ) - (int (int 4 * call_v a ) * call_v c ) ) 
CONDITIONAL
IF (char (int call_v delta > 0 ) )
call_f @out1 ( (int (int (int -1 * call_v b ) - call_f @sqrt ( call_v delta ) ) / (int 2 * call_v a ) ) ) 
call_f @out1 ( (int (int (int -1 * call_v b ) + call_f @sqrt ( call_v delta ) ) / (int 2 * call_v a ) ) ) 
IF_END
IF (char (int call_v delta == 0 ) )
call_f @out1 ( (int (int -1 * call_v b ) / (int 2 * call_v a ) ) ) 
IF_END
ELSE
ELSE_END
CONDITIONAL_END

FUNCTION_END

)");
Runner runner(code);
runner.run();
return 0;
}

