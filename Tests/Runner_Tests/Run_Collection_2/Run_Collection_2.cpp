#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"

int main() {
Executive_Code code(
R"()");
	Splitted_Line declaration("declare int const test 2 ");
	Splitted_Line in_set("In_Set (int call_v test colection { 0 1 } ) ");
	Runner runner(code);
	runner.create_variable(declaration,true);
	auto value = runner.execute_In_Set(in_set);
	if (*value.get() == 0) {
		return 0;
	}
	return -1;
}