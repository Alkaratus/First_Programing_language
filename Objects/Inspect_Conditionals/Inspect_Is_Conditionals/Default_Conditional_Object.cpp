#include "Default_Conditional_Object.h"
#include "../../../Visitor/Visitor.h"

Default_Conditional_Object::Default_Conditional_Object(Position position):
	Inspect_Is_Conditional_Object(position)
{}

void Default_Conditional_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Default_Conditional_Object::generate_code(){
	return "_";
}
