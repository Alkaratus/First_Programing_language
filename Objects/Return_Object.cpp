#include "Return_Object.h"
#include "../Visitor/Visitor.h"

Return_Object::Return_Object(Position _position, std::shared_ptr<Operative_Object> _returned):
	Compilation_Object(_position),
	returned(_returned)
{}

void Return_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Return_Object::generate_code(){
	return "return "+returned->get_type().generate_code()+returned->generate_code();
}

std::shared_ptr<Operative_Object>& Return_Object::get_returned(){
	return returned;
}