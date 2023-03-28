#include "Conditional_Object.h"
#include "../Visitor/Visitor.h"

Conditional_Object::Conditional_Object(Position position, std::vector<If_Object> _if_statements, std::optional<Else_Object> _else_statement):
	Compilation_Object(position),
	if_statements(_if_statements),
	else_statement(_else_statement)
{}

void Conditional_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Conditional_Object::generate_code() {
	std::string code="CONDITIONAL\n";
	for (auto& if_object : if_statements) {
		code+=if_object.generate_code();
	}
	if (else_statement.has_value()) {
		code += else_statement.value().generate_code();
	}
	code += "CONDITIONAL_END\n";
	return code;
}

std::vector<If_Object> &Conditional_Object::get_if_statements() {
	return if_statements;
}

std::optional<Else_Object> &Conditional_Object::get_else_statement() {
	return else_statement;
}