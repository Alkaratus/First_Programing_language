#include "If_Object.h"
#include "../../Visitor/Visitor.h"

If_Object::If_Object(Position position, std::shared_ptr<Operative_Object> _condition): 
	Scoped_Object(position),condition(_condition)
{}

void If_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string If_Object::generate_code(){
	std::string code="IF ("+ condition->get_type().generate_code() + condition->generate_code() + ")\n";
	code += Scoped_Object::generate_statements_code();
	code += "IF_END\n";
	return code;
}

std::shared_ptr<Operative_Object>& If_Object::get_condition() {
	return condition;
}