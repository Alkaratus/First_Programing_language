#include "Real_Parser.h"

Real_Parser::Real_Parser(Lexer& lexer):Parser(lexer)
{}

Object_Tree Real_Parser::parse_all(){
	Object_Tree objects;
	while (!is_lexer_end()) {
		objects.add_object(parse());
	}
	return objects;
}
