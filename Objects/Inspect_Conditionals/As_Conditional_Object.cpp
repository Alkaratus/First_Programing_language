#include <map>
#include "As_Conditional_Object.h"
#include "../../Visitor/Visitor.h"

As_Conditional_Object::As_Conditional_Object(Position position, std::string _name, Data_Type_Object _type):
	Inspect_Conditional_Object(position),
	name(_name),
	type(_type)
{}

void As_Conditional_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string As_Conditional_Object::generate_code() {
	return name+" as "+type.generate_code();
}

std::string As_Conditional_Object::get_name() {
	return name;
}

Data_Type_Object As_Conditional_Object::get_type() {
	return type;
}