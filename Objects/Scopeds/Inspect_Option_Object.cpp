#include "Inspect_Option_Object.h"
#include "../../Visitor/Visitor.h"

Inspect_Option_Object::Inspect_Option_Object(Position position, std::shared_ptr<Inspect_Conditional_Object> _condition):
Scoped_Object(position),condition(_condition)
{}

void Inspect_Option_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Inspect_Option_Object::generate_code() {
	std::string code = "OPTION " +condition->generate_code() + '\n';
	code += Scoped_Object::generate_statements_code();
	code += "OPTION_END\n";
	return code;
}

std::shared_ptr<Inspect_Conditional_Object> Inspect_Option_Object::get_condition() {
	return condition;
}