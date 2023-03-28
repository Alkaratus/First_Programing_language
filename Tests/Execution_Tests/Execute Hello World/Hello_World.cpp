#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"
#include "../../../Lexer/Source_Lexer.h"
#include "../../../Parser/Real_Parser.h"
#include "../../../Executives/Executive_Code.h"
#include "../../../Runner/Runner.h"
#include "../../../Runner/Executor.h"
#include "../../../Source/Source_String.h"

Object_Tree objects;

int main() {
	Source_String source(
R"(include "io.apl";

int main(){
	out("Hello World");
})"
);
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(true);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	Executor executor(validated_tree);
	executor.execute();
	return 0;
}