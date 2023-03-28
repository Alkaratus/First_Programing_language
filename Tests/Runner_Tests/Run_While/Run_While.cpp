#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"

int main() {
Executive_Code code(
R"(FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
WHILE (int call_v test ) 
(int call_v res = (int call_v res * 2 ) ) 
(int call_v test = (int call_v test - 1 ) ) 
WHILE_END
FUNCTION_END

)");
	Splitted_Line declaration("declare int const test 2 ");
	Splitted_Line declaration1("declare int var res 1 ");
	Splitted_Line call("call_v res");
	Runner runner(code);
	runner.create_variable(declaration,true);
	runner.create_variable(declaration1, true);
	runner.run();
	auto value=runner.execute_call_v<long long int>(call);
	if (*value.get() == 4) {
		return 0;
	}
	return -1;
}