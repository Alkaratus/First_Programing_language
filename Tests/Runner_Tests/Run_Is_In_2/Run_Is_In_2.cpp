#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"
#include <any>

int main() {
	Executive_Code code(R"()");
	Splitted_Line is_option("is (int in zone [ 1 9 ] ) ");
	Runner runner(code);
	long long int  conc_value = 2;
	std::any value = conc_value;
	auto result = runner.check_option_condition(is_option, value, "(int");
	if (result) {
		return 0;
	}
	return -1;
}