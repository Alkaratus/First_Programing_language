#include "../../../Executives/Executive_Code.h"
#include "../../../Runner/Runner.h"

int main() {
	Executive_Code code(
R"(FUNCTION float power 
ARGUMENTS
declare float const base 
declare int var exp 
ARGUMENTS_END
declare float var result 1.000000 
WHILE (int call_v exp )
(float call_v result = (float call_v result * call_v base ) ) 
(int call_v exp = (int call_v exp - 1 ) ) 
WHILE_END

return call_v result 
FUNCTION_END

FUNCTION int factorial 
ARGUMENTS
declare int var number 
ARGUMENTS_END
declare int var result 1 
WHILE (int call_v number )
(int call_v result = (int call_v result * call_v number ) ) 
(int call_v number = (int call_v number - 1 ) ) 
WHILE_END

return call_v result 
FUNCTION_END

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
declare float const pow_res call_f power ( 2.000000 3 ) 
declare int var number 6 
call_f factorial ( # call_v number ) 
return 0 
FUNCTION_END

)");
	Runner runner(code);
	runner.run();
	return 0;
}