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
	char y = x in (0,2);
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto object = parser.create_declarations_object();
	parser.consume_if(Token::semicolon);
	auto operation = parser.create_declarations_object();
	object->accept(validator);
	operation->accept(validator);
	Validated_Object_Tree tree;
	Executor executor(tree);
	object->accept(executor);
	operation->accept(executor);
	auto check=executor.get_var("y");
	if ((*std::get<shared_ptr<char>>(check).get()) == 1) {
		return 0;
	}
	return -1;
}