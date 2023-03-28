#include "While_Object.h"
#include "../../Visitor/Visitor.h"

While_Object::While_Object(Position position, std::shared_ptr<Operative_Object> _condition):Scoped_Object(position), 
	condition(_condition)
{}

void While_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string While_Object::generate_code() {
	std::string code = "WHILE (" + condition->get_type().generate_code() + condition->generate_code() + ")\n";
	code += generate_statements_code();
	code += "WHILE_END\n";
	return code;
}

std::shared_ptr<Operative_Object>& While_Object::get_condition() {
	return condition;
}