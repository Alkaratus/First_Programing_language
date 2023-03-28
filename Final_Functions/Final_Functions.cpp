#include "Final_Functions.h"
#include "../Lexer/Source_Lexer.h"
#include "../Parser/Real_Parser.h"
#include "../Validator/Validator.h"
#include "../Runner/Executor.h"

std::string compile(Source& source){
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(true);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	return validated_tree.generate_code();
}

void compile_to_file(Source_File& file) {
	auto code = compile(file);
	auto executive_file_name = file.get_position().get_file().get_directory()+"/"+file.get_position().get_file().get_file_name();
	executive_file_name.replace(executive_file_name.end() - 3, executive_file_name.end(), "apx");
	Executive_File executive_file(executive_file_name, std::ios::out);
	executive_file.load(code);
}

void execute(Source& source) {
	Source_Lexer lexer(source);
	Real_Parser parser(lexer);
	Validator validator(false);
	auto tree = parser.parse_all();
	auto validated_tree = validator.validate_tree(tree);
	Executor executor(validated_tree);
	executor.execute();
}