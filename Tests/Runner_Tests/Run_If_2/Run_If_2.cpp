#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"

int main() {
Executive_Code code(
R"(FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
CONDITIONAL
IF (char (int call_v test > 0 ))
(int call_v res = 1 )
IF_END
IF (char (int call_v test == 0 ))
(int call_v res = 2 )
IF_END
ELSE
(int call_v res = 3 )
ELSE_END
CONDITIONAL_END
FUNCTION_END

)");
	Splitted_Line declaration("declare int const test 0 ");
	Splitted_Line declaration1("declare int var res 0 ");
	Splitted_Line call("call_v res");
	Runner runner(code);
	runner.create_variable(declaration,true);
	runner.create_variable(declaration1, true);
	runner.run();
	auto value=runner.execute_call_v<long long int>(call);
	if (*value.get() == 2) {
		return 0;
	}
	return -1;
}