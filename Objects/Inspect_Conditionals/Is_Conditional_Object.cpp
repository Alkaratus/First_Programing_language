#include "Is_Conditional_Object.h"
#include "../../Visitor/Visitor.h"

Is_Conditional_Object::Is_Conditional_Object(Position position, std::shared_ptr<Inspect_Is_Conditional_Object> _condition):
	Inspect_Conditional_Object(position),
	condition(_condition)
{}

void Is_Conditional_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Is_Conditional_Object::generate_code(){
	return "is "+condition->generate_code();
}

std::shared_ptr<Inspect_Is_Conditional_Object> Is_Conditional_Object::get_condition() {
	return condition;
}