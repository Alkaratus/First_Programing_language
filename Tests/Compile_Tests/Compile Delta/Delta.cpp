#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"


int main() {
	Source_String source(
R"(include "io.apl";
include "math.apl";

int main(){
	int var a, var b, var c;
	inp(a);inp(b);inp(c);
	
	auto delta=b*b-4*a*c;
	if(delta>0){
		out(((-1)*b-sqrt(delta))/(2*a));
		out(((-1)*b+sqrt(delta))/(2*a));
	}
	else if(delta==0){
		out((-1)*b/(2*a));
	}
	else{

	}
})");
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(true);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	auto code = validated_tree.generate_code();
	if (code ==
R"(FUNCTION void @out 
ARGUMENTS
declare string const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out1 
ARGUMENTS
declare int const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out2 
ARGUMENTS
declare char const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @out3 
ARGUMENTS
declare float const what 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp 
ARGUMENTS
declare string var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp1 
ARGUMENTS
declare int var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp2 
ARGUMENTS
declare char var where 
ARGUMENTS_END
FUNCTION_END

FUNCTION void @inp3 
ARGUMENTS
declare float var where 
ARGUMENTS_END
FUNCTION_END

declare float const math_pi 3.141590 
FUNCTION int @sqrt 
ARGUMENTS
declare int const value 
ARGUMENTS_END
FUNCTION_END

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
declare int var a 0 
declare int var b 0 
declare int var c 0 

call_f @inp1 ( call_v a ) 
call_f @inp1 ( call_v b ) 
call_f @inp1 ( call_v c ) 
declare int const delta (int (int call_v b * call_v b ) - (int (int 4 * call_v a ) * call_v c ) ) 
CONDITIONAL
IF (char (int call_v delta > 0 ) )
call_f @out1 ( (int (int (int -1 * call_v b ) - call_f @sqrt ( call_v delta ) ) / (int 2 * call_v a ) ) ) 
call_f @out1 ( (int (int (int -1 * call_v b ) + call_f @sqrt ( call_v delta ) ) / (int 2 * call_v a ) ) ) 
IF_END
IF (char (int call_v delta == 0 ) )
call_f @out1 ( (int (int -1 * call_v b ) / (int 2 * call_v a ) ) ) 
IF_END
ELSE
ELSE_END
CONDITIONAL_END

FUNCTION_END

)") {
		return 0;
	}
	return -1;
}

