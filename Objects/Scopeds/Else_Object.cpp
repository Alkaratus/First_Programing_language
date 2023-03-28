#include "Else_Object.h"
#include "../../Visitor/Visitor.h"

Else_Object::Else_Object(Position position):
	Scoped_Object(position) 
{}

void Else_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Else_Object::generate_code() {
	std::string code = "ELSE\n";
	code += Scoped_Object::generate_statements_code();
	code += "ELSE_END\n";
	return code;
}