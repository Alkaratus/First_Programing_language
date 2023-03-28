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
	int x=-1, var y;
	
	if (x>0){
		y=1;
	}
	else if(x==0){
		y=0;
	}
	else{
		y=-1;
	}
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto object = parser.create_declarations_object();
	parser.consume_if(Token::semicolon);
	auto conditional = parser.create_conditional_object();
	object->accept(validator);
	conditional->accept(validator);
	Validated_Object_Tree tree;
	Executor executor(tree);
	object->accept(executor);
	conditional->accept(executor);
	auto check=executor.get_var("y");
	if ((*std::get<shared_ptr<long long int>>(check).get()) == -1) {
		return 0;
	}
	return -1;
}