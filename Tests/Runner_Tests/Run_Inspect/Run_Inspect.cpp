#include "../../../Runner/Runner.h"
#include "../../../Runner/Splited_Line.h"
#include "../../../Executives/Executive_Code.h"
#include <any>

int main() {
	Executive_Code code(
R"(FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
INSPECT (string "1" )
OPTION i as int 
INSPECT (int call_v i )
OPTION is (int in zone [ 0 2 ] ) 
return 5 
OPTION_END
OPTION is (int >= 3 ) 
return 4 
OPTION_END
OPTION is _
return 3 
OPTION_END
INSPECT_END

OPTION_END
OPTION is (string == "" ) 
return 2 
OPTION_END
OPTION is _
return 1 
OPTION_END
INSPECT_END

FUNCTION_END

)");
	Runner runner(code);
	auto returned_value=runner.run();
	if (returned_value ==5) {
		return 0;
	}
	return -1;
}