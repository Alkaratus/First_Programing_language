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
	int var a=1, var b= -5, var c=6;
	
	auto delta=b*b-4*a*c;
	if(delta>0){
		out(((-1)*b-sqrt(delta))/(2*a));
		out(" ");
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
	Executor executor(validated_tree);
	executor.execute();
	return 0;
}

