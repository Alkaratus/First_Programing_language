#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
#include "../../../Executives/Executive_Code.h"
#include "../../../Runner/Runner.h"

Object_Tree objects;

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

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
call_f @out ( "Hello World" ) 
FUNCTION_END


)");
	Runner runner(code);
	runner.run();
	return 0;
}