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
	float angle=1.0;
	//sinus
	if(angle%(2.0*math_pi) in (0.0,math_pi)){
		out("+");
	}
	else if (angle%(2.0*math_pi) in (math_pi,2.0*math_pi)){
		out("-");
	}
	else{
		out(0);
	}
	/* cosinus */
	if(angle%(2.0*math_pi) in (0.5*math_pi,1.5*math_pi)){
		out("-");
	}
	else if(angle%(2.0*math_pi) in {0.5*math_pi,1.5*math_pi}){
		out(0);
	}
	else{
		out("+");
	}
	return 0;
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
declare float const angle 1.000000 

CONDITIONAL
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( 0.000000 call_v math_pi ) ) )
call_f @out ( "+" ) 
IF_END
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( call_v math_pi (float 2.000000 * call_v math_pi ) ) ) )
call_f @out ( "-" ) 
IF_END
ELSE
call_f @out1 ( 0 ) 
ELSE_END
CONDITIONAL_END

CONDITIONAL
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) zone ( (float 0.500000 * call_v math_pi ) (float 1.500000 * call_v math_pi ) ) ) )
call_f @out ( "-" ) 
IF_END
IF (char In_Set (float (float call_v angle % (float 2.000000 * call_v math_pi ) ) colection { (float 0.500000 * call_v math_pi ) (float 1.500000 * call_v math_pi ) } ) )
call_f @out1 ( 0 ) 
IF_END
ELSE
call_f @out ( "+" ) 
ELSE_END
CONDITIONAL_END

return int 0 
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}