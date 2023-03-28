#include "String_Object.h"
#include "../../../Visitor/Visitor.h"

String_Object::String_Object(Position position, std::string _value) :
	Constans_Object(position, Data_Type::_string),
	value(_value)
{}

std::string String_Object::generate_code(){
	return "\""+value+"\" ";
}

value_variant String_Object::get_value() {
	return value;
}

void String_Object::accept(Visitor& visitor) {
	visitor.visit(*this);
}