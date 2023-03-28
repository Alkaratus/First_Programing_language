#include "Char_Object.h"
#include "../../../Visitor/Visitor.h"

Char_Object::Char_Object(Position position, char _value) :
	Constans_Object(position, Data_Type::_char),
	value(_value)
{}

std::string Char_Object::generate_code() {
	return '\''+std::to_string(value) + "\' ";
}

value_variant Char_Object::get_value() {
	return value;
}

void Char_Object::accept(Visitor& visitor) {
	visitor.visit(*this);
}