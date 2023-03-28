#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
#include "../../../Runner/Executor.h"
#include "../../../Source/Source_String.h"

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
	Executor executor(validated_tree);
	executor.execute();
	return 0;
}