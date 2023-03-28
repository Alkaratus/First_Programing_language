#include "../../../Validator/Validator.h"

int main() {
	Include_Object include(Position(), "../../../../../../simple.apl");
	Validator validator(true);
	include.accept(validator);
	auto tree = validator.get_current_tree();
	auto code = tree.generate_code();
	if (code ==
R"(FUNCTION int return_0 
ARGUMENTS
ARGUMENTS_END
return int 0 
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}