#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"

int main() {
	Source_String source(
R"(include "io.apl";
void check(string value){
	inspect(value){
		i as int :{
			inspect(i){
				is 0: { out("Default int/float value");}
				is in [1,9] : { out("One digit positive value");}
				is _: { out("Non-zero intiger");}
			}
		}
		f as float :{
			inspect(f){
				is >0: { out("Possitive float");}
				is _: { out("Non-positive float");}
			}
		}
		is "": {out("Empty string");}
		is _: {out("Unconvertable non-empty string");}
	}
}

int main(){
	check("0");
}
)");
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

FUNCTION void check 
ARGUMENTS
declare string const value 
ARGUMENTS_END
INSPECT (string call_v value )
OPTION i as int 
INSPECT (int call_v i )
OPTION is (int == 0 ) 
call_f @out ( "Default int/float value" ) 
OPTION_END
OPTION is (int in zone [ 1 9 ] ) 
call_f @out ( "One digit positive value" ) 
OPTION_END
OPTION is _
call_f @out ( "Non-zero intiger" ) 
OPTION_END
INSPECT_END

OPTION_END
OPTION f as float 
INSPECT (float call_v f )
OPTION is (int > 0 ) 
call_f @out ( "Possitive float" ) 
OPTION_END
OPTION is _
call_f @out ( "Non-positive float" ) 
OPTION_END
INSPECT_END

OPTION_END
OPTION is (string == "" ) 
call_f @out ( "Empty string" ) 
OPTION_END
OPTION is _
call_f @out ( "Unconvertable non-empty string" ) 
OPTION_END
INSPECT_END

FUNCTION_END

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
call_f check ( "0" ) 
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}