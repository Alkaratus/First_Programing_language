#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"

int main() {
	Source_String source(
R"(float power(float base, int var exp){
	auto var result = 1.0;
	while(exp){
		result = result * base;
		exp = exp - 1;
	}
	return result;
}

int factorial(int var number){
	auto var result = 1;
	while (number){
		result = result * number;
		number = number - 1;
	}
	return result;
}

int main(){
	auto pow_res = power(2.0,3);
	auto var number= 6;
	factorial(#number);
	return 0;
})");
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(true);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	auto code = validated_tree.generate_code();
	if (code ==
R"(FUNCTION float power 
ARGUMENTS
declare float const base 
declare int var exp 
ARGUMENTS_END
declare float var result 1.000000 
WHILE (int call_v exp )
(float call_v result = (float call_v result * call_v base ) ) 
(int call_v exp = (int call_v exp - 1 ) ) 
WHILE_END

return float call_v result 
FUNCTION_END

FUNCTION int factorial 
ARGUMENTS
declare int var number 
ARGUMENTS_END
declare int var result 1 
WHILE (int call_v number )
(int call_v result = (int call_v result * call_v number ) ) 
(int call_v number = (int call_v number - 1 ) ) 
WHILE_END

return int call_v result 
FUNCTION_END

FUNCTION int main 
ARGUMENTS
ARGUMENTS_END
declare float const pow_res call_f power ( 2.000000 3 ) 
declare int var number 6 
call_f factorial ( # call_v number ) 
return int 0 
FUNCTION_END

)") {
		return 0;
	}
	return -1;
}