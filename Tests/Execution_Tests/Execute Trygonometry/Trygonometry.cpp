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
out(" ");
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
	Executor executor(validated_tree);
	executor.execute();
	return 0;
}