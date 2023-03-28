#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"
#include <any>

int main() {
	Executive_Code code(R"()");
	Splitted_Line is_option("is _ ");
	Runner runner(code);
	std::any value = std::string("hello");
	auto result=runner.check_option_condition(is_option,value,"(string");
	if (result) {
		return 0;
	}
	return -1;
}