#include "Int_Object.h"
#include "../../../Visitor/Visitor.h"

Int_Object::Int_Object(Position position, long long int _value):
	Constans_Object(position,Data_Type::_int),
	value(_value)
{}

std::string Int_Object::generate_code() {
	return std::to_string(value) + ' ';
}

value_variant Int_Object::get_value() {
	return value;
}

void Int_Object::accept(Visitor& visitor) {
	visitor.visit(*this);
}