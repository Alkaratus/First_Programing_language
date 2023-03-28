#include "Float_Object.h"
#include "../../../Visitor/Visitor.h"

Float_Object::Float_Object(Position position, double _value):
	Constans_Object(position, Data_Type::_float),
	value(_value)
{}

std::string Float_Object::generate_code(){
	return std::to_string(value) + ' ';
}

value_variant Float_Object::get_value() {
	return value;
}

void Float_Object::accept(Visitor& visitor) {
	visitor.visit(*this);
}