#pragma once
#include "Parser.h"
#include "Objects_Tree.h"

class Real_Parser :private Parser {
public:
	Real_Parser(Lexer& lexer);
	Object_Tree parse_all();
};