#include "Declarations_Object.h"
#include "../Visitor/Visitor.h"

Declarations_Object::Declarations_Object(Position position, std::vector<Variable_Object> _declarated_variables):
	Compilation_Object(position),declarated_variables(_declarated_variables) {

}

void Declarations_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Declarations_Object::generate_code() {
	std::string code;
	for (auto& variable : declarated_variables) {
		code += variable.generate_code();
		code += '\n';
	}
	return code;
}

std::vector<Variable_Object>& Declarations_Object::get_declarations() {
	return declarated_variables;
}