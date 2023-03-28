#include "Include_Object.h"
#include "../Visitor/Visitor.h"

Include_Object::Include_Object(Position position, std::string _name):Compilation_Object(position),name(_name){}

void Include_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Include_Object::generate_code(){
	return "";
}

std::string Include_Object::get_name() {
	return name;
}