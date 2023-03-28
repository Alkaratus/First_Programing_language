#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"

int main() {
Executive_Code code(
R"(FUNCTION int return_2 
ARGUMENTS
ARGUMENTS_END
return 2 
FUNCTION_END

)");
	Splitted_Line declaration("declare int const test call_f return_2 ( ) ");
	Splitted_Line call("call_v test");
	Runner runner(code);
	runner.create_variable(declaration,true);
	auto value=runner.execute_call_v<long long int>(call);
	if (*value.get() == 2) {
		return 0;
	}
	return -1;
}