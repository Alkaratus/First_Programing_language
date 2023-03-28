#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"

int main() {
	Source_String source(
R"(void check(string value){
	inspect(value){
		i as int :{
			inspect(i){
				is 0: { out("Default int/float value");}
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
})");
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(true);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	auto code = validated_tree.generate_code();
	if (code ==
R"(FUNCTION void check 
ARGUMENTS
declare string const value 
ARGUMENTS_END
INSPECT call_v value 
OPTION i as int 
INSPECT call_v i 
OPTION is == 0 
call_f out ( "Default int/float value" ) 
OPTION_END
OPTION is _
call_f out ( "Non-zero intiger" ) 
OPTION_END
INSPECT_END

OPTION_END
OPTION f as float 
INSPECT call_v f 
OPTION is > 0 
call_f out ( "Possitive float" ) 
OPTION_END
OPTION is _
call_f out ( "Non-positive float" ) 
OPTION_END
INSPECT_END

OPTION_END
OPTION is == "" 
call_f out ( "Empty string" ) 
OPTION_END
OPTION is _
call_f out ( "Unconvertable non-empty string" ) 
OPTION_END
INSPECT_END

FUNCTION_END

)") {
		return 0;
	}
	return -1;
}