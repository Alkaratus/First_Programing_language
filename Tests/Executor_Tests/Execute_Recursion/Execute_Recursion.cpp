#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Source/Source_String.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
#include "../../../Runner/Executor.h"
#include "../../../Source/Source_String.h"

int main() {
	
	Source_String source(
R"(
	int recurse(int x){
		if(x<=0){
			return 0;
		}
		return x+recurse(x-1);
	}
	int y=recurse(3);
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto function = parser.create_type_start_object();
	auto object = parser.create_declarations_object();
	function->accept(validator);
	object->accept(validator);
	Validated_Object_Tree tree;
	tree.add_object(function);
	Executor executor(tree);
	object->accept(executor);
	auto check=executor.get_var("y");
	if ((*std::get<shared_ptr<long long int>>(check).get()) == 6) {
		return 0;
	}
	return -1;
}