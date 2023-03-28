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
	int var x=1;
	x=3;
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto object = parser.create_declarations_object();
	auto operation = parser.create_name_start_object();
	object->accept(validator);
	operation->accept(validator);
	Validated_Object_Tree tree;
	Executor executor(tree);
	object->accept(executor);
	operation->accept(executor);
	auto check=executor.get_var("x");
	if ((*std::get<shared_ptr<long long int>>(check).get()) == 3) {
		return 0;
	}
	return -1;
}