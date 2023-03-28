#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"

int main() {
	Executive_Code code(R"()");
	Splitted_Line declaration("declare int const test 2");
	Splitted_Line operation("(int call_v test = 4 )");
	Splitted_Line call("call_v test");
	Runner runner(code);
	runner.create_variable(declaration,true);
	runner.execute_assignment(operation);
	auto value = runner.execute_call_v<long long int>(call);
	if (*value.get() == 4) {
		return 0;
	}
	return -1;
}