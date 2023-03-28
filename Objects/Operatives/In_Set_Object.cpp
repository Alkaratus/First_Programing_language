#include "In_Set_Object.h"
#include "../../Visitor/Visitor.h"

In_Set_Object::In_Set_Object(Position position, std::shared_ptr<Operative_Object> _checked, std::shared_ptr<Set_Object> _set):
	Operative_Object(position,false,Token::_char),
	checked(_checked),
	set(_set)
{}

void In_Set_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string In_Set_Object::generate_code() {
	return "In_Set ("+checked->get_type().generate_code()+ checked->generate_code() + set->generate_code() + ") ";
}

std::shared_ptr<Operative_Object> In_Set_Object::get_checked() {
	return checked;
}

std::shared_ptr<Set_Object> In_Set_Object::get_set() {
	return set;
}