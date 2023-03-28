#include "In_Conditional_Object.h"
#include "../../../Visitor/Visitor.h"

In_Conditional_Object::In_Conditional_Object(Position position, std::shared_ptr<Set_Object> _set):
	Inspect_Is_Conditional_Object(position),
	set(_set)
{}

void In_Conditional_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string In_Conditional_Object::generate_code(){
	return "("+set->get_type().generate_code()+"in "+ set->generate_code() + ") ";
}

std::shared_ptr<Set_Object> In_Conditional_Object::get_set() {
	return set;
}