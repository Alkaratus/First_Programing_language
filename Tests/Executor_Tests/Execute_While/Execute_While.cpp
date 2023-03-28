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
	int var x=3, var y=1;
	
	while (x>0){
		y=y*2;
		x=x-1;
	}
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto object = parser.create_declarations_object();
	parser.consume_if(Token::semicolon);
	auto _while = parser.create_while_object();
	object->accept(validator);
	_while->accept(validator);
	Validated_Object_Tree tree;
	Executor executor(tree);
	object->accept(executor);
	_while->accept(executor);
	auto check=executor.get_var("y");
	if ((*std::get<shared_ptr<long long int>>(check).get()) == 8) {
		return 0;
	}
	return -1;
}