#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
#include "../../../Runner/Executor.h"
#include "../../../Source/Source_String.h"

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
	Executor executor(validated_tree);
	executor.execute();
	return 0;
}