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
int var x;
inspect("3"){
	i as int:{
		inspect(i){
			is in [0,2]:{
				x= 5;
			}
			is >2:{
				x= 4; 
			}
			is _:{
				x= 3;
			}
		}
	}
	is "":{
		x= 2;
	}
	is _:{
		x= 1;
	}
}
)");
	Source_Lexer lexer(source);
	Parser parser(lexer);
	Validator validator(true);
	auto declaration = parser.create_declarations_object();
	parser.consume_if(Token::semicolon);
	auto object = parser.create_inspect_object();
	declaration->accept(validator);
	object->accept(validator);
	Validated_Object_Tree tree;
	Executor executor(tree);
	declaration->accept(executor);
	object->accept(executor);
	auto check = executor.get_var("x");
	if ((*std::get<shared_ptr<long long int>>(check).get()) == 4) {
		return 0;
	}
	return -1;
}